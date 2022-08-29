#include <iostream>

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    if (n / 2 * 2 == n && n != 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}