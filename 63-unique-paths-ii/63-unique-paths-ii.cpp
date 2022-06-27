class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //just add one additional condition to unique paths 1, then it is alright
        //for recur+mem soln -> add the base condition if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0
        //for tabulation add the condition if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
        
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();
        
        //special edge case
        if(obstacleGrid[0][0] == 1) return 0;
        
        //for this problem base condition is dp[i][j] = 1 when i == 0 && j == 0
        
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                //extra condition for this problem
                else if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    
                    dp[i][j] = up+left;
                }
            }
        }
        
        return dp[r-1][c-1];
    }
};