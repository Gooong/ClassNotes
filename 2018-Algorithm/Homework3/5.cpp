//
// Created by gongxr on 18-12-2.
//

#include <iostream>

using namespace std;

int main_5() {
    int T, N, price[100000], p[100000];
    int min_price, max_price, max_income, income;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &price[i]);
        }

        min_price = price[0];
        max_income = 0;
        for (int i = 0; i < N; i++) {
            min_price = min(min_price, price[i]);
            income = price[i] - min_price;
            max_income = max(max_income, income);
            p[i] = max_income;
        }

        max_price = price[N - 1];
        max_income = p[N - 1];
        for (int i = N - 1; i >= 0; i--) {
            max_price = max(max_price, price[i]);
            income = max_price - price[i];
            max_income = max(max_income, income + p[i]);
        }

        printf("%d\n", max_income);
    }

    return 0;
}
