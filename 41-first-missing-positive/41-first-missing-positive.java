class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean one_t =  false;//if one is not there in nums return 1//knowledge center channel
        // in a good array input array elements should be 1 to n... if the array contains perfect elements from 1 to n eg[1,3,2,4,5] return n+1 eg: 6
        for(int i : nums){
            if(i == 1){
                one_t = true;
            }
        }

        
        if(!one_t){return 1;}
        
        if(n == 1){return 2;}
        //if nums <= 0 or nums > size of nums -> set the number in the array as 1
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        
        //to find the missing element multiply nums[a-1] by -1, if already -ve dont change it... there can not be negative numbers in the array at this point because, we made all the numbers < 0 as 1 in previous step
        for(int i = 0; i < n; i++){
            int a = Math.abs(nums[i]);
            if(nums[a-1] > 0){
                nums[a-1] *= -1;
            }
        }
        
        //traverse through modified nums when hen a positive number is found return i+1             
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i+1;
            }
        }
        //eg in a perfect array like [1,3,2], all the numbers in nums would get -ve and no +ve value can be found in the above step so return n+1
        return n+1;
    }
}