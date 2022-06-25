class Solution {
public:
    string smallestSubsequence(string s) {
        
        string res = "";
        
        //stores the lastIndex of each letter in string s
        vector<int> lastIndex(26,0);
        
        vector<bool> visited(26, false);
        
        for(int i = 0; i < s.size(); i++) lastIndex[s[i]-'a'] = i;
        
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            
            if(visited[c-'a']) continue;
            
            while(res.size() > 0 && res.back() > c && lastIndex[res.back()-'a'] > i){
                visited[res.back()-'a'] = false;
                res.pop_back();
            }
            
            res += c;
            visited[c-'a'] = true;
        }
        
        return res;
    }
};