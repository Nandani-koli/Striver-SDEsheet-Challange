#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//Brute Force Approach TC:- O(k*n)
Node *rotate(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    for (int i = 0; i < k; i++)
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }

    return head;
}


//Optimized Approach TC-> O(length of list) + O(length of list – (length of list%k))

Node *rotate(Node *head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;
    
    int length = 1;
    Node* current = head;
    while(current->next != NULL)
    {
        ++length;
        current = current->next;
    }
    
    current->next = head;
    k = k%length;
    k = length - k;
    
    while(k--)
    {
        current = current->next;
    }
    head = current->next;
    current->next = NULL;
    
    return head;
}