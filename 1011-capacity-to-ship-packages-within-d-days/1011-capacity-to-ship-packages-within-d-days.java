class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int min = 0, max = 0;
        
        for(int i : weights){
            max += i;
            min = Math.max(min, i);
        }
        
        int ans = 0;
        while(min <= max){
            int mid = min + (max-min)/2;
            int daysRequired = numOfDaysRequired(weights, mid);
            
            if(daysRequired > days){
                min = mid+1;
            }
            else{
                ans = mid;
                max = mid-1;
            }
            
        }
        
        return ans;
        
    }
    
    public int numOfDaysRequired(int[] weights, int capacity){
        int daysRequired = 1;
        int current = 0;
        
        for(int i : weights){
            current += i;
            if(current > capacity){
                daysRequired++;
                current = i;
            }
        }
        
        return daysRequired;
    }
}