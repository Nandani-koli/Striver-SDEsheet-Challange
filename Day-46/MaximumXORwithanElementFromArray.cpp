/*
You are given an array/list ‘ARR’ consisting of ‘N’ non-negative integers.  You are also given a list ‘QUERIES’ consisting of ‘M’ queries, where the ‘i-th’ query is a list/array of two non-negative integers ‘Xi’, ‘Ai’, i.e ‘QUERIES[i]’ = [‘Xi’, ‘Ai’].
The answer to the ith query, i.e ‘QUERIES[i]’ is the maximum bitwise xor value of ‘Xi’ with any integer less than or equal to ‘Ai’  in ‘ARR’.   
You should return an array/list consisting of ‘N’ integers where the ‘i-th’ integer is the answer of ‘QUERIES[i]’.

1. If all integers are greater than ‘Ai’ in array/list ‘ARR’  then the answer to this ith query will be -1.

*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[2];
    
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }
    
    Node *get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node *node){
        links[bit] = node;
    }
};
class Trie{
    private:
        Node *root;
     public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node *node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }
        int getMax(int num){
            Node * node = root;
            int maxVal = 0;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(node->containsKey(!bit)){
                    maxVal = maxVal | (1 << i);
                    node = node->get(!bit);
                }
                else
                    node = node->get(bit);
            }
            return maxVal;
        }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    Trie trie;
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    sort(arr.begin(), arr.end());
    int idx = 0;
    for(auto it: queries){
        offlineQueries.push_back({it[1], {it[0], idx++}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    int i = 0;
    for(auto &it: offlineQueries){
        int ai = it.first;
        int xi = it.second.first;
        int index = it.second.second;
        while(i < arr.size() && arr[i] <= ai){
            trie.insert(arr[i]);
            i++;
        }
        if(i != 0)
            ans[index] = trie.getMax(xi);
        else
            ans[index] = -1;
    }
    return ans;
}