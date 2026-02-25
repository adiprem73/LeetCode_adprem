class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt =0;
        int n = colors.size();
        for(int i=0;i<n;i++){
            int j = (i+1)%n;
            int k = (i+2)%n;
            if(colors[i] == colors[k] && colors[i] != colors[j]){
                cnt++;
            }
        }
        return cnt;
    }
};