class Solution {
    public String orderlyQueue(String s, int k) {
        if(k>1){
            char[] arr= s.toCharArray();
            Arrays.sort(arr);
            return new String(arr);
        }
        else{
            String min = s;
            String r = s+s;
            for(int i=1;i<s.length();i++){
                if(r.substring(i,i+s.length()).compareTo(min)<0)
                    min=r.substring(i,i+s.length());
            }
            return min;
        }
    }
}
