class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*for(int i=2;i<cost.size();i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);*/
        
        int n=cost.size();
        vector<int> dp(n+1,0);
        
        for(int i=2;i<n;i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        dp[n]=min(dp[n-1]+cost[n-1],dp[n-2]+cost[n-2]);
        return dp[n];
    }
};