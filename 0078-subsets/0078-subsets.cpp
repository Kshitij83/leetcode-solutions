class Solution {
public:
// apply recursion by first pushing and incrementing index and then by popping and incrementing index, while base case being to return when 
// index becomes equal to nums.size
//TC - O(2^N) SC - O(2^N)
    vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> subset;

    //     createSubset(nums, 0, res, subset);
    //     return res;        
    // }

    // void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
    //     if (index == nums.size()) {
    //         res.push_back(subset);
    //         return;
    //     }

    //     subset.push_back(nums[index]);
    //     createSubset(nums, index + 1, res, subset);

    //     subset.pop_back();
    //     createSubset(nums, index + 1, res, subset);   

        //using bitwise operations
        //TC - O() , SC - O()
        vector<vector<int>> result;
        vector<int> subset;
        int n = nums.size();
        for(int i=0;i<=(1<<n)-1;i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)) subset.push_back(nums[j]);
            }
            result.push_back(subset);
            subset.clear();
        }
        return result;
    }
    
};