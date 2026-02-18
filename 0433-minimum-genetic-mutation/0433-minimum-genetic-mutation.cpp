class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
{
    unordered_set<string>st (bank.begin(), bank.end());

    queue<pair<string,int>> q;
    q.push({startGene, 0});
    vector<char> ch  = {'A', 'C', 'G', 'T'};
    while(!q.empty()){
        auto [gene, steps] = q.front();
        q.pop();
        if(gene == endGene){
            return steps; // base case
        }

        for(int i=0;i<8;i++){
            string temp = gene;
            for(auto chr: ch){
                temp[i] = chr;
                if(st.count(temp)){
                    q.push({temp, steps+1});
                    st.erase(temp);
                }
            }
        }
    }
    return 0;
}
};