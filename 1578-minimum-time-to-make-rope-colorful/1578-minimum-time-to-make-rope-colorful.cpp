class Solution {
public:
    int minCost(string colors, vector<int> &neededTime)
{
    int sum=neededTime[0];
    int maxi = neededTime[0];
    int n= colors.length();
    int ans=0;
    for(int i=1;i<n;i++){
        if(colors[i]==colors[i-1]){
            sum+=neededTime[i];
            maxi= max(maxi, neededTime[i]);
        }else{
            cout<<"hello"<<endl;
            ans+=(sum-maxi);
            sum=neededTime[i];
            maxi= neededTime[i];
        }
    }
    ans+= sum-maxi;
    return ans;
}
};