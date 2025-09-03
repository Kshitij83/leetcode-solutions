class Solution {
public:
    string originalDigits(string s) {
        int n = s.size();
        //vector<int> alphabets(26,0);
        vector<string> nums = {"zero","six","four","eight","two","three","five","seven","nine","one"};
        vector<int> digits = {0,6,4,8,2,3,5,7,9,1};
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++) {
            mpp[s[i]]++;
        }
        string res;
        for(int i=0;i<10;i++) {
            string num = nums[i];
            int freq = 1e9;
            for(char c : num) {
                if(mpp.find(c)!=mpp.end() && mpp[c]>0) {
                    freq = min(freq,mpp[c]);
                }
                else {
                    freq = 1e9;
                    break;
                }
            }
            cout<<freq<<" ";
            if(freq!=1e9) {
                for(char c : num) {
                    mpp[c] -= freq;
                }
                res.append(freq,digits[i]+'0');
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};