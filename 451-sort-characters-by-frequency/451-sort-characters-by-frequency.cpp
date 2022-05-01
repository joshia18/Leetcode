class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for(char c : s){
            mp[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        
        for(auto i : mp){
            pq.push({i.second, i.first});
        }
        
        string ans = "";
        
        while(!pq.empty()){
            int num = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            
            while(num > 0){
                ans += c;
                num--;
            }
        }
            
        return ans;
        
    }
};