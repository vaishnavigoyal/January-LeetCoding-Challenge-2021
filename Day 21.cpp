// Day 21
// Question : Find the Most Competitive Subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int to_del=nums.size()-k;
        for(int i=0;i<nums.size();i++)
        {
            while(!res.empty()&&nums[i]<res.back()&&to_del)
            {
                res.pop_back();
                to_del--;
            }
            res.push_back(nums[i]);
        }
        return vector<int>(res.begin(),res.begin()+k);
    }
};
