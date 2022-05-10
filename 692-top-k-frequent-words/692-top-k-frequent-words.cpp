class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //create minheap
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        unordered_map<string, int> mp;
        
        for(string &i : words){
            mp[i]++;
        }
        
        for(auto i : mp){
            pq.push({i.second, i.first});
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            vector<string> temp;
            
            int freq = pq.top().first;
            while(!pq.empty() && pq.top().first == freq){
                temp.push_back(pq.top().second);
                pq.pop();
            }
            
            //cout << temp.size() << " ";
            
            if(temp.size() > 1) sort(temp.begin(), temp.end());
            
            if(temp.size() > 0) ans.insert(ans.begin(), temp.begin(), temp.end());
            
        }
        
        return vector<string>(ans.begin(), ans.begin()+k);
    }
};