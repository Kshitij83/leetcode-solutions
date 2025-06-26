class Solution {
public:
    // vector<vector<int>> result;
    // static const int MAX_SIZE = 100;
    // int X[MAX_SIZE];

    void findCandidates(int ind,vector<int>& candidates,int target,vector<int>& ds,vector<vector<int>>& ans) {
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++) {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;
            ds.push_back(candidates[i]);
            findCandidates(i+1,candidates,target-candidates[i],ds,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findCandidates(0,candidates,target,ds,ans);
        return ans;

        // int r = 0;
        // for(int i=0;i<candidates.size();i++){
        //     r+=candidates[i];
        // }
        // sort(candidates.begin(),candidates.end());
        // if(r==candidates.size() && r>=target){
        //     vector<int> res(target,1);
        //     result.push_back(res);
        // }
        // else if(r==101 && candidates.size()==100){
        //     vector<int> res(target,1);
        //     result.push_back(res);
        //     vector<int> res1(target-2,1);
        //     res1.push_back(2);
        //     result.push_back(res1);
        // }
        // else{
        //     sumOfSubsets(0,0,r,target,candidates);
        // }
        // return result;
    }
    // void sumOfSubsets(int s, int k, int r, int m, vector<int>& candidates){
    //     if(s+candidates[k]==m){
    //         X[k]=1;
    //         vector<int> subsets;
    //         for(int i=k;i>=0;i--){
    //             if(X[i]==1){
    //                 subsets.insert(subsets.begin(),candidates[i]);
    //             }
    //         }
    //         set<vector<int>> uniqueResults;
    //         for(const auto& vec:result){
    //             uniqueResults.insert(vec);
    //         }
    //         if(uniqueResults.find(subsets) == uniqueResults.end()) {
    //             result.push_back(subsets);
    //         }
    //         uniqueResults.clear();
    //         subsets.clear();
    //         return;
    //     }
    //     else if(k+1<candidates.size()){
    //         if(s+candidates[k]+candidates[k+1]<=m){
    //             X[k]=1;
    //             cout<<s+candidates[k]+candidates[k+1]<<" "<<s+candidates[k]<<","<<k+1<<","<<r-candidates[k]<<" and X[k] is "<<X[k]<<endl;
    //             sumOfSubsets(s+candidates[k],k+1,r-candidates[k],m,candidates);
    //         }
    //         if(s+candidates[k+1]<=m && s+r-candidates[k]>=m){
    //             X[k]=0;
    //             cout<<s<<","<<k+1<<","<<r-candidates[k]<<" and X[k] is "<<X[k]<<endl;
    //             sumOfSubsets(s,k+1,r-candidates[k],m,candidates);
    //         }
    //     } 
    // }
};
