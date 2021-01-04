// Day 1
// Question : Check Array Formation Through Concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> mp;
        for(int i=0;i<pieces.size();i++)
        {
            mp[pieces[i][0]]=i;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(arr[i])!=mp.end())
            {
                int j=mp[arr[i]];
                if(pieces[j].size()>1)
                {
                    int k=1;
                    i++;
                    while(i<arr.size()&&k<pieces[j].size())
                    {
                        if(arr[i]!=pieces[j][k])
                        {
                            return false;
                        }
                        k++;
                        i++;
                    }
                    i--;
                    if(k!=pieces[j].size())
                    {
                        return false;
                    }
                }
                mp.erase(arr[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
