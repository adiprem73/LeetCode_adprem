class MinStack{
    private:
        vector<pair<int,int>> s;
    
    public:
    MinStack() {}  //constructor doesnt need ot doanythig
    
    void push(int val) {
        if(s.empty()){
            s.emplace_back(val,val);
        }
        else{
            int currentMin=min(s.back().second,val);
            s.emplace_back(val,currentMin);
        }
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};