class Solution {
public:
    
    int helper(int n, vector<int> &temp, int i, vector<vector<int>> &dp){
        //don't forget the condition for both n and i
        if(n < 0 || i < 0){
            return 1e9;
        }
        
        if(n == 0) return 0;
        
        if(dp[i][n] != -1) return dp[i][n];
        
        int take = INT_MAX;
        
        take = 1 + helper(n-temp[i], temp, i, dp);
        int nottake = 0 + helper(n, temp, i-1, dp);
        
        return dp[i][n] = min(take, nottake);
    }
        
    int numSquares(int n) {
        
//         vector<int> dp(n+1, 0);
        
//         for(int i = 1; i <= n; i++){
//             dp[i] = i;
            
//             for(int j = 1; j*j <= i; j++){
                
//                 dp[i] = min(dp[i], 1 + dp[i - j*j]);
                
//             }
//         }
        
        vector<int> temp;
        
        for(int i = 1; i*i <= n; i++){
            temp.push_back(i*i);
        }
        
        vector<vector<int>> dp(temp.size(), vector<int>(n+1, -1));
        
        return helper(n, temp, temp.size()-1, dp);
        
//       return dp[n];
        
    }
};