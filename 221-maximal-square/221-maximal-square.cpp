class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        
        if(r == 0) return 0;
        
        //improved space complexity
        vector<vector<int>> dp(2, vector<int>(c));
        
        int ans = 0;
        
        for(int i = 0; i < r; i++){
            
            if(i > 1){
                for(int k = 0; k < c; k++){
                    dp[0][k] = dp[1][k];
                    //dp[1][k] = 0;
                }
            }
            
            for(int j = 0; j < c; j++){
                           
                if(i == 0){
                    dp[0][j] = matrix[i][j] == '1' ? 1 : 0;
                    ans = max(ans, dp[0][j]);
                }
                else if(j == 0){
                    dp[1][j] = matrix[i][j] == '1' ? 1 : 0;
                }
                else if(matrix[i][j] == '1'){
                    dp[1][j] = 1 + min({dp[0][j], dp[1][j-1], dp[0][j-1]});
                }
                else{
                    dp[1][j] = 0;
                }
                
                ans = max(ans, dp[1][j]);
                
            }
            
        }
        
        return ans*ans;
        
    }
};