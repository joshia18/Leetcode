class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //can be done using something like sliding window after sorting
        sort(piles.begin(), piles.end());
        
        int i = 0, j = piles.size()-2;
        
        int sum = 0;
        
        while(i < j){
            sum += piles[j];
            i++;
            j-=2;
        }
        
        return sum;
    }
};