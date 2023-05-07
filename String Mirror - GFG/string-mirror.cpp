//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        
        string t="";
        t+=str[0];
        
        for(int i=1;i<str.length();i++)
        {
            if(str[i]<t[i-1])t+=str[i];
            else if(str[i]==t[i-1] and i!=1)t+=str[i];
            else break;
        }
        
        string s=t;
        reverse(s.begin(),s.end());
        t+=s;
        return t;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends