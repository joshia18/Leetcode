class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        
        int temp = grid[i][j];
        
        grid[i][j] = 0;
        
        int up = -1e6, down = -1e6, right = -1e6, left = -1e6;
        
        //don't forget to use temp instead of grid[i][j] while doing memory optimization of visited array
        up = temp + helper(i-1, j, grid);
        down = temp + helper(i+1, j, grid);
        right = temp + helper(i, j+1, grid);
        left = temp + helper(i, j-1, grid);
        
        //this visited[i][j] = 0 is mandatory here as it is returned from this particular place, it needs to be marked as not visited
        grid[i][j] = temp;
        
        return max({up, down, right, left});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        
        int r = grid.size(), c = grid[0].size();
        
        //there is an answer without using the visited array also, just make the grid value to zero whenever visiting and hchange it back to original value once the recurisin is completed
        //vector<vector<int>> visited(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] != 0){
                    int temp = helper(i, j, grid);
                    ans = max(ans, temp);
                }
            }
        }
        
        return ans < 0 ? 0 : ans;
    }
};