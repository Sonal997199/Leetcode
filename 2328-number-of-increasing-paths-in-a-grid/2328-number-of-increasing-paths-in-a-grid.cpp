#define ll long long

class Solution {
public:
    ll m,n;
    ll mod=1e9+7;
    ll dp[1005][1005],a[1005][1005],vis[1005][1005];
    ll dx[4]={1,-1,0,0};
    ll dy[4]={0,0,1,-1};
    
    void dfs(ll x,ll y)
    {
        if(vis[x][y])return;
        vis[x][y]=1;
        dp[x][y]=1;
        
        for(ll i=0;i<4;i++)
        {
            ll nx=x+dx[i];
            ll ny=y+dy[i];
            
            if(nx>=0 and nx<m and ny>=0 and ny<n and a[x][y]<a[nx][ny])
            {
                dfs(nx,ny);
                if(dp[nx][ny]){
                    dp[x][y]=(dp[x][y]+dp[nx][ny])%mod;}
            }
        }
    }
    
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                dp[i][j]=0;
                a[i][j]=grid[i][j];
                vis[i][j]=0;
            }
        }
        
        ll ans=0;
        
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(vis[i][j]==0)dfs(i,j);
                ans=(ans+dp[i][j])%mod;
            }
        }
        return ans;
    }
};