/*
Implement a Stack Data Structure specifically to store integer data using two Queues.
There should be two data members, both being Queues to store the data internally. You may use the inbuilt Queue.
*/

#include<bits/stdc++.h>
using namespace std;
class Stack {
	// Define the data members.
    int s;
    queue <int> q1;
    queue <int> q2;
   public:
    Stack() {
        // Implement the Constructor.
        s = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return s;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q1.empty() && q2.empty())
        {
            return true;
        }
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        s++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue <int> temp = q1;
        q1 = q2;
        q2 = temp;
        
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty())
        {
            return -1;
        }
        int del = q1.front();
        q1.pop();
        s--;
        return del;
    }

    int top() {
        // Implement the top() function.
        if(isEmpty())
        {
            return -1;
        }
        return q1.front();
    }
};