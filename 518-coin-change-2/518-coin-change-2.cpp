class Solution {
public:
//     int helper(int i, int amount, vector<int>& coins, vector<vector<int>> &dp){
//         if(amount == 0) return 1;
        
//         if(i == 0){
//             if(amount % coins[i] == 0) return 1;
//             else return 0;
//         }
        
//         if(dp[i][amount] != -1) return dp[i][amount];
        
//         int take = 0;
//         if(amount >= coins[i]) take = helper(i, amount-coins[i], coins, dp);
//         int nottake = helper(i-1, amount, coins, dp);
        
//         return dp[i][amount] = take+nottake;
        
//     }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        //vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        //single array optimization
        vector<int> prev(amount+1, 0);
        
        //here it is i%coins[0] not amount%coins[0] -> IMPORTANT
        for(int i = 0; i <= amount; i++) prev[i] = i%coins[0] == 0 ? 1 : 0;
        
        //for all amount = 0, set all the rows to 1
        //for(int i = 0; i < n; i++) prev[0] = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int take = 0;
                if(j >= coins[i]) take = prev[j-coins[i]];
                int nottake = prev[j];

                prev[j] = take+nottake;
            }
        }
        
        return prev[amount];
        
        //return helper(n-1, amount, coins, dp);
    }
};