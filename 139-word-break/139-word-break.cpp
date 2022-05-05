class Solution {
public:
    unordered_map<int,bool> mp;
    
    bool helper(string &s, unordered_set<string> &st, int index){
        
        if(index == s.size()){
            return true;
        }
        
        if(mp.find(index) != mp.end()) return mp[index];
        
        for(int i = index; i < s.size(); i++){
            if(st.find(s.substr(index, i-index+1)) != st.end() && helper(s, st, i+1)){
                return mp[index] = true;
            }
        }
        
        
        return mp[index] = false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        
        for(string i : wordDict){
            st.insert(i);
        }
        
        return helper(s, st, 0);
    }
};