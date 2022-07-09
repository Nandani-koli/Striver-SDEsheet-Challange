/*
You are given a Singly Linked List of integers and an integer array 'B' of size 'N'. Each element in the array 'B' represents a block size. Modify the linked list by reversing the nodes in each block whose sizes are given by the array 'B'.
Note:

1. If you encounter a situation when 'B[i]' is greater than the number of remaining nodes in the list, then simply reverse the remaining nodes as a block and ignore all the block sizes from 'B[i]'.

2. All block sizes are contiguous i.e. suppose that block 'B[i]' ends at a node cur, then the block 'B[i+1]' starts from the node just after the node cur.

Linked list: 1->2->3->4->5
Array B: 3 3 5

Output: 3->2->1->5->4
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

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    Node *dummy = new Node(0);
    dummy->next = head;

    Node *prev = dummy;
    Node *cur;
    Node *nex;

    int i = 0;
    while (count > 0 && i < n)
    {
        cur = prev->next;
        nex = cur->next;
        int x = (b[i] <= count) ? b[i] : count;
        if (x == 0)
        {
            i++;
            continue;
        }

        for (int j = 1; j < x; j++)
        {
            cur->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = cur->next;
        }
        prev = cur;
        count -= b[i];
        i++;
    }

    return dummy->next;
}