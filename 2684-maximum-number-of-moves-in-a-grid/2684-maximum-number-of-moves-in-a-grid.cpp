class Solution {
public:
    int dfs(int n,int m,vector<vector<int>>& grid,int i,int j,int pre)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]<=pre)return 0;
        
        int val=grid[i][j];
        grid[i][j]=0;
        
        int ans=0;
        
        ans=max({dfs(n,m,grid,i-1,j+1,val),dfs(n,m,grid,i,j+1,val),dfs(n,m,grid,i+1,j+1,val)})+1;
        
        return ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            res=max(res,dfs(n,m,grid,i,0,-1e6));
        }
        return res-1;
    }
};