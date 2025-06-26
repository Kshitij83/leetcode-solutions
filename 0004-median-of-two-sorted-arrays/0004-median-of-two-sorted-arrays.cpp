class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(n<m) return findMedianSortedArrays(nums2,nums1);
        int left=0;
        int right = m;
        int left1 = (m+n+1)/2;
        while(left<=right){
            int mid1=(left+right)/2;
            int mid2=left1-mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX; 
            if(mid1<m) r1 = nums1[mid1];
            if(mid2<n) r2 = nums2[mid2];
            if(mid1-1>=0) l1 = nums1[mid1-1]; 
            if(mid2-1>=0) l2 = nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if((m+n)%2==1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2){
                right=mid1-1;
            }
            else{
                left=mid1+1;
            }
        }
        // if(index*2 == m+n){
        //     index--;
        // }
        // int index1 = index+1;
        // int count = 0;
        // int i=0;
        // int j=0;
        // int first_index,second_index;
        // while(i<m && j<n){
        //     if(nums1[i]<nums2[j]){
        //         if(count==index){
        //             first_index=nums1[i];
        //         }
        //         if(count==index1){
        //             second_index=nums1[i];
        //         }
        //         count++;
        //         i++;
        //     }
        //     else{
        //         if(count==index){
        //             first_index=nums2[j];
        //         }
        //         if(count==index1){
        //             second_index=nums2[j];
        //         }
        //         count++;
        //         j++;
        //     }
        // }
        // while(i<m){
        //     if(count==index){
        //         first_index=nums1[i];
        //     }
        //     if(count==index1){
        //         second_index=nums1[i];
        //     }
        //     count++;
        //     i++;
        // }
        // while(j<n){
        //     if(count==index){
        //         first_index=nums2[j];
        //     }
        //     if(count==index1){
        //         second_index=nums2[j];
        //     }
        //     count++;
        //     j++;
        // }
        // double answer;
        // if((m+n)%2==0){
        //     answer = ((double)first_index+(double)second_index)/2.0;
        // }
        // else{
        //     answer = (double)first_index;
        // }
        // return answer;
        return 0;
    }
};