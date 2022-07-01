/*
Implement a queue data structure which follows FIFO(First In First Out) property, using only the instances of the stack data structure.

*/

#include<bits/stdc++.h>
using namespace std;
class Queue {
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if (s1.empty() && s2.empty())
        {
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topop = s2.top();
        s2.pop();
        return topop;
    }

    int peek() {
        // Implement the peek() function here.
        if (s1.empty() && s2.empty())
        {
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
         if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
};
