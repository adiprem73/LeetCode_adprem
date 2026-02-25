class Solution {
public:
    int func(int n){
    int cnt=0;
    while(n>0){
        int x = n%2;
        if(x==1){
            cnt++;
        }
        n=n/2;
    }
    return cnt;
}

vector<int> sortByBits(vector<int>& arr) {
    unordered_map<int, int> bitsCnt;
    for(auto it: arr){
        bitsCnt[it] = func(it);
    }
    sort(arr.begin(), arr.end(), [&](int a , int b){
        if(bitsCnt[a] != bitsCnt[b])return bitsCnt[a]<bitsCnt[b];
        else return a<b;
    });
    return arr;
}
};

