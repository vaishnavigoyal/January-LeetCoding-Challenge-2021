// Day 31
// Question : Next permutation

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), idx = -1;
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                idx = i - 1;
                break;
            }
        }
        if (idx != -1)
        {
            int i = n - 1;
            while (nums[i] <= nums[idx])
            {
                --i;
            }
            swap(nums[i], nums[idx]);
        }
        int j = n - 1;
        int i = idx + 1;
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
    }
};
