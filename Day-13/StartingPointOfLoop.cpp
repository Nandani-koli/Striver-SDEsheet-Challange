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

//Brute Force TC:-O(n) SC:- O(n)
Node *firstNode(Node *head)
{
    unordered_set<Node *> st;
    Node* temp = head;
    while(temp != NULL)
    {
        if(st.find(temp) != st.end()) return temp;
        
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}

//optimized Approach TC-> O(n) SC-> O(1)
Node *firstNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;
    Node *entry = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }

    return NULL;
}