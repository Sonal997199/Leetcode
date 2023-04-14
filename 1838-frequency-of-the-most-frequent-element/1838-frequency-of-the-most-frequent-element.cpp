class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        /*sort(nums.begin(),nums.end());
        int i=1,j=nums.size(),ans=1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            long long int sum=0,c=1;
            for(int k=0;k<mid;k++){sum+=nums[k]*1LL;}
            long long int t=1LL*nums[mid-1]*mid;
            if(t-sum<=k){c=-1;}
            if(c==1)
            {
                int p=0;
                for(int k=mid;k<nums.size();k++)
                {
                    sum-=nums[p];
                    sum+=nums[k];
                    t=1LL*nums[k]*mid;
                    p++;
                    if(t-sum<=k)
                    {
                        c=-1;
                        break;
                    }
                }
            }
            if(c==-1)
            {
                ans=mid;
                i=mid+1;
            }
            else {j=mid-1;}
        }
        return ans;*/
        
        
        
        
        
        sort(nums.begin(), nums.end());
        int i=1, j=nums.size(), ans=1;
        while(i<=j){
            int mid=i+(j-i)/2;
            long long int sum=0, chk=1;
            for(int k1=0; k1<mid; k1++){sum+=nums[k1]*1LL;}
            long long int tt=1LL*nums[mid-1]*mid;
            if(tt-sum<=k){
                chk=-1;
            }
            if(chk==1){
                int j=0;
                for(int k1=mid; k1<nums.size(); k1++){
                    sum-=nums[j];
                    sum+=nums[k1];
                    tt=1LL*nums[k1]*mid;
                    j++;
                    if(tt-sum<=k){chk=-1; break;}
                }
            }
            if(chk==-1){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};