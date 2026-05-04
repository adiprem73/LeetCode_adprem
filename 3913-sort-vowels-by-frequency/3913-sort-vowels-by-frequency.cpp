class Solution {
public:
    string sortVowels(string s) {
    int n = s.length();
    string vowels = "";
    map<char,int> mp;
    map<char,int> first_ind;
    for(int i=0;i<n;i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
            vowels+=s[i];
            mp[s[i]]++;
            if(first_ind.count(s[i])==0){
                first_ind[s[i]] = i; //  to store the very first index only
            }
        }
    }       
    sort(vowels.begin(), vowels.end(), [&](char ch, char ch1){
        if(mp[ch] == mp[ch1])return first_ind[ch]<first_ind[ch1];
        return mp[ch]>mp[ch1];
    });
    int x=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            s[i] = vowels[x];
            x++;
        }
    }
    return s;
}
};