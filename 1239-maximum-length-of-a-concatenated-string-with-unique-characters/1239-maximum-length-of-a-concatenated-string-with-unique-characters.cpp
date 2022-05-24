class Solution {
public:
    
    int helper(int index, vector<string>& arr, vector<int> mp){
        
        if(index >= arr.size()) return 0;
        
        int flag = 0;
        
        for(char c : arr[index]){
            mp[c-'a']++;
            if(mp[c-'a'] > 1){
                flag = 1;
            }
        }
        
        int take = 0;
        
        if(flag != 1) take = arr[index].size() + helper(index+1, arr, mp);
        
        for(char c : arr[index]){
            mp[c-'a']--;
        }
        
        int nottake = helper(index+1, arr, mp);
        
        return max(take, nottake);
        
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> mp(26, 0);
        return helper(0, arr, mp);
    }
};