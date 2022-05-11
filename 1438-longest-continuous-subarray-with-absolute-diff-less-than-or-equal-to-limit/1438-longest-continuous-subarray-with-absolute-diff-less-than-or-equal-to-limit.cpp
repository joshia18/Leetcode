class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //have to keep two deques
        //one maxdeque to keep the maximum element index at the front which is in decreasing order
        //one mindeque to keep the minimum element index at the front which is in increasing order
        
        int ans = 0;
        deque<int> maxdeq;
        deque<int> mindeq;
        int start = 0, end = 0;
        
        while(end < nums.size()){
            
            int x = nums[end];
            
            while(!maxdeq.empty() && nums[maxdeq.back()] <= x) maxdeq.pop_back();
            
            maxdeq.push_back(end);
            
            while(!mindeq.empty() && nums[mindeq.back()] >= x) mindeq.pop_back();
            
            mindeq.push_back(end);
            
            int mini = nums[mindeq.front()];
            int maxi = nums[maxdeq.front()];
            
            if(maxi - mini > limit){
                start++;
                //if start pointer starts moving pop the indices from both the deques fronts which are less than start
                
                if(start > mindeq.front()) mindeq.pop_front();
                if(start > maxdeq.front()) maxdeq.pop_front();
            }
            else{
                ans = max(ans, end - start + 1);
                end++;
            }
            
        }
        
        return ans;
    }
};