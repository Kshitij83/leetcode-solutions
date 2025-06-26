class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int min = INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>=nums[left]){
                if(nums[left]<min){
                    min = nums[left];
                    left=mid+1;
                }
                else{
                    left=mid+1;
                }
            }
            else{
                if(nums[mid]<min){
                    min=nums[mid];
                    right=mid-1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return min;
    }
};