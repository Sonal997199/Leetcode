class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l=0;
        int h=removable.size();
        int ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            string s1=s;
            for(int i=0;i<mid;i++)
            {
                s1[removable[i]]='A';
            }
            int t=p.size(),k=0;
            for(int i=0;i<s1.size() && k<t;i++)
            {
                if(s1[i]==p[k])k++;
            }
            
            if(t==k)
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
        
        
        
       /* int i=0, j=removable.size(), ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            string s1=s;
            for(int i=0; i<mid; i++){
                s1[removable[i]]='A';
            }
            int l=p.size(), k=0;
            for(int i=0; i<s1.size() && k<l; i++){
                if(s1[i]==p[k]){k++;}
            }
            //cout<<mid<<" "<<l<<" "<<k<<endl;
            if(l==k){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;*/
    }
};