class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> hmp = new HashSet<>();
        int l = 0;
        int r = 0;
        int maxlen = Integer.MIN_VALUE;
        while(r<s.length()) {
            while(hmp.contains(s.charAt(r))!=false) {
                hmp.remove(s.charAt(l));
                l++;
            }
            hmp.add(s.charAt(r));
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return (maxlen==Integer.MIN_VALUE) ? 0:maxlen;
    }
    public int max(int a, int b) {
        return (a>b) ? a:b;
    }
}