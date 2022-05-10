class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        //priority queue(maxheap) with the ratio of pass/total, and pair of pass and total
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for(auto &i : classes){
            int pass = i[0];
            int total = i[1];
            
            //here the change variable is for the pq by checking adding one person to which class will give maximum pass ratio, so that in next while loop we will add the extrastudent first to that class
            double change = (double)(pass+1)/(total+1) - (double)pass/total;
            
            pq.push({change, {pass, total}});
        }
        
        while(extraStudents--){
            
            //taking the class's pass and total from the top of the pq which provides classes to which we can add students who will give max pass ratio
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            
            //IMPORTANT: increment pass and total for one extrastudent
            pass++; total++;
            
            //do the same thing as before to find the class which will give max pass ratio from the priority queue
            double newchange = (double)(pass+1)/(total+1) - (double)pass/total;
            
            //remove the class with old change, pass, total from pq and the new class with new change, pass and total
            pq.pop();
            
            pq.push({newchange, {pass, total}});
            
        }
        
        double ans = 0.0;
        
        while(!pq.empty()){
            
            //IMPORTANT here -> we add new pass/total ratios with the answer, also at the end divide the answer with the classes size
            
            ans += (double)(pq.top().second.first)/(pq.top().second.second);
            pq.pop();
        }
        
        return ans/classes.size();
        
    }
};