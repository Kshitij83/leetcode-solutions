class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l = j+1;
                int k = nums.size()-1;
                while(l<k){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(target>sum){
                        l++;
                        while(l<k && nums[l]==nums[l-1])l++;
                    }
                    else if(target<sum){
                        k--;
                        while(l<k && nums[k]==nums[k+1])k--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[k]});
                        l++;
                        k--;
                        while(l<k && nums[l]==nums[l-1])l++;
                        while(l<k && nums[k]==nums[k+1])k--;
                    }
                }
            }
        }
        return ans;
    }
};