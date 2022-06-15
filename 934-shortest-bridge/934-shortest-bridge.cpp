class Solution {
public:
    void floodfill(vector<vector<int>>& grid, int i, int j, set<pair<int, int>> &hashset){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] != 1){
            return;
        }
        
        hashset.insert({i, j});
        grid[i][j] = 0;
        
        floodfill(grid, i+1, j, hashset);
        floodfill(grid, i-1, j, hashset);
        floodfill(grid, i, j+1, hashset);
        floodfill(grid, i, j-1, hashset);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        //two sets to store the coordinates of two islands
        set<pair<int, int>> a, b;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    if(a.size() == 0){
                        floodfill(grid, i, j, a);
                    }
                    else if(b.size() == 0){
                        floodfill(grid, i, j, b);
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        
        for(auto &i : a){
            for(auto &j : b){
                //the formula is important here
                int formula = (abs(i.first - j.first) + abs(i.second - j.second)) - 1;
                ans = min(ans, formula);
            }
        }
        
        return ans;
    }
};