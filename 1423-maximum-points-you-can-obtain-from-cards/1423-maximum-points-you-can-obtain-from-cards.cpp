class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int s=0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            s+=cardPoints[i];
            v.push_back(s);
        }
        int ans=0,res=INT_MIN;
        
        if(n==k)
            return s;
        
        for(int i=0;i<=k;i++)
        {
            int j=i+n-k-1;
            
            if(i==0)
                ans=v[j];
            else
                ans=v[j]-v[i-1];
            
            res=max(res,s-ans);
        }
        return res;
        
    }
};