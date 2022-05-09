class Solution {
public:
    vector<vector<int>> dp;
    
    int helper(int idx, int jump, vector<int>& stones){
        
        if(idx >= stones.size()-1) return 1;
        
        if(dp[idx][jump] != -1) return dp[idx][jump];
        
        int flag = 0;
        
        for(int i = idx+1; i < stones.size(); i++){
            
            if(stones[i] - stones[idx] > jump+1) break;
            
            //if difference is same as jump do not increment the humo
            if(stones[i] - stones[idx] == jump){
                if(helper(i, jump, stones)) flag = 1;
            }
            
            if(stones[i] - stones[idx] == jump+1){
                if(helper(i, jump+1, stones)) flag = 1;
            }
            
            if(stones[i] - stones[idx] == jump-1){
                if(helper(i, jump-1, stones)) flag = 1;
            }
            
        }
        
        return dp[idx][jump] = flag;
        
    }
    
    bool canCross(vector<int>& stones) {
        dp.resize(2001, vector<int>(2001, -1));
        
        // If 2nd stone is not rechable in 1 unit jump then return false.
        if(stones[1] - stones[0] > 1) return false;
        
        //start from 1st index
        return helper(1, 1, stones);
    }
};