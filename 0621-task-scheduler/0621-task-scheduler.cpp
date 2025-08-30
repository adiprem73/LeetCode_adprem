class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    map<char,int> mp;
    for(auto it: tasks){
        mp[it]++;
    }

    priority_queue<pair<int, char>> pq;
    for(auto it: mp){
        pq.push({it.second, it.first});
    }
    int cnt=0;

    while(!pq.empty()){
        vector<pair<int, char>> temp;  //this stores the pairs which still ahe freq left so that we can push them back in the pq after the cycle completes
        int cycle=n+1; //if n=2, then three tasks can be schedules inside the sma ecycle since this way the distance bwteen two same tasks will be atleast 2

        while(cycle>0 && !pq.empty()){
            auto it= pq.top(); 
            pq.pop();

            cnt++; 
            it.first--;

            if(it.first>0) temp.push_back(it);

            cycle--;
        }

        for(auto t: temp)pq.push(t); //here we push the elements of the temp back into the pq

        if (!pq.empty())cnt+=cycle;
    }
    return cnt;
    
}
};