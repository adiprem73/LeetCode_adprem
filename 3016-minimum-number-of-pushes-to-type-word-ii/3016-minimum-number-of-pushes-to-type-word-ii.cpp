class Solution {
public:
   int minimumPushes(string word)
{
    int n = word.length();
    map<char,int> mp;
    for(auto it: word){
        mp[it]++;
    }
    vector<char> characters;
    for(auto it: mp){
        characters.push_back(it.first);
    }
    sort(characters.begin(), characters.end(), [&](char ch1, char ch2){
        if(mp[ch1]==mp[ch2]){
            return ch1>ch2;
        }else{
            return mp[ch1]>mp[ch2];
        }
    });
    int size = characters.size();
    // 0-7  8-15  16-23  24-25
    vector<int> temp(size);
    for(int i=0;i<size;i++){
        if(i>23){
            temp[i]=4;
        }else if(i>15){
            temp[i]=3;
        }else if(i>7){
            temp[i]=2;
        }else{
            temp[i]=1;
        }
    }
    int ans=0;
    for(int i=0;i<size;i++){
        ans+=mp[characters[i]]*temp[i];
    }
    return ans;
}
};