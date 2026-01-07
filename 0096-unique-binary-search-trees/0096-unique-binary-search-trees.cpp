class Solution {
public:
    int func(int k){
    //base case
    if(k<=1)return 1;

    int ways=0;
    for(int i=1;i<=k;i++){
        ways+= func(i-1)* func(k-i);
    }
    return ways;
}

int numTrees(int n){
    return func(n);
}
};