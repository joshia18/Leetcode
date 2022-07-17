class Solution {
public:
    bool checkPowersOfThree(int n) {
        //3^14 is closest to 10^7 which is the largest constraintg
        
        for(int i = 14; i >= 0; i--){
            int temp = pow(3, i);
            
            if(n - temp >= 0){
                n = n-temp;
            }
            
            if(n == 0) return true;
        }
        
        return false;
    }
};