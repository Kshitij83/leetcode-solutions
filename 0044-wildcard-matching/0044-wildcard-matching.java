class Solution {
    public boolean isMatch(String s, String p) {
        char str[] = s.toCharArray();
        char pat[] = p.toCharArray(); 
        int ls = str.length;
        int ind = 0;
        boolean star = false;
        for(int i=0;i<pat.length;i++) {
            if(pat[i]=='*' && star==false) {
                star = true;
                pat[ind] = pat[i];
                ind++;
            } 
            else if(pat[i]!='*') {
                pat[ind] = pat[i];
                ind++;
                star = false;
            }
        }
        int lp = ind;
        System.out.println(lp+ " "+ls);
        boolean dp[][] = new boolean[lp+1][ls+1];
        for(int i=0;i<=lp;i++) {
            for(int j=0;j<=ls;j++) {
                if(j==0) {
                    if(i==0) dp[i][j] = true;
                    else if(pat[i-1]=='*') dp[i][j] = dp[i-1][j];
                }
                else if(i>0 && (pat[i-1]==str[j-1] || pat[i-1]=='?') && dp[i-1][j-1]==true) dp[i][j] = true;
                else if(i>0 && pat[i-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        // for(int i=0;i<=lp;i++) {
        //     for(int j=0;j<=ls;j++) {
        //         System.out.print(dp[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        return dp[lp][ls];
    }
}