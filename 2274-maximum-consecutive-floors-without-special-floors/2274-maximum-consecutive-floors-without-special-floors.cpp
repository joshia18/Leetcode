class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        //if(top-bottom+1 == special.size()) return 0;
        
        sort(special.begin(), special.end());
        
        int ans = 0, j = 0;
        
        for(int i = 0; i < special.size(); i++){
            ans = max(ans, special[i] - bottom);
            bottom = special[i]+1;
        }
        
        ans = max(ans, top - special[special.size()-1]);
        
        return ans;
    }
};