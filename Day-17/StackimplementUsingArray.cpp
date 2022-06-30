#include<iostream>
using namespace std;
// Stack class.
class Stack {
    int stop;
    int *arr;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        size = capacity;
        arr = new int[capacity];
        stop = -1;
    }

    void push(int num) {
        // Write your code here.
        if(stop < size-1)
        {
        stop++;
        arr[stop] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(isEmpty())
        {
            return -1;
        }
        int del = arr[stop];
        stop--;
        return del;
    }
    
    int top() {
        // Write your code here.
        if(isEmpty())
        {
            return -1;
        }
        return arr[stop];
    }
    
    int isEmpty() {
        // Write your code here.
        if(stop == -1)
        {
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(stop >= size)
        {
            return 1;
        }
        return 0;
    }
    
};