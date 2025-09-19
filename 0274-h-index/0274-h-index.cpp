class Solution {
public:
    int hIndex(vector<int> & citations){
    sort(citations.rbegin(), citations.rend());
    int mini=INT_MAX;
    int hindex;
    for(int i=0;i<citations.size();i++){
        mini=min(mini, citations[i]);
        if(mini<i+1){
            hindex=i;
            break;
        }
    }
    return hindex;
}
};