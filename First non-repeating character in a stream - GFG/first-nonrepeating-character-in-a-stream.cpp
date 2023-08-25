//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    
		    unordered_map<char,int> mp;
		    
		    if(a.size()==1)return a;
		    if(a.size()==0)return "#";
		    
		    string ans;
		    ans+=a[0];
		    mp[a[0]]=1;
		    queue<char> q;
		    q.push(a[0]);
		    
		    for(int i=1;i<a.size();i++)
		    {
		        mp[a[i]]++;
		        //cout<<mp[a[i]]<<" ";
		        q.push(a[i]);
		        
		        while(!q.empty() and mp[q.front()]>1)
		        {
		            q.pop();
		        }
		    
		        if(q.empty())ans+='#';
		        else ans+=q.front();
		    }
		    
		    return ans;
		    
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends