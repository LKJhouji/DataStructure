#include <deque>

class My_queue {
public:
    deque<int> dq;

    void push(int x) {
        while (x > dp.back()) {
            dp.pop_back();
        }
        dp.push_back(x);
    }

    void pop(int value) {
        if (!dq.empty() && value == dp.front()) {
            dp.pop_front();
        }
    }
    
};