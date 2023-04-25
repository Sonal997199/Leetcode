//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


int dp[100010][1024];
class Solution{
public:
    int goodSubsets(vector<int> &arr, int n){
        // Code here
        
        const int mod=1e9+7;
        
        map<int,int> bits={ {2,0},
                            {3,1},
                            {5,2},
                            {7,3},
                            {11,4},
                            {13,5},
                            {17,6},
                            {19,7},
                            {23,8},
                            {29,9}
                          };
                
        vector<int> mask(31,0);
        
        for(int i=2;i<31;i++)
        {
            int currMask=0;
            bool ok=1;
            int val=i;
            
            for(int j=2;j*j<=val;j++)
            {
                while(val%j==0)
                {
                    int pos=bits[j];
                    if((currMask>>pos)&1)
                    {
                        ok=0;
                        break;
                    }
                    
                    currMask|=(1<<pos);
                    val/=j;
                }
                if(!ok)break;
            }
            
            if(val>1)
            {
                int pos=bits[val];
                if((currMask>>val)&1)ok=0;
                else currMask|=(1<<pos);
            }
            if(!ok)mask[i]=0;
            else mask[i]=currMask;
        }
        
        dp[0][0]=0;
        for(int i=1;i<1024;i++)dp[0][i]=1;
        
        int cnt=0;
        for(int i=1;i<n+1;i++)
        {
            if(arr[i-1]==1)cnt++;
            for(int j=0;j<1024;j++)
            {
                int val=arr[i-1];
                if(val==1)
                {
                    dp[i][j]=dp[i-1][j];
                    continue;
                }
                bool ok=1;
                int finalMask;
                
                if(mask[val])
                {
                    if(mask[val]&j)ok=0;
                    else finalMask=mask[val]|j;
                }
                else ok=0;
                
                if(ok)
                {
                    int x=dp[i-1][finalMask];
                    int y=dp[i-1][j];
                    dp[i][j]=(x+y)%mod;
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        auto expo=[](long long a,int n,int mod)->long long
        {
            long long res=1;
            
            while(n)
            {
                if(n&1)
                {
                    res=(res*a)%mod;
                    --n;
                }
                else
                {
                    a=(a*a)%mod;
                    n>>=1;
                }
            }
            return res;
        };
        
        long long temp=expo(2,cnt,mod);
        int ans=(dp[n][0]*temp)%mod;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends