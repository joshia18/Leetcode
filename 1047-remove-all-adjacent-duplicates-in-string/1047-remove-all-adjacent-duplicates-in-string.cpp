class Solution {
public:
    string removeDuplicates(string s) {
        //using the string itseld as as a stack
        
        string ans = "";
        
        for(char c : s){
            if(ans.length() > 0 && ans.back() == c){
                ans.pop_back();
            }
            else{
                ans += c;
            }
        }
        
        return ans;
    }
};