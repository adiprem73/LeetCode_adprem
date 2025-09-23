class RandomizedSet
{
private:
set<int> st;
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        bool flag;
        flag= (st.count(val))? false: true;
        st.insert(val);
        return flag;
    }

    bool remove(int val)
    {
        // for(auto it: st){
        //     if(it== val){
        //         st.erase(it);
        //         return true;
        //     }
        // }
        // return false;
        if(st.count(val)){
            st.erase(val);
            return true;
        }return false;
        
    }

    int getRandom()
    {
        int n=st.size();
        int r= rand()%n ;
        auto it= st.begin();
        advance(it, r);
        return *it;
    }
};