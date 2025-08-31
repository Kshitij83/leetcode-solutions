class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,-1);
        int maxi = 0;
        int ind = -1;
        vector<int> ans;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if((nums[i]%nums[j])==0 && dp[i]<dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                    if(dp[i]>maxi) {
                        maxi = dp[i];
                        ind = i;
                    }
                } 
            }
        }
        if(ind==-1) ans.push_back(nums[0]);
        while(ind!=-1) {
            ans.push_back(nums[ind]);
            ind = hash[ind];
        }
        return ans;
    }
};