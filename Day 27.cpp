// Day 27
// Question : Concatenation of Consecutive Binary Numbers

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        long long res = 1;
        int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++)
        {
            int x = log2(i) + 1;
            res = (res << x) % mod;
            res += i;
            res %= mod;
        }
        return res % mod;
    }
};