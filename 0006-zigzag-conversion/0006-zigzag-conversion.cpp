class Solution {
public:
    string convert(string s, int numRows) {
        string res="";
        if(numRows==1)
            return s;
        for(int i=0;i<numRows;i++)
        {
            bool flag=true;
            int j=i;
            while(j<s.size())
            {
                res+=s[j];
                if(i==0 || i==numRows-1)
                {
                    j+=2*(numRows-1);
                    continue;
                }
                j+=flag?(2*(numRows-i-1)):2*i;
                flag=!flag;
            }
        }
        return res;
    }
};