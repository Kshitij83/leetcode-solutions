class Solution {
public:
    string minWindow(string s, string t) {
        //optimal approach - TC -> O(2N+M)
        //IDEA: USE 2 POINTER AND SLIDING WINDOW APPROACH, ALTER L ONLY WHEN COUNT REACHES T.SIZE
        int l=0, r=0, minlen = INT_MAX;
        int start = -1, count = 0;
        int hash[58] = {0};
        for(int i=0;i<t.size();i++){
            hash[t[i]-'A']++;
        }
        while(r < s.size()){
            if(hash[s[r]-'A'] > 0) count++;
            hash[s[r]-'A']--;
            while(count==t.size()){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    start = l;
                }
                hash[s[l]-'A']++;
                if(hash[s[l]-'A'] > 0) count--;
                l++;
            }
            r++;
        }
        return (start==-1)?"":s.substr(start,minlen);


        //brute force - TC -> O(N^2)
        //IDEA: CHECK ALL SUBSTRINGS AND IF THE CHARACTER APPEARS THEN DECREMENT IN HASH ARRAY TO ENSURE IT APPEARS EXACT NUMBER OF TIMES AS IN t
        // int minlen = INT_MAX;
        // int start = -1;
        // for(int i=0;i<s.size();i++){
        //     int count = 0;
        //     int hash[58] = {0}; //z is 122 and A is 65
        //     for(int j=0;j<t.size();j++){
        //         hash[t[j]-'A']++;
        //     }
        //     for(int j=i;j<s.size();j++){
        //         if(hash[s[j]-'A']>0) count++;
        //         hash[s[j]-'A']--;
        //         if(count==t.size()){
        //             if(j-i+1 < minlen){
        //                 minlen = j-i+1;
        //                 start = i;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // if(start == -1) return "";
        // return s.substr(start,minlen);
    }
};