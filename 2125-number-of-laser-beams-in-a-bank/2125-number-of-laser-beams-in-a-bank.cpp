class Solution {
public:
    int numberOfBeams(vector<string> &bank)
    {
        vector<int> devices;
        for (string s : bank)
        {
            int cnt = 0;
            for (char ch : s)
            {
                if (ch == '1')
                {
                    cnt++;
                }
            }
            devices.push_back(cnt);
        }
        // vprint(devices);
        int ind=-1;
        for(int i=0;i<devices.size();i++){
            if(devices[i]!=0){
                ind=i;
                break;
            }
        }
        // cout<<i<<endl;
        if (ind == -1)
        {
            return 0;
        }
        int count = 0;
        int current = devices[ind];
        ind++;
        // cout<<current<<endl;
        // cout << "hello" << endl;

        while (ind < devices.size())
        {
            if (devices[ind] == 0)
            {
            }
            else
            {
                count += devices[ind] * current;
                current = devices[ind];
            }
            // cout<<"count : "<<count<<endl;
            ind++;
        }
        return count;
    }
};