/*

Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, ‘A’ of size ‘N’. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".
String ‘P’ is lexicographically smaller than string ‘Q’, if : 

1. There exists some index ‘i’ such that for all ‘j’ < ‘i’ , ‘P[j] = Q[j]’ and ‘P[i] < Q[i]’. E.g. “ninja” < “noder”.

2. If ‘P’ is a prefix of string ‘Q’, e.g. “code” < “coder”.

*/
#include<iostream>
#include<vector>
using namespace std;
struct node{
    node *next[26]={NULL};
    bool isLeaf=false;
};
class trie{
    node *root;
    public:
    trie(){
        root=new node;
    }
    void insert(string &a){
        node *head=root;
        for(int i=0;i<a.size();i++){
            if(!head->next[a[i]-'a'])
                head->next[a[i]-'a']= new node;
            head=head->next[a[i]-'a'];
        }
        head->isLeaf=true;
    }
    bool search(string &s){
        node *head=root;
        for(int i=0;i<s.size();i++){
            if(!head->next[s[i]-'a'] or !head->next[s[i]-'a']->isLeaf) return false;
            head=head->next[s[i]-'a'];
        }
        return head->isLeaf;
    }
};
string completeString(int n, vector<string> &a){
    trie *t=new trie();
    for(auto i:a) t->insert(i);
    string ans="";
    for(auto i:a){
        if(!t->search(i)) continue;
        if(ans.size()==i.size()) ans=min(ans,i);
        else if(i.size()>ans.size()) ans=i;
    }
    if(ans=="") return "None";
    return ans;
}