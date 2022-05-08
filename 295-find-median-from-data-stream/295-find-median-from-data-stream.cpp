class MedianFinder {
public:
    //first half of input array should be stored in maxheap
    //second half of input array should be stored in minheap
    //maxheap
    priority_queue<int> maxheap;
    //minheap
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top() > num){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        
        //the difference between sizes of two heaps should not be greater than 1
        
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()){
            return (maxheap.top()+minheap.top())/2.0;
        }
        
        if(maxheap.size() > minheap.size()){
            return maxheap.top()/1.0;
        }
        else{
            return minheap.top()/1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */