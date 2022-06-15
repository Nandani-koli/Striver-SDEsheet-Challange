#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

//Brute Force Approach O(2n)

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(head == NULL || K == 0)
    {
        return head;
    }
    int length = 0;
    LinkedListNode <int>* temp = head;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    if(length == K)
    {
        return head->next;
    }
    
    int count = length - K;
    
    LinkedListNode <int> *prev = NULL;
    LinkedListNode <int> *curr = head;
    for(int i =0; i <count; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    
    return head;
}

// Two pointer Method O(n)

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(head == NULL || K == 0)
    {
        return head;
    }
    LinkedListNode<int>* temp = new LinkedListNode<int>(-1);
    temp->next = head;
    LinkedListNode<int>* slow = temp;
    LinkedListNode<int>* fast = temp;
    
    for(int i =0; i< K; i++)
    {
        fast = fast->next;
    }
    
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    
    return temp->next;
}