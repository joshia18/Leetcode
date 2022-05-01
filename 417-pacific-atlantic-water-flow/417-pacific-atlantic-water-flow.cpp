class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
    
    void addrow(int row, queue<pair<int, int>> &q, int columns){
        for(int i = 0; i < columns; i++){
            q.push({row, i});
        }
    }
    
    void addcol(int col, queue<pair<int, int>> &q, int rows){
        for(int i = 0; i < rows; i++){
            q.push({i, col});
        }
    }
    
    vector<vector<bool>> bfs(vector<vector<int>>& heights, queue<pair<int, int>> &q1){
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
        
        while(!q1.empty()){
            int size = q1.size();
            
            for(int i = 0; i < size; i++){
                auto current = q1.front();
                q1.pop();
                
                int p = current.first, q = current.second;
                if(visited[p][q] == true) continue;
                visited[p][q] = true;
                
                for(auto k : directions){
                    int x = p + k[0];
                    int y = q + k[1];
                    
                    if(x >= 0 && y >= 0 && x < heights.size() && y < heights[0].size() && heights[x][y] >= heights[p][q] && visited[x][y] == false){
                        q1.push({x,y});
                    }
                }
            }
        }
        
        return visited;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        queue<pair<int, int>> q1;
        
        int r = heights.size(), c = heights[0].size();
        
        addrow(0, q1, c);
        addcol(0, q1, r);
        
        vector<vector<bool>> pacific = bfs(heights, q1);
        
        queue<pair<int, int>> q2;
        
        addrow(r-1, q2, c);
        addcol(c-1, q2, r);
        
        vector<vector<bool>> atlantic = bfs(heights, q2);
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                //this condition is important here *IMPORTANT*
                if(pacific[i][j] == true && atlantic[i][j] == true){
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
        
    }
};