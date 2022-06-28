class Solution {
public:
//     int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
//         if(j < 0 || j >= matrix[0].size()) return 1e6;
//         if(i == 0) return matrix[i][j];
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         //s = straight up, ld -> left diagonal up, rd -> right diagonal up
//         int s = matrix[i][j] + helper(i-1, j, matrix, dp);
//         int ld = matrix[i][j] + helper(i-1, j-1, matrix, dp);
//         int rd = matrix[i][j] + helper(i-1, j+1, matrix, dp);
        
//         return dp[i][j] = min(s, min(ld, rd));
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        
        int ans = INT_MAX;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        //tabulation (for every possible i, value of j is 0 to c-1 as per the working)
        //base case
        for(int i = 0; i < c; i++) dp[0][i] = matrix[0][i];
        
        for(int i = 1; i < r; i++){
            for(int j = 0; j < c; j++){
                int s = 1e6, ld = 1e6, rd = 1e6;
                s = matrix[i][j] + dp[i-1][j];
                if(j-1 >= 0) ld = matrix[i][j] + dp[i-1][j-1];
                if(j+1 < c) rd = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(s, min(ld, rd));
            }
        }
        
        for(int i = 0; i < c; i++) ans = min(ans, dp[r-1][i]);
        
        // for(int i = 0; i < c; i++){
        //     ans = min(ans, helper(r-1, i, matrix, dp));
        // }
        
        return ans;
    }
};