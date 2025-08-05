class Solution {
public:

    int minCapability(vector<int>& nums, int k) {
        //idea : apply binary search on the range : min(nums) , max(nums)
        //determine mid as current capability, if u can pick elements greater than capability increment takes
        //if takes reach k it means u may have a chance of lowering your capability
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i : nums) {
            mini = min(mini,i);
            maxi = max(maxi,i); 
        }
        int left = mini;
        int right = maxi;
        while(left<right) {
            int mid = (left+right)/2;
            int take = 0;
            for(int i=0;i<nums.size();i++) {
                if(nums[i]<=mid) {
                    take++;
                    i++;
                }
            }
            if(take>=k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};