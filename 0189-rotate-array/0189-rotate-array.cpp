class Solution {
public:
    void rotate(vector<int>& nums, int k) {
//         for(int i=0;i<k;i++){
//             int n = nums[nums.size()-1];
//             nums.erase(nums.end()-1);
//             nums.insert(nums.begin(),n);
//         }
        k=k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
      
    }
};