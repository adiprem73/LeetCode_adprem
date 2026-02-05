class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn){
    // using a lamda function
    auto countSB = [](int n)
    {
        int cnt=0;
        while (n > 0)
        {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    };

    auto convertString = [](int n){
        if(n<10){
            return "0"+to_string(n);
        }else{
            return to_string(n);
        }
    };

    vector<string> ans;
    for(int i=0;i<12;i++){
        for(int j=0;j<60;j++){
            if(countSB(i)+ countSB(j) == turnedOn){
                ans.push_back(to_string(i)+":"+convertString(j));
            }
        }
    }
    return ans;
}
};