class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            string word= it.first;
            int steps= it.second;
            if(word==endWord)return steps;
            for(int i=0;i<word.size();i++){
                char og= word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i]= og; // revert back to the base case
            }
            
        }
        return 0;
    }
};