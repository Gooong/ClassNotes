#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_COUNT = 100000;

struct Point {
    double_t x;
    double_t y;
} points[MAX_COUNT];
int tmp[MAX_COUNT];

bool compare_x(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool compare_y(int a, int b) {
    return points[a].y < points[b].y;
}

double distance2(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double min_distance2(int start, int end) {
    double min_d2 = distance2(points[start], points[start + 1]);
    if (end - start <= 5) {
        for (int i = start; i < end; i++) {
            for (int j = i + 1; j < end; j++) {
                min_d2 = min(distance2(points[i], points[j]), min_d2);
            }
        }
        return min_d2;
    } else {
        int mid = (start + end) / 2;
        double min_left = min_distance2(start, mid);
        double min_right = min_distance2(mid, end);
        min_d2 = min(min_left, min_right);
        double mid_x = points[mid].x;
        int s = 0;
        for (int i = start; i < end; i++) {
            if (fabs(mid_x - points[i].x) <= min_d2) {
                tmp[s++] = i;
            }
        }
        sort(tmp, tmp + s, compare_y);
        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j < i + 12 && j < s; j++) {
                min_d2 = min(min_d2, distance2(points[tmp[i]], points[tmp[j]]));
            }
        }
        return min_d2;
    }
}


int main_1() {
    int T, N;
    double distance;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%lf%lf", &points[j].x, &points[j].y);
        }
        sort(points, points + N, compare_x);
        distance = sqrt(min_distance2(0, N));
        printf("%.6lf\n", distance);
    }

    return 0;
}