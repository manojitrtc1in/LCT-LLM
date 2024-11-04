#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <random>
#include <iomanip>
#include <unordered_map>

using namespace std;

const int mod = (int)pow(10, 9) + 7;

long long choose(long long total, long long choose) {
    if (total < choose)
        return 0;
    if (choose == 0 || choose == total)
        return 1;
    return (choose(total - 1, choose - 1) + choose(total - 1, choose)) % mod;
}

long long binaryExponentiation(long long x, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return result;
}

int gcd(int p2, int p22) {
    if (p2 == 0)
        return p22;
    return gcd(p22 % p2, p2);
}

void nextGreater(long long a[], int ans[], int n) {
    stack<int> stk;
    stk.push(0);

    for (int i = 1; i < n; i++) {
        if (!stk.empty()) {
            int s = stk.top();
            stk.pop();
            while (a[s] < a[i]) {
                ans[s] = i;
                if (!stk.empty())
                    s = stk.top(), stk.pop();
                else
                    break;
            }
            if (a[s] >= a[i])
                stk.push(s);
        }
        stk.push(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    int m;
    cin >> n >> m;
    
    vector<long long> a(m);
    for (int i = 0; i < m; i++)
        a[i] = n / m;
    for (int i = 1; i <= n % m; i++)
        a[i - 1]++;
    
    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
        int t = (i % m * i % m) % m;
        b[t] += a[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            ans += (b[i] * b[i]);
        } else {
            ans += b[i] * b[m - i];
        }
    }
    
    cout << ans << '\n';
    return 0;
}
