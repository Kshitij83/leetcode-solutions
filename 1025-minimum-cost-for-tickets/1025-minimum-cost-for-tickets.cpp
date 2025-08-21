class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        unordered_set<int> travel(days.begin(),days.end());
        vector<int> dp(days[days.size()-1]+1);
        for(int i=1;i<dp.size();i++) {
            if(travel.find(i) == travel.end()) dp[i] = dp[i-1];
            else dp[i] = min({dp[i-1] + cost[0],dp[max(0,i-7)] + cost[1],dp[max(0,i-30)] + cost[2]});
        }
        return dp[dp.size()-1];
    }
};