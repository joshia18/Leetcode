class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        //the given equation is yi + yj + |xi - xj|
        //this equation can also be written as (yi+yj) + (xj - xi)
        //this in turn can be written as (yi-xi) + (yj+xj)
        //the x coordinates are sorted in the given input array
        
        //need priority queue(def max heap) to save values of (yi-xi), xi
        
        priority_queue<pair<int, int>> pq;
        
        int ans = INT_MIN;
        
        for(int i = 0; i < points.size(); i++){
            
            while(!pq.empty() && points[i][0] - pq.top().second > k) pq.pop();
            
            if(!pq.empty()){
                int eqn = pq.top().first + points[i][0] + points[i][1];
                    
                ans = max(ans, eqn);
            }
            
            pq.push({points[i][1] - points[i][0], points[i][0]});
            
        }
        
        return ans;
    }
};