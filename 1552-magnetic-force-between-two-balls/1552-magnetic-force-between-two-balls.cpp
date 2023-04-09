class Solution {
public:
    bool isPossible(vector<int>& position, int len, int m, int mid)
    {
        int ballCount = 1;
        int lastPos = position[0];

        for(int i = 0; i < len; i++)
        {
            if(position[i] - lastPos >= mid)
            {
                ballCount++;
                lastPos = position[i];
            }
        }
        return (ballCount >= m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int len = position.size();
        int s = 1;
        int e = (position[len-1] - position[0]);
        int ans = -1;
        int mid = mid = s + (e - s)/2;;
        
        while(s <= e)
        {
            if(isPossible(position, len, m, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s)/2;
        }
        return ans;
    }
};