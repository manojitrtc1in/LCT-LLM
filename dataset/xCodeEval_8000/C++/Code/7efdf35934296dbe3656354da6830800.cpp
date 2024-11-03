#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
long long a[200010], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n;) {
        ans++;
        int i1 = i;
        while (a[i1] == -1 && i1 <= n) {
            i1++;
        }
        if (i1 == n + 1) {
            break;
        }

        int i2 = i1 + 1;
        while (a[i2] == -1 && i2 <= n) {
            i2++;
        }
        if (i2 == n + 1) {
            break;
        }
        int dist = (i2 - i1);
        if ((a[i2] - a[i1]) % dist) {
            i = i2;
            continue;
        }
        auto d = (a[i2] - a[i1]) / dist;
        if (d > 0 && a[i1] - (i1 - i) * d < 1) {
            i = i2;
            continue;
        }

        int r = 1;
        while (r <= n - i2) {
            auto expected = a[i2] + (r * d);
            if (a[r + i2] != expected && a[r + i2] != -1) {
                break;
            }
            if (expected < 1) break;
            r++;
        }
        i = r + i2;
    }

    cout << ans << endl;
    return 0;
}












































