class Solution {
public:
    
    enum state{
        unvisited, instack, visited
    };
    
    bool cyclic(int u, vector<vector<int>>& prereq, vector<state>& states){
        if(states[u] == unvisited){
            states[u] = instack;
            
            for(int i : prereq[u]){
                if(states[i] == instack) return true;
                if(states[i] == unvisited && cyclic(i, prereq, states)) return true;
            }
            
            states[u] = visited;
        }
        
        return false;
    }
    
    void top_sort(int u, vector<vector<int>>& prereq, vector<state>& states, stack<int>& stk){
            states[u] = visited;
            
            for(int i : prereq[u]){
                if(states[i] == unvisited) top_sort(i, prereq, states, stk);
            }
            
            stk.push(u);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort using stack
        int n = numCourses;
        
        vector<vector<int>> adjList(n);
        vector<int> ans;
        
        for(auto& i : prerequisites){
            adjList[i[1]].push_back(i[0]);
        }
        
        vector<state> states(n, unvisited);
        
        for(int i = 0; i < n; i++){
            if(states[i] == unvisited && cyclic(i, adjList, states)) return ans;
        }
        
        for(int i = 0; i < n; i++) states[i] = unvisited;
        stack<int> stk;
        
        for(int i = 0; i < n; i++){
            if(states[i] == unvisited) top_sort(i, adjList, states, stk);
        }
        
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        return ans;
    }
};