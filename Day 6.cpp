// Day 6
// Question : Kth Missing Positive Number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x=1,i=0,n=arr.size();
        while(k!=0&&i<n)
        {
            if(arr[i]==x)
            {
                i++;
                x++;
            }
            else
            {
                k--;
                x++;
            }
        }
        while(k!=0)
        {
            x++;
            k--;
        }
        return --x;
    }
};
