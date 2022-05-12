class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        
        if(r == 0) return 0;
        
        int ans = 0;
        
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i == 0){
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                }
                else if(j == 0){
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                }
                else if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                }
                else{
                    dp[i][j] = 0;
                }
                
                ans = max(ans, dp[i][j]);
                
            }                
        }
        
        return ans*ans;
        
    }
};