class Solution {
public:
    int wordCount(string s){
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            count++;
        }
    }
    // cout<<count+1;
    return count+1;
}


int mostWordsFound(vector<string>& sentences) {
    int ans=0;
    for(int i=0;i<sentences.size();i++){
        ans=max(ans,wordCount(sentences[i]));
        // cout<<wordCount(sentences[i]);
        // cout<<"ans : "<<ans<<endl;
    }
    return ans;
}
};