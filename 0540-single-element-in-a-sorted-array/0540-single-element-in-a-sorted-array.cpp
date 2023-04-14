class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*int l=0,h=nums.size()-1;
        while(l<h)
        {
            int m=(l+h)/2;
            if((m%2==0 && nums[m]==nums[m+1]) || (m%2==1 && nums[m]==nums[m-1]))
            {
                l=m+1;
            }
            else h=m;
        }
        return nums[l];*/
        
        
        
        int ans=0;
        for(int i=0;i<nums.size();i++)ans=ans^nums[i];
        return ans;
    }
};