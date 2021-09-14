#include<vector>
using namespace std;
class StockSpanner {
public:
    vector<vector<int>> stock;
    int n = 0;
    StockSpanner() : stock(){
        
    }
    
    int next(int price) {
       int count = 1;
       while (n && stock[n-1][0] <= price)
       {
           count += stock[--n][1];
        }
        if(n>= stock.size()){
            stock.push_back({price, count});
        }
        else{
            stock[n][0] = price;
            stock[n][1] = count;
        }
        n++;
        return count;
    }
};