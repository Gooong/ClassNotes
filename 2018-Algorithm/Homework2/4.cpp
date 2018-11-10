//
// Created by gongxr on 18-11-9.
//
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct line {
    double l, r;
} lines[1000];

bool compare(const line &a, const line &b) {
    return a.r < b.r;
}

int main2_4() {
    int n, d, x, y;
    int sum = 0, j = 1;
    bool no_solution = false;
    double latest;
    while (cin >> n >> d) {
        if (!(n || d)) {
            break;
        }
        no_solution = false;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (y > d) {
                no_solution = true;
            }
            if (!no_solution) {
                lines[i].l = x - sqrt(d * d - y * y);
                lines[i].r = x + sqrt(d * d - y * y);
            }

        }

        if(no_solution){
            cout << "Case " << j << ": " << -1 << endl;
            j++;
            continue;
        }

        sort(lines, lines + n, compare);

        sum = 0;
        latest = lines[0].l - 1;
        for (int i = 0; i < n; i++) {
            if (lines[i].l > latest) {
                latest = lines[i].r;
                sum++;
            }
        }
        cout << "Case " << j << ": " << sum << endl;
        j++;
    }
    return 0;
}
