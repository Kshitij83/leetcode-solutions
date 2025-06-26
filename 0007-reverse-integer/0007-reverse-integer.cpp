class Solution {
public:
    int reverse(int x) {
        long y=0;
        int x1=x;
        while(x1!=0){
            int x2=x1%10;
            y=10*y+x2;
            x1=x1/10;
        }
        if(y>INT_MAX || y<INT_MIN){
            return 0;
        }
        else{
            return long(y);
        }
        
        
    }
};