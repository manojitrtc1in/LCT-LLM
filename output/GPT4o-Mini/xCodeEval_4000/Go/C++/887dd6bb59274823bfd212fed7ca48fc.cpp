#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <random>

const int64_t MOD = 1000 * 1000 * 1000 + 7;

void solve() {
    int a, b;
    std::cin >> a >> b;

    int64_t r = 0;
    for (int i = 1; i <= b - 1; i++) {
        r += i;
        if (r >= MOD) {
            r -= MOD;
        }
    }

    int64_t res = static_cast<int64_t>(a) * r % MOD;

    int64_t k = 0;
    for (int i = 1; i <= a; i++) {
        k += static_cast<int64_t>(i) * r % MOD;
        if (k >= MOD) {
            k -= MOD;
        }
    }

    res += static_cast<int64_t>(b) * k % MOD;
    if (res >= MOD) {
        res -= MOD;
    }

    std::cout << res << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::random_device rd;
    std::mt19937 gen(rd());
    
    solve();
    return 0;
}
