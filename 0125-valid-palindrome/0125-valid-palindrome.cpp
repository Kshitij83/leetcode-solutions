class Solution {
public:
    string result;
    bool isPalindrome(string s) {
        for(char c : s){
            if(isalnum(c)){
                result+=tolower(c);
            }    
        }
        s = result;
        int left=0;
        int right = s.length()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};