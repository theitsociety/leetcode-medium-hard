#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long result = 0;
        unordered_map<double, long long> m;
        for(auto& r : rectangles){
           result += m[(double)r[0] / r[1]]++;
        }

        return result;
    }
};