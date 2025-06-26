class Solution {
    public void backtrack(int[] candidates, int target, int start, List<Integer> temp, List<List<Integer>> result) {
        if(start==candidates.length) {
            if(target==0) result.add(new ArrayList<>(temp));
            return;
        }
        if(target>=candidates[start]) {
            temp.add(candidates[start]);
            backtrack(candidates,target-candidates[start],start,temp,result);
            temp.remove(temp.size()-1);
        }
        backtrack(candidates,target,start+1,temp,result);
        
        // if(target == 0) {
        //     result.add(new ArrayList<>(temp));
        //     return;
        // }
        // for(int i=start;i<candidates.length;i++) {
        //     if(target>=candidates[i]) {
        //         temp.add(candidates[i]);
        //         backtrack(candidates,target-candidates[i],i,temp,result);
        //         temp.remove(temp.size()-1);
        //     }
        // }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(candidates,target,0,new ArrayList<>(),result);
        return result;
    }
}