class Solution {
public:
    int minimumPushes(string word) {
    map<char,int> mp;
    int len=word.length();
    for(int i=0;i<len;i++){
        mp[word[i]]++;
    }
    int count=0;
    int ans=0;
    for(auto it:mp){
        count++;
        if(count<=8){
            ans=ans+(it.second);
        }
        else if(count>8&&count<=16){
            ans=ans+(it.second*2);
        }
        else if(count>16&&count<=24){
            ans=ans+(it.second*3);
        }
        else{
            ans=ans+(it.second*4);
        }
    }
    return ans;
}

};