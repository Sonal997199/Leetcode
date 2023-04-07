class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        grid[i][j]=0;
        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        
        for(vector<int>& it:dir)
        {
            int new_i=i+it[0];
            int new_j=j+it[1];
            if(new_i>=0 && new_i<grid.size() && new_j>=0 && new_j<grid[0].size() && grid[new_i][new_j]==1)dfs(grid,new_i,new_j);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1)dfs(grid,i,j);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};