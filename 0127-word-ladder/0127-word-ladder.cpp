class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //TC : O(word.size * wordlist.size(that keeps on decreasing as it is in set and we erase it) * 26)
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            //cout<<"hi"<<endl;
            for(int i=0;i<word.size();i++) {
                char original = word[i];
                for(char ch='a';ch<='z';ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        if(word==endWord) return steps+1;
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};