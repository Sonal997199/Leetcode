class Solution {
public:
    int dp[505][505];
    /*int lcs(string s,string t)
    {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int lps(string s)
    {
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }*/
    
    int solve(string& s,int i,int j)
    {
        if(i==j || i>j)return dp[i][j]=0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==s[j])return dp[i][j]=solve(s,i+1,j-1);
        else return dp[i][j]=min(solve(s,i+1,j)+1,solve(s,i,j-1)+1);
        return 0;
    }
    int minInsertions(string s) {
        //return s.length()-lps(s);
        
        
        for(int i=0;i<=500;i++)
        {
            for(int j=0;j<=500;j++)
            {
                dp[i][j]=-1;
            }
        }
        int n=s.size();
        return solve(s,0,n-1);
    }
};