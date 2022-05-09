// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        
        //there are some edge cases to consider in this problem like the below if condition AND farthest == r in the while loop
        
        if(arr[0] == 0 && n > 1) return -1;
        
        int l = 0, r = 0, result = 0;
        
        //while loop breaks when r < n-1
        while(r < n-1){
            int farthest = 0;
            
            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + arr[i]);
            }
            
            //IMPORTANT: this is an important point to consider here if an element 0 stopping us to get to the last element of array
            if(farthest == r) return -1;
            
            l = r+1;
            r = farthest;
            
            result++;
        }
        
        return result;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends