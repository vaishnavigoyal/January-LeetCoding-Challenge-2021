// Day 26
// Question : Path With Minimum Effort

class Solution {
public:
    int n,m;
    bool vis[101][101];
    bool bfs(vector<vector<int>>& heights,int k)
    {
        memset(vis,false,sizeof(vis));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            vis[x][y]=true;
            q.pop();

            if(x==n-1&&y==m-1)
            {
                return true;
            }
            if(x+1<n&&!vis[x+1][y]&&abs(heights[x+1][y]-heights[x][y])<=k)
            {
                vis[x+1][y]=true;
                q.push({x+1,y});
            }
            if(x-1>=0&&!vis[x-1][y]&&abs(heights[x-1][y]-heights[x][y])<=k)
            {
                vis[x-1][y]=true;
                q.push({x-1,y});
            }
            if(y+1<m&&!vis[x][y+1]&&abs(heights[x][y+1]-heights[x][y])<=k)
            {
                vis[x][y+1]=true;
                q.push({x,y+1});
            }
            if(y-1>=0&&!vis[x][y-1]&&abs(heights[x][y-1]-heights[x][y])<=k)
            {
                vis[x][y-1]=true;
                q.push({x,y-1});
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
           int l=0,r=1e6;
        n=heights.size();
        m=heights[0].size();
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(bfs(heights,mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
