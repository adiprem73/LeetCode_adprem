class Solution {
public:
    bool isHappy(int n) {
        // the key thing to note here is that loop will only happen when a number that we started with or come across is visited again

        vector<int> visit;
        int i=n;
        while (true){
            int sum=0;
            while(i>0){
                int d=i%10;
                sum=sum+(d*d);
                i=i/10;
            }
            // cout<<sum<<endl;
            if(sum==1){
                return true;
            }
            if(find(visit.begin(), visit.end(), sum)!=visit.end()){
                return false;
            }
            visit.push_back(sum);
            i=sum;
        }
        
    }
};