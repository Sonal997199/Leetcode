class Solution {
public:
    bool check(int h,vector<int>& citations)
    {
        int cnt=citations.size();
        for(auto i:citations)
        {
            if(i<h)cnt--;
            if(cnt<h)return false;
        }
        return true;
    }
    int hIndex(vector<int>& citations) {
        int l=0,h=citations.size();
        while(l<h)
        {
            int mid=(l+h+1)/2;
            if(check(mid,citations))l=mid;
            else h=mid-1;
        }
        return l;
    }
};