class MedianFinder {
public:
    priority_queue<int>left_maxheap;
    priority_queue<int,vector<int>,greater<int>>right_minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_maxheap.empty() || num<left_maxheap.top()){
            left_maxheap.push(num);
        }else{
            right_minheap.push(num);
        }

        if(abs((int)left_maxheap.size()-(int)right_minheap.size())>1){
            right_minheap.push(left_maxheap.top());
            left_maxheap.pop();
        }else if(left_maxheap.size()<right_minheap.size()){
            left_maxheap.push(right_minheap.top());
            right_minheap.pop();
        }

        
    }
    
    double findMedian() {
        if(left_maxheap.size()==right_minheap.size()){
            double mean=(left_maxheap.top()+right_minheap.top())/2.0;
            return mean;
        }else{
            return left_maxheap.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */