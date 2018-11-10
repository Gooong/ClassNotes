//
// Created by gongxr on 18-11-10.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int parents[1002][1002];
int sizes[1002][1002];
int T, N, M;


int parent(int p) {
    int x = p / (N + 2);
    int y = p % (N + 2);
    return parents[x][y];
}

int size(int p) {
    int x = p / (N + 2);
    int y = p % (N + 2);
    return sizes[x][y];
}

// set the parent of p to q
void set_parent(int p, int q) {
    int xp = p / (N + 2);
    int yp = p % (N + 2);

    int xq = q / (N + 2);
    int yq = q % (N + 2);

    parents[xp][yp] = q;
    sizes[xq][yq] += sizes[xp][yp];
}


int find(int p) {
    if (p != parent(p)) {
        set_parent(p, find(parent(p)));
    }
    return parent(p);
}


void union_cell(int p, int q) {
    int P = find(p);
    int Q = find(q);

    if (P == Q) {
        return;
    }

    if (size(P) <= size(Q)) {
        set_parent(P, Q);
    } else {
        set_parent(P, Q);
    }
}


// i,j in [1,N]
void open(int a, int b) {
    parents[a][b] = a * (N + 2) + b;
    if (parents[a - 1][b] != -1) {
        union_cell(a * (N + 2) + b, (a - 1) * (N + 2) + b);
    }
    if (parents[a + 1][b] != -1) {
        union_cell(a * (N + 2) + b, (a + 1) * (N + 2) + b);
    }
    if (parents[a][b - 1] != -1) {
        union_cell(a * (N + 2) + b, a * (N + 2) + b - 1);
    }
    if (parents[a][b + 1] != -1) {
        union_cell(a * (N + 2) + b, a * (N + 2) + b + 1);
    }
}

bool check() {
    return find(0) == find((N + 2) * (N + 2) - 1);
}


int main2_3() {
    cin >> T;
    int a, b;
    bool opened;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;

        for (int k = 0; k < N + 2; k++) {
            for (int j = 0; j < N + 2; j++) {
                parents[k][j] = -1;
                sizes[k][j] = 1;
            }
        }

        for (int k = 0; k < N + 2; k++) {
            set_parent(k, 0);
            set_parent((N + 2) * (N + 2) - 1 - k, (N + 2) * (N + 2) - 1);
        }

        opened = false;
        for (int j = 0; j < M; j++) {
            cin >> a >> b;
            open(a, b);
            if (!opened && check()) {
                opened = true;
                cout << j + 1 << endl;
            }
        }
    }

    return 0;
}