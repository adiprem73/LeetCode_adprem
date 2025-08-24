class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    sort(letters.begin(), letters.end());
    char temp=letters[0];
    bool flag= false;
    for(auto it: letters){
        if(it>target){
            return it;
        }
    } return temp; 
}
};