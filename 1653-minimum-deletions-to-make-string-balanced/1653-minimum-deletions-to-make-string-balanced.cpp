class Solution {
public:
    int minimumDeletions(string s) {
 
    int n=  s.length();
    vector<int> b_before(n);
    vector<int> a_after(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        b_before[i]= cnt;
        if(s[i]=='b')cnt++;
    }
    cnt=0;
    for(int i=n-1;i>=0;i--){
        a_after[i]=cnt;
        if(s[i]=='a')cnt++;
    }
    int ans=INT_MAX;

    for(int i=0;i<n;i++){
        int deletions = b_before[i] +a_after[i];
        ans= min(ans, deletions);
    }

    return ans;
}
};