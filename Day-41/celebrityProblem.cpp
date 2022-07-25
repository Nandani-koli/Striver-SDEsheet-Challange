/*
There are ‘N’ people at a party. Each person has been assigned a unique id between 0 to 'N' - 1(both inclusive). A celebrity is a person who is known to everyone but does not know anyone at the party.
Given a helper function ‘knows(A, B)’, It will returns "true" if the person having id ‘A’ know the person having id ‘B’ in the party, "false" otherwise. Your task is to find out the celebrity at the party. Print the id of the celebrity, if there is no celebrity at the party then print -1.
Note:

1. The helper function ‘knows’ is already implemented for you.
2. ‘knows(A, B)’ returns "false", if A doesn't know B.
3. You should not implement helper function ‘knows’, or speculate about its implementation.
4. You should minimize the number of calls to function ‘knows(A, B)’.
5. There are at least 2 people at the party.
6. At most one celebrity will exist.

*/

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
bool knows(int a,int b)
{
    
}
// Approach 1:-
int findCelebrity(int n) {
 	// Write your code here.
     int c=0;
    for(int i=1;i<n;i++){
        if(knows(c,i)==1){
            c=i;
           }
     }
    for(int i=0;i<n;i++){
        if(i!=c and (knows(c,i)==1 or knows(i,c)==0))return -1;
       }
   return c;
}


//Approach 2:-

#include<stack>
using namespace std;
int findCelebrity(int n) {
 	// Write your code here.
    stack<int> s;
    for(int i=0;i<n;i++)
        s.push(i);
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(knows(a,b))
            s.push(b);
        else
            s.push(a);
    }
    int ans=s.top();    //possible condidate
    //checking for 0, if we found 1 in the row then it is not celebrity
    for(int i=0;i<n;i++){
        if(knows(ans,i))
            return -1;
    }
    //checking for number of 1
    int count=0;
    for(int i=0;i<n;i++){
        if(knows(i,ans))
            count++;
    }
    //if count(number of 1 in column) = number of candidates - 1
    //then that candidate is out celebrity.
    //else, there is no celebrity among these people
    if(count==n-1)
        return ans;
    return -1;
}
