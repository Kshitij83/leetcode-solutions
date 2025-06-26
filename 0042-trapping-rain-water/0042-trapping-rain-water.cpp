class Solution {
public:
    int trap(vector<int>& height) {

        //OPTIMAL APPROACH TC - O(N) , SC - O(1)
        //logic: use two pointers and iterate only the smaller one
        int lmax = 0;
        int rmax = 0;
        int total = 0;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l]) total+=lmax-height[l];
                else lmax=height[l];
                l+=1;
            }
            else{
                if(rmax>height[r]) total+=rmax-height[r];
                else rmax=height[r];
                r-=1;
            }
        }
        return total;

        //BETTER APPROACH without leftmax and remembering it at last loop
        //TC - O(2N) , SC - O(N)
        // int h = height.size();
        // if(h<=1) return 0;
        // vector<int> rightmax(h,0);
        // rightmax[h-1] = height[h-1];
        // for(int i=h-2;i>=0;i--){
        //     if(height[i]>rightmax[i+1]) rightmax[i] = height[i];
        //     else rightmax[i] = rightmax[i+1];
        // }
        // int sum = 0;
        // int leftmax = height[0];
        // for(int i=1;i<h-1;i++){
        //     if(height[i]<leftmax && height[i]<rightmax[i]){
        //         sum += (min(leftmax,rightmax[i])-height[i]);
        //     }
        //     if(leftmax<height[i]) leftmax = height[i];
        // }
        // return sum;

        //TC - O(2N) , SC - O(2N)
        //logic used: water will log in an area which is less than its right max and left max
        // int h = height.size();
        // if(h<=1) return 0;
        // vector<int> leftmax(h,0);
        // vector<int> rightmax(h,0);
        // leftmax[0] = height[0];
        // rightmax[h-1] = height[h-1];
        // for(int i=1;i<h;i++){
        //     if(height[i]>leftmax[i-1]) leftmax[i] = height[i];
        //     else leftmax[i] = leftmax[i-1];
        //     if(height[h-i-1]>rightmax[h-i]) rightmax[h-i-1] = height[h-i-1];
        //     else rightmax[h-i-1] = rightmax[h-i];
        // }
        // int sum = 0;
        // for(int i=1;i<h-1;i++){
        //     if(height[i]<leftmax[i] && height[i]<rightmax[i]){
        //         sum += (min(leftmax[i],rightmax[i])-height[i]);
        //     }
        // }
        // return sum;
    }
};