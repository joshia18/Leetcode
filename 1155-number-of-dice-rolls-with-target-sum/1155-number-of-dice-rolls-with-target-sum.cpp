class Solution {
public:
    //using memoization
    int MOD = 1000000007;
    unordered_map<string, int> hashmap;
    
    int numRollsToTarget(int n, int k, int target) {
        
        //base cases
        if(target < n || target > (n*k)) return 0;
        
        if(n == 1) return target <= k ? 1 : 0;
        
        string key = to_string(n) + "," + to_string(k) + "," + to_string(target);
        
        if(hashmap.find(key) != hashmap.end()) return hashmap[key];
        
        int sum = 0;
        for(int i = 1; i <= k; i++){
            //reduce number of dice by one while calling recursion
            sum += numRollsToTarget(n-1, k, target-i);
            sum %= MOD;
        }
        
        return hashmap[key] = sum;
        
    }
};