class Solution {
public:
    void dfs(string u,string v,map<string,double>& mp,map<string,vector<string>>& mm,double &val,map<string,int>& vis,bool &found)
    {
        vis[u]=1;
        if(found==true)return;
        for(auto child:mm[u])
        {
            if(vis[child]!=1)
            {
                val*=mp[u+"->"+child];
                if(v==child)
                {
                    found=true;
                    return;
                }
                dfs(child,v,mp,mm,val,vis,found);
                if(found==true)return;
                else val/=mp[u+"->"+child];
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string,double> mp;
        map<string,vector<string>> mm;
        for(int i=0;i<equations.size();i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u+"->"+v]=values[i];
            mp[v+"->"+u]=1/values[i];
            mm[u].push_back(v);
            mm[v].push_back(u);
        }
        
        for(int i=0;i<queries.size();i++)
        {
            string u=queries[i][0];
            string v=queries[i][1];
            if(mm.find(u)==mm.end() || mm.find(v)==mm.end())ans.push_back(-1);
            else
            {
                double val=1;
                map<string,int> vis;
                bool found=false;
                if(u==v)found=true;
                else dfs(u,v,mp,mm,val,vis,found);
                if(found==true)ans.push_back(val);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};