class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(mpp.find(sum-k)!=mpp.end()) count += mpp[sum-k];
            mpp[sum]++;
        }


        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //             count++;
        //         }
        //     }
        //     sum = 0;
        // }
        // if(nums[nums.size()-1]==k){
        //     count++;
        // }
        return count;
    }
};