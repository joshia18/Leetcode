class Solution {
public:
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    int dfs(int i, int j, vector<vector<int>>& grid, int id){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1){
            return 0;
        }
        
        grid[i][j] = id;
        
        return 1 + dfs(i+1, j, grid, id) + dfs(i-1, j, grid, id) + dfs(i, j+1, grid, id) + dfs(i, j-1, grid, id);
    }
    
    int calculateMaxIsland(int i, int j, unordered_map<int, int> &mp, vector<vector<int>>& grid){
        int sum = 0;
        
        unordered_set<int> st;
        
        for(auto &d : dir){
            int p = d.first + i;
            int q = d.second + j;
            
            if(!(p >= grid.size() || q >= grid[0].size() || p < 0 || q < 0)){
                st.insert(grid[p][q]);
            }
            
        }
        
        for(auto &id : st) sum += mp[id];
        
        return sum+1;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int id = -1;
        
        int r = grid.size(), c = grid[0].size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    int size = dfs(i, j, grid, id);
                    mp.insert({id, size});
                    id--;
                }
            }
        }
        
        int maxIsland = 0;
        
        for(auto &i : mp) maxIsland = max(maxIsland, i.second);
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 0){
                    int temp = calculateMaxIsland(i, j, mp, grid);
                    maxIsland = max(maxIsland, temp);
                }
            }
        }
        
        return maxIsland;
    }
};