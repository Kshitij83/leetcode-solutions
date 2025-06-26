class Solution {
public:

    // void findPermut(vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans,vector<int>& freq) {
    //     if(ds.size()==nums.size()) {
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++) {
    //         if(!freq[i]) {
    //             ds.push_back(nums[i]);
    //             freq[i] = 1;
    //             findPermut(nums,ds,ans,freq);
    //             freq[i] = 0;
    //             ds.pop_back();
    //         }
    //     }
    // }

    void findPermute(vector<int>& nums,vector<vector<int>>& ans,int index) {
        if(index==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++) {
            swap(nums[i],nums[index]);
            findPermute(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        //approach 2: same tc but o(1) sc, idea: do swapping by looping
        vector<vector<int>> ans;
        findPermute(nums,ans,0);
        return ans;



        //approach 1 : tc - O(n! * n) , sc - o(n) + o(n) (using extra space)
        // vector<int> ds;
        // vector<vector<int>> ans;
        // vector<int> freq(nums.size(),0);
        // findPermut(nums,ds,ans,freq);
        // return ans;
    }
};