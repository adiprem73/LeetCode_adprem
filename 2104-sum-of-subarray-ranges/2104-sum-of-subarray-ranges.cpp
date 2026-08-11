class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // FOR THIS questions we will need to find the nse, pse, nge and pge all four arrays
        int n = nums.size();
        vector<int> nse(n), pse(n), nge(n), pge(n);
        // finding the pse
        pse[0] = -1;
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty())pse[i] =-1;
            else pse[i] = st.top();
            st.push(i);
        }

        // finding nse
        nse[n-1]=-1;
        st={};
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty())nse[i] =-1;
            else nse[i] = st.top();
            st.push(i);
        }

        // finding pge
        pge[0]=-1;
        st={};
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty())pge[i] = -1;
            else pge[i] = st.top();
            st.push(i);
        }

        // finding nge
        nge[n-1]=-1;
        st={};
        st.push(n-1);
        for(int i=n-2; i>=0 ; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            if(st.empty()) nge[i] =-1;
            else nge[i] = st.top();
            st.push(i);
        }

        // for(int i=0;i<n;i++){
        //     cout<<pse[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<nse[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<pge[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<nge[i]<<" ";
        // }
        // cout<<endl;

        // finding the subarray minimum sum
        long long  smin=0;
        for(int i=0;i<n;i++){
            int cntL=0, cntR=0;
            if(pse[i] == -1){
                cntL = i+1;
            }else{
                cntL = i- pse[i] ;
            }

            if(nse[i] == -1){
                cntR = n-i;
            }

            else{
                cntR = nse[i] - i;
            }
            smin += (1LL * cntL * cntR)*nums[i];
        }

        cout<<smin<<endl;

        // finding the subarray maximum sum
        long long smax =0;
        for(int i=0;i<n;i++){
            int cntL=0, cntR=0;
            if(pge[i] == -1){
                cntL = i+1;
            }else{
                cntL = i- pge[i] ;
            }

            if(nge[i] == -1){
                cntR = n-i;
            }

            else{
                cntR = nge[i] - i ;
            }
            smax += (1LL * cntL * cntR)*nums[i];
        }

        cout<<smax<<endl;

        long long ans = smax - smin;
        return ans;

    }
};