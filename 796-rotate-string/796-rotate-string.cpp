class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        string temp = s + s;
        
        int left = 0;
        
        while(left + s.size() < temp.size()){
            string subs = temp.substr(left, s.size());
            
            if(goal == subs) return true;
            
            left++;
        }
        
        return false;
    }
};