class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cookiePtr=0, childPtr=0;
        int nCookies = s.size();
        int nChildren = g.size();
        int contentChildren=0;
        while(cookiePtr < nCookies && childPtr < nChildren){
            if(g[childPtr]<= s[cookiePtr]){
                contentChildren++;
                childPtr++;
                cookiePtr++;
            }else{
                cookiePtr++;
            }
        }
        return contentChildren;
    }
};