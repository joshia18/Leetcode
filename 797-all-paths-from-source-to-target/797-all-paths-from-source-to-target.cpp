class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int start, int end, vector<vector<int>> &ans, vector<int> current){
        current.push_back(start);
        if(start == end){
            ans.push_back(current);
        }
        
        //if(current.size() == 0) current.push_back(start);
        
        for(int i : graph[start]){
            //current.push_back(i);
            dfs(graph, i, end, ans, current);
            //current.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //using dfs which does not use backtracking, this problem was solved using three methods
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> current;
        
        dfs(graph, 0, n-1, ans, current);
        
        return ans;
    }
};