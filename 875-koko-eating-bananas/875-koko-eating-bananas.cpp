class Solution {
public:
    bool helper(int k, vector<int>& piles, int &h){
        long hours = 0;
        
        for(int &i : piles){
            hours += (i/k);
            if(i%k != 0) hours++;
        }
        
        //cout << k << " " << hours << endl;
        
        return hours <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        //piles = [3,6,7,11], for eg: lets take k = 5, k means no of bananas koko can eat from one pile in an hour
        //index 0: 3, as k > 3, she can complete the 0th pile in an hour
        //index 1: 6, she can eat 5 bananas in one hour and remaining 1 banana in 1 hour, so 2 hrs
        //index 2: 7, 2 hours
        //index 3: 3 hours
        //1 + 2 + 2 + 3 = 8 hrs for k = 5, we can also get 8hrs for k = 4, also we need to minimise the value of k using binary search                 
        //low should actually be set to 1, for eg tc: [312884470], h = 312884469 => ans = 2
        //if low is set to  min number of array minimum will be 312884470, abd high = 312884470 => do we have ans=2 within this range..?
        int low = 1, high = INT_MIN;
        
        for(int i : piles){
            high = max(high, i);
        }
        
        int ans = 0;
        
        //low <= high is important just like capacity to ship packages within d days
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(helper(mid, piles, h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};