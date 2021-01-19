// Day 18
// Question : Max Number of K-Sum Pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>0)
            {
                mp[nums[i]]--;
                if(mp[k-nums[i]]>0)
                {
                    res++;
                    mp[k-nums[i]]--;
                }
                else
                {
                    mp[nums[i]]++;
                }
            }
        }
        return res;
    }
};
