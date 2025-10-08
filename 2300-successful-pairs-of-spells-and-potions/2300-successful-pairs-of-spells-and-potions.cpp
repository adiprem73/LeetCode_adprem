class Solution {
public:
   vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    int n = spells.size();
    int m = potions.size();
    vector<int> pairs(n);
    sort(potions.begin(), potions.end());
    for(int i=0;i<n;i++){
        long long val= spells[i];
        long long target= (success + val -1)/ val;
        // cout<<"tagert : "<<target<<endl; //7
        // now we will search for this element using binary search
        int s=0;
        int e=m;
        while(s<e){
            // cout<<"s : "<<s<<" e : "<<e<<endl;
            int mid= s+(e-s)/2;
            if(potions[mid]<target){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        // cout<<"found at : "<<s<<endl;
        pairs[i]= m-s;
    }
    return pairs;
}
};