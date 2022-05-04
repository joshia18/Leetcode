class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<pair<int, int>> intervals;
        
        for(int i = 0; i < ranges.size(); i++){
            intervals.push_back({max(0, i-ranges[i]), i + ranges[i]});
        }
        
        //sort according to the first number in the intervals array
        sort(intervals.begin(), intervals.end());
        
        int start = 0, end = 0, index = 0, count = 0;
        
        while(true){
            int newEnd = end;
            count++;
            
            //this while loop looks through all the connected intervals and checks what is the maximum end 
            while(index < intervals.size() && intervals[index].first >= start && intervals[index].first <= end){
                newEnd = max(newEnd, intervals[index].second);
                index++;
            }
            
            if(newEnd >= n) return count;
            
            //if many of the taps' ranges == 0, then this case might happen where the whole garden cannot be watered
            if(newEnd == end) return -1;
            
            end = newEnd;
            
        }
        
    }
};