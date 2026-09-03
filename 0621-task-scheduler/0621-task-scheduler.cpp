class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // greedily we decide that the one with the most frequency, we will need to process those tasks first, so that they dont accumulate at the last and increase the overall time.
        int len = tasks.size();
        unordered_map<int,int> mp;
        for(int i=0;i<len;i++){
            mp[tasks[i]] ++;
        }
        // we will need a max_heap
        priority_queue<int> pq;
        int time =0;
        for(auto it: mp){
            pq.push(it.second);
        }
        while(!pq.empty()){

            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int & f: temp){
                if(f>0)pq.push(f);
            }

            if(pq.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }
        }

        return time;
        
    }
};