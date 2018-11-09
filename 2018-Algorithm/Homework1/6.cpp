#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main1_6() {
    int n, l, r;
    vector<pair<int, int>> pairs;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        pairs.emplace_back(pair<int, int>(l, r));
    }

    sort(pairs.begin(), pairs.end());
    l = pairs[0].first;
    r = pairs[0].second;
    for (int i = 0; i < pairs.size(); i++) {
        if (pairs[i].first > r) {
            cout << "no";
            return 0;
        } else {
            if (pairs[i].second > r) {
                r = pairs[i].second;
            }
        }
    }
    cout << l << " " << r;
    return 0;
}