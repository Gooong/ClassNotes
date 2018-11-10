//
// Created by gongxr on 18-11-10.
//
#include <iostream>

using namespace std;

int count_inversions(int *target_arrs, int *help_arrs, int start, int end) {
    if (start + 1 == end) {
        return 0;
    } else {
        int result = 0;
        int middle = (start + end) / 2;
        result += count_inversions(target_arrs, help_arrs, start, middle);
        result += count_inversions(target_arrs, help_arrs, middle, end);

        int i = start, j = middle, t = start;
        while (t < end) {
            if (i >= middle) {
                help_arrs[t++] = target_arrs[j++];
            } else if (j >= end) {
                help_arrs[t++] = target_arrs[i++];
            } else {
                if (target_arrs[i] <= target_arrs[j]) {
                    help_arrs[t++] = target_arrs[i++];
                } else {
                    result += middle - i;
                    help_arrs[t++] = target_arrs[j++];
                }
            }
        }
        for (t = start; t < end; t++) {
            target_arrs[t] = help_arrs[t];
        }

        return result;
    }


}


int main2_6() {
    int nums[20000], help_nums[20000];
    int N;
    scanf("%d", &N);
    while (N != 0) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &nums[i]);
        }
        printf("%d\n", count_inversions(nums, help_nums, 0, N));
        scanf("%d", &N);
    }

    return 0;
}
