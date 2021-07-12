class MedianFinder {
public:
    /** initialize your data structure here. */
    int dt;
    double med;
    priority_queue<int>maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        dt = INT_MIN;
        med = DBL_MIN;
    }
    
    void addNum(int num) {
        dt = num;
        if(med == DBL_MIN){
            maxheap.push(num);
            med = dt;
            return;
        }
        if(maxheap.size()>minheap.size()){
            if(dt<med){
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(dt);
            }
            else {
                minheap.push(dt);
            }
            med = (maxheap.top()+minheap.top())/2.0;
        }
        else if(maxheap.size() == minheap.size()){
            if(dt<med){
                maxheap.push(dt);
                med = maxheap.top();
            }
            else{
                minheap.push(dt);
                med = minheap.top();
            }
        }
        else{
            if(dt>med){
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(dt);
            }
            else{
                maxheap.push(dt);
            }
            med = (maxheap.top()+minheap.top())/2.0;
        }
    }
    
    double findMedian() {
        return med;
    }
};
