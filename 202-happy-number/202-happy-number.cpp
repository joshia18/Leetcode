class Solution {
public:
    bool isHappy(int n) {
        int current = n;
        
        unordered_set<int> seen;
        
        int sum = 0;
        
        while(n != 1){
            sum = 0;
            current = n;
            while(current != 0){
                sum += (current%10) * (current%10);
                current = current / 10;
            }
            
            if(seen.find(sum) != seen.end()) return false;
            
            seen.insert(sum);
            
            n = sum;
        }
        
        return true;
    }
};