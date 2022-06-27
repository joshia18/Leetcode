class Solution {
public:
    
//     int helper(int i, int j, vector<vector<int>> &mem){
//         if(i == 0 && j == 0){
//             return 1;
//         }
        
//         if(i < 0 || j < 0) return 0;
        
//         if(mem[i][j] != -1) return mem[i][j];
        
//         int up = helper(i-1, j, mem);
//         int left = helper(i, j-1, mem);
        
//         return mem[i][j] = up + left;
//     }
    
    int uniquePaths(int m, int n) {
        
        // vector<vector<int>> mem(m, vector<int>(n, -1));
        
        //tabulation dp
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //base case
        dp[0][0] = 1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int up = 0, left = 0;
                
                if(i == 0 && j == 0) continue;
                else{
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                }
                
                dp[i][j] = up + left;
            }
        }
        
        return dp[m-1][n-1];
        //return helper(m-1, n-1, mem);
    }
};