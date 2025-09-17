class FoodRatings
{


private:
    struct Compare
    {
        bool operator()(const pair<int, string> &a,
                        const pair<int, string> &b) const
        {
            if (a.first != b.first)
                return a.first < b.first; // larger int first
            return a.second > b.second;   // lexicographically smaller string first
        }
    };
map <string, vector<pair<int,string>>> data;
map <string, priority_queue <pair<int,string>, vector<pair<int, string>>, Compare > > underlyingData;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n=foods.size();
        for(int i=0;i<n;i++){
            data[cuisines[i]].push_back({ratings[i], foods[i]});
            underlyingData[cuisines[i]].push({ratings[i], foods[i]});
        }
        
    }

    void changeRating(string food, int newRating)
    {
        string cuisine="";
        bool flag = true;
        for(auto &it: data){
            // it.second is the vector of pair
            for(int i=0;i<it.second.size();i++){
                auto pr= it.second[i];
                if(pr.second==food){
                    // cout<<"food found"<<endl;
                    // cout<<pr.first<<" "<<pr.second<<endl;
                    it.second.erase(it.second.begin()+ i); //pair removed
                    it.second.push_back({newRating, food});
                    // cout << endl;
                    // for(int i=0;i<it.second.size();i++){
                    //     cout<<it.second[i].first<<" "<<it.second[i].second<<endl;
                        
                    // }
                    // cout << endl;
                    //now we have saved the changes in the data but we also need to change the underlying data
                    cuisine= it.first;
                    flag= false;
                    break;
                }
            }
            if(flag== false){
                break;
            }
            //now we know that the changes is to be done in th cuisine 
        }
        if(flag== false){
            //remove everytingg fromt he priority queue:
            // priority queue is underlyingData[cuisine]
            while(!underlyingData[cuisine].empty()){
                underlyingData[cuisine].pop();
            }
            for(auto it: data[cuisine]){
                // cout<<it.first<<" "<<it.second<<endl;
                // here it will be a pair
                underlyingData[cuisine].push(it);
            }
        }


    }

    string highestRated(string cuisine)
    {
        auto it= underlyingData[cuisine].top();
        return it.second;
    }
};