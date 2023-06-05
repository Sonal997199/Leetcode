class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> s1;
        set<char> s2;
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        
        for(auto it:word1)
        {
            m1[it-'a']++;
            s1.insert(it);
        }
        for(auto it:word2)
        {
            m2[it-'a']++;
            s2.insert(it);
        }
        sort(m1.begin(),m1.end());
        sort(m2.begin(),m2.end());
        return m1==m2 && s1==s2;
        
        
    }
};