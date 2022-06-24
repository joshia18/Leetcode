class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        
        for(int i = 0; i < r; i++){
            for(int j = 1; j < c; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int ans = 0;
        
        for(int start = 0; start < c; start++){
            for(int end = start; end < c; end++){
                
                //doing prefix sum and finding number of subarrays column-wise having sum == target
                int sum = 0;
                
                unordered_map<int, int> mp;
                mp[0]++;
                
                for(int i = 0; i < r; i++){
                    int curr = matrix[i][end];
                    
                    //curr holds the sum of elements between start and end
                    if(start > 0) curr -= matrix[i][start-1];
                    
                    sum += curr;
                    
                    ans += mp[sum-target];
                    
                    mp[sum]++;
                }
                
            }
        }
        
        return ans;
    }
};