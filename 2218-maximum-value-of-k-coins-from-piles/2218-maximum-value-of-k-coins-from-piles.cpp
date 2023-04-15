class Solution {
public:
    int dp[1001][2001];
    int solve(vector<vector<int>>&piles,int k,int i)
    {
        if(i>=piles.size())return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        
        int mx=0;
        mx=max(mx,solve(piles,k,i+1));
        
        for(int j=0;j<piles[i].size();j++)
        {
            if(j+1<=k)
            {
                mx=max(mx,piles[i][j]+solve(piles,k-j-1,i+1));
            }
            else
            {
                break;
            }
        }
        return dp[i][k]=mx;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i=0;i<piles.size();i++)
        {
            for(int j=1;j<piles[i].size();j++)
            {
                piles[i][j]=piles[i][j]+piles[i][j-1];
            }
        }
        
        for(int i=0;i<piles.size()+1;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        return solve(piles,k,0);
    }
};