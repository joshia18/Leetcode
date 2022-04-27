class Solution {
public:
    
    double getslope(vector<int> &p1, vector<int> &p2){
        if(p1[0] == p2[0]) return (double)INT_MAX;
        
        int x = p2[1] - p1[1];
        int y = p2[0] - p1[0];
        
        return (double)x/y;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        //if the input contains only two points, then simply return points.size()
        
        if(points.size() <= 2){
            return points.size();
        }
        
        int maxpoints = 2;
        
        for(int i = 0; i < points.size()-1; i++){
            unordered_map<double, int> slopecount;
            int currMax = 0;
            
            for(int j = i+1; j < points.size(); j++){
                
                double slope = getslope(points[i], points[j]);
                
                slopecount[slope]++;
                
                currMax = max(currMax, slopecount[slope]);
            }
            
            maxpoints = max(maxpoints, currMax+1);
        }
        
        return maxpoints;
        
    }
};