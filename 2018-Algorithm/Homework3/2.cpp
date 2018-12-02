//
// Created by gongxr on 18-12-2.
//

#include <iostream>

using namespace std;

int height[100], r_height[100], l[100], u[100];

void lis(int *h, int *ta, int m) {
    ta[0] = 1;
    for (int i = 1; i < m; i++) {
        int s = 0;
        for (int j = 0; j < i; j++) {
            if (h[j] < h[i]) {
                s = max(s, ta[j]);
            }
        }
        ta[i] = s + 1;
    }
}


int main_2() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> height[i];
        r_height[N - 1 - i] = height[i];
    }

    lis(height, l, N);
    lis(r_height, u, N);

    int m = 0;
    for (int i = 0; i < N; i++) {
        m = max(m, l[i] + u[N - i - 1]);
    }
    cout << N - (m - 1) << endl;

    return 0;
}