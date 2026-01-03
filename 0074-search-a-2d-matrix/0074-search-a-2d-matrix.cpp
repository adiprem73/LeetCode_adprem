class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n= matrix.size();
    if(!n)return false;
    int m= matrix[0].size();

    // now we need to perform binary search from 0 to m*n-1

    int s=0;
    int e=m*n-1;
    while(s<=e){
        int mid= s+(e-s)/2;

        int row= mid/m;
        int col= mid%m;

        int element = matrix[row][col];
        if(element == target)return true;
        else if(element <target){
            s=mid+1;
        }else {
            e=mid-1;
        }
    }
    return false;
    
}
};