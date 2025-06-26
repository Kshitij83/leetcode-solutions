class Solution {
    public void backtrack(int n, List<String> result, int opencnt, int closecnt, String s) {
        if(s.length()==n*2) {
            result.add(s);
            return;
        }
        if(opencnt < n) backtrack(n,result,opencnt+1,closecnt,s+"(");
        if(closecnt < opencnt) backtrack(n,result,opencnt,closecnt+1,s+")");
    }
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(n,result,0,0,"");
        return result;
    }
}