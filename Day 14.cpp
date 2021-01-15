// Day 14
// Question : Minimum Operations to Reduce X to Zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int i=0,sum=0;
        while(i<n&&sum<x)
        {
            sum+=nums[i];
            i++;
        }
        if(i==n)
        {
            return sum==x?n:-1;
        }
        int l=i-1,r=n-1;
        int res=sum==x?i:INT_MAX;
        while(l<r)
        {
            if(sum>=x&&l>=0)
            {
                sum-=nums[l--];
            }
            if(sum<x)
            {
                sum+=nums[r--];
            }
            if(sum==x)
            {
                res=min(res,n+l-r);
            }
            if(sum>=x&&l<0)
            {
                break;
            }
        }
        return res==INT_MAX?-1:res;
    }
};
