// Day 11
// Question : Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
        {
            return;
        }
        if(m==0)
        {
            nums1=nums2;
            return;
        }
        int i=0,j=0;
        nums1.resize(m);
        while(i<nums1.size()&&j<n)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1.insert(nums1.begin()+i,nums2[j]);
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        while(j<n)
        {
            nums1.insert(nums1.begin()+i,nums2[j]);
            i++;
            j++;
        }
        return;
    }
};
