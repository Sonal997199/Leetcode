class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*int i=0,j=0,sum=0;
        int mn=INT_MAX;
        bool flag=0;
        int n=nums.size();
        while(j<n)
        {
            sum+=nums[j];
            if(sum>=target)
            {
                flag=1;
                mn=min(mn,j-i+1);
                sum-=nums[i];
                i++;
            }
            while(sum>=target)
            {
                sum-=nums[i];
                mn=min(mn,j-i+1);
                i++;
            }
            j++;
        }
        if(!flag)return 0;
        return mn;*/
        
        
        
        
        
        //Using Binary Search and Prefix sum
        int n=nums.size();
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++)v[i+1]=v[i]+nums[i];
        
        long long ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            long long sum=target+v[i];
            long long idx=lower_bound(v.begin(),v.end(),sum)-v.begin();
            if(idx!=n+1)ans=min(ans,idx-i);
        }
        
        if(ans==INT_MAX)return 0;
        return ans;
    }
};