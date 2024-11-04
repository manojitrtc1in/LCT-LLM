#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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

long long fact(long long n) {
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int gcd(int p2, int p22) {
    if (p2 == 0)
        return p22;
    return gcd(p22 % p2, p2);
}

void nextGreater(vector<long long>& a, vector<int>& ans) {
    stack<int> stk;
    stk.push(0);

    for (int i = 1; i < a.size(); i++) {
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

void id7(vector<long long>& a, vector<int>& ans) {
    int n = a.size();
    vector<int> pans(n, -1);
    vector<long long> arev(n);
    for (int i = 0; i < n; i++)
        arev[i] = a[n - 1 - i];

    stack<int> stk;
    stk.push(0);

    for (int i = 1; i < n; i++) {
        if (!stk.empty()) {
            int s = stk.top();
            stk.pop();
            while (arev[s] < arev[i]) {
                pans[s] = n - i - 1;
                if (!stk.empty())
                    s = stk.top(), stk.pop();
                else
                    break;
            }
            if (arev[s] >= arev[i])
                stk.push(s);
        }
        stk.push(i);
    }

    for (int i = 0; i < n; i++)
        ans[i] = pans[n - i - 1];
}

void id0(vector<long long>& a, vector<int>& ans) {
    stack<int> stk;
    stk.push(0);

    for (int i = 1; i < a.size(); i++) {
        if (!stk.empty()) {
            int s = stk.top();
            stk.pop();
            while (a[s] > a[i]) {
                ans[s] = i;
                if (!stk.empty())
                    s = stk.top(), stk.pop();
                else
                    break;
            }
            if (a[s] <= a[i])
                stk.push(s);
        }
        stk.push(i);
    }
}

long long lcm(int a, int b) {
    return (a * 1LL * b) / gcd(a, b);
}

long long LCM(long long a, long long b) {
    return (a * b) / gcd(a, b);
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
        a[i]++;
    
    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
        int t = ((i) % m * (i) % m) % m;
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
