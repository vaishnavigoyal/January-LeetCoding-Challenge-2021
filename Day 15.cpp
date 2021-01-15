// Day 15
// Question : Get Maximum in Generated Array

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        vector<int> arr(n+1);
        arr[0]=0;
        arr[1]=1;
        int i=1;
        while(i<=n/2)
        {
            if(2*i<=n)
            {
                arr[2*i]=arr[i];
            }
            if(2*i+1<=n)
            {
                arr[2*i+1]=arr[i]+arr[i+1];
            }
            i++;
        }
        return *max_element(arr.begin(),arr.end());

    }
};
