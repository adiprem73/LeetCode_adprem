class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque <int> dq;
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        // cout<<"for "<<i<<" : "<<endl;
        // printdq(dq);

        //kya window filled hai. agar filled hai to hi naa saamne wala element ko nikaalenge
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }


        //this makes sur ethat the front of a window always has windo's maximum.
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        
        dq.push_back(i);

        //we have completed the window
        if(i>=k-1){

            //this time this will only be the maximum. if this weren;t the max, it would have already been removed
            ans.push_back(nums[dq.front()]);
        }
        
    }
    return ans;
}
};