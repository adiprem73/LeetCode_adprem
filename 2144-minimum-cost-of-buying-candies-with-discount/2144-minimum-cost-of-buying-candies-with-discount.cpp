class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();  //6
        
        int x = n/3;  //2
        if(n%3!=0)x+=1;

        int ans =0;
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        if(n==1){
            return cost[0];
        }
        if(n<=3){
            return cost[0]+cost[1];
        }
        for(int i=0;i<x;i++){
            int temp = i*3;
            int a = temp;
            int b = temp+1;
            cout<<a<<"&"<<b<<endl;
            if(a<n )ans+= cost[a];
            if(b<n) ans+= cost[b];
        }
        return ans;
    }
};