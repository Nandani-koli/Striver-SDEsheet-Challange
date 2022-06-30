#include<iostream>
using namespace std;
class Queue {
    int *arr;
    int qfront;
    int back;
public:
    Queue() {
        // Implement the Constructor
        arr = new int[10000];
        qfront = -1;
        back = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == -1 && back == -1 || qfront > back)
            {
                return true;
            }
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(isEmpty())
        {
            qfront = 0;
            back = 0;
            arr[back] = data;
        }
        else{
            back++;
            arr[back] = data;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())
        {
            return -1;
        }
        else if(qfront == back)
        {
            int del = arr[qfront];
            qfront = -1;
            back = -1;
            
            return del;
        }
        else{
            int del = arr[qfront];
            qfront++;
            return del;
        }
    }

    int front() {
        // Implement the front() function
         if(isEmpty())
            {
                return -1;
            }
            return arr[qfront];
    }
};