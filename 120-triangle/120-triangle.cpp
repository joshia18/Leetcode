class Solution {
public:
    
//     int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
//         if(i == triangle.size()-1) return triangle[triangle.size()-1][j];
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int down = triangle[i][j] + helper(i+1, j, triangle, dp);
//         int diagonal = triangle[i][j] + helper(i+1, j+1, triangle, dp);
        
//         return dp[i][j] = min(down, diagonal);
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        //we start recursion from start 0 for this question as it is fixed point, basically r and c has same valued
        int r = triangle.size(), c = triangle[r-1].size();
        
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        for(int i = r-1; i >= 0; i--){
            //each row is of differernt sizes triangle[i].size()-1 => no of columns, instad of triangle[i].size()-1 we can use i also
            for(int j = i; j >= 0; j--){
                if(i == r-1) dp[r-1][j] = triangle[r-1][j];
                else{
                    
                    int down = 1e6, diagonal = 1e6;
                    if(i+1 <= r-1) down = triangle[i][j] + dp[i+1][j];
                    if(j+1 <= c-1) diagonal = triangle[i][j] + dp[i+1][j+1];
                    
                    dp[i][j] = min(down, diagonal);
                }
            }
        }
        
        return dp[0][0];
        
        //return helper(0, 0, triangle, dp);
    }
};