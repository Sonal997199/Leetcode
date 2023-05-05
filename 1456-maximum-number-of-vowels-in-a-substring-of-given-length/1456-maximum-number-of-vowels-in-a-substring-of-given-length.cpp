class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt=0;
        int temp=0;
        unordered_set<char> st={'a','e','i','o','u'};
        for(int i=0;i<s.size();i++)
        {
            temp+=st.count(s[i]);
            if(i-k>=0)temp-=st.count(s[i-k]);
            cnt=max(temp,cnt);
        }
        return cnt;
        
    }
};