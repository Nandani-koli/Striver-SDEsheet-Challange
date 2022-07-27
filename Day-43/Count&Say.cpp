/*
write as you speak is a special sequence of string that starts with string "1" and after one iteration you write the sequence as whatever you speak.

input-> nth number 
number of testcases:- 5
1
2
3
4
5

OUTPUT->
1
11
21
1211
111221

*/
#include<string>
using namespace std;

string writeAsYouSpeak(int n) 
{
	// Write your code here.
    if(n == 1) return "1";
    if(n == 2) return "11";
    string str = "11";
    for(int i = 3; i<= n; i++)
    {
        string newstr = "";
        str += '$';
        int count = 1;
        
        for(int j = 1; j<str.length(); j++)
        {
            if(str[j] != str[j-1])
            {
                newstr += to_string(count);
                newstr += str[j-1];
                count = 1;
            }
            else count++;
        }
        str = newstr;
    }
    
    return str;
}