class Solution {
    
public:
    int helper(int day, vector<int>& days, vector<int>& costs, vector<int> &dp){
        if(day == days.size()){
            return 0;
        }
        
        if(dp[day] != -1) return dp[day];
        
        //if i buy the 1-day pass i can travel one day of any daynumber present un the days array
        int onedaypass = costs[0] + helper(day+1, days, costs, dp);
        
        //if i buy the 7-day pass, i need to know in which index i will stand after using that 7-day pass totally
        //eg: if i buy 7 day pass initially, i could have came until index 3 of [1,4,6,7,8,20] => 7
        //eg: if i bought 1-day pass first, i came to index 1, and i bought 7-day pass after that, i could have came until the number which is less than days[start]+7 -> days[start] means the day i bought the 7-day pass, in case of first example it is 4, so i can travel until day 11
        int i = day;
        
        while(i < days.size() && days[i] < days[day]+7){
            i++;
        }
        
        int twodaypass = costs[1] + helper(i, days, costs, dp);
        
        while(i < days.size() && days[i] < days[day]+30){
            i++;
        }
        
        int threedaypass = costs[2] + helper(i, days, costs, dp);
        
        return dp[day] = min({onedaypass, twodaypass, threedaypass});
            
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        //this is kind of a different dp problem from striver video
        
        //memoizing needs an array of size of days array
        vector<int> dp(days.size(), -1);
        
        //here 0 points to the index in the days array where we are standing
        return helper(0, days, costs, dp);
    }
};