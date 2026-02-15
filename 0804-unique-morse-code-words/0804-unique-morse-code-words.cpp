class Solution {
public:
   int uniqueMorseRepresentations(vector<string> &words)
{
    unordered_map<char, string> morse = {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}};
    set<string> st;
    for(auto it: words){
        string w="";
        for(auto ch: it){
            w+=morse[ch];
        }
        st.insert(w);
    }
    return st.size();
}
};