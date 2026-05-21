class Solution {
public:
    int compare(int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);
    int x = min(sa.length(), sb.length());
    int cnt =0;
    for(int i=0;i<x;i++){
        if(sa[i] == sb[i]){
            cnt++;
        }else{
            break;
        }
    }
    return cnt;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<string> st;
    for(auto it: arr1){
        string s = to_string(it);
        string temp="";
        for(auto ch: s){
            temp+=ch;
            st.insert(temp);
        }
    }
    int ans =0;
    for(auto it:arr2){
        string s = to_string(it);
        string temp="";
        for(auto ch: s){
            temp+=ch;
            if(st.count(temp)>0){
                if(temp.length()>ans){
                    ans=temp.length();
                }
            }
        }
    }
    return ans;
}
};