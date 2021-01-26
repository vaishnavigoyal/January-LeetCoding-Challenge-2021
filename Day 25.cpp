// Day 25
// Question : Check If All 1's Are at Least Length K Places Away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pos=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                pos=i;
                break;
            }
        }
        if(pos!=-1)
        {
            for(int i=pos+1;i<nums.size();i++)
            {
                if(nums[i]==1)
                {
                    if(i-pos-1<k)
                    {
                        return false;
                    }
                    else
                    {
                        pos=i;
                    }
                }
            }
            return true;
        }
        return true;
    }
};
