class SnapshotArray {
public:
    vector<vector<pair<int,int>>> v;
    int curr=0;
    SnapshotArray(int length) {
        v=vector<vector<pair<int,int>>>(length);
    }
    
    void set(int index, int val) {
        if(v[index].empty() || v[index].back().first!=curr)
            v[index].push_back({curr,val});
        else v[index].back().second=val;
    }
    
    int snap() {
        return curr++;
    }
    
    int get(int index, int snap_id) {
        auto it=upper_bound(v[index].begin(),v[index].end(),pair<int,int>(snap_id,INT_MAX));
        
        return it==v[index].begin()?0:prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */