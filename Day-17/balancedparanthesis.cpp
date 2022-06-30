/*
You're given string ‘STR’ consisting solely of “{“, “}”, “(“, “)”, “[“ and “]” . Determine whether the parentheses are balanced.
*/
#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> st;
    
    for(int i = 0; i<expression.length(); i++)
    {
         if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            st.push(expression[i]);
        }
        else 
        {
            if(st.empty())
            {
                return false;
            }
            else if((st.top() == '{' && expression[i] == '}') || (st.top() == '[' && expression[i] == ']') || (st.top() == '(' && expression[i] == ')'))
            {
            st.pop();
            }
            else{
            return false;
            }
        }
    }
    
    if(st.empty())
        return true;
    else
        return false;
}

int main()
{
    string s;
    getline(cin,s);
    cout<<isValidParenthesis(s)<<endl;
}