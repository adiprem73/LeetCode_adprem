class Solution {
public:
    int findKthPositive(vector<int> &arr, int k)
{
    int cnt=0;
    int e= *max_element(arr.begin(), arr.end());
    vector<int> missing;
    for(int i=1;i<e;i++){
        if(find(arr.begin(), arr.end(), i) == arr.end()){
            missing.push_back(i);
            cnt++;
        }
    }
    if(cnt>=k){
        return missing[k-1];
    }else{
        int temp=k-cnt;
        return e+temp;
    }   
}
};