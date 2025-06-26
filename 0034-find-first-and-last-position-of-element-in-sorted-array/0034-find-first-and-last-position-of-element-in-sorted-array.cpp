class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left=0;
        int right=nums.size()-1;
        if(nums.size()==0){
            ans.insert(ans.begin(),2,-1);
            return ans;
        }
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                cout<<"You came here";
                int left1=mid;
                int right1=mid;
                while(left1>=0 && nums[left1]==target){
                    left1--;
                }
                while(right1<=nums.size()-1 && nums[right1]==target){
                    right1++;
                }
                left1+=1;
                right1-=1;
                ans.push_back(left1);
                ans.push_back(right1);
                return ans;
            }
        }
        ans.insert(ans.begin(),2,-1);
        return ans;
    }
};