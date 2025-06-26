class Solution {
public:

    void findCandidates(vector<int>& candidates,int target,set<vector<int>,less<>>& unique,vector<int>& temp, int i) {
        if(i==candidates.size()) {
            if(target==0) {
                unique.insert(temp);
            }
            return;
        }
        if(candidates[i]<=target) {
            temp.push_back(candidates[i]);
            findCandidates(candidates,target-candidates[i],unique,temp,i);
            temp.pop_back();
        }
        findCandidates(candidates,target,unique,temp,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>,less<>> unique;
        vector<int> temp;
        findCandidates(candidates,target,unique,temp,0);
        vector<vector<int>> result;
        for(auto it : unique) {
            result.push_back(it);
        }
        return result;
    }
};