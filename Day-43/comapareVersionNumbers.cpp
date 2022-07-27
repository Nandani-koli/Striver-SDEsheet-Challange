/*
Problem link :- https://www.codingninjas.com/codestudio/problems/1062582?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

*/

#include<string>
using namespace std;
int compareVersions(string s1, string s2) 
{
    // Write your code here
            int i = 0,j = 0;
            long long intofs1 = 0,intofs2 = 0;
        int n = s1.length(),m = s2.length();
 
        while(i<n or j<m){
            while(i<n and s1[i]!='.'){
                intofs1 = intofs1*10 + (s1[i]-'0');
                i++;
            }
 
            while(j<m and s2[j]!='.'){
                intofs2 = intofs2*10 + (s2[j]-'0');
                j++;
            }
 
            if(intofs1<intofs2){
                return -1;
            }
 
            if(intofs1>intofs2){
                return 1;
            }
 
            intofs1 = intofs2 = 0;
            i++;
            j++;
        }
 
        return 0;
}