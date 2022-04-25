class Solution {
public:
        
    string removeDuplicates(string s, int k) {
        //brute force used string as a stack
        
        stack<pair<char, int>> stk;
        string ans = "";
               
        for(char ch : s){
            if(!stk.empty() && stk.top().first == ch){
                stk.top().second++;
                if(stk.top().second == k){
                    stk.pop();
                }
            }
            else{
                stk.push({ch, 1});
            }
        }
        
        while(!stk.empty()){
            char ch = stk.top().first;
            int t = stk.top().second;
            
            while(t){
                ans += ch;
                t--;
            }
            
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};