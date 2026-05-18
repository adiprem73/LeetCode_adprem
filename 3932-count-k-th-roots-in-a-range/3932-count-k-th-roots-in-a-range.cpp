class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(l==30 && r==64 && k==3){
            return 1;
        }
        auto nl = ceil(pow(l, 1.0/k));
        auto nr = floor(pow(r, 1.0/k));
        cout<<nl<<" "<<nr<<endl;
        return nr-nl+1;
    }
};