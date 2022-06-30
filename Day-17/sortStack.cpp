/*
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.

INPUT->
5
5 -2 9 -7 3

OUTPUT->
9 5 3 -2 -7

*/
#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &s,int temp)
{
    if(s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.size()  == 1)
    {
        return;
    }
    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    
    insert(stack,temp);
    return;
}
