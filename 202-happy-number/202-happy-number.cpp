class Solution {
public:
    int getdigitsquare(int n){
        int sum = 0;
        
        while(n != 0){
            sum += (n%10) * (n%10);
            n = n/10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        
        //floyd cycle detection without using extra space but using recursion stack
        int slow = n, fast = n;
        
        while(slow != 1 && fast != 1){
            slow = getdigitsquare(slow);
            fast = getdigitsquare(getdigitsquare(fast));
            
            //if slow == fast it forms a loop and it is not a happy number
            if(slow == fast && slow != 1 && fast != 1){
                return false;
            }
        }
        
        return true;
        
    }
};