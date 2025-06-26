class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //optimal approach using 2 pointers and a hash array
        //TC - O(N) , SC - O(256)
        // int hash[256];
        // fill(begin(hash), end(hash), -1);
        // int maxlen = 0;
        // int r=0;
        // int l=0;
        // while(r<s.size()){
        //     if(hash[s[r]]!=-1){
        //         if(hash[s[r]]>=l){
        //             l = hash[s[r]]+1;
        //         }
        //     }
        //     hash[s[r]] = r;
        //     cout<<l<<" "<<r<<endl;
        //     maxlen = max(maxlen,r-l+1);
        //     r++;
        // }
        // return maxlen;

        //can also use map but SC would be O(N)
        unordered_map<char,int> mpp;
        int maxlen = 0;
        int r=0;
        int l=0;
        while(r<s.size()){
            if(mpp.find(s[r])!=mpp.end()){
                if(mpp[s[r]]>=l){
                    l = mpp[s[r]]+1;
                }
            }
            mpp[s[r]] = r;
            cout<<l<<" "<<r<<endl;
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;

        //naive approach by generating all substrings
        //TC - O(n^2) , SC - O(256)
        // int n = 0;
        // for(int i=0;i<s.size();i++){
        //     string sub = "";
        //     int hash[256] = {0};
        //     for(int j=i;j<s.size();j++){
        //         if(hash[s[j]]) break;
        //         sub += s[j];
        //         hash[s[j]] = 1;
        //         n = max(n,j-i+1);
        //     }
        // }
        // return n;
    }
};