class OrderedStream {
private:
    vector<string> s;
    int ptr;

public:
    OrderedStream(int n) {
        s.resize(n);
        ptr=0;
    }
    
    vector<string> insert(int idKey, string value) {
        s[idKey-1]= value;
        vector<string> ans;
        if(idKey-1 == ptr){
            while(ptr<s.size() && s[ptr] != ""){
                ans.push_back(s[ptr]);
                ptr++;
            }
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */