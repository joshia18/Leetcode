struct compare{
    bool operator()(pair<int, string> &a, pair<int, string> &b){
        
        //as it is a minheap we are creating a.first < b.first
        //if a.first == b.first, then return a.second > b.second, have to be IMPORTANT here
        
        return a.first < b.first || ((a.first == b.first) && a.second > b.second);
        
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //create minheap
        //another method using comparator in priority queue
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        unordered_map<string, int> mp;
        
        for(string &i : words){
            mp[i]++;
        }
        
        for(auto i : mp){
            pq.push({i.second, i.first});
        }
        
        vector<string> ans;
        
        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        
        return ans;
    }
};