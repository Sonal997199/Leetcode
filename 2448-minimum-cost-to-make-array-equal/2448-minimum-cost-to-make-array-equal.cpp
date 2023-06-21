class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        long long ans=1e18;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)v[i]={nums[i],cost[i]};
        
        sort(v.begin(),v.end());
        
        vector<long long> pre(n);
        long long curr=0,temp=0;
        for(int i=0;i<n;i++)
        {
            pre[i]=(v[i].first*curr-temp);
            curr+=(long long)v[i].second;
            temp+=(long long)v[i].first*(long long)v[i].second;
        }
        
        curr=0,temp=0;
        for(int i=n-1;i>=0;i--)
        {
            ans=min(abs(v[i].first*curr-temp)+pre[i],ans);
            curr+=(long long)v[i].second;
            temp+=(long long)v[i].first*(long long)v[i].second;
        }
        
        return ans;
    }
};