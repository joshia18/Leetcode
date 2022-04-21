class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] ans = new int[2];
        int k = 0;
        for(int i=0; i<nums.length; i++){
            int diff = target - nums[i];
            
           
            if(map.containsKey(diff)){
                ans[0] = i; 
                ans[1] = map.get(diff);
                return ans;
            }
            map.put(nums[i], i);
        }
        System.out.println(map);
        
        return ans;
    }
}