class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        priority_queue<int> pq;
        for (auto &x:nums) {
            mp[x]++;
        }
        for (auto &it:mp) {
            pq.push(it.second);
        }
        
        while (k>0) {
            int countFreq = pq.top();
            pq.pop();
            for (auto &it:mp) {
                if(countFreq == it.second) {
                    ans.push_back(it.first);
                    mp.erase(it.first);
                    k--;
                    break;
                }
            }
        }
        return ans;

    }
};