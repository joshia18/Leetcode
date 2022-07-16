class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //another apprach with the same array of size 1001
        
        vector<int> count(1001, 0);
        
        for(auto &trip : trips){
            count[trip[1]] += trip[0];
            count[trip[2]] -= trip[0];
        }
        
        for(int &i : count){
            capacity -= i;
            if(capacity < 0) return false;
        }
        
        return true;
    }
};