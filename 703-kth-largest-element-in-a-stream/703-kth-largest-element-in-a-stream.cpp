class KthLargest {
public:
    
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(int i : nums){
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size() < n){
            pq.push(val);
            if(pq.size() == n) return pq.top();
        }
        
        if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */