class Solution {
public:
    int scoreOfString(string s) {
    int ans=0;
    int n= s.length();
    for(int i=0;i<n-1;i++){
        ans+=abs(((int)s[i])- ((int)s[i+1]));
    }
    return ans;       
}
};