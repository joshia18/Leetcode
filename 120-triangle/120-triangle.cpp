class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i == triangle.size()-1) return triangle[triangle.size()-1][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + helper(i+1, j, triangle, dp);
        int diagonal = triangle[i][j] + helper(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        //we start recursion from start 0 for this question as it is fixed point
        int r = triangle.size(), c = triangle[r-1].size();
        
        vector<vector<int>> dp(r, vector<int>(c, -1));
        
        return helper(0, 0, triangle, dp);
    }
};