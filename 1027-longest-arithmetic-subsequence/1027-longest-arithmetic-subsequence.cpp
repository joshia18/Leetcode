class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        
        //this is unlike other dp problems, the solution is not very intuitive
        vector<unordered_map<int, int>> dp(n);
        
        int ans = INT_MIN;
        
        if(n <= 2) return n;
        
        //taking a number from array and storing difference of it and the previous numbers to it and store it in a map
        //if the same difference occurs in the maps of previous numbers take that value of key(diff) and add one to it
        //the data structure used is a vector of map of same size as array, so there is a map for each number of input array
        //the map is empty for the first number in nums(0th index)
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = nums[j] - nums[i];
                
                if(dp[j].find(diff) != dp[j].end()){
                    dp[i][diff] = dp[j][diff]+1;
                }
                else{
                    dp[i][diff] = 1;
                }
                
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans+1;
    }
};