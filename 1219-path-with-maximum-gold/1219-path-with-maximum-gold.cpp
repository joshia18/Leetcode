class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &visited){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]){
            return 0;
        }
        
        visited[i][j] = 1;
        
        int up = -1e6, down = -1e6, right = -1e6, left = -1e6;
        
        up = grid[i][j] + helper(i-1, j, grid, visited);
        down = grid[i][j] + helper(i+1, j, grid, visited);
        right = grid[i][j] + helper(i, j+1, grid, visited);
        left = grid[i][j] + helper(i, j-1, grid, visited);
        
        //this visited[i][j] = 0 is mandatory here as it is returned from this particular place, it needs to be marked as not visited
        visited[i][j] = 0;
        
        return max({up, down, right, left});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        
        int r = grid.size(), c = grid[0].size();
        
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] != 0){
                    vector<vector<int>> visited(r, vector<int>(c, 0));
                    int temp = helper(i, j, grid, visited);
                    ans = max(ans, temp);
                }
            }
        }
        
        return ans < 0 ? 0 : ans;
    }
};