/*
You are given two linked lists representing two non-negative numbers. The digits in the linked list are stored in reverse order, i.e. starting from least significant digit (LSD) to the most significant digit (MSD), and each of their nodes contains a single digit. Your task is to find the sum list and return the head of the sum list where the sum list is a linked list representation of the addition of two numbers.
Note : The number represented by the linked lists do not contain any leading zeros.

INPUT->
5 -> 6 -> 3 -> NULL 
8 -> 4 -> 2 -> NULL 

OUTPUT->
3 -> 1 -> 6 -> NULL

Explaination->
365 + 248 = 613

*/

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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node * head = new Node(-1);
    Node * temp = head;
    
    int carry = 0;
    while(head1 != NULL || head2 != NULL || carry)
    {
        int sum = 0;
        if(head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        
        sum += carry;
        carry = sum/10;
        Node* newnode = new Node(sum%10);
        temp->next = newnode;
        temp = temp->next;
    }
    
    return head->next;
}                                   