class Solution {
public:
    void sortColors(vector<int>& nums) {
        int czero=0;
        int cone=0;
        int ctwo=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                czero++;
            }
            else if(nums[i]==1){
                cone++;
            }
            else if(nums[i]==2){
                ctwo++;
            }
        }
        vector<int> result;
        result.insert(result.begin(),ctwo,2);
        result.insert(result.begin(),cone,1);
        result.insert(result.begin(),czero,0);
        nums = result;
    }
};