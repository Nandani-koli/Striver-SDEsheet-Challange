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

//Using Hashtable TC:- O(n) Sc-> O(n)
bool detectCycle(Node *head)
{
    //	Write your code here
    unordered_set<Node *> st;
    while (head != NULL)
    {
        if (st.find(head) != st.end())
        {
            return true;
        }
        st.insert(head);
        head = head->next;
    }

    return false;
}

