class UnionFind{
    vector<int> component;
    int distinctComponents;
public:
    UnionFind(int n){
        distinctComponents=n;
        for(int i=0;i<=n;i++)
            component.push_back(i);
    }
    
    bool unite(int a,int b){
        if(findComponent(a)==findComponent(b))return false;
        component[findComponent(a)]=b;
        distinctComponents--;
        return true;
    }
    
    int findComponent(int a){
        if(component[a]!=a)component[a]=findComponent(component[a]);
        return component[a];
    }
    
    bool united(){
        return distinctComponents==1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){return a[0]>b[0];});
        
        int edgesAdded=0;
        UnionFind alice(n),bob(n);
        
        for(auto it:edges)
        {
            int x=it[0],y=it[1],z=it[2];
            switch(x)
            {
                case 3:edgesAdded+=(bob.unite(y,z))|(alice.unite(y,z));
                       break;
                case 2:edgesAdded+=bob.unite(y,z);
                       break;
                case 1:edgesAdded+=alice.unite(y,z);
                       break;
            }
        }
        
        return (bob.united()&&alice.united())?(edges.size()-edgesAdded):-1;
    }
};