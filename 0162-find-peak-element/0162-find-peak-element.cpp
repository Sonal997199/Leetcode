class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*int n=nums.size();
        if(nums.size()==1 || nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        
        for(int i=1;i<nums.size()-1;i++)
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])return i;
        return -1;*/
        
        
        //Binary Search
        
        /*int n=nums.size();
        int low=0;
        int high=n-1;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1])high=mid;
            else low=mid+1;
        }
        return low;*/
        
        return max_element(nums.begin(),nums.end())-nums.begin();
    }
};