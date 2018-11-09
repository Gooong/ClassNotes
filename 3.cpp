#include <iostream>
#include <stack>

using namespace std;


int main3() {
    int t, n, next, tmp, a[1000];
    bool legal;
    stack<int> sta;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        while (!sta.empty())sta.pop();
        for (int j = 0; j < n; j++) cin >> a[j];

        next = 1;
        legal = true;
        for (int j = 0; j < n; j++) {
            if (sta.empty() && next <=n){
                sta.push(next);
                next ++;
            }

            if (a[j] == sta.top()) {
                sta.pop();
            } else if (a[j] < sta.top()) {
                legal = false;
                break;
            } else {
                for (; next <= a[j] && next <= n; next++) sta.push(next);

                if (sta.top() == a[j]) {
                    sta.pop();
                } else {
                    legal = false;
                    break;
                }
            }
        }

        if (legal) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }

    return 0;
}