class Solution {
public:
    int minimumIndex(vector<int> &nums)
{
    // find the dominant number
    int n = nums.size();
    map<int,int> mp;
    for(int i=0;i<n ;i++){
        mp[nums[i]]++;
    }
    int x=-1, f=-1;
    for(auto it: mp){
        if(it.second > n/2){
            x = it.first;
            f = it.second;
        }
    }
    if(x==-1){
        return -1; // if htere is not odminant elelment then most proabbly ther eis not oing to be one even if we splot
    }

    // cout<<"x : "<< x<<endl;
    map<int,int> mp2;
    for(int i=0;i<n;i++){
        mp2[nums[i]]++ ;
        // cout<<" For i = "<<i <<endl
        // mprint(mp2);
        if(mp.count(x)>0){
            int f1 = mp2[x];
            int f2 = f-f1;
            int l1= i+1;
            int l2 = n-i-1;
            // cout<<"f1 : "<<f1<<endl;
            // cout << "f2 : " << f2 << endl;
            // cout << "l1 : " << l1 << endl;
            // cout << "l2 : " << l2 << endl;
            if((f1 > l1/2) && (f2 > l2/2)){
                return i;
            }
        }
    }
    return -1;
}
};