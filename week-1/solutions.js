
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
 var threeSum = function(nums) {
  const sortedArray= nums.sort( (a, b) => a - b);
  let ind = 0;
  const results = [];
  for (const num of sortedArray) {
      // console.log(ind, num);
      let start = ++ind, end = sortedArray.length -1;
      while (start < end) {
          const total = sortedArray[start] + sortedArray[end] + num;
          if (total === 0) {
              const triple =  JSON.stringify([ num, sortedArray[start],  sortedArray[end] ]);
              if (results.indexOf(triple) === -1) {
                  results.push(triple);      
              }
          }
          if (total >= 0){
              end--;
          } else {
              start++;
          }
      } 
  }
  return results.map( el => JSON.parse(el));
};