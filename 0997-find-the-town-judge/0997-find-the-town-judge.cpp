class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> score(n+1);
    for(auto it: trust){
        score[it[1]]++;
        score[it[0]]--;
    }
    for(int i=1;i<n+1;i++){
        if(score[i]==n-1)return i;
    }return -1;
}
};