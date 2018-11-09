#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main2() {
    int n, k, t, rank[201], cycle[201];
    string str;
    char result[201];

    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> t;
            t--;
            rank[t] = i;
        }

        for (int i = 0; i < n; i++) {
            int c = 0, r = i;
            while (true) {
                c++;
                r = rank[r];
                if (r == i) {
                    cycle[i] = c;
                    //cout << i << ' ' << c << endl;
                    break;
                }
            }
        }


        cin >> k;
        while (k) {
            cin.get();
            getline(cin, str);

            for (int i = 0; i < n; i++) {
                t = i;
                for (int j = 0; j < k % cycle[i]; j++) {
                    t = rank[t];
                }

                if (t >= str.size()) {
                    result[i] = ' ';
                } else {
                    result[i] = str[t];
                }
            }
            result[n] = '\0';
            puts(result);
            cin >> k;
        }

        cout << endl;
    }


    return 0;
}