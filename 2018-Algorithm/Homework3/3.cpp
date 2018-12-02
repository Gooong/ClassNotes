//
// Created by gongxr on 18-12-2.
//

#include <string.h>
#include <iostream>

using namespace std;

int main_3() {
    char a[210], b[210];
    int opt[210], len_a, len_b, pre, next;
    while (scanf("%s%s", a, b) != -1) {

        len_a = strlen(a);
        len_b = strlen(b);

        for (int i = 0; i <= len_b; i++) {
            for (int j = 0; j <= len_a; j++) {
                if (i == 0 || j == 0) {
                    opt[j] = 0;
                    pre = 0;
                } else {
                    if (b[i - 1] == a[j - 1]) {
                        next = pre + 1;
                        pre = opt[j];
                        opt[j] = next;
                    } else {
                        pre = opt[j];
                        opt[j] = max(opt[j], opt[j - 1]);
                    }
                }
            }
        }
        cout << opt[len_a] << endl;

    }
}