class Solution {
public:
    void dfs(int root, vector<vector<int>>& rooms, vector<bool> &visited){
        visited[root] = true;
        
        for(int i : rooms[root]){
            if(!visited[i]){
                dfs(i, rooms, visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool> visited(n, false);
        
        dfs(0, rooms, visited);
        
        for(bool i : visited){
            if(i == false) return false;
        }
        
        return true;
        
    }
};