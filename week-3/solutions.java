class s674 {
    public int findLengthOfLCIS(int[] nums) {
        if(nums.length<2)
            return nums.length;
        int max=0;
        int l=0;
        for(int r=1;r<nums.length;r++){
            if(nums[r]<=nums[r-1])
                l=r;
            max=Math.max(max,r-l+1);
        }
        return max;
    }
}

class s3 {
    
    public int lengthOfLongestSubstring(String s) {
        if(s.length()<2)
            return s.length();
        
        int l=0, r=0, result=0;
        Set<Character> seen = new HashSet<>();
        
        while(r<s.length()){
            while(seen.contains(s.charAt(r))){
                seen.remove(s.charAt(l));
                l++;
            }
            seen.add(s.charAt(r));
            result=Math.max(r-l+1,result);
            r++;
        }
        return result;
    }
    
    public int lengthOfLongestSubstringMap(String s) {
        if(s.length()<2)
            return s.length();
        
        int l=0, r=0, result=0;
        Map<Character,Integer> pos = new HashMap<>();
        
        while(r<s.length()){
            if(pos.containsKey(s.charAt(r))){
                l=Math.max(l,pos.get(s.charAt(r))+1);
            }
            pos.put(s.charAt(r),r);
            result=Math.max(r-l+1,result);
            r++;
        }
        return result;
    }
}


class s1695 {
    public int maximumUniqueSubarray(int[] nums) {
        if(nums.length<2)
            return nums[0];
        
        int l=0, r=0, sum=0, result=0;
        Set<Integer> seen = new HashSet<>();
        
        while(r<nums.length){
            while(seen.contains(nums[r])){
                sum-=nums[l];
                seen.remove(nums[l]);
                l++;
            }
            seen.add(nums[r]);
            sum+=nums[r];
            result=Math.max(sum,result);
            r++;
        }
        return result;
    }
    
    
    public int maximumUniqueSubarrayArray(int[] nums) {
        if(nums.length<2)
            return nums[0];
        
        int l=0, r=0, sum=0, result=0;
        boolean[] seen = new boolean[10001];
        
        while(r<nums.length){
            while(seen[nums[r]]==true){
                sum-=nums[l];
                seen[nums[l]]=false;
                l++;
            }
            seen[nums[r]]=true;
            sum+=nums[r];
            result=Math.max(sum,result);
            r++;
        }
        return result;
    }

}
