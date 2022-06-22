#include <bits/stdc++.h>
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};


//Brute Force Approach
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
     unordered_map <LinkedListNode<int>* , LinkedListNode<int>*> umap;
    
    LinkedListNode<int> *temp = head;
    while(temp != NULL)
    {
        umap[temp] = new LinkedListNode<int>(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL)
    {
        umap[temp]->next = umap[temp->next];
        umap[temp]->random = umap[temp->random];
        temp= temp->next;
    }
    
    return umap[head];
}


//Optimized Approach 
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *itr = head;
    LinkedListNode<int> *front = head;

    while (itr != NULL)
    {
        front = itr->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(itr->data);
        itr->next = copy;
        copy->next = front;

        itr = front;
    }

    itr = head;

    while (itr != NULL)
    {

        itr->next->random = itr->random != NULL ? itr->random->next : NULL;
        itr = itr->next->next;
    }

    LinkedListNode<int> *ans = new LinkedListNode<int>(0);
    LinkedListNode<int> *copy = ans;

    itr = head;
    while (itr != NULL)
    {
        front = itr->next->next;
        copy->next = itr->next;
        itr->next = front;
        copy = copy->next;
        itr = front;
    }

    return ans->next;
}
