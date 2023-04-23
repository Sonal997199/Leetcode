class Solution {
public:
    int dp[100001];
    int mod=1e9+7;
    int solve(string &s,int i,int k)
    {
        if(i==s.length())return 1;
        if(dp[i]!=-1)return dp[i];
        else
        {
            if(s[i]=='0')return 0;
            long long n=0;
            int ans=0;
            for(int j=i;j<s.length();j++)
            {
                n=n*10+s[j]-'0';
                if(n>k)break;
                ans+=solve(s,j+1,k);
                ans=ans%mod;
            }
            return dp[i]=ans;
        }
    }
    int numberOfArrays(string s, int k) {
        for(int i=0;i<=s.size();i++)dp[i]=-1;
        return solve(s,0,k);
    }
};