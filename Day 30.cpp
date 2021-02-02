// Day 30
// Question : Minimize Deviation in Array

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int minn = INT_MAX, maxx = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                nums[i] *= 2;
            }
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
        }
        int ans = maxx - minn;
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        while ((pq.top()) % 2 == 0)
        {
            int top = pq.top();
            pq.pop();
            ans = min(ans, top - minn);
            top /= 2;
            minn = min(minn, top);
            pq.push(top);
        }
        ans = min(ans, pq.top() - minn);
        return ans;
    }
};
