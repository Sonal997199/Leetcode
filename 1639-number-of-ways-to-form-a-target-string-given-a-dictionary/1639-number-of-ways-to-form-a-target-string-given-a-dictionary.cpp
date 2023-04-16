class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int w=words[0].size();
        int t=target.size();
        vector<vector<int>> freq(w,vector<int>(26,0));
        
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<n;j++)
            {
                int lt=words[j][i]-'a';
                freq[i][lt]+=1;
            }
        }
        
        
        vector<vector<long long>> dp(t+1, vector<long long>(w+1, 0));
        for (int i = 0; i <= w; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < t; i++) {
            int tar = target[i] - 'a';
            for (int j = 0; j < w; j++) {
                int num = freq[j][tar];
                dp[i+1][j+1]=(dp[i+1][j]+(dp[i][j]*num)%1000000007)%1000000007;
            }
        }
        return (int)dp[t][w];
    }
};