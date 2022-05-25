class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        
        sort(intervals.begin(), intervals.end());
        
        //temp marks the previous interval
        vector<int> temp = intervals[0];
        
        for(auto &i : intervals){
            int start = i[0];
            int end = i[1];
            
            if(temp[1] >= start){
                if(end > temp[1]){
                    temp[1] = end;
                }
            }
            else{
                result.push_back({temp[0], temp[1]});
                temp = i;
            }
        }
        
        //don't forget to add the last temp
        result.push_back({temp[0], temp[1]});
        
        return result;
        
    }
};