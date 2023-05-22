class Solution {
private:
    vector<int> validNums;
public:
    bool isValid(string nums,int sum)
    {
        if(sum<0)return false;
        if(nums.empty() and sum==0)return true;
        bool ans=false;
        for(int i=0;i<nums.length();i++)
        {
            string curr=nums.substr(0,i+1);
            int val=stoi(curr);
            ans|=isValid(nums.substr(i+1),sum-val);
        }
        return ans;
    }
    void preComputeValidNums()
    {
        validNums.push_back(1);
        for(int i=2;i<=1000;i++)
        {
            if(isValid(to_string(i*i),i))validNums.push_back(i);
        }
    }
    int punishmentNumber(int n) {
        preComputeValidNums();
        int ans=0;
        for(int i=0;i<validNums.size();i++)
        {
            int curr=validNums[i];
            if(curr<=n)ans+=(curr*curr);
        }
        return ans;
    }
};