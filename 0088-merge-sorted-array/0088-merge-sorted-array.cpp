class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m,nums1.end());
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        // for(int i=0;i<n;i++){
        //     nums1[i+m]=nums2[i];
        // }
        // sort(nums1.begin(),nums1.end());
    }
};