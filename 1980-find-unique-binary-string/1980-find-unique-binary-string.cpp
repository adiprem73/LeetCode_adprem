class Solution {
public:
    string findDifferentBinaryString(vector<string> & nums){
    int n= nums.size();
    string s = "";
    int j=0; // the basic ideas is the in our new string we will differ each character from each of the string in nums. this will work because the lenght of nums and the lenght of eachs ring in nums is the same = n
    for(int i=0;i<n;i++){
        if(nums[i][j] == '0') s+='1';
        else s+='0';
        j++;
    }return s;
}

};