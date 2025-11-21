class Solution {
public:
    int countPalindromicSubsequence(string s) {
    vector<int> hash(26);
    int n= s.length();

    for(char ch:s){
        hash[ch-97]++;
    }

    int count=0;

    for(int i=0;i<26;i++){
        if(hash[i]>=2){
            char ch= (char)(i+97);

            int start=0;
            int end=n-1;

            while(start<n){
                if(s[start]==ch){
                    break;
                }
                start++;
            }

            while(end>=0){
                if(s[end]==ch){
                    break;
                }
                end--;
            }

            unordered_set<char> st;
            for(int j=start+1;j<end;j++){
                if(st.count(s[j])==0){
                    st.insert(s[j]);
                    count++;
                }
            }
        }
    }
    return count;
}
};