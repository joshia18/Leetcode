class Solution {
public:
    
       
    vector<string> reorderLogFiles(vector<string>& logs) {
        //sort(logs.begin(), logs.end(), comp);
        
        vector<pair<string, string>> letterlogs;
        vector<string> digitlogs;
        
        for(auto log : logs){
            int i = 0;
            while(log[i] != ' ') i++;
            
            if(log[i+1] >= '0' && log[i+1] <= '9'){
                digitlogs.push_back(log);
                cout << "digitlogs: " << digitlogs.back() << endl;
            }
            else{
                letterlogs.push_back({log.substr(i), log.substr(0, i)});
            }
        }
        
        sort(letterlogs.begin(), letterlogs.end());
        
        vector<string> ans;
        
        for(auto i : letterlogs) ans.push_back(i.second + i.first);
        for(auto i : digitlogs) ans.push_back(i);
        
        return ans;
    }
};