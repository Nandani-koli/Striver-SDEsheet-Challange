/*
You have been given two integers ‘N’ and ‘K’. Your task is to find the K-th permutation sequence of numbers from 1 to ‘N’. The K-th permutation is the K-th permutation in the set of all sorted permutations of string 1 to ‘N’.
For example :

If ‘N’ = 3 and ‘K’ = 4. Then all permutations for ‘N’ = 3 are “123”, “132”, “213”, “231”, “312”, “321”. So the 4-th permutation is “231”.
*/
#include<iostream>
#include<vector>
using namespace std;

string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
}
