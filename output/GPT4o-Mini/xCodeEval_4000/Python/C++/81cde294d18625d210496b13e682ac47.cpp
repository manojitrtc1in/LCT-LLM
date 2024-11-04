#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    
    if (n >= 100) {
        cout << 1 << endl;
        return 0;
    }
    
    int ans = n * n;
    vector<int> cur(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cur[i] = cur[i - 1] ^ l[i - 1];
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if ((cur[j] ^ cur[i - 1]) > (cur[k] ^ cur[j])) {
                    ans = min(ans, k - i - 1);
                }
            }
        }
    }
    
    if (ans == n * n) {
        ans = -1;
    }
    
    cout << ans << endl;
    return 0;
}
