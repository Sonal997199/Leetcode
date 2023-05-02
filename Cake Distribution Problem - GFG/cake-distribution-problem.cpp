//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool solve(int mid,vector<int> &sweetness,int K)
    {
        int cnt=0,sum=0;
        
        for(int i=0;i<sweetness.size();i++)
        {
            sum+=sweetness[i];
            if(sum>=mid)
            {
                cnt++;
                sum=0;
            }
        }
        return cnt>=K+1;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here.
        int low=INT_MAX;
        int high=0,mid;
        
        for(int i=0;i<N;i++)
        {
            low=min(low,sweetness[i]);
            high+=sweetness[i];
        }
        int ans=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(solve(mid,sweetness,K))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends