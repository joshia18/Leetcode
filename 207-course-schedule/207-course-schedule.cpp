class Solution {
public:
    enum state{
        unvisited, instack, visited
    };
    
    bool dfs(int u, vector<vector<int>>& prereq, vector<state>& states){
        if(states[u] == unvisited){
            states[u] = instack;
            
            for(int i : prereq[u]){
                if(states[i] == instack) return true;
                if(states[i] == unvisited && dfs(i, prereq, states)) return true;
            }
            
            states[u] = visited;
        }
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        
        vector<vector<int>> edges(n);
        
        for(auto& i : prerequisites){
            edges[i[0]].push_back(i[1]);
        }
        
        vector<state> states(n, unvisited);
        
        for(int i = 0; i < n; i++){
            if(states[i] == unvisited && dfs(i, edges, states)){
                return false;
            }
        }
        
        return true;
        
    }
};