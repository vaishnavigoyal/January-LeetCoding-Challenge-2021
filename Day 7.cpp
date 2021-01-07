// Day 7
// Question : Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0,temp=0;
        set<char> st;
        int i=0,j=0;
        while(j<s.length())
        {
            if(st.find(s[j])==st.end())
            {

                st.insert(s[j++]);
                len=max(len,j-i);
            }
            else
            {
                st.erase(s[i++]);
            }
        }
        return len;
    }
};
