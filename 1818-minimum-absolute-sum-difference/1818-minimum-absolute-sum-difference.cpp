class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> diff(n);
        int m=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            diff[i]=abs(nums1[i]-nums2[i]);
            sum=(sum+diff[i])%m;
        }
        
        sort(nums1.begin(),nums1.end());
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            int it=lower_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
            if(it!=0 && it!=n)
            {
                v[i]=min(abs(nums2[i]-nums1[it]),abs(nums2[i]-nums1[it-1]));
            }
            else if(it==0)
            {
                v[i]=abs(nums2[i]-nums1[it]);
            }
            else if(it==n)
            {
                v[i]=abs(nums2[i]-nums1[it-1]);
            }
        }
        int best=0;
        for(int i=0;i<n;i++)
        {
            best=max(best,diff[i]-v[i]);
        }
        return (m+sum-best)%m;
    }
};