#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class PriorityQueue {
public:
    PriorityQueue<T>(bool maxQ = true) : maxQueue(maxQ) {
        vec = vector<T>(10000);
    }

    bool is_max_queue() {
        return maxQueue;
    }

    void clear() {
        vec.clear();
    }

    unsigned long size() {
        return vec.size();
    }

    void push(T data) {
        vec.push_back(data);
        swim(vec.size() - 1);
    }

    void pop() {
        T largest = vec[0];
        vec[0] = vec[vec.size() - 1];
        vec.pop_back();
        sink(0);
    }

    T get_top() {
        return vec[0];
    }

private:
    vector<T> vec;
    bool maxQueue;

    bool inline compare(T a, T b) {
        return maxQueue ? a >= b : a <= b;
    }

    //上浮
    void swim(unsigned long i) {
        T tmp;
        while (i != 0 && !compare(vec[i / 2], vec[i])) {
            tmp = vec[i];
            vec[i] = vec[i / 2];
            vec[i / 2] = tmp;
            i = i / 2;
        }
    }

    //下沉
    void sink(unsigned long i) {
        T tmp;
        unsigned long largest = i;
        while (2 * i < vec.size()) {
            if (!compare(vec[i], vec[2 * i])) {
                largest = 2 * i;
            }
            if (2 * i + 1 < vec.size() && !compare(vec[largest], vec[2 * i + 1])) {
                largest = 2 * i + 1;
            }
            if (largest != i) {
                tmp = vec[largest];
                vec[largest] = vec[i];
                vec[i] = tmp;
                i = largest;
            } else {
                break;
            }
        }
    }
};

template<typename T>
class MedianQueue {
public:
    MedianQueue<T>() {
        max_queue = PriorityQueue<T>();
        min_queue = PriorityQueue<T>(false);
    }

    unsigned long size() {
        return max_queue.size() + min_queue.size();
    }

    void clear() {
        max_queue.clear();
        min_queue.clear();
    }

    void push(T data) {
        if (max_queue.size() == min_queue.size()) {
            // insert left
            max_queue.push(data);
        } else {
            // insert right
            min_queue.push(data);
        }

        if (min_queue.size() != 0 && max_queue.get_top() > min_queue.get_top()) {
            T tmp = max_queue.get_top();
            max_queue.pop();
            max_queue.push(min_queue.get_top());
            min_queue.pop();
            min_queue.push(tmp);
        }
    }

    void pop() {
        if (size() != 0) {
            if (max_queue.size() > min_queue.size()) {
                max_queue.pop();
            } else if (max_queue.size() == min_queue.size()) {
                max_queue.pop();
                max_queue.push(min_queue.get_top());
                min_queue.pop();
            } else {
                min_queue.pop();
            }
        }
    }

    T get_median() {
        if (max_queue.size() >= min_queue.size()) {
            return max_queue.get_top();
        } else {
            return min_queue.get_top();
        }
    }


private:
    PriorityQueue<T> max_queue;
    PriorityQueue<T> min_queue;
};

int main2_1() {
    int T, N, data;
    MedianQueue<int> mq;
    char op;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        mq.clear();

        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%c", &op);
            scanf("%c", &op);
            if (op == 'I') {
                scanf("%d", &data);
                mq.push(data);
            } else if (op == 'Q') {
                printf("%d\n", mq.get_median());
            } else {
                mq.pop();
            }
        }

    }
    return 0;
}