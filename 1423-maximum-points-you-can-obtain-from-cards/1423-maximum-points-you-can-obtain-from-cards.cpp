class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    int l=0,r=0,sum=0,minSum=INT_MAX,totalSum=0;

    while(r<cardPoints.size()){

        //sliding window
        if(r-l+1>cardPoints.size()-k){
            sum-=cardPoints[l];
            l++;
        }

        // for(int i=l;i<=r;i++){
        //     cout<<cardPoints[i]<<" ";
        // }
        // cout<<endl;

        sum+=cardPoints[r];
        if(r-l+1==cardPoints.size()-k){
            minSum=min(minSum,sum);
            // cout<<"current sum : "<<sum<<endl;
            // cout<<"current min sum : "<<minSum<<endl;
        }

        r++;
    }

    for(int i=0;i<cardPoints.size();i++){
        totalSum+=cardPoints[i];
    }

    return totalSum-minSum;

}
};