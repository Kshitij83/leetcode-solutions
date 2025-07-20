class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int l = 0, r = 0;
        int p = players.size();
        int t = trainers.size();
        int assigned = 0;
        while(l<p && r<t) {
            if(players[l]<=trainers[r]) {
                assigned++;
                l++;
            }
            r++;
        }
        return assigned;
    }
};