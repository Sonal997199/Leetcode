class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums2[i],nums1[i]});
        }
        
        sort(v.begin(),v.end());
        
        long long res=0,curr=0;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=n-1;i>n-1-k;i--)
        {
            pq.push(v[i].second);
            curr+=v[i].second;
        }
        
        res=max(res,curr*v[n-k].first);
        
        for(int i=n-1-k;i>=0;i--)
        {
            int temp=pq.top();
            pq.pop();
            curr-=temp;
            curr+=v[i].second;
            pq.push(v[i].second);
            res=max(res,curr*v[i].first);
        }
        
        return res;
    }
};