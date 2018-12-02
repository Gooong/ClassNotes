//
// Created by gongxr on 18-12-2.
//

#include <iostream>

using namespace std;

int main_4() {
    int N;
    int m[100][100], row[100], l[100], max_sum = INT32_MIN;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            row[j] = 0;
        }

        for (int j = i; j < N; j++) {
            for (int k = 0; k < N; k++) {
                row[k] += m[j][k];
                if (k == 0 || l[k - 1] <= 0) {
                    l[k] = row[k];
                } else {
                    l[k] = l[k - 1] + row[k];
                }
                max_sum = max(max_sum, l[k]);
            }
        }
    }
    printf("%d\n", max_sum);

    return 0;
}