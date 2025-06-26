class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int max_count = 1;
        int count = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]+1){
                count++;
                cout<<nums[i]<<" ";
                max_count = max(count,max_count);
            }
            else if(nums[i+1]==nums[i]){
                continue;
            }
            else{
                count = 1;
            }
            
        }
        return max_count;
    }
};