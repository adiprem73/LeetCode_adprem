class Solution {
public:
   bool func(int ind, vector<int> &arr, vector<bool>& vis)
{
    int n = arr.size();
    if (ind >= n || ind < 0)
    {
        return false;
    }
    if (arr[ind] == 0)
    {
        return true;
    }

    bool forward = false, backward = false;


    if(ind+arr[ind] < n && vis[ind+ arr[ind]]==false){
        vis[ind + arr[ind]]= true;
        forward = func(ind + arr[ind], arr, vis);
    }
    // cout<<"ind :"<<ind<<endl;

    if (ind - arr[ind] >= 0 && vis[ind - arr[ind]] == false)
    {
        // cout<<"hello"<<endl;
        vis[ind - arr[ind]] = true;
        backward = func(ind - arr[ind], arr, vis);
    }

    return forward || backward;
}

bool canReach(vector<int> &arr, int start)
{
    int n = arr.size();
    vector<bool> vis(n);
    return func(start, arr, vis);
}
};