class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n,0);
        stack<pair<int,int>> st;
        st.push({temperatures[n-1],0});
        for(int i=n-2;i>=0;i--) {
            int ans = 1;
            while(!st.empty() && temperatures[i]>=st.top().first) {
                ans += st.top().second;
                st.pop();
            }
            if(st.empty()) {
                st.push({temperatures[i],0});
                answer[i] = 0;
            }
            else {
                st.push({temperatures[i],ans});
                answer[i] = ans;
            }
        }
        return answer;
    }
};