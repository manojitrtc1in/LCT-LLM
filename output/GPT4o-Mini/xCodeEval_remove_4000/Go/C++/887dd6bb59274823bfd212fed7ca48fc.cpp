#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

const int64_t MOD = 1000 * 1000 * 1000 + 7;

int64_t readInt() {
    int64_t x;
    std::cin >> x;
    return x;
}

void id5(int64_t value) {
    std::cout << value;
}

void solve() {
    int64_t a = readInt();
    int64_t b = readInt();
    
    int64_t r = 0;
    for (int64_t i = 1; i <= b - 1; i++) {
        r += i;
        if (r >= MOD) {
            r -= MOD;
        }
    }

    int64_t res = (a * r) % MOD;

    int64_t k = 0;
    for (int64_t i = 1; i <= a; i++) {
        k += (i * r) % MOD;
        if (k >= MOD) {
            k -= MOD;
        }
    }

    res += (b * k) % MOD;
    if (res >= MOD) {
        res -= MOD;
    }

    id5(res);
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    solve();
    return 0;
}
