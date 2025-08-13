class Solution {
public:
    unordered_map<string, int> mpp;   // shortest distance from beginWord
vector<vector<string>> ans;       // all shortest paths
string beginWordGlobal;

void dfs(string word, vector<string> &seq) {
    if (word == beginWordGlobal) {
        vector<string> path = seq;
        reverse(path.begin(), path.end());
        ans.push_back(path);
        return;
    }
    int steps = mpp[word];
    int sz = word.size();

    for (int i = 0; i < sz; i++) {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (ch == original) continue;          // avoid no-op
            word[i] = ch;
            auto it = mpp.find(word);
            if (it != mpp.end() && it->second + 1 == steps) {
                seq.push_back(word);
                dfs(word, seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    // reset globals
    mpp.clear();
    ans.clear();

    unordered_set<string> st(wordList.begin(), wordList.end());
    if (!st.count(endWord)) return {}; // endWord must be in wordList for a valid ladder

    beginWordGlobal = beginWord;
    st.erase(beginWord);               // CRITICAL: don't revisit the start as a "dictionary" word

    queue<string> q;
    q.push(beginWord);
    mpp[beginWord] = 1;                // distance starts at 1 (beginWord itself)
    int sz = beginWord.size();

    bool foundEnd = false;

    // BFS to fill mpp with shortest distances
    while (!q.empty() && !foundEnd) {
        int levelSize = q.size();
        unordered_set<string> toErase;

        for (int k = 0; k < levelSize; k++) {
            string cur = q.front(); q.pop();
            int steps = mpp[cur];

            for (int i = 0; i < sz; i++) {
                char original = cur[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;  // avoid self-loop
                    cur[i] = ch;
                    if (st.count(cur) && !mpp.count(cur)) {
                        mpp[cur] = steps + 1;
                        q.push(cur);
                        toErase.insert(cur);
                        if (cur == endWord) foundEnd = true;
                    }
                }
                cur[i] = original;
            }
        }
        for (auto &w : toErase) st.erase(w);
    }

    if (!mpp.count(endWord)) return {}; // unreachable

    // DFS backtrack from endWord using mpp distances
    vector<string> seq = { endWord };
    dfs(endWord, seq);
    return ans;
}
};