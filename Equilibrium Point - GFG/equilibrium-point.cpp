// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    // 

        //without using extra space a simple method
        long long rightsum = 0;

        for(int i = 0; i < n; i++){
            rightsum += a[i];
        }

        int pos = -1;
        long long leftsum = 0;

        for(int i = 0; i < n; i++){
            pos = i;
            rightsum -= a[i];
            if(rightsum == leftsum){
                return pos+1;
                break;
            }
            leftsum += a[i];
        }

        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends