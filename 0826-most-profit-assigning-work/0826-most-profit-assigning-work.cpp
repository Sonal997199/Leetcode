class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<profit.size();i++)
        {
            pq.push({profit[i],difficulty[i]});
        }
        
        sort(worker.begin(),worker.end());
        
        int i=worker.size()-1;
        int ans=0;
        
        while(i>=0 and !pq.empty())
        {
            pair<int,int> p=pq.top();
            if(worker[i]>=p.second)
            {
                ans+=p.first;
                i--;
            }
            else pq.pop();
        }
        return ans;
    }
};