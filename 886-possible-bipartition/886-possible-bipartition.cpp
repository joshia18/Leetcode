class Solution {
public:
    bool bfs(int node, vector<int> &color, vector<vector<int>> &graph){
        
        queue<int> q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                
                int temp = q.front();
                q.pop();
                
                for(int j : graph[temp]){
                    if(color[j] == -1){
                        color[j] = 1 - color[temp];
                        q.push(j);
                    }
                    else if(color[j] == color[temp]){
                        return false;
                    }
                }
                
            }
        }
        
        return true;
        
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        
        for(auto &i : dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> color(n+1, -1);
        
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                if(!bfs(i, color, adj)) return false;
            }
        }
        
        return true;
    }
};