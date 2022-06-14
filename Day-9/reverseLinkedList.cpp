/*
Given a singly linked list of integers. Your task is to return the head of the reversed linked list.
INPUT->
1 2 3 4 5 6 

OUTPUT->
6 5 4 3 2 1
*/
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
//Iterative Approach
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* nextptr;
    
    while(curr != NULL)
    {
        nextptr = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = nextptr;
    }
    return prev;       
}

//Recursive Aprroach 
LinkedListNode<int> *reverseLinkedListRecursively(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedListNode<int> *newhead = reverseLinkedListRecursively(head->next);
    head->next->next = head;
    head->next = NULL;
   
    return newhead;
}
