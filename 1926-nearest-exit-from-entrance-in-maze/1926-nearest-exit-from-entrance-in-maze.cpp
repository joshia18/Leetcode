class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> qu;
        qu.push({entrance[0], entrance[1]});
        
        int steps = 0;
        
        vector<vector<int>> directions = {{0,1}, {1,0}, {-1, 0}, {0, -1}};
        
        while(!qu.empty()){
            int size = qu.size();
            steps++;
            for(int i = 0; i < size; i++){
                auto [p, q] = qu.front();
                qu.pop();
                
                //to not visit the same cell again
                if(maze[p][q] == '*') continue;
                
                maze[p][q] = '*';
                
                for(auto j : directions){
                    int x = p + j[0];
                    int y = q + j[1];
                    
                    if(x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == '.'){
                        if(x == 0 || y == 0 || x == maze.size()-1 || y == maze[0].size()-1) return steps;
                        
                        qu.push({x,y});
                    }
                }
            }
        }
        
        return -1;
    }
};