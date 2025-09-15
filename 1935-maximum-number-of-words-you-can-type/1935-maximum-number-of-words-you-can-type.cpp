class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    //create hashtables for each word
    vector<int> hashBroken(26,0);
    for(char ch: brokenLetters){
        // cout << "hello" << endl;
        hashBroken[ch-'a']++;
    }
    // vprint(hashBroken);
    text=text+' ';
    int cnt=0;
    vector<int> hashWord(26,0);
    bool flag= false;
    for(char ch: text){
        // cout<<ch<<endl;
        if(ch==' '){
            if(flag==false){
                cnt++;
            }
            flag=false;
        }else{
            // cout<<"hello"<<endl;
            if(hashBroken[ch-'a']!=0){
                // cout<<"hello"<<endl;
                flag= true;
            }
        }
    }
    return cnt;
}
};