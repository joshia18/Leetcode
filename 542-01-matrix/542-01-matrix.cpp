class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //bfs method using extra space
        int r = mat.size(), c = mat[0].size();
        
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<pair<int, int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto temp = q.front();
                q.pop();
                for(auto d : dir){
                    int x = temp.first + d.first;
                    int y = temp.second + d.second;
                    
                    if(x >= 0 && y >= 0 && x < r && y < c && !visited[x][y]){
                        q.push({x,y});
                        mat[x][y] = 1 + mat[temp.first][temp.second];
                        visited[x][y] = true;
                    }
                }
            }
        }
        
        return mat;
    }
};