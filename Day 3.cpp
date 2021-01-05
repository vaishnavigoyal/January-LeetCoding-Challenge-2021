// Day 3
// Question : Beautiful Arrangement

class Solution {
public:
    void possible(int n,int pos,vector<bool> &vis,int &res)
    {
        if(pos>n)
        {
            res++;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false&&(i%pos==0||pos%i==0))
            {
                vis[i]=true;
                possible(n,pos+1,vis,res);
                vis[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        int res=0;
        vector<bool> vis(n+1,false);
        possible(n,1,vis,res);
        return res;

    }
};
