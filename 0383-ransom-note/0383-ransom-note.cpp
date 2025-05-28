class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    map<char,int> ranmap;
    map<char,int> magmap;
    for(int i=0;i<ransomNote.length();i++){
        ranmap[ransomNote[i]]++;
    }
    for(int i=0;i<magazine.length();i++){
        magmap[magazine[i]]++;
    }
    bool ans=true;
    for (auto it:ranmap){
        if(magmap.find(it.first)==magmap.end()){
            ans=false;
            break;
        }
        if(magmap[it.first]<it.second){
            ans=false;
            break;
        }
    }
    return ans;
}
};