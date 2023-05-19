class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        else if(nums[0]==0)
            return false;
        int reach=0;
        for(int i=0;i<nums.size();i++)
        {
            if(reach<i)
                return false;
            reach=max(reach,i+nums[i]);
        }
        return true;
    }
};