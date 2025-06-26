class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breaker = -1;
        int n = nums.size()-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breaker = i;
                break;
            }
        }
        if(breaker==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n;i>breaker;i--){
                if(nums[i]>nums[breaker]){
                    swap(nums[i],nums[breaker]);
                    break;
                }
            }
            reverse(nums.begin()+breaker+1,nums.end());
        }
    }
};