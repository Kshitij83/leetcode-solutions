class Solution {
public:
    bool isPalindrome(int x) {
        
        int x1=x;
        long long rev=0;
        while(x1>0){
            int z=x1%10;
            rev=10*rev+z;
            x1=x1/10;
        }
        return rev==x;
    }
};