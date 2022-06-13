class Solution {
public:
//     int helper(int i, vector<int>& arr, int k, vector<int> &dp){
//         if(i == arr.size()) return 0;
        
//         if(dp[i] != -1) return dp[i];
        
//         //j < i+k is the maximum partition that we can do
//         int len = 0, maxelement = INT_MIN, maxsum = INT_MIN;
        
//         for(int j = i; j < min(i+k, (int)arr.size()); j++){
//             len++;
//             maxelement = max(maxelement, arr[j]);
//             int sum = maxelement * len + helper(j+1, arr, k, dp);
//             maxsum = max(maxsum, sum);
//         }
        
//         return dp[i] = maxsum;
//     }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> dp(n+1, 0);
        
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--){
            
            int len = 0, maxelement = INT_MIN, maxsum = INT_MIN;
        
            for(int j = i; j < min(i+k, (int)arr.size()); j++){
                len++;
                maxelement = max(maxelement, arr[j]);
                int sum = maxelement * len + dp[j+1];
                maxsum = max(maxsum, sum);
            }
            
            dp[i] = maxsum;
        }
        
        return dp[0];
        //return helper(0, arr, k, dp);
    }
};