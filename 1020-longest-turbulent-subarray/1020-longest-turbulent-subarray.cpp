class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1) return 1;
        for(int i=0;i<arr.size()-1;i++) {
            if(arr[i]!=arr[i+1]) break;
            if(i==arr.size()-2) return 1;
        }
        int max_count = 2;
        int count = 2;
        for(int i=1;i<arr.size()-1;i++) {
            bool prevGreater = (arr[i-1]>arr[i]);
            bool prevSmaller = (arr[i-1]<arr[i]);
            if((arr[i]>arr[i+1] && prevSmaller) || (arr[i]<arr[i+1] && prevGreater)) {
                count++;
                max_count = max(max_count,count);
            }
            else count = 2;
        }
        return max_count;
    }
};