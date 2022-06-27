class Solution {
public:
//     int helper(int i, int j, vector<vector<int>>& grid){
//         if(i == 0 && j == 0) return grid[0][0];
//         if(i < 0 || j < 0) return 1e6;
        
//         int up = grid[i][j] + helper(i-1, j, grid);
//         int left = grid[i][j] + helper(i, j-1, grid);
        
//         return min(up, left);
//     }
    
    //this is space optimised and the previous one is non space optimised
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        vector<int> prev(c, 0);
        
        for(int i = 0 ; i < r; i++){
            vector<int> temp(c, 0);
            for(int j = 0; j < c; j++){
                if(i == 0 && j == 0) temp[j] = grid[0][0];
                else{
                    //important thing is initialise up and left with maximum number as we are finding min path sum
                    int up = 1e6, left = 1e6;
                    if(i > 0) up = grid[i][j] + prev[j];
                    if(j > 0) left = grid[i][j] + temp[j-1];
                    
                    temp[j] = min(up, left);
                }
            }
            
            prev = temp;
        }
        
        return prev[c-1];
        
        // return helper(r-1, c-1, grid);
    }
};