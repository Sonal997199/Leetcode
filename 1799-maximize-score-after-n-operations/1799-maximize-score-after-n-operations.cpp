class Solution {
public:
    bool isBitSet(int& num, int bitIdx)
    {
        if ((num & (1 << bitIdx)) != 0) 
            return true;
        return false;
    }
    
    void setBit(int& num, int bitIdx)
    {
        num = num | (1 << bitIdx);
    }
    
    
    int solve(vector<int>& nums,map<int,int>& mp,int vis,int op)
    {
        if (mp.count(vis)) return mp[vis];
        int maxScore=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(isBitSet(vis,i))continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(isBitSet(vis,j))continue;
                
                int newVis=vis;
                setBit(newVis,i);
                setBit(newVis,j);
                
                int currScore=op*__gcd(nums[i],nums[j]);
                int nextMaxScore=solve(nums,mp,newVis,op+1);
                int total=currScore+nextMaxScore;
                maxScore=max(maxScore,total);
                
            }
        }
        
        return mp[vis]=maxScore;
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        int vis=0;
        map<int,int> mp;
        int ans=solve(nums,mp,vis,1);
        return ans;
    }
};