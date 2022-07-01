/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

1. Push(num): Push the given number in the stack.
2. Pop: Remove and return the top element from the stack if present, else return -1.
3. Top: return the top element of the stack if present, else return -1.
4. getMin: Returns minimum element of the stack if present, else return -1.
*/

#include<bits/stdc++.h>
using namespace std;
// Implement class for minStack.
class minStack
{
	// Write your code here.
    stack<int>st;
    int minele;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
           while(st.empty() == false) st.pop();
            minele = 1e9;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            if(st.empty())
            {
                st.push(num);
                minele = num;
            }
            else 
            {
             if(num >= minele)
            {
                st.push(num);
            }
            else{
               st.push(2 * num - minele);
                minele = num;
            }
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(st.empty())
            {
                return -1;
            }
            else if(st.top() < minele)
            {
                int del = minele;
                minele = 2*minele - st.top();
                st.pop();
                return del;
            }
            else{
                int del = st.top();
                st.pop();
                return del;
            }
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(st.empty())
            {
                return -1;
            }
            else{
            if(st.top() < minele)
            {
                return minele;
            }
            else{
            return st.top();
            }
            }
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
           if(st.empty())
           {
               return -1;
           }
           
           return minele;
		}
};