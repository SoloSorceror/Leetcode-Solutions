class Solution {
    public String reverseWords(String s) {
        Stack stack = new Stack<>();
        StringBuilder curr = new StringBuilder();

        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);

            if(c != ' '){
                curr.append(c);
            }
            else if(curr.length() > 0){
                stack.push(curr.toString());
                curr.setLength(0);
            }           
        }

        if(curr.length() > 0){
            stack.push(curr.toString());
        }

        StringBuilder result = new StringBuilder();

        while(!stack.isEmpty()){
            result.append(stack.pop());
            if(!stack.isEmpty()){
                result.append(' ');
            }
        }
        return result.toString();
    }
}