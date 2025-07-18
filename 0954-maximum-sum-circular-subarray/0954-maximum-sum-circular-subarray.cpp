class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = INT_MIN;
        int currMax = 0;
        int globalMin = INT_MAX;
        int currMin = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++) {
            total += nums[i];
            currMax = max(currMax+nums[i],nums[i]);
            globalMax = max(currMax,globalMax);
            currMin = min(currMin+nums[i],nums[i]);
            globalMin = min(currMin,globalMin);
        }
        return (globalMax>0) ? max(globalMax,total-globalMin) : globalMax;
    }
};