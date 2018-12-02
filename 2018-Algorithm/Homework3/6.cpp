//
// Created by gongxr on 18-12-2.
//

#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include <float.h>
#include <math.h>

using namespace std;
double s[9][9][9][9][15], g[8][8];


double min_s2(int a, int b, int c, int d, int k) {

    assert(a < c && b < d);

    if (s[a][b][c][d][k] != 0) {
        return s[a][b][c][d][k];
    }

    double s2 = INFINITY;
    if (k == 1) {
        double sum = 0;
        for (int i = a; i < c; i++) {
            for (int j = b; j < d; j++) {
                sum += g[i][j];
            }
        }
        s2 = sum * sum;
        //cout << s2 << endl;
    } else {
        int left_num, right_num;
        double left_s2, right_s2;
        for (int i = a + 1; i < c; i++) {
            left_num = (i - a) * (d - b);
            right_num = (c - i) * (d - b);
            if (left_num >= k - 1) {
                left_s2 = min_s2(a, b, i, d, k - 1);
                right_s2 = min_s2(i, b, c, d, 1);
                s2 = min(s2, left_s2 + right_s2);
            }
            if (right_num >= k - 1) {
                left_s2 = min_s2(a, b, i, d, 1);
                right_s2 = min_s2(i, b, c, d, k - 1);
                s2 = min(s2, left_s2 + right_s2);
            }
        }

        for (int i = b + 1; i < d; i++) {
            left_num = (i - b) * (c - a);
            right_num = (d - i) * (c - a);
            if (left_num >= k - 1) {
                left_s2 = min_s2(a, b, c, i, k - 1);
                right_s2 = min_s2(a, i, c, d, 1);
                s2 = min(s2, left_s2 + right_s2);
            }
            if (right_num >= k - 1) {
                left_s2 = min_s2(a, b, c, i, 1);
                right_s2 = min_s2(a, i, c, d, k - 1);
                s2 = min(s2, left_s2 + right_s2);
            }
        }

    }

    s[a][b][c][d][k] = s2;
    return s2;
}

int main_6() {
    int n;
    double sum = 0, ss2;
    cin >> n;
    memset(s, 0, sizeof(s));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> g[i][j];
            sum += g[i][j];
        }
    }

    ss2 = min_s2(0, 0, 8, 8, n);
    printf("%.3lf\n", sqrt((ss2 - (sum * sum / n)) / n));

    return 0;
}