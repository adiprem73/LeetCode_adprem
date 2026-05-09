class Solution {
public:
    int minJumps(vector<int> & nums){
    int n = nums.size();
    int mx =0;
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        mx = max(mx, nums[i]);
        mp[nums[i]].push_back(i);
    }
    
    // seieve of eratosthenes
    vector<bool> prime(mx+1, true);
    for(int i=2;i*i<=mx;i++){
        if (prime[i])
        {
            for (int j = i * i; j <= mx; j += i)
            {
                prime[j] = false;
            }
        }
    }
    prime[1]= false;
    prime[0]= false;
    // cout<<"hello"<<endl;
    // for(int i=0;i<=mx;i++){
    //     cout<<i<<" : "<<prime[i]<<endl;
    // }

    // there is no need to make the adjacent vector. we will just do it in runtime

    unordered_set<int> usedPrime;
    queue<int> q;
    vector<bool> vis(n, false);
    vis[0]= true;
    q.push(0); //source inserted
    int steps=0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int curr = q.front();
            q.pop();
            if (curr == n - 1)
            {
                return steps;
            }

            if(curr+1<n && vis[curr+1]==false){
                q.push(curr+1);
                vis[curr+1]= true;
            }
            if (curr - 1 >=0 && vis[curr - 1] == false)
            {
                q.push(curr - 1);
                vis[curr - 1] = true;
            }

            if(prime[nums[curr]]){
                // cout<<"prime curr : "<<curr<<endl;
                int p = nums[curr];
                if(prime[p] && !usedPrime.count(p)){
                    usedPrime.insert(p);
                    for (int m = p; m <= mx; m += p)
                    {
                        if (mp.count(m) > 0)
                        {
                            for (auto it : mp[m])
                            {
                                if (vis[it] == false)
                                {
                                    q.push(it);
                                    vis[it] = true;
                                }
                            }
                        }
                    }
                }
                
            }
        }
        steps++;
    }
    return -1;
}
};