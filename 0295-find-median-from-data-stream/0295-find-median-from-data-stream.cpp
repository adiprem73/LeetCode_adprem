class MedianFinder {
public:
    priority_queue<int> mxHeap; //for the lower half of the array
    priority_queue<int, vector<int>, greater<int>> mnHeap; //for the larger half of the array
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxHeap.empty() || num<=mxHeap.top()){
            mxHeap.push(num);
        }
        else{
            mnHeap.push(num);
        }

        //rebalancing of sizes

        if(mxHeap.size()>mnHeap.size()+1){
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }else if(mnHeap.size()>mxHeap.size()+1){
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }
    }
    
    double findMedian() {
        if(mxHeap.size()==mnHeap.size()){ //even number of elements int he array right now
            return ((mxHeap.top()+mnHeap.top()) / 2.0);
        }else if(mxHeap.size()>mnHeap.size()){
            return mxHeap.top();
        }else{
            return mnHeap.top();
        }
    }
};