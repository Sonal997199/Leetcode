class Solution {
public:
    int dp[101][201];
    int help(int idx,int m,vector<int>& p)
    {
        if(idx>=p.size())return 0;
        if(dp[idx][m]!=-1)return dp[idx][m];
        int sum=0,ans=INT_MIN;
        for(int i=idx;i<idx+2*m && i<p.size();i++)
        {
            sum+=p[i];
            ans=max(ans,sum-help(i+1,max(m,i-idx+1),p));
        }
        return dp[idx][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int diff=help(0,1,piles);
        int sum=0;
        for(auto x:piles)sum+=x;
        return (sum+diff)/2;
    }
};