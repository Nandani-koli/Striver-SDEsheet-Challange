/*
You are given an unsorted array/list 'ARR' of 'N' integers. Your task is to return the length of the longest consecutive sequence.
The consecutive sequence is in the form ['NUM', 'NUM' + 1, 'NUM' + 2, ..., 'NUM' + L] where 'NUM' is the starting integer of the sequence and 'L' + 1 is the length of the sequence.
Note:

If there are any duplicates in the given array we will count only one of them in the consecutive sequence.

For the given 'ARR' [9,5,4,9,10,10,6].

Output = 3
The longest consecutive sequence is [4,5,6].

*/

#include <bits/stdc++.h> 
using namespace std;

//method 1
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int longeststreak =0;
    set<int> hashset;
    for(int i =0; i<n; i++)
    {
        hashset.insert(arr[i]);
    }
    
    for(auto num : hashset)
    {
        if(!hashset.count(num - 1))
        {
            int curnum = num;
            int currentstreak = 1;
            
            while(hashset.count(curnum + 1))
            {
                curnum += 1;
                currentstreak += 1;
            }
            
            longeststreak = max(longeststreak,currentstreak);
        }
    }
    
    return longeststreak;
}

//method 2
#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int longeststreak =0;
    set<int> hashset;
    for(int i =0; i<n; i++)
    {
        hashset.insert(arr[i]);
    }
    
    for(auto num : hashset)
    {
        if(!hashset.count(num - 1))
        {
            int curnum = num;
            int currentstreak = 1;
            
            while(hashset.count(curnum + 1))
            {
                curnum += 1;
                currentstreak += 1;
            }
            
            longeststreak = max(longeststreak,currentstreak);
        }
    }
    
    return longeststreak;
}

int main()
{
    vector <int> arr ;
    arr = {9,5,4,9,10,10,6};

   cout<< lengthOfLongestConsecutiveSequence(arr,7)<<endl;
}