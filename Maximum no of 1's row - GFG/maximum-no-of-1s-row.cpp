// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int bsearch(vector<int> &arr, int n){
            int l = 0, h = n-1;
            
            int ans = INT_MIN;
            
            while(l <= h){
                int mid = l + (h-l)/2;
                
                if(arr[mid] == 1){
                    ans = mid;
                    h = mid-1;
                }
                else if(arr[mid] < 1){
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
            
            return ans == INT_MIN ? 0 : n-ans;
        }
        
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {   
            int maxones = 0, ans = 0;
            
            for(int i = 0; i < N; i++){
                int ones = bsearch(Mat[i], M);
                if(ones > maxones){
                    maxones = ones;
                    ans = i;
                }
            }
            
            return ans;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends