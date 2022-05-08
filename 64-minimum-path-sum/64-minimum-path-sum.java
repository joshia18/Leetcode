class Solution {
    public int minPathSum(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        //System.out.println("r= " + r + " , c= " + c );
        int[][] dp = new int[r][c];
        int t = 0;
        dp[0][0] = grid[0][0];
        for(int i = 1; i < c; i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
            //System.out.print(dp[0][i] + " ");
        }
        
        //System.out.println();
        
        for(int i = 1; i < r; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
            //System.out.print(dp[i][0] + " ");
        }
        
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                dp[i][j] = grid[i][j] + Math.min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        
        return dp[r-1][c-1];
        
    }
}