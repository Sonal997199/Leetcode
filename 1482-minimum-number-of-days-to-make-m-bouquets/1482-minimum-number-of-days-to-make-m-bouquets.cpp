class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int i=*min_element(bloomDay.begin(), bloomDay.end());
        int j=*max_element(bloomDay.begin(), bloomDay.end());
        
        while(i<j)
        {
            int mid=i+(j-i)/2;
            int cnt=0,ans=0;
            for(auto it:bloomDay)
            {
                if(it>mid)cnt=0;
                else
                {
                    cnt++;
                    if(cnt==k)
                    {
                        cnt=0;ans++;
                    }
                }
                if(ans>=m)break;
            }
            if(ans>=m)j=mid;
            else i=mid+1;
        }
        
        int cnt=0, ans=0;
        for(auto it: bloomDay){
            if(it>i){cnt=0;}
            else{
                cnt++;
                if(cnt==k){
                    cnt=0;
                    ans++;
                }
            }
            if(ans>=m){break;}
        }
        if(ans>=m){return i;}
        return -1;
    }
};