/*
Design and implement a data structure for Least Recently Used (LRU) cache to support the following operations:

1. get(key) - Return the value of the key if the key exists in the cache, otherwise return -1.

2. put(key, value), Insert the value in the cache if the key is not already present or update the value of the given key if the key is already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.

You will be given ‘Q’ queries. Each query will belong to one of these two types:

Type 0: for get(key) operation.
Type 1: for put(key, value) operation.

*/

#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int nodekey,int data)
        {
            key = nodekey;
            val = data;
        }
    };
    
    int cap;
    unordered_map<int,node*> cache;
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_)
    {
        // Write your code here
        if(cache.find(key_) != cache.end())
        {
            node* resnode = cache[key_];
            int res = resnode->val;
            cache.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            cache[key_] = head->next;
            
            return res;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        // Write your code here
        if(cache.find(key_) != cache.end())
        {
            node *exisiting = cache[key_];
            cache.erase(key_);
            deletenode(exisiting);
        }
        if(cache.size() == cap)
        {
            cache.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key_,value));
        cache[key_] = head->next;
    }
};

