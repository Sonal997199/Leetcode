class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,sum=0;
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
        return mn;
    }
};