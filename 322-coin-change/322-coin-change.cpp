class Solution {
public:
//     int helper(int i, int amount, vector<int>& coins, vector<vector<int>> &dp){
//         //this internal if consition is very important
//         if(i == 0){
//             if(amount%coins[0] == 0) return amount/coins[0];
//             return 1e6;
//         }
        
//         if(dp[i][amount] != -1) return dp[i][amount];
        
//         int take = INT_MAX;
//         if(amount >= coins[i]) take = 1 + helper(i, amount - coins[i], coins, dp);
//         int nottake = 0 + helper(i-1, amount, coins, dp);
        
//         return dp[i][amount] = min(take, nottake);
//     }
    
    int coinChange(vector<int>& coins, int amount) {
        //take care of this edge case, what if amount = 0
        //having a 2d array causing TLE here, so space ptimize it
        //if(amount == 0) return 0;
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        //base case
        for(int i = 0; i <= amount; i++){
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e6;
        }
        
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int take = INT_MAX;
                if(j >= coins[i]) take = 1 + dp[i][j - coins[i]];
                int nottake = 0 + dp[i-1][j];

                dp[i][j] = min(take, nottake);
            }
        }
        
        //int ans = helper(n-1, amount, coins, dp);
        
        return dp[n-1][amount] >= 1e6 ? -1 : dp[n-1][amount];
    }
};
