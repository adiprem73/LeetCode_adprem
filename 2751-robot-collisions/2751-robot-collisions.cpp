class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    
    vector<tuple<int,int,char,int>> robots;
    for(int i=0;i<n;i++){
        robots.push_back({positions[i], healths[i], directions[i], i});
    }
    
    sort(robots.begin(), robots.end()); // sort by position
    
    stack<int> st; // indices in robots
    
    for(int i=0;i<n;i++){
        auto &[pos, health, dir, idx] = robots[i];
        
        if(dir == 'R'){
            st.push(i);
        } 
        else {
            while(!st.empty() && health > 0){
                auto &[pos2, health2, dir2, idx2] = robots[st.top()];
                
                if(health2 < health){
                    health--;
                    health2 = 0;
                    st.pop();
                }
                else if(health2 > health){
                    health2--;
                    health = 0;
                }
                else{
                    health = 0;
                    health2 = 0;
                    st.pop();
                }
            }
        }
    }
    
    vector<int> ans(n, -1);
    for(auto &[pos, health, dir, idx] : robots){
        if(health > 0){
            ans[idx] = health;
        }
    }
    
    vector<int> res;
    for(int i=0;i<n;i++){
        if(ans[i] != -1) res.push_back(ans[i]);
    }
    
    return res;
}
};