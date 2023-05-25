//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void help(string &s,int &tgt,int ind,vector<string>&ans,int val,int last,string newString)
    {
        if(ind==s.length())
        {
            if(val==tgt){ans.push_back(newString);}
            return;
        }
        string temp="";
        int n=0;
        for(int i=ind;i<s.length();i++)
        {
            temp+=s[i];
            n=n*10+(s[i]-'0');
            if(ind==0)help(s,tgt,i+1,ans,n,n,temp);
            else
            {
                help(s,tgt,i+1,ans,val+n,n,newString+"+"+temp);
                help(s,tgt,i+1,ans,val-n,-n,newString+"-"+temp);
                help(s,tgt,i+1,ans,val-last+last*n,last*n,newString+"*"+temp);
            }
            
            if(s[ind]=='0')break;
        }
    }
    vector<string> addOperators(string S, int target) {
        // code here
        
        vector<string> ans;
        help(S,target,0,ans,0,0,"");
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends