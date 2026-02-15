class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> (n, vector<int>(n));
        int i=0;
        int j=0;
        for(auto it: commands){
            if(it== "UP"){
                i--;
            }else if(it == "DOWN"){
                i++;
            }else if(it == "RIGHT"){
                j++;
            }else {
                j--;
            }
        }
        return (i*n)+j;
    }
};