class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> v;
        int cnt=1;
        int maxi=INT_MIN;
        
        if(nums.size()==0)return 0;
        if(nums.size()==1)return 1;
        
        sort(nums.begin(),nums.end());
        
        v.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++)
        {
            if(v.back()+1==nums[i])
            {
                v.push_back(nums[i]);
                cnt++;
            }
            else if(v.back()+1!=nums[i] && v.back()!=nums[i])
            {
                v.clear();
                v.push_back(nums[i]);
                maxi=max(maxi,cnt);
                cnt=1;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};