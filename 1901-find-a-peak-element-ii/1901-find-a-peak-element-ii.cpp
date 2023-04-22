class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int low=0,high=m-1;
        
        while(low<=high)
        {
            int maxRow=0;
            int mid=(low+high)>>1;
            
            for(int row=0;row<n;row++)
            {
                if(mat[row][mid]>mat[maxRow][mid])maxRow=row;
            }
            
            int curr=mat[maxRow][mid];
            
            int left=mid==0?-1:mat[maxRow][mid-1];
            int right=mid==m-1?-1:mat[maxRow][mid+1];
            
            if(curr>left && curr>right)return {maxRow,mid};
            else if(curr<left)high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};