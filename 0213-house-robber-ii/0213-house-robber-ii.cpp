class Solution {
public:
    int solve(vector<int> &nums,int n,vector< int> &dp)
    {
      if(n==1) return nums[0];
      if(n==2) return max(nums[0],nums[1]);
      if(dp[n]!=-1) return dp[n];
      return dp[n]=max(solve(nums,n-1,dp),solve(nums,n-2,dp)+nums[n-1]);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        
        if(nums.size()==1) return nums[0]; 
        if(nums.size()==2)return max(nums[0],nums[1]);
        if(nums.size()==3)
        {
           int t = max(nums[0],nums[1]);
           return max(t,nums[2]);
        }
        int temp=nums[n-1];
        nums.pop_back();
        
        int ans1=solve(nums,nums.size(),dp);
        nums.pop_back();
        nums.erase(nums.begin());
        for(int i=0;i<=n;i++)
        {
          dp[i]=-1;
        }
        int ans2=temp+solve(nums,nums.size(),dp);
        return max(ans1,ans2);
    }
};