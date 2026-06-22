class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto it: text){
            mp[it] ++ ;
        }

        int cnt=0;
        while(true){
            if(mp['b']>=1 && mp['a']>=1 && mp['l']>=2&& mp['o']>=2 && mp['n']>=1){
                cnt++;
                mp['b']-=1;
                mp['a']-=1;
                mp['n']-=1;
                mp['l']-=2;
                mp['o']-=2;
            }else{
                break;
            }
        }
        return cnt;
    }
};