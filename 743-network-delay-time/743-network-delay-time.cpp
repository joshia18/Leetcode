class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //this problem has complete dijkstras
        vector<vector<vector<int>>> adjList(n+1);
        
        for(auto &i : times){
            adjList[i[0]].push_back({i[1], i[2]});
        }
        
        vector<int> distances(n+1, INT_MAX);
        distances[k] = 0;
        vector<bool> visited(n+1, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k});
        
        while(!pq.empty()){
            auto [currdist, currNode] = pq.top();
            pq.pop();
            if(visited[currNode]) continue;
            visited[currNode] = true;
            
            for(auto i : adjList[currNode]){
                int neighbour = i[0];
                int distance = i[1];
                int nextdist = currdist + distance;
                
                if(!visited[neighbour] && nextdist < distances[neighbour]){
                    distances[neighbour] = nextdist;
                    pq.push({nextdist, neighbour});
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 1; i < distances.size(); i++){
            if(distances[i] == INT_MAX) return -1;
            ans = max(ans, distances[i]);
        }
        
        return ans;
        
    }
};