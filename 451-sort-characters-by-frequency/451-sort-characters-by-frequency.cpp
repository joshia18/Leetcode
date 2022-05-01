class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for(char c : s){
            mp[c]++;
        }
        
        unordered_map<int, vector<char>> charlist;
        int maxi = 0;
        
        for(auto i : mp){
            char c = i.first;
            charlist[i.second].push_back(c);
            maxi = max(maxi, i.second);
        }
        
//         for(auto i : charlist){
//             for(auto j : i.second) {cout << j << " ";}
//             cout << endl;
//         }
        
//         cout << maxi;
        
        string ans = "";
        
        for(int i = maxi; i >= 0; i--){
            if(charlist.find(i) == charlist.end()) continue;
            
            for(char c : charlist[i]){
                int num = i;
                while(num > 0){
                    ans += c;
                    num--;
                }
            }
        }
        
        return ans;
        
    }
};