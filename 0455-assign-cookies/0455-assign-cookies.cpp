class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int childPtr=0;
        int cookiePtr=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gSize= g.size();
        int sSize = s.size();
        int cnt =0;
        while(childPtr < gSize && cookiePtr < sSize){
            if(s[cookiePtr] >= g[childPtr]){
                cnt++;
                childPtr++;
                cookiePtr++;
            }else{
                cookiePtr++;
            }
        }
        return cnt;
    }
};