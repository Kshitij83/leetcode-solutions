class Solution {

    public void backtrack(List<String> result,String digits,Map<Character,String> phoneMap,String temp,int i) {
        if(i==digits.length()) {
            result.add(temp);
            return;
        }
        String letters = phoneMap.get(digits.charAt(i));
        for(char letter : letters.toCharArray()) {
            backtrack(result,digits,phoneMap,temp+letter,i+1);
        }
    }

    public List<String> letterCombinations(String digits) {
        if(digits==null || digits.isEmpty()) return new ArrayList<>();
        List<String> result = new ArrayList<>();
        Map<Character,String> phoneMap = new HashMap<>();
        phoneMap.put('2',"abc");
        phoneMap.put('3',"def");
        phoneMap.put('4',"ghi");
        phoneMap.put('5',"jkl");
        phoneMap.put('6',"mno");
        phoneMap.put('7',"pqrs");
        phoneMap.put('8',"tuv");
        phoneMap.put('9',"wxyz");
        backtrack(result,digits,phoneMap,"",0);
        return result;
    }
}