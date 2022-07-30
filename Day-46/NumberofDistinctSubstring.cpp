/*
Ninja has been given a string ‘WORD’ containing lowercase English alphabets having length ‘N’. Ninja wants to calculate the number of distinct substrings in the ‘WORD’.

For ‘WORD’ = “abcd” and ‘N’ = 4 following are the 10 distinct substrings of ‘WORD’.
“abcd”, “abc”, “ab”, “a”, “bcd”, “bc”, “b”, “cd”, “c”, and “d”

Can you help the Ninja to find out the number of distinct substrings in the ‘WORD’?
If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.

*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node * links[26];

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }

  Node * get(char ch) {
    return links[ch - 'a'];
  }

  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
};

int distinctSubstring(string &word) {
    //  Write your code here.
    Node * root = new Node();
  int count = 0;
  int n = word.size();
  for (int i = 0; i < n; i++) {
    Node * node = root;

    for (int j = i; j < n; j++) {
      if (!node -> containsKey(word[j])) {
        node -> put(word[j], new Node());
        count++;
      }
      node = node -> get(word[j]);
    }

  }
  return count;
}
