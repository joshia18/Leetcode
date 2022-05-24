class Solution {
public:
    int helper(int index, vector<string>& arr, unordered_map<char, int> mp){
        
        if(index >= arr.size()) return 0;
        
        int flag = 0;
        
        for(char c : arr[index]){
            mp[c]++;
            if(mp[c] > 1){
                flag = 1;
            }
        }
        
        int take = 0;
        
        if(flag != 1) take = arr[index].size() + helper(index+1, arr, mp);
        
        for(char c : arr[index]){
            mp[c]--;
        }
        
        int nottake = helper(index+1, arr, mp);
        
        return max(take, nottake);
        
    }
    
    int maxLength(vector<string>& arr) {
        unordered_map<char, int> mp;
        return helper(0, arr, mp);
    }
};