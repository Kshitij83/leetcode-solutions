class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxarea = INT_MIN;
        while(left<right) {
            int area = min(height[left],height[right]) * (right - left);
            maxarea = max(area,maxarea);
            if(height[left]<height[right]) left++;
            else right--;
        }
        return maxarea;
    }
};