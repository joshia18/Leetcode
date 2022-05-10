// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //traverse the 1st array from left to right and the second array from right to left
        //see both arrays may have different sizes i guss
        
        int l = 0, r = m-1;
        
        int diff = INT_MAX;
        vector<int> ans(2);
        
        while(l < n && r >= 0){
            
            int sum = arr[l] + brr[r];
            
            //DONT Forget to use abs(sum - x) in both places
            if(abs(sum - x) < diff){
                diff = abs(sum - x) ;
                ans = {arr[l], brr[r]};
                //cout << ans[0] << " " << ans[1] << endl;
            }
            
            if(sum < x) l++;
            else r--;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends