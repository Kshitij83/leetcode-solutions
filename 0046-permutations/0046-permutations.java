class Solution {
    public void backtrack(int[] nums, int index, List<List<Integer>> result) {
        if(index==nums.length) {
            List<Integer> perm = new ArrayList<>();
            for (int num : nums) perm.add(num);
            result.add(perm);
            return;
        }
        for(int i=index;i<nums.length;i++) {
            swap(nums,i,index);
            backtrack(nums,index+1,result);
            swap(nums,i,index);
        }
    }
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(nums,0,result);
        return result;
    }
}