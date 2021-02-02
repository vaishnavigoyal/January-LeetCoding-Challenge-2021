// Day 28
// Question : Smallest String With A Given Numeric Value

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string res;
        while (k > 0)
        {
            for (int i = 1; i <= 26; i++)
            {
                if ((k - i) <= ((n - 1) * 26))
                {
                    res += (char)(i + 96);
                    k -= i;
                    break;
                }
            }
            n--;
        }
        return res;
    }
};
