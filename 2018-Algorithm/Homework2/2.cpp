//
// Created by gongxr on 18-11-9.
//
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int n, m;
short relation[1000][1000];
short color[1000];
bool rational = true;

// c = 1 or -1
void dfs(short i, short c) {
    if (rational) {
        if (color[i] == 0) {
            color[i] = c;
            for (short j = 0; j < n; j++) {
                if (relation[i][j] != 0) {
                    dfs(j, c * relation[i][j]);
                }
            }
        } else {
            if (color[i] != c) {
                rational = false;
            }
        }
    }
}


int main2_2() {

    short f, t, e;
    while (scanf("%d%d", &n, &m) != -1) {
        memset(relation, 0, sizeof(relation));
        memset(color, 0, sizeof(color));
        rational = true;

        for (int i = 0; i < m; i++) {
            scanf("%hu%hu%hu", &f, &t, &e);
            if (e == 1) {
                e = -1;
            }
            if (e == 0) {
                e = 1;
            }
            relation[f][t] = e;
            relation[t][f] = e;
        }

        for (short i = 0; i < n; i++) {
            if (!color[i] && rational) {
                dfs(i, 1);
            }
        }

        if (rational) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}