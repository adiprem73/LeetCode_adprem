class Solution {
public:
    int longestCommonSubsequenceSO(string text1, string text2) {
    int n1=text1.length();
    int n2=text2.length();
    vector<int> prev(n2+1, 0);
    for(int ind1=1;ind1<n1+1;ind1++){
        vector<int> curr(n2+1, 0);
        for(int ind2=1; ind2<n2+1;ind2++){
            if(text1[ind1-1]==text2[ind2-1]){
                curr[ind2]=1+ prev[ind2-1];
            }else{
                curr[ind2]= max(prev[ind2], curr[ind2-1]);
            }
        }
        prev=curr;
    }
    return prev[n2];
}

int longestPalindromeSubseq(string s) {
    string s2=s;
    reverse(s2.begin(),s2.end());
    return longestCommonSubsequenceSO(s, s2);
}
};