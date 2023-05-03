class Solution {
public:
    int solve(int len_s,int len_p,string &s,string &p,vector<vector<int>> &dp)
    {
        if(len_s==0 and len_p==0)return 1;
        if(len_p==0)return 0;
        
        if(dp[len_s][len_p]!=-1)return dp[len_s][len_p];
        
        if(p[len_p-1]=='*')
        {
            int res=solve(len_s,len_p-2,s,p,dp);
            int len_rep=0;
            
            while(1)
            {
                if(len_s-len_rep>0 and (s[len_s-1-len_rep]==p[len_p-2] || p[len_p-2]=='.'))
                    len_rep++;
                else
                    break;
                
                res=res|(solve(len_s-len_rep,len_p-2,s,p,dp));
            }
            return dp[len_s][len_p]=res;
        }
        
        if(len_s==0)return dp[len_s][len_p]=0;
        
        if(p[len_p-1]=='.' || s[len_s-1]==p[len_p-1])
            return dp[len_s][len_p]=solve(len_s-1,len_p-1,s,p,dp);
        
        return dp[len_s][len_p]=0;
        
    }
    bool isMatch(string s, string p) {
        int len_s=s.length();
        int len_p=p.length();
        
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        
        return solve(len_s,len_p,s,p,dp);
    }
};