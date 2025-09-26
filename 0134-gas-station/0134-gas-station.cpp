class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n=gas.size();
    if(n==0) return -1;
    long long total_tank=0;
    long long curr_tank=0;
    int start=0;

    for(int i=0;i<n;i++){
        long long diff= (long long)gas[i]- (long long ) cost[i];
        total_tank+=diff;
        curr_tank+=diff;

        if(curr_tank<0){
            start=i+1;
            curr_tank=0;
        }
    }

    return (total_tank>=0)? start%n:-1;

}
};