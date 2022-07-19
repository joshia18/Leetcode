class Solution {
public:
//     int findDuplicate(vector<int>& nums) {
//         //this problem is solved in o(n) time and o(1) space using the linkedlist cycle methof;
        
//         int slow = nums[0], fast = nums[0];
        
//         do{
//             //slow moves one step
//             slow = nums[slow];
//             //fast moves two steps
//             fast = nums[nums[fast]];
//         }while(slow != fast);
            
//         //After doing the above step, assign the fast pointer with nums[0]
//         //move  slow and fast in only one steps
//         fast = nums[0];
//         while(slow != fast){
//             slow = nums[slow];
//             fast = nums[fast];
//         }
        
//         return slow;
            
//     }
    
    //anothr method
    
    int findDuplicate(vector<int>& nums){
        int i=0;
        
        while(nums[i]>0)
        {
            int j=nums[i];
            nums[i]=0;
            i=j;

        }
        
        // for(int i : nums){
        //     cout << i << " ";
        // }
        
        return i;
    }
};