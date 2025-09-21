class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int> mp;
        for(int i=0;i<candyType.size();i++){
            mp[candyType[i]]++;
        }
        int diff=mp.size();
        if(diff  >=  candyType.size()/2){
            return candyType.size()/2;
        }else{
            return diff;
        }
    };
};