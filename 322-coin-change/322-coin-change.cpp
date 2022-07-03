class Solution {
public:
    int helper(int i, int amount, vector<int>& coins, vector<vector<int>> &dp){
        //this internal if consition is very important
        if(i == 0){
            if(amount%coins[0] == 0) return amount/coins[0];
            return 1e6;
        }
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int take = INT_MAX;
        if(amount >= coins[i]) take = 1 + helper(i, amount - coins[i], coins, dp);
        int nottake = 0 + helper(i-1, amount, coins, dp);
        
        return dp[i][amount] = min(take, nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        //take care of this edge case, what if amount = 0
        if(amount == 0) return 0;
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        int ans = helper(n-1, amount, coins, dp);
        
        return ans >= 1e6 ? -1 : ans;
    }
};