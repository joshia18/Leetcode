class Solution {
    public String removeKdigits(String num, int k) {
        
        Stack<Character> stk = new Stack<>();
        
        for(char c : num.toCharArray()){
            while(!stk.isEmpty() && stk.peek() > c &&  k > 0){
                stk.pop();
                k--;
            }
            
            stk.push(c);
        }
        
        while(!stk.isEmpty() && k > 0){
            stk.pop();
            k--;
        }
        
        StringBuilder sb = new StringBuilder();
        
        while(!stk.isEmpty()){
            sb.append(stk.pop());
        }
        
        sb.reverse();
        
        while(sb.length() > 1 && sb.charAt(0) == '0'){
            sb.deleteCharAt(0);
        }
        
        if(sb.length() == 0) return "0";
        
        return sb.toString();
        
    }
}