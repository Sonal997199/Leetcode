class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int curr=0;
        int count=0;
        int reach=0;
        int n=nums.size()-1;
        for(int i=0;i<n;i++)
        {
           reach=max(reach,nums[i]+i);
           
           if(i==curr)
           {
               curr=reach;
               count++;
           }
        }
        return count;
    }
};