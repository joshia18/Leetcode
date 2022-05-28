class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;
        
        for(string email : emails){
            string s = "";
            int i = 0;
            for(i = 0; i < email.length() && email[i] != '@'; i++){
                if(email[i] == '.'){
                    continue;
                }
                else if(email[i] == '+'){
                    while(email[i] != '@'){
                        i++;
                    }
                    i = i-1;
                }
                else{
                    s += email[i];
                }
            }
            s += email.substr(i);
            cout << s << endl;
            
            ans.insert(s);
        }
        
        return ans.size();
    }
};