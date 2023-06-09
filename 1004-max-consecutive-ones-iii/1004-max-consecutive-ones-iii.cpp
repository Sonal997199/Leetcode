class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int st=0,mx=INT_MIN;
        int zero=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)zero++;
        
            while(zero>k)
            {
               if(nums[st]==0)zero--;
               st++;
            }
        
            mx=max(mx,i-st+1);
        }
        return mx;
    }
};