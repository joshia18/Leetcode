class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //usin binary search fraz
        
        int start = 0, end = arr.size()-1, ans = -1;
        
        //here start < end, not start <= end because inorder to find peak element we need to compare two numbers
        //mid and mid+1 for the left half, where mid+1 is the answer case (arr[mid] < arr[mid+1])
        //mid and mid+1 for the right half, where mid is the answer case (arr[mid] > arr[mid+1])
        //end = mid because we don't want to miss the answer mid if that is the answer
        while(start < end){
            
            int mid = start + (end-start)/2;
            
            if(arr[mid] > arr[mid+1]){
                ans = mid;
                end = mid;
            }
            else{
                ans = mid+1;
                start = mid+1;
            }
        }
        
        return ans;
    }
};