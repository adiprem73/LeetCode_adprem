class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
    int n= energy.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int start= i;
        int sum=0;
        while(start<n){
            sum+=energy[start];
            start+=k;
        }
        maxi=max(maxi,sum);
    } 
    return maxi;
}
};