class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        //important thing to note
        //practically, there cannot be more than two elements in the nums array which appears more than n/3 times
        int n = nums.size();
        
        int num1 = INT_MIN, num2 = INT_MIN, count1 = 0, count2 = 0, count3 = 0, temp = nums[0];
        
        for(int i : nums){
            
            if(i == num1){
                count1++;
            }
            else if(i == num2){
                count2++;
            }
            else if(count1 == 0){
                num1 = i;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = i;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
            
            //this condition is to check if all the elements in the array are same
            if(i == temp) count3++;
            
        }
        
        if(count3 == n) return {temp};
        
        count1 = 0; count2 = 0;
        
        for(int i : nums){
            if(i == num1) count1++;
            if(i == num2) count2++;
        }
        
        if(count1 > (n/3) && count2 > (n/3)){
            return {num1, num2};
        }
        else if(count1 > (n/3)){
            return {num1};
        }
        else if(count2 > (n/3)){
            return {num2};
        }
        
        return {};        
        
    }
};