class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //optimal approach using buckets, form bigger solutions using smaller solutions(let the bitwise operators do their job)
        //TC - O(n) , SC - O(1)
        int ones = 0; //if not in twos then its in ones
        int twos = 0; //if its in ones only then can it come to twos
        for(int i=0;i<nums.size();i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
        
        //more better approach
        //TC - O(nlogn) + O(n/3), SC - O(1);
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<nums.size();i+=3){
        //     if(nums[i]!=nums[i-1]){
        //         return nums[i-1];
        //     }
        // }
        // return nums[nums.size()-1];

        //better approach reduced memory
        //TC - O(32*n) , SC - O(1)
        // int ans = 0;
        // for(int i=0;i<=31;i++){
        //     long long int cnt = 0;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[j] & 1<<i){
        //             cnt++;
        //         }
        //     }
        //     if(cnt%3!=0){
        //         ans = ans|(1<<i);
        //     }
        // }
        // return ans;

        //brute force using mapping 
        //TC - O(n*logm) + O(m) , SC - O(m) , m = (n/3)+1
        // unordered_map<int,int> mpp;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it:mpp){
        //     if(it.second == 1){
        //         return it.first;
        //     }
        // }
        // return 0;
    }
};