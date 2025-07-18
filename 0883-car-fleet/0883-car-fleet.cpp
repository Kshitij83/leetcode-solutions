class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> posSpeed;
        for (int i = 0; i < n; i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.rbegin(),posSpeed.rend());
        stack<double> st;
        for(auto p : posSpeed) {
            double val = (double)(target-p.first)/p.second;
            if(!st.empty() && st.top()>=val) continue;
            st.push(val);
        }
        return st.size();
    }
};