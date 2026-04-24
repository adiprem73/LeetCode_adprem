class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
    map<char,int> mp;
    // mp['L']=0;
    // mp['R']=0;
    // mp['_']=0;
    for(auto ch: moves){
        mp[ch]++;
    }       
    if(mp['L']>=mp['R']){
        return mp['L']-mp['R']+mp['_'];
    }
    if (mp['L'] < mp['R'])
    {
        return mp['R'] - mp['L'] + mp['_'];
    }
    // mprint(mp);
    return 0;
}
};