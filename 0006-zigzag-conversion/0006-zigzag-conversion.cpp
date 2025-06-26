class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()) return s;
        vector<string> rows(numRows);
        bool goingdown = false;
        int rownum = 0;
        for(char c : s) {
            rows[rownum] += c;
            if(rownum==0 || rownum==numRows-1) goingdown = !goingdown;
            rownum += (goingdown)?1:-1;
        }
        string result;
        for(auto c : rows) {
            result += c;
        }
        return result;
    }
};
