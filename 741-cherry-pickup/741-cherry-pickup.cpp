class Solution {
public:
    vector<vector<vector<int>>> dp;
    int helper(int i1, int j1, int i2, int j2, int n, vector<vector<int>>& grid){
        
        if(i1 == n-1 && j1 == n-1 && i2 == n-1 && j2 == n-1) return grid[n-1][n-1];
        if(i1 >= n || j1 >= n || i2 >= n || j2 >= n) return -1e6;
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e6;
        
        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];
        
        int count = 0;
        
        if(i1 == i2 && j1 == j2) count += grid[i1][j1];
        else count += grid[i1][j1] + grid[i2][j2];
        
        int move1 = helper(i1+1, j1, i2+1, j2, n, grid);
        int move2 = helper(i1, j1+1, i2, j2+1, n, grid);
        int move3 = helper(i1+1, j1, i2, j2+1, n, grid);
        int move4 = helper(i1, j1+1, i2+1, j2, n, grid);
        
        int ans = count + max(max(move1, move2), max(move3, move4));
        
        return dp[i1][j1][i2] = ans;       
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // return toptobottom(0, 0, n, grid);
        //start two players from the same point
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        int ans = helper(0, 0, 0, 0, n, grid);
        return ans < 0 ? 0 : ans;
    }
    
};