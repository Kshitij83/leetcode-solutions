class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long ans = 0;
        while(i<n) {
            long long cz = 0;
            while(i<n && nums[i]==0) {
                cz++;
                i++;
            }
            ans += ((cz*(cz+1))/2);
            i++;
        }
        return ans;
    }
};