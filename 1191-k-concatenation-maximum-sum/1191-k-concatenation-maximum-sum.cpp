class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum=0,n=arr.size();
        for(auto i=0,temp=0;i<min(2,k)*n;i++)
        {
            temp=max(temp+arr[i%n],arr[i%n]);
            sum=max(sum,temp);
        }
        
        return ((long long)sum+max(0ll,accumulate(begin(arr),end(arr),0ll)*max(0,k-2)))%1000000007;
    }
};