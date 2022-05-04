class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if(n == 0) return 0;
        int ans = INT_MIN;
        
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        
        for(int i = 0; i <= k; i++){
            
            int maxDiff = INT_MIN;
            
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    maxDiff = max(maxDiff, dp[i-1][j-1] - prices[j-1]);
                    dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};