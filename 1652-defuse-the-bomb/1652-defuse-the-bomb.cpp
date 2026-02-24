class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k){
    int n = code.size();
    vector<int> ans (n, 0);
    if(k==0){
        return ans;
    }
    if(k>0){
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=1;j<=k;j++){
                int ind = (i+j)%n;
                sum+= code[ind];
            }
            ans[i] = sum;
        }
    }
    else if(k<0){
        k = -1 * k;
        for (int i = 0; i < n; i++)
        {
            // cout << "hello" << endl;
            int sum = 0;
            
            for (int j = 1; j <= k; j++)
            {

                int ind = (i - j + n) % n;
                sum += code[ind];
            }
            ans[i] = sum;
        }
    }
    return ans;
}
};