class Solution {
public:
    //using memoization
    int MOD = 1000000007;
    
    
    int numRollsToTarget(int n, int k, int target) {
        
        //using dp
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        for(int i = 1; i <= min(target, k); i++){
            dp[0][i] = 1;
        }
        
        for(int dice = 1; dice < n; dice++){
            for(int total = dice; total <= min(target, (dice+1) * k); total++){
                for(int faces = 1; faces <= k; faces++){
                    
                    if(total - dice < faces) continue;
                    
                    dp[dice][total] += dp[dice-1][total - faces];
                    dp[dice][total] %= MOD;
                }
            }
        }
        
        return dp[n-1][target];
        
    }
};