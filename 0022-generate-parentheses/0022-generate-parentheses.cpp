class Solution {
public:
    void backtrack(int n, vector<string>& result, int opencnt, int closecnt, string s) {
        if(s.length()==n*2) {
            result.push_back(s);
            return;
        }
        if(opencnt<n) backtrack(n,result,opencnt+1,closecnt,s+"(");
        if(closecnt<opencnt) backtrack(n,result,opencnt,closecnt+1,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n,result,0,0,"");
        return result;
    }
};