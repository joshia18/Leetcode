class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //its time complexity is o(n logk)
        priority_queue<tuple<int, int, int>> pq;
        
        for(auto i : points){
            int dist = (i[0]*i[0]) + (i[1]*i[1]);
            
            pq.push({dist, i[0], i[1]});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        
        while(!pq.empty()){
            auto [_, x, y] = pq.top();
            pq.pop();
            ans.push_back({x,y});
        }
        
        return ans;
    }
};