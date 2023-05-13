class Solution {
    #define ll long long
public:
    ll mod=1e9+7;
    
    ll solve(ll len,ll low,ll high,vector<ll>&dp,int zero,int one){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        ll ans=0;
        if(len>=low && len<=high)ans=1;
        ans += solve(len+zero,low,high,dp,zero,one)%mod;
        ans =  (ans%mod + solve(len+one,low,high,dp,zero,one)%mod)%mod;
        dp[len]=ans;
        return ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll>dp(high+1,-1);
        return solve(0,low,high,dp,zero,one);
    }
};