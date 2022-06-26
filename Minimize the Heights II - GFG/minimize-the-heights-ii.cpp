// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        //to minimise the height difference between two towers(1st is small, 2nd is large), you have to increase the height of 1st by k and decrease the height of 2nd by k
        
        //1st important step is to sort this array to implement this solution
        sort(arr, arr+n);
        
        int ans = arr[n-1] - arr[0];
        
        //initialize small and large variables with the current smallest and largest heights in the sorted array with k added
        //if k = 0, small-large will be the answer
        int small = arr[0]+k;
        int large = arr[n-1]-k;
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        for(int i = 0; i < n-1; i++){
            //to minimise the height difference, increase the height of arr[i] by k and decrease the height of  arr[i+1] by k
            maxi = max(large, arr[i]+k);
            mini = min(small, arr[i+1]-k);
            if(mini < 0) continue;
            ans = min(ans, maxi - mini);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends