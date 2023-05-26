class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> dp=piles;
        for(int i=1;i<piles.size();i++)
        {
            for(int j=0;j<piles.size()-i;j++)
            {
                dp[j]=max(piles[j]-dp[j+1],piles[j+i]-dp[j]);
            }
        }
        return dp[0]>0;
    }
};