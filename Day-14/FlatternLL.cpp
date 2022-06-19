/*
You are given a linked list containing N nodes, where every node in the linked list contains two pointers, first one is ‘NEXT’ which points to the next node in the list and the second one is ‘CHILD’ pointer to a linked list where the head is this node. And each of these child linked lists is in sorted order.
Your task is to flatten this linked such that all nodes appear in a single layer or level while the nodes should maintain the sorted order.
For example:

The given linked list is - 
5
3 4 6  -1
5 11 14 -1
22 25 -1
26 28 -1
39  -1

OUTPUT->
3 4 5 6 11 14 22 25 26 28 39
*/

#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* mergelist(Node* a, Node* b)
{
    Node* temp = new Node(0);
    Node* res = temp;
    
    while(a != NULL && b != NULL)
    {
        if(a->data < b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
            temp->next = NULL;
        }
        else{
            temp->child = b;
            temp = temp->child;
            b = b->child;
            temp->next = NULL;
        }
    }
    
    if(a) temp->child = a;
    else temp->child = b;
    
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head == NULL || head->next == NULL)
        return head;
    
    head->next = flattenLinkedList(head->next);
    
    head = mergelist(head,head->next);
    
    
    return head;
   
}
