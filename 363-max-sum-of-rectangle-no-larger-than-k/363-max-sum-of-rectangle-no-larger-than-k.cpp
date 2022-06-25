class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r = matrix.size(), c = matrix[0].size();
        
        for(int i = 0; i < r; i++){
            for(int j = 1; j < c; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int ans = INT_MIN;
        
        for(int start = 0; start < c; start++){
            for(int end = start; end < c; end++){
                vector<int> temp(r);
                
                //we have to find the maximum sum subarray less than or equal to k each column wise
                //we need set for that
                set<int> st;
                int prefsum = 0;
                st.insert(0);
                
                for(int i = 0; i < r; i++){
                    int curr = matrix[i][end];
                    
                    if(start > 0) curr -= matrix[i][start-1];
                    prefsum += curr;
                    
                    //lower_bound gives iterator where the element is greater than or equal to prefsum-k
                    auto itr = st.lower_bound(prefsum-k);
                    
                    if(itr != st.end()){
                        ans = max(ans, prefsum-*(itr));
                    }
                    
                    st.insert(prefsum);
                    
                }
                
                
            }
        }
        
        return ans;
    }
};