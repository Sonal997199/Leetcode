class Solution {
public:
    void dfs(vector<vector<int>>&g,vector<bool>&vis,int &c,int &i)
    {
        vis[i]=true;
        c++;
        for(int j=0;j<g[i].size();j++)
        {
            if(!vis[g[i][j]])dfs(g,vis,c,g[i][j]);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++)
        {
            long long x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    long long x2,y2,r2;
                    x2=abs(x1-bombs[j][0]);
                    y2=abs(y1-bombs[j][1]);
                    if(x2*x2+y2*y2<=r1*r1)graph[i].push_back(j);
                }
            }
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int c=0;
            vector<bool>vis(n,false);
            dfs(graph,vis,c,i);
            ans=max(ans,c);
        }
        return ans;
    }
};