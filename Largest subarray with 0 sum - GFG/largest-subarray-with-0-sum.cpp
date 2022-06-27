// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        //using the property of prefix sum as in the problem continuous subarray sum
        
        unordered_map<int , int> mp;
        mp.insert({0,-1});
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            
            if(mp.find(sum) != mp.end()){
                ans = max(ans, i - mp[sum]);
            }
            else{
                mp.insert({sum, i});
            }
            
        }
        
         return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends