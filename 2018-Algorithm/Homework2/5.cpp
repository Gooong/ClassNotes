//
// Created by gongxr on 18-11-10.
//
#include <iostream>

using namespace std;

int N;
int matrix[100][100];
int min_e[100];
bool added[100];

int main2_5() {
    int cost, visited_n;
    int curr_node, curr_cost, min_node;
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }

        cost = 0;
        visited_n = 0;
        for (int i = 0; i < 100; i++) {
            min_e[i] = 1000001;
            added[i] = false;
        }
        curr_node = 0;
        curr_cost = 0;
        min_node = 0;

        while (visited_n < N) {
            cost += curr_cost;
            added[curr_node] = true;
            visited_n += 1;

            curr_cost = 1000001;
            for (int i = 0; i < N; i++) {
                if (!added[i]) {
                    min_e[i] = min(min_e[i], matrix[curr_node][i]);
                    if (min_e[i] < curr_cost) {
                        curr_cost = min_e[i];
                        min_node = i;
                    }
                }
            }
            curr_node = min_node;
        }

        cout << cost << endl;
    }
    return 0;
}