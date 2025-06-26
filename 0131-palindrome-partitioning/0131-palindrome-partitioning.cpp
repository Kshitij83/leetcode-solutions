class Solution {
public:

    bool isPalindrome(int start,int end,string s) {
        while(start<=end) {
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void func(vector<vector<string>>& res,vector<string>& path,string s,int index) {
        if(index==s.size()) {
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++) {
            if(isPalindrome(index,i,s)) {
                path.push_back(s.substr(index,i-index+1));
                func(res,path,s,i+1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(res,path,s,0);
        return res;
    }
};