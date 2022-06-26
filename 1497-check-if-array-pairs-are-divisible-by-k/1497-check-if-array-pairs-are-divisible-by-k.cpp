class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int i : arr){
            int temp = i%k;
            
            if(temp < 0){
                temp = temp+k;
            }
            
            mp[temp]++;
        }
        
        if(mp[0]%2 != 0) return false;
        
        for(auto i : mp){
            int first = i.first;
            if(first != 0 && mp[first] != mp[k-first]) return false;
        }
        
        return true;
    }
};