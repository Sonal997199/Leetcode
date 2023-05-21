class Solution {
public:
    int reverse(int x) {
        int temp=abs(x);
        long long sum=0;
        while(temp>0)
        {
            if(sum > INT_MAX/10 || sum < INT_MIN/10)
                return 0;
            sum=(sum*10)+(temp%10);
            temp/=10;
        }
        if(x<0)
            return -1*sum;
        else
            return sum;
    }
};