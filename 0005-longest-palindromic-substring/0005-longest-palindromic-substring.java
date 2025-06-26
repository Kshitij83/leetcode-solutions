class Solution {
    public String longestPalindrome(String s) {
        //for explanation check the cpp soln
        int maxlen = -1;
        int n = s.length();
        int start = 0;
        for(int i=0;i<n;i++) {
            int evenpal = expandAroundCenter(s,i,i+1);
            int oddpal = expandAroundCenter(s,i,i);
            int len = Math.max(evenpal,oddpal);
            if(len>maxlen) {
                maxlen = len;
                start = i - (maxlen - 1) / 2;
            }
        }
        return s.substring(start,start+maxlen);
    }
    public int expandAroundCenter(String s, int left, int right) {
        while(left>=0 && right<s.length() && s.charAt(left)==s.charAt(right)) {
            left--;
            right++;
        }
        return right-left-1;
    }
}