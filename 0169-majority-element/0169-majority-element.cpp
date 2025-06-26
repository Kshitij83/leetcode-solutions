class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int num;
        for(int i=0;i<nums.size();i++) {
            if(count==0) {
                num = nums[i];
                count++;
            }
            else {
                if(nums[i]==num) count++;
                else count--;
            }
        }
        count=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==num) count++;
        }
        return (count>nums.size()/2) ? num : -1;
    }
};