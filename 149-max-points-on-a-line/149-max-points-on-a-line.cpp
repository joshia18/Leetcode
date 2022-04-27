class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //if the input contains only two points, then simply return points.size()
        
        if(points.size() <= 2){
            return points.size();
        }
        
        int maxpoints = 2;
        
        for(int i = 0; i < points.size(); i++){
            unordered_map<double, int> slopecount;
            int currMax = 0;
            
            for(int j = 0; j < points.size(); j++){
                
                if(i == j) continue;
                
                //slope formula y2-y1/x2-x1
                int nume = (points[j][1] - points[i][1]);
                int deno = (points[j][0] - points[i][0]);
                
                double slope = (double)nume/deno;
                
                slopecount[slope]++;
                
                currMax = max(currMax, slopecount[slope]);
            }
            
            maxpoints = max(maxpoints, currMax+1);
        }
        
        return maxpoints;
        
    }
};