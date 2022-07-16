class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //naive approach
        //this condition 0 <= fromi < toi <= 1000 represents that there can be 1000 unique locations
        //using an array of size 1001, we count the number of passengers while travelling across locations
        vector<int> count(1001, 0);
        int ans = 0;
        
        for(auto &trip : trips){
            //i < trip[2] as passengers are dropped on this location
            for(int i = trip[1]; i < trip[2]; i++){
                count[i] += trip[0];
                ans = max(ans, count[i]);
            }
        }
        
        return ans <= capacity;
    }
};