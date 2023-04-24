class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(),-1);
        unordered_map<int,int> mp;
        set<int> s;
        for(int i=0;i<rains.size();i++)
        {
            if(rains[i]==0)
            {
                s.insert(i);
                ans[i]=1;
            }
            else
            {
                if(mp.count(rains[i]))
                {
                    int lastIndex=mp[rains[i]];
                    auto zeroIndex=s.upper_bound(lastIndex);
                    if(zeroIndex==s.end())return {};
                    ans[*zeroIndex]=rains[i];
                    s.erase(zeroIndex);
                }
                mp[rains[i]]=i;
            }
        }
        return ans;
    }
};