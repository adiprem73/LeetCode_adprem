class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> hashA(n+1,0);
    vector<int> hashB(n+1,0);

    // for(int i: A){
    //     hashA[i]++;
    // }

    // for(int i: B){
    //     hashB[i]++;
    // }
    int cnt=0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        hashA[A[i]]++;
        hashB[B[i]]++;
        if(A[i]== B[i]){
            cnt++;
        }else{
            if(hashA[B[i]]!=0){
            cnt++;
        }
        if (hashB[A[i]] != 0){
            cnt++;
        }
        }
        
            ans.push_back(cnt);
    }
    return ans;
}
};