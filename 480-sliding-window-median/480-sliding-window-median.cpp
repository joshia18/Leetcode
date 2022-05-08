class Solution {
public:
    void balance(multiset<int> &minheap, multiset<int, greater<int>> &maxheap){
        //inorder to get first half of array in maxheap and second half in minheap,
        //i want the maxheap.size() == minheap.size() OR
        //           maxheap.size() == minheap.size()+1
        if(minheap.size() > maxheap.size()){
            maxheap.insert(*(minheap.begin()));
            minheap.erase(minheap.begin());
        }
        else if(maxheap.size() > minheap.size()+1){
            minheap.insert(*(maxheap.begin()));
            maxheap.erase(maxheap.begin());
        }
    }
    
    void addToAns(multiset<int> &minheap, multiset<int, greater<int>> &maxheap, vector<double> &ans){
        if(minheap.size() == maxheap.size()){
            ans.push_back((*(maxheap.begin())/2.0 + *(minheap.begin())/2.0));
        }
        else if(maxheap.size() > minheap.size()){
            ans.push_back(*(maxheap.begin())/1.0);
        }
        else if(minheap.size() > maxheap.size()){
            ans.push_back(*(minheap.begin())/1.0);
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        multiset<int> minheap;
        multiset<int, greater<int>> maxheap;
        vector<double> ans;
        
        int i = 0;
        
        for(i = 0; i < k; i++){
            if(maxheap.size() == 0 || *(maxheap.begin()) > nums[i]){
                maxheap.insert(nums[i]);
            }
            else{
                minheap.insert(nums[i]);
            }
            
            balance(minheap, maxheap);
        }
        
        addToAns(minheap, maxheap, ans);
        
        int start = 0;
        
        int numToRemove = nums[start]; start++;
        
        while(i < nums.size()){
            
            //removing the number for sliding window
            //remove numToRemove from maxheap if(numToRemove <= maxheap.top()) else remove from minheap
            if(numToRemove <= *(maxheap.begin())){
                maxheap.erase(maxheap.lower_bound(numToRemove));
            }
            else{
                minheap.erase(minheap.lower_bound(numToRemove));
            }
            
            balance(minheap, maxheap);
            
            if(maxheap.size() == 0 || *(maxheap.begin()) > nums[i]){
                maxheap.insert(nums[i]);
            }
            else{
                minheap.insert(nums[i]);
            }
            
            balance(minheap, maxheap);
            
            //adding to ans array 
            addToAns(minheap, maxheap, ans);
            
            numToRemove = nums[start]; start++;
            
            i++;
        }
        
        return ans;
        
        
    }
};