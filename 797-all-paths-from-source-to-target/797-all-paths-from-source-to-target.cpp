class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //using bfs
        vector<vector<int>> ans;
        int n = graph.size();
        
        vector<int> path;
        path.push_back(0);
        queue<vector<int>> q;
        q.push(path);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                //don't forget to pop from the while doing bfs
                path = q.front();
                q.pop();
                int last = path.back();
                
                if(last == n-1){
                    ans.push_back(path);
                }
                
                for(int j : graph[last]){
                    vector<int> newpath = path;
                    newpath.push_back(j);
                    q.push(newpath);
                }
            }
        }
        
        return ans;
    }
};