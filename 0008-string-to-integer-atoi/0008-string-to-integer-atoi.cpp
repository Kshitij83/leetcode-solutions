#include <iostream>
#include <cstdlib>
#include <limits>
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        while(i<n && s[i]==' '){
            i++;
        }
        int sign = 1;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            sign = (s[i]=='-')?-1:1;
            i++;
        }
        long result = 0;
        while(i<n && isdigit(s[i])){
            int digit = s[i]-'0';
            result = result*10+digit;
            if(result>INT_MAX && sign==-1){
                return INT_MIN;
            }
            else if(result>INT_MAX && sign==1){
                return INT_MAX;
            }
            i++;
        }
        return result*sign;
    }
};