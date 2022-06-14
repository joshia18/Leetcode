class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int min = 0, max = 0;
        
        for(int i : weights){
            max += i;
            min = Math.max(min, i);
        }
        
        int ans = Integer.MAX_VALUE;
        while(min <= max){
            int mid = min + (max-min)/2;
            
            if(numOfDaysRequired(weights, mid, days)){
                //ans = Math.min(ans, mid); OR
                ans = mid;
                max = mid-1;
            }
            else{
                min = mid+1;
            }
            
        }
        
        return ans;
        
    }
    
    public boolean numOfDaysRequired(int[] weights, int capacity, int days){
        int daysRequired = 1;
        int current = 0;
        
        for(int i : weights){
            current += i;
            if(current > capacity){
                daysRequired++;
                current = i;
            }
        }
        
        return daysRequired <= days;
    }
}