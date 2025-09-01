class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (auto it : nums)
        {
            if (pq.size() < k)
            {
                pq.push(it);
            }
            else
            {
                if (it > pq.top())
                {
                    pq.pop();
                    pq.push(it);
                }
            }
        }
    }

    int add(int val)
    {
        if (pq.size() >= K)
        {
            if (val > pq.top())
            {
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }
        else{
            pq.push(val);
        }
        return pq.top();
    }
};