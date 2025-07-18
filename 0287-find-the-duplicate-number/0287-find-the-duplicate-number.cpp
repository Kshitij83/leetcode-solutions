class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //optimal approach : TC - O(N) , SC - O(1)
        //idea: use slow and fast pointers like in linked list cycle detection
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow!=fast);
        slow = nums[0];
        while(slow!=fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;

        //using binary search
        //TC - O(nlogn) , SC - O(1);
        // int left = 1;
        // int right = nums.size()-1;
        // while(left<right) {
        //     int mid = (left+right)/2;
        //     int count = 0;
        //     for(int num : nums) {
        //         if(num <= mid) count++;
        //     }
        //     if(count<=mid) left = mid+1;
        //     else right = mid;
        // }
        // return left;
    }
};