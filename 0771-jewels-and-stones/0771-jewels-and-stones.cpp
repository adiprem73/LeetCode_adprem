class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
{
    unordered_map<char, int> j;
    for(char ch: jewels){
        j[ch]++;
    }
    int cnt = 0;
    for(char ch: stones){
        if(j.count(ch)!=0)cnt++;
    }
    return cnt;
}
};