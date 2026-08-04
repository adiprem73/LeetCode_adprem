class Solution {
public:
    

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        vector<int> used(wordList.size());
        // we wil need to use BFS for this problem
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        unordered_set<string>st(wordList.begin(), wordList.end());
        while (!q.empty()) {
            auto [steps, word] = q.front();
            q.pop();

            // base case
            if(word == endWord){
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    char temp = word[i];
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({steps+1, word});
                        st.erase(word);
                    }
                    word[i] = temp;
                }
            }
        }

        return 0;
    }
};