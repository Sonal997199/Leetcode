class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n,0);
        for(int i=-1;i<n;i++)
        {
            if(i>=0 && dp[i]==false)continue;
            for(auto w:wordDict)
            {
                int j=0;
                while(j<w.length() and i+1+j<n and w[j]==s[i+1+j])j++;
                if(j==w.length())dp[i+w.length()]=true;
            }
        }
        return dp[n-1];
    }
};