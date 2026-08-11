class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // finding the nse and pse of vector in indexes
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n), nse(n);

        int MOD = 1e9+7;
        
        // finding the pse
        pse[0] = -1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        // find the nse
        nse[n-1]=-1;
        stack<int> st1;
        st1.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st1.empty() && arr[st1.top()] > arr[i]){
                st1.pop();
            }
            nse[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);
        }

        // for(int i=0;i<n;i++){
        //     cout<<pse[i] <<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<nse[i] <<" ";
        // }
        cout<<endl;
        long long ans=0;
        for(int i=0;i<n;i++){
            int cntL=0, cntR =0;
            if(pse[i] == -1){
                cntL = i-0+1;
            }else{
                cntL = i-pse[i];
            }

            if(nse[i] == -1){
                cntR = n-i;
            }else{
                cntR = nse[i] - i;
            }

            // cout<<"index : "<<cntL<<" "<<cntR<<endl;

            ans = (ans + ((cntL * 1LL * cntR) % MOD) * arr[i]) % MOD;
        }

        return (int)ans;
    }
};