//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        vector<int> v(N,0);
        for(int i=1;i<N;i++)
        {
            v[p[i]]++;
            v[i]++;
        }
        int cnt=0;
        for(auto x:v)
        {
            if(x==1)cnt++;
        }
        if(cnt==N)return 0;
        return N-1-cnt;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends