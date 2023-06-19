class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,k=0;

        while(i<n)
        {
            int j=i;
            while(j<n && chars[j]==chars[i])
            {
                j++;
            }
            chars[k++]=chars[i];
            if(j-i>1)
            {
                for(char c:to_string(j-i))
                {
                    chars[k++]=c;
                }
            }
            i=j;
        }
        return k;
    }
};