#include <iostream>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = 3;
    if (a % m == 1) {
        ans -= 1;
    }
    if (b % m == 0 || b == n) {
        ans -= 1;
    }
    if (m == 1) {
        cout << 1 << endl;
        return 0;
    } else if ((a - 1) / m == (b - 1) / m) {
        cout << 1 << endl;
        return 0;
    } else if ((a % m - b % m) % m == 1) {
        cout << min(2, ans, (b - 1) / m - (a - 1) / m + 1) << endl;
        return 0;
    }
    cout << min(ans, (b - 1) / m - (a - 1) / m + 1) << endl;
    return 0;
}
