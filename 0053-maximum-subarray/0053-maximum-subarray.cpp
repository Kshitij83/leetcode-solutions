class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum = 0;
        int ansEnd,start;
        for(int i=0;i<nums.size();i++) {
            if(sum==0) start = i;
            sum += nums[i];
            if(sum>max_sum) {
                max_sum = sum;
                ansEnd = i;
            }
            if(sum<0) sum = 0;
        }
        for(int i=start;i<=ansEnd;i++) cout<<nums[i]<<" ";
        return max_sum;
    }
};