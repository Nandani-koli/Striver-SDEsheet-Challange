/*
Design and implement a Least Frequently Used(LFU) Cache, to implement the following functions:

1. put(U__ID, value): Insert the value in the cache if the key(‘U__ID’) is not already present or update the value of the given key if the key is already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting the new item.

2. get(U__ID): Return the value of the key(‘U__ID’),  present in the cache, if it’s present otherwise return -1.

Note:

  1) The frequency of use of an element is calculated by a number of operations with its ‘U_ID’ performed after it is inserted in the cache.

  2) If multiple elements have the least frequency then we remove the element which was least recently used. 

You have been given ‘M’ operations which you need to perform in the cache. Your task is to implement all the functions of the LFU cache.

Type 1: for put(key, value) operation.
Type 2: for get(key) operation.

*/

#include<bits/stdc++.h>
using namespace std;

class LFUCache
{
public:
    class node{
        public :
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int nodekey,int value)
        {
            key = nodekey;
            val = value;
        }
    };
    
    int cap;
    unordered_map<int,node*> keynode;
    unordered_map<int,int> freq;
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    void addnode(node* newnode)
    {
        node *temp = head->next;
        head->next = newnode;
        newnode->next = temp;
        temp->prev = newnode;
        newnode->prev = head;
    }
    
    void deletenode(node * delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    LFUCache(int capacity)
    {
        // Write your code here.
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_)
    {
        // Write your code here.
        if(keynode.find(key_) != keynode.end())
        {
            int res;
            node * tempnode = keynode[key_];
            res = tempnode->val;
            keynode.erase(key_);
            deletenode(tempnode);
            addnode(tempnode);
            keynode[key_] = head->next;
            freq[key_]++;
            
            return res;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        // Write your code here.
        if(keynode.find(key_) != keynode.end())
        {
            node * newnode = keynode[key_];
            deletenode(newnode);
            keynode.erase(key_);
            freq[key_]++;
        }
        if(keynode.size() == cap)
        {
            int minimum = 1000;
            node *delnode;
            for(auto x:freq){
                minimum = min(minimum,x.second);
            }
            int count = 0;
            for(auto x:freq){
                if(x.second == minimum) count++;
            }
            if(count == 1){
                int keyvalue = 0;
                for(auto x:freq){
                    if(x.second == minimum){
                        delnode = keynode[x.first];
                        keyvalue = x.first;
                        break;
                    }
                }
                keynode.erase(keyvalue);
                freq.erase(keyvalue);
                deletenode(delnode);
            }
            else{
            keynode.erase(tail->prev->key);
            deletenode(tail->prev);
            freq.erase(tail->prev->key);
        }
            
        }
        
        addnode(new node(key_,value));
        keynode[key_] = head->next;
        freq[key_]++;
    }
};
