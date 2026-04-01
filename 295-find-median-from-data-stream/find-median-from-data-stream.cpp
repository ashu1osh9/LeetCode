class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>left; // max heap
    priority_queue<int,vector<int>,greater<int>>right; //min heap
    void addNum(int num) {
        
        if(left.size()==0 || num<=left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
         if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
         }
        else if(right.size()>left.size()){
            int num2=right.top();
            left.push(num2);
            right.pop();
        }
    }
    
    double findMedian() {
        double median=-1;
        if(left.size()==right.size()){
            median=(left.top()+right.top())/2.0;
        }
        else{
            median=left.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */