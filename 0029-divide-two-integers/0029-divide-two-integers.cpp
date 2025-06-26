class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool sign = true;
        if(dividend<0 && divisor>0 || dividend>0 && divisor<0) sign = false;
        long n = abs(dividend);
        long d = abs(divisor);
        if(n==d) return (sign==true)?1:-1;
        long q = 0;
        while(d<=n){
            int cnt=0;
            while(d<<cnt <= n){
                cnt++;
            }
            cnt--;
            n -= d<<cnt;
            q += 1<<cnt;
        } 
        if(q == 1<<31 && sign) return INT_MAX;
        if(q == 1<<31 && !sign) return q;
        return (sign)?q:-q;

        // if(static_cast<long>(dividend)/static_cast<long>(divisor) > INT_MAX) return INT_MAX;
        // if(static_cast<long>(dividend)/static_cast<long>(divisor) < INT_MIN) return INT_MIN;
        // return dividend/divisor;
        // 10 -> 1010 , 3->11
    }
};