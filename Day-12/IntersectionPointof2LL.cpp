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

//Using Hashing TC:- O(n+m) SC-> O(n)

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_set<Node*> st;
    
    while(firstHead != NULL)
    {
        st.insert(firstHead);
        firstHead = firstHead->next;
    }
    
    while(secondHead != NULL)
    {
        if(st.find(secondHead) != st.end()) return secondHead->data;
        
        secondHead = secondHead->next;
    }
    
    return -1;
}

//opyimal aaproach O(2n)
int findIntersection(Node *firstHead, Node *secondHead)
{

    if (firstHead == NULL || secondHead == NULL)
        return -1;
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    while (temp1 != temp2)
    {
        if (temp1 == NULL)
        {
            temp1 = secondHead;
        }
        else
        {
            temp1 = temp1->next;
        }

        if (temp2 == NULL)
        {
            temp2 = firstHead;
        }
        else
        {
            temp2 = temp2->next;
        }
    }

    if (temp1 == NULL)
    {
        return -1;
    }
    else
    {
        return temp1->data;
    }
}
