class Solution {
public:
    string reverseByType(string s) {
    string letters, special;

    for(char c : s){
        if(isalpha(c))
            letters += c;
        else
            special += c;
    }

    reverse(letters.begin(), letters.end());
    reverse(special.begin(), special.end());

    string ans;
    int i=0, j=0;

    for(char c : s){
        if(isalpha(c))
            ans += letters[i++];
        else
            ans += special[j++];
    }

    return ans;
}
};