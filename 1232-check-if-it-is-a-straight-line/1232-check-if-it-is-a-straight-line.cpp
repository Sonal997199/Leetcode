class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int y=c[1][1]-c[0][1];
        int x=c[1][0]-c[0][0];
        
        for(int i=2;i<c.size();i++)
        {
            auto t=c[i];
            if(x*(t[1]-c[0][1])!=y*(t[0]-c[0][0]))return false;
        }
        return true;
    }
};