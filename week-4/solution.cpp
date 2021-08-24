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
        if(K > 1){
            sort(S.begin(), S.end());
            return S;
        }
        int n = S.size();
        string result = S;
        S += S;
        for(int i = 0; i < n; i++){
            if(result > S.substr(i,n)) result = S.substr(i);
        }
        return result.substr(0,n);
    }
};
