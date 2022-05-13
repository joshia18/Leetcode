class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //int i = 0, j = 1;
        
        int n = time.size();
        
        unordered_map<int, int> mp;
        
        int ans = 0;
        
        for(int i : time){
            
            if(i%60 == 0){
                ans += mp[0];
            }
            else{
                ans += mp[60 - i%60];
            }
            
            mp[i%60]++;
            
        }
        
        return ans;
        
    }
};