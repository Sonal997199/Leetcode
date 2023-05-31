class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mn=INT_MAX;
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                int temp=nums[i]+nums[j]+nums[k];
                if(temp>target)
                {
                    mn=min(mn,abs(target-temp));
                    k--;
                }
                else
                {
                    mn=min(mn,abs(target-temp));
                    j++;
                }
                
                if(mn==abs(temp-target))
                    sum=temp; 
            }
        }
        return sum;
    }
};