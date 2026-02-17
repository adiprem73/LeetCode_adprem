class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;
        int n= arr.size();
        for(int i=0;i<n;i++){
            int x = 0;
            for(int j=i;j<n;j++){
                x = x^ arr[j];
                if(x == 0){
                    cnt+=(j-i);
                }
            }
        }
        return cnt;
    }
};