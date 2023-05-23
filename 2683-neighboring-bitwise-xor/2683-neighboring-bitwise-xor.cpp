class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int t=0;
        for(auto x:derived)
        {
            t^=x;
        }
        if(t==0)return 1;
        else return 0;
    }
};