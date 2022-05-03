class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        
        int maxi = INT_MIN, mini = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            maxi = INT_MIN, mini = INT_MAX;
            
            for(int j = i; j < nums.size(); j++){
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                //cout << (maxi - mini) << " ";
                sum += (maxi - mini);
            }
        }
        
        return sum;
    }
};