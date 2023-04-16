class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        map<int,int> mp;
        for(int i=0;i<intervals.size();i++)
        {
            mp[intervals[i][0]]=i;
        }
        
        for(int i=0;i<intervals.size();i++)
        {
            ans[i]=mp.lower_bound(intervals[i][1])!=end(mp)?mp.lower_bound(intervals[i][1]) -> second:-1;
        }
        return ans;
    }
};