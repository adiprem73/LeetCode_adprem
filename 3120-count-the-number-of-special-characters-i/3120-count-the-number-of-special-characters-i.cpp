class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;
        for(auto it: word){
            st.insert(it);
        }
        int cnt =0;
        for(auto it: st){
            if(isupper(it)){
                if(st.find(tolower(it))!=st.end()){
                    cnt++;
                }
            }
            else if(islower(it)){
                if(st.find(toupper(it))!=st.end()){
                    cnt++;
                }
            }
        }
        return cnt/2;
    }
};