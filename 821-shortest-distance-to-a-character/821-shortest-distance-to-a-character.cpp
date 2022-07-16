class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        //set all values to INT_MAX initially for better uage
        vector<int> ans(s.size(), INT_MAX);
        
        int l = 0, r = 0;
        
        //there needs to be a special consideration for the last character and the last element of ans array
        //if the last character of string s == c, then we can set it to 0
        //else, we can set the correct value for last element of array in second traversal only
        //set it's value to INT_MAX after the first traversal
        
        int n = s.size();
        
        while(r < n){
           if(s[r] == c){
               while(l <= r){
                   ans[l++] = r - l; 
               }
           }
           r++;
        }
        
        r = s.size()-1, l = s.size()-1;
        
        //another same traversal from the last index of string s
        while(r >= 0){
            if(s[r] == c){
                while(r <= l){
                    ans[l] = min(ans[l], l-r);
                    l--;
                }
            }
            r--;
        }
        
        return ans;
    }
};