class Solution {
public:
    int mod = 1e9+7;
    int helper(int m, int n, int maxmove, int i, int j, vector<vector<vector<int>>> &dp){
        
        if(i >= m || j >= n || i < 0 || j < 0){
            return 1;
        }
        
        if(maxmove == 0) return 0;
            
        if(dp[i][j][maxmove] != -1) return dp[i][j][maxmove];
        
        int ans = 0;
        
        ans = (ans + helper(m, n, maxmove-1, i+1, j, dp))%mod;
        ans = (ans + helper(m, n, maxmove-1, i-1, j, dp))%mod;
        ans = (ans + helper(m, n, maxmove-1, i, j+1, dp))%mod;
        ans = (ans + helper(m, n, maxmove-1, i, j-1, dp))%mod;
        
        return dp[i][j][maxmove] = ans%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        
        return helper(m,n, maxMove, startRow, startColumn, dp);
    }
};