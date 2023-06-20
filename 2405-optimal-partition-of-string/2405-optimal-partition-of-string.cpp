class Solution {
public:
    bool checkBit(int &flag,int &n)
    {
        return flag & (1<<n);
    }
    void setBit(int &flag,int &n)
    {
        flag=flag | (1<<n);
    }
    int partitionString(string s) {
        /*unordered_set<char> st;
        int cnt=1;
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s[i])!=st.end())
            {
                cnt++;
                st.clear();
                st.insert(s[i]);
            }
            else st.insert(s[i]);
        }
        return cnt;*/




        int flag=0,cnt=1;
        int i=0;
        while(i<s.length())
        {
            int n=s[i]-'a';
            if(checkBit(flag,n))
            {
                flag=0;
                cnt++;
            }
            setBit(flag,n);
            i++;
        }
        return cnt;
    }
};