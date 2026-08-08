class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // we will use a bfs approach since it will automatically give the shortest number of steps
        unordered_set<string> st(wordList.begin(), wordList.end());
        // (steps, word),
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        while(!q.empty()){
            auto [steps, word] = q.front();
            q.pop();
            if(word == endWord) return steps;
            for(int i=0;i<word.length();i++){
                char temp = word[i];
                for(char ch = 'a'; ch <= 'z';ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){
                        st.erase(word);
                        q.push({steps+1, word});
                    }
                }
                word[i] = temp;
            }
        }
        return 0;
    }
};