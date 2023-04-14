class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=1,j=nums.size(),ans=1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            long long int sum=0,c=1;
            for(int k1=0;k1<mid;k1++){sum+=nums[k1]*1LL;}
            long long int t=1LL*nums[mid-1]*mid;
            if(t-sum<=k){c=-1;}
            if(c==1)
            {
                int p=0;
                for(int k1=mid;k1<nums.size();k1++)
                {
                    sum-=nums[p];
                    sum+=nums[k1];
                    t=1LL*nums[k1]*mid;
                    p++;
                    if(t-sum<=k)
                    {
                        c=-1;
                        break;
                    }
                }
            }
            if(c==-1)
            {
                ans=mid;
                i=mid+1;
            }
            else {j=mid-1;}
        }
        return ans;
        
        
        
        
        
        
    }
};