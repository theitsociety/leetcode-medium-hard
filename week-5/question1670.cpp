#include<queue>
using namespace std;
class FrontMiddleBackQueue {
public:
    deque<int> right, left;
    int size;
    FrontMiddleBackQueue() {
        size=0;
    }
    
    void pushFront(int val) {
        size++;
        left.push_front(val);
        if(left.size() - right.size() == 2)
        {
            int back = left.back();
            left.pop_back();
            right.push_front(back);
        }
    }
    
    void pushMiddle(int val) {
        size++;
        if(right.size() != left.size()){
            int tmp = left.back();
            left.pop_back();
            right.push_front(tmp);
        }
        left.push_back(val);
    }
    
    void pushBack(int val) {
        size++;
        right.push_back(val);
        if(right.size() > left.size()){
            int front = right.front();
            right.pop_front(),
            left.push_back(front);
        }
    }
    
    int popFront() {
        if(size == 0) return -1;
        size--;
        int front = left.front();
        left.pop_front();
        balance();
        return front;
    }
    
    int popMiddle() {
        if(size == 0) return -1;
        if(size == 1) return popFront(); 
        size--;
        int val = left.back();
        left.pop_back();
        balance();
        return val;
    }
    
    int popBack() {
        if(size == 0) return -1;
        if(size == 1) return popFront(); 
        size--;
        int val = right.back();
        right.pop_back();
        if(left.size() - right.size() == 2)
        {
            int back = left.back();
            left.pop_back();
            right.push_front(back);
        }
        return val;
    }
    void balance(){
        if(left.size()<right.size()){
            int tmp = right.front();
            right.pop_front();
            left.push_back(tmp);
        }

    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */