class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(),-1);
        int len=2*k+1;
        long sum=0;
        if(nums.size()<len)return res;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(i-len>=0)sum-=nums[i-len];
            if(i>=len-1)res[i-k]=sum/len;
        }
        return res;
    }
};