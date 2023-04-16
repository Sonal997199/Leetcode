class Solution {
public:
    int addMinimum(string word) {
        int cnt=0;
        int prev='z';
        for(char& c:word)
        {
            cnt+=c<=prev;
            prev=c;
        }
        return cnt*3-word.size();
    }
};