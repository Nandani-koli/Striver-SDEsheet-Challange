#include <bits/stdc++.h> 
using namespace std;
    
    class Node {
        public:
        int data;
        Node* next;
    };
void displayList(Node *n)
{
    if(n == NULL)
    {
        cout<<"NUll value"<<endl;
    }
    while (n != NULL)
    {
        cout<<n->data<<"->";
        n = n->next;
    }
    cout<<"NULL"<<endl;  
}
void InsertAtEnd(Node **head , int newvalue)
{
    //1. Prepare a new node 
    Node * newnode = new Node;
    newnode->data = newvalue;
    newnode->next = NULL;

    //2. if a linkedlist is empty, newnode will be head node
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }

    //3. Find the last node
    Node * last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }

    //4. Insert a newnode after last node
    last->next = newnode;

}

Node* sortTwoLists(Node* first, Node* second)
{
    if(first == NULL)
        return second;
    else if(second == NULL)
        return first;
    
    // Write your code here.
    Node *ans = NULL;
    if(first->data <= second->data)
        {
        ans = first;  
        first = first->next;
        }
    else{
        ans = second;
        second = second->next;
    }
    
    Node *tail = ans;
    
    while(first != NULL && second != NULL)  
    {
        Node *temp = NULL;
        if(first->data <= second->data)
        {
             temp = first;
            first = first->next;
        }
        else
        {
             temp = second;
            second = second->next;
        }
        
        tail->next = temp;
        tail = temp;
    }
    
    while(first != NULL)
    {
        tail->next = first;
        tail= tail->next;
        first = first->next;
    }
        
    while(second != NULL)
    {
        tail->next = second;
        tail = tail->next;
        second = second->next;
    }
      
    return ans;
}
int main()
{
    Node *first = NULL;
    Node *second = NULL;

    int n,m, num;
    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        cin>>num;
        InsertAtEnd(&first, num);
    }

    for (int i = 0; i < m; i++)
    {
        cin>>num;
        InsertAtEnd(&second, num);
    }

    displayList(first);
    displayList(second);

    Node* result = sortTwoLists(first,second);
    displayList(result);
}