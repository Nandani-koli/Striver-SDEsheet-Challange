/*
Nobita wants to impress Shizuka by guessing her lucky number.
Shizuka gave Nobita a sorted list of ‘N’ numbers such that every number occurred twice in the list except Shizuka’s lucky number which appears only once.
Nobita asked Doraemon to help him but Doraemon doesn’t have a gadget that can find Shizuka’s lucky number.
So, Doraemon called you to find Shizuka’s lucky number. The fate of Nobita lies in your hand.
Note :

1. Shizuka’s lucky number will surely be present.
2. There will only be a single lucky number.

INPUT->
5 
1 1 3 5 5 

OUTPUT->
3

*/

// BRUTE force Approach
#include<bits/stdc++.h>
using namespace std;

int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int elem = 0;
            for (int i = 0; i < n; i++) {
                elem = elem ^ arr[i];
            }
            
            return elem;
}


//optimized Approach

int uniqueElement(vector<int> arr, int n)
{

int low = 0;
            int high = n - 2;
        
            while (low <= high) {
                int mid = (low + high) / 2;
                
                if (mid % 2 == 0) {
                    if (arr[mid] != arr[mid + 1]) 


                        high = mid - 1; 
                    else
                        low = mid + 1;
                } else {

                    if (arr[mid] == arr[mid + 1]) 
                        high = mid - 1; 
                    else
                        low = mid + 1;
                }
            }

            return arr[low];
}
