#include <iostream>
#include <stack>

using namespace std;

int main1() {
    char c, str[500];
    stack<char> word;
    cin.getline(str, 500);

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        if (c == ' ') {
            while (!word.empty()) {
                cout << word.top();
                word.pop();
            }
            cout << ' ';
        } else {
            word.push(c);
        }
    }

    while (!word.empty()) {
        cout << word.top();
        word.pop();
    }

    return 0;
}