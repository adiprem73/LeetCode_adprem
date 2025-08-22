class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n=g.size(); //number of children
    int m=s.size(); //number of cookies
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(g[i]<=s[j]){
            cnt++;
            i++;
            j++;
        }else{
            j++; //its madatory to do j++ here, since if this cookie cantt satisfy this children witht he least greed as of now, the upcoming children will have higher greed only. so this cookie is basically useless.
        }
    }
    return cnt;
}
};