/*
You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
INPUT_>
4 3 10

Output->
4
*/
#include <bits/stdc++.h> 
using namespace std;
int modularExponentiation(int x, int n, int mm) 
{
     long ans = 1;
    long xx = x;
       while(n>0){
           if(n%2==0)
           {
               xx = (xx%mm*xx%mm)%mm;
               n=n>>1;
           } 
           else
           {
               ans = (ans*xx%mm)%mm;
               n=n-1;
           }
       }
       return (int)(ans%mm);
}
int main()
{
    int x,n,m;
    cin>>x>>n>>m;
    cout<<modularExponentiation(x,n,m)<<endl;
}