// Day 22
// Question : Determine if Two Strings Are Close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> mp1;
        unordered_map<int,int> mp2;
        unordered_map<char,int> mp3;
        set<char> s1;
        set<char> s2;

        for(int i=0;i<word1.length();i++)
        {
            mp1[word1[i]]++;
            s1.insert(word1[i]);
        }
        for(auto it=mp1.begin();it!=mp1.end();it++)
        {
            mp2[it->second]++;
        }
        for(int i=0;i<word2.length();i++)
        {
            mp3[word2[i]]++;
            if(s1.find(word2[i])==s1.end())
            {
                return false;
            }
        }
        for(auto it=mp3.begin();it!=mp3.end();it++)
        {
            if(mp2[it->second]>0)
            {
                mp2[it->second]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
