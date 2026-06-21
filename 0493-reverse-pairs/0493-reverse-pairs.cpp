class Solution {
public:
    int merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int cnt = 0;

    vector<int> A(n1);
    vector<int> B(n2);
    
    for (int i = 0; i < n1; i++)
    {
        A[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        B[i] = arr[mid + 1 + i];
    }

    int j=0;
    int tempCnt=0;
    for(int i=0;i<n1;i++){
        while(j<n2 && ((long long)arr[left+i]> 2LL*arr[mid+1+j])){
            tempCnt++;
            j++;
        }
        cnt+=tempCnt;
    }

    int i = 0, k = left;
    j=0;
    // merge
    while (i < n1 && j < n2)
    {
        if (A[i] <= B[j])
        {
            arr[k++] = A[i++];
        }

        else
        {
            arr[k++] = B[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = A[i++];
    }

    while (j < n2)
    {
        arr[k++] = B[j++];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int left, int right)
{
    int cnt = 0;
    if (left >= right)
        return cnt;
    int mid = (left + right) / 2;

    cnt += mergeSort(arr, left, mid);
    cnt += mergeSort(arr, mid + 1, right);
    cnt += merge(arr, left, mid, right);
    return cnt;
}

int reversePairs(vector<int> nums)
{
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
}
};