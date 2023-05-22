class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto c:s)
        {
            if(!st.empty() and ((c=='B' and st.top()=='A') || (c=='D' and st.top()=='C')))
                st.pop();
            else st.push(c);
        }
        return st.size();
    }
};