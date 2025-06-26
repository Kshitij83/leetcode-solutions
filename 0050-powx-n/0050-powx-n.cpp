class Solution {
public:
    double myPow(double x, int n) {
        //observe that when n is even we divide it by 2 and when its odd we subtract it by 1 and take the number out 
        //eg: 4^4 = 16^2 and 4^5 = 4*(4^4)
        long nn = n;
        double ans = 1.0;
        if(nn<0) nn = -1.0 * nn;
        while(nn>0){
            if(nn%2==0){
                nn = nn/2;
                x = x*x;
            }
            else{
                nn--;
                ans *= x;
            }
        }
        if(n<0) return 1.0/ans;
        return ans;
    }
};