class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>prefix(m+1 , vector<int>(n+1 , 0));
        for(int i = 1 ; i <= m ; i++)
        {
            for(int j = 1; j <= n ; j++)
            {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + mat[i-1][j-1] - prefix[i-1][j-1];
            }
        }
        
        int maximum = 0;
        for(int len = 0 ; len <= min(m,n) ; len++ )
        {
            for(int i = 1 ; i <= n-len ; i++) // column basically
            {
                for(int j = 1 ; j <= m -len ; j++) // for row selection
                {
                    int res = prefix[j+len][i+len] + prefix[j-1][i-1] - (prefix[j-1][i+len] + prefix[j+len][i-1]);
                    if(res <= threshold) maximum = max(maximum , len+1);
                }

            }
        }
        return maximum;
    }
};