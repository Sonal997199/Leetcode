class Solution {
public:
    static bool check(vector<int>& nums,int k)
    {
        long long temp=0;
        for(int n:nums)
        {
            if(n<=k)
            {
                temp+=k-n;
            }
            else 
            {
                if(temp<n-k)return 0;
                else temp-=n-k;
            }
        }
        return 1;
    }
    int minimizeArrayValue(vector<int>& nums) {
        /*int left=0,right=*max_element(nums.begin(),nums.end());
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(check(nums,mid))right=mid;
            else left=mid+1;
        }
        return left;*/


        long sum=0;
        long res=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            res=max(res,(sum+i)/(i+1));
        }
        return res;
    }
};