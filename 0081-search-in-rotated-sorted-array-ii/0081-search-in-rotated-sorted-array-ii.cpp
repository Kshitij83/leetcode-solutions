class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[left]==nums[mid] && nums[mid]==nums[right]){
                right-=1;
                left+=1;
                continue;
            }
            if(nums[mid]>=nums[left]){
                if(nums[mid]>=target && target>=nums[left]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return false;
    }
};