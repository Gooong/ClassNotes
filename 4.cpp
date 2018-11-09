#include <iostream>

using namespace std;

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << 1 << ":" << a << "->" << c << endl;
    } else {
        hanoi(n - 1, a, c, b);
        cout << n << ":" << a << "->" << c << endl;
        hanoi(n - 1, b, a, c);
    }
}


int main4() {
    int n;
    char a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    hanoi(n, a, b, c);

    return 0;
}