class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        long long n = nums.size(),ans=0,mod=1e9+7;
        
        for(int i=1;i<n;i++) nums[i] += nums[i-1];
        
        for(int i=0;i<n;i++)
        {
            int j1=i+1,j2=n-1,ans1=0,ans2=0;
            while(j1<=j2)
            {
                int m = (j1+j2)/2;
	            if(nums[m]>=2*nums[i]) ans1=m,j2=m-1;
	            else j1=m+1;
            }
            j1=i+1,j2=n-1;
            while(j1<j2)
            {
                int m = (j1+j2)/2;
	            if(nums[n-1]>=2*nums[m]-nums[i]) ans2=m,j1=m+1;
	            else j2=m;
            }
            if(ans1>ans2 || ans1==0 || ans2==0 || ans1<i || ans2<i) continue;
            ans = (ans + (ans2 - ans1 + 1)%mod)%mod;
        }
        return ans;
    }
};