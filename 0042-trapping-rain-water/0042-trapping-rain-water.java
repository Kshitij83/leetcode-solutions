class Solution {
    public int trap(int[] height) {
        //to see explanation, see cpp code
        int h = height.length;
        int l = 0;
        int r = h-1;
        int lmax = height[0];
        int rmax = height[h-1];
        int total = 0;
        while(l<r) {
            if(height[l]<=height[r]) {
                if(lmax>height[l]) total += lmax-height[l];
                else lmax = height[l]; 
                l++;
            }
            else {  
                if(rmax>height[r]) total += rmax-height[r];
                else rmax = height[r];
                r--;
            }
        }
        return total;
    }
}