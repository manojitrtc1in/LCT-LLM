#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iomanip>
#include <fstream>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define lli long long int
#define ulli unsigned long long int
#define mod 998244353
#define inf 1000000000000000000
#define vi vector<int>
#define vlli vector<lli>
#define pii pair<int,int>
#define plli pair<lli,lli>
#define vpii vector<pii>
#define vplli vector<plli>
#define F first
#define S second
#define endl "\n"
#define debug(x) cout<<#x<<" : "<<x<<endl

const int N = 100005;
const int LOGN = 20;
const int M = 1000000007;
const double PI = acos(-1);

int powmod(int a, int b, int m) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (ans * 1LL * a) % m;
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}

int add(int a, int b, int m) {
    a += b;
    if (a >= m) a -= m;
    return a;
}

int sub(int a, int b, int m) {
    a -= b;
    if (a < 0) a += m;
    return a;
}

int mul(int a, int b, int m) {
    return (a * 1LL * b) % m;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int inv(int a, int m) {
    return powmod(a, m - 2, m);
}

int fact[N], invfact[N];

void precompute() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i, M);
        invfact[i] = inv(fact[i], M);
    }
}

int nCr(int n, int r) {
    if (r < 0 || n < 0 || r > n) return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r], M), M);
}

int nPr(int n, int r) {
    if (r < 0 || n < 0 || r > n) return 0;
    return mul(fact[n], invfact[n - r], M);
}

int logPow(int a, int b) {
    int ans = 0;
    while (b) {
        ans++;
        b >>= 1;
    }
    return ans - 1;
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> ss(n);
    vector<string> oss(n);
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
        oss[i] = ss[i];
    }
    vector<int> offset(n + 1);
    offset[0] = 1;
    for (int i = 0; i < n; i++) {
        offset[i + 1] = offset[i] + ss[i].length() - 1;
    }
    int U = offset[n] - 1;

    const int D = 5;
    vector<vector<int>> M((U + 1) * D, vector<int>((U + 1) * D, 0));

    for (int i = 0; i < U + 1; i++) {
        int lb, of;
        if (i == 0) {
            lb = 0;
            of = 0;
        } else {
            lb = lower_bound(offset.begin(), offset.end(), i + 1) - offset.begin() - 1;
            of = i - offset[lb] + 1;
        }

        if (i == 0) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k != j && oss[k].find(oss[j]) == 0) {
                        M[offset[k] + ss[j].length() - 1][0 + (U + 1) * (ss[j].length() - 1)] = 1;
                    }
                }
                M[0][0 + (U + 1) * (ss[j].length() - 1)] += 1;
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (oss[lb].substr(of) == oss[j]) {
                    M[0][i + (U + 1) * (oss[j].length() - 1)] += 2;
                } else if (oss[lb].substr(of).find(oss[j]) == 0) {
                    M[i + oss[j].length()][i + (U + 1) * (oss[j].length() - 1)] += 1;
                }
            }

            string suf = oss[lb].substr(of);
            for (int j = 0; j < n; j++) {
                if (oss[j].find(suf) == 0 && oss[j] != suf) {
                    M[offset[j] + suf.length() - 1][i + (U + 1) * (suf.length() - 1)] += 1;
                }
            }
        }
    }
    for (int i = 0; i < U + 1; i++) {
        for (int j = 0; j < D - 1; j++) {
            M[i + (U + 1) * (j + 1)][i + (U + 1) * j] = 1;
        }
    }

    vector<int> v((U + 1) * D, 0);
    v[0] = 1;
    for (int i = 0; i < m; i++) {
        vector<int> temp((U + 1) * D, 0);
        for (int j = 0; j < (U + 1) * D; j++) {
            for (int k = 0; k < (U + 1) * D; k++) {
                temp[j] = add(temp[j], mul(M[j][k], v[k], mod), mod);
            }
        }
        v = temp;
    }

    cout << v[0] << endl;

    return 0;
}
