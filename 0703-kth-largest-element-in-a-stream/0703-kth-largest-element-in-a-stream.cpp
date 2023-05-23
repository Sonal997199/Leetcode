class KthLargest {
public:
    int n;
    //multiset<int> stream;

    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        //stream=multiset<int>(nums.begin(),nums.end());

        /*while(stream.size()>n)
            stream.erase(stream.begin());*/
        
        for(auto& t:nums)
            add(t);
    }
    
    int add(int val) {
        /*stream.insert(val);
        if(stream.size()>n)
            stream.erase(stream.begin());
        return *stream.begin();*/

        pq.push(val);
        if(pq.size()>n) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */