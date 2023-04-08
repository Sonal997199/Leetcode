class Solution {
public:
    int chalkReplacer(vector<int>& ch, int k) {
        int n = ch.size();

        vector<long long> chalk(ch.begin(),ch.end());

        for(int i=1;i<n;i++) chalk[i] += chalk[i-1];

        if(k == chalk[n-1] || k % chalk[n-1] == 0) return 0;
        if(k >= chalk[n-1]) k %= chalk[n-1];
        
        int lo = 0 , hi = n - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(chalk[mid] == k) return mid + 1;
            else if(chalk[mid] < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};