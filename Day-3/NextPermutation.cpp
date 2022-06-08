#include <bits/stdc++.h> 
using namespace std;
vector
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    vector<int> ans = permutation;
    int bp1,bp2;
    for(bp1 = n-2; bp1 >= 0; bp1-- )
    {
        if(ans[bp1] < ans[bp1+1])
        {
            break;
        }
    }
    
    if(bp1 < 0)
    {
        reverse(ans.begin(),ans.end());
    }
    else{
        for(bp2 = n-1; bp2 > bp1; bp2--)
        {
            if(ans[bp2] > ans[bp1])
            {
                break;
            }
        }
        swap(ans[bp1],ans[bp2]);
        reverse(ans.begin()+ bp1+1, ans.end());
    }
  return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> permutation(n);
    for(int i =0; i<n; i++)
    {
        cin>>permutation[i];
    }

    vector<int> next = nextPermutation(permutation,n);
    for(int i =0; i<next.size(); i++)
    {
        cout<<next[i]<<" ";
    }
    cout<<endl;
}