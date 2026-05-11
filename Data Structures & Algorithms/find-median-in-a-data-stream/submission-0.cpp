class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallHeap; //this is a max heap
    priority_queue<int, vector<int>, greater<int>> largeHeap; //this is a min heap

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //add the number to smallHeap initially everytime
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        //now size check and rebalancing 
        if(smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        //first case for even size // other cases if anyone has extra element, their top element is the median
        if(largeHeap.size() == smallHeap.size()) {
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        } else if(largeHeap.size() > smallHeap.size()) {
            return largeHeap.top();
        } else {
            return smallHeap.top();
        }
    }
};
