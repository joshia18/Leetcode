class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int, int>> pq;
        
        unordered_map<int, int> mp;
        
        int count = 0;
        
        for(int &i : arr) mp[i]++;
        
        for(auto &i : mp) pq.push({i.second, i.first});
        
        int n = arr.size();
        
        while(n > arr.size()/2){
            n = n - pq.top().first;
            count++;
            pq.pop();
        }
        
        return count;
    }
};