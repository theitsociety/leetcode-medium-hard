/**
 * @param {string} s
 * @return {number}
 * Solution with searching char in substring
 */
 var lengthOfLongestSubstring = function(s) {
    
  if (s.length < 2) {
      return s.length;
  }
  let l = 0, r = 0, len = 0;
  
  while (r < s.length - 1) {
      r++;
      const ind = s.indexOf(s[r], l);
      l = ind < r ? ind + 1 : l;
      len = Math.max(len, r - l + 1)
  }
  return len;
};



/**
 * @param {string} s
 * @return {number}
 * Solution with using char map
 */
var lengthOfLongestSubstring = function(s) {
  var l=-1,ans=0,arr=[];
  for(var i=0;i<256;i++)arr.push(-1);
  for(var i=0;i<s.length;i++){
      var j=s.charCodeAt(i);
      l=Math.max(l,arr[j]);
      ans=Math.max(ans,i-l);
      arr[j]=i;
  }
  return ans;
};