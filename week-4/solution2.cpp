#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <bitset>
#include <list>
using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        int n = S.size();
        if(K > 1){
            sort(S.begin(), S.end());
            return S;
        }
        int result = 0;
        S += S;
        for(int i = 1; i < n; i++){
            if(compare(S,i,result,n)) result = i;
        }
        return S.substr(result, n);
    }
    bool compare(string& s, int i, int r, int n){
        for(int j =0; j < n; j++){
            if(s[i + j] < s[r + j]) return true;
            else if (s[i + j] > s[r + j]) return false;
        }
        return false;
    }
};
