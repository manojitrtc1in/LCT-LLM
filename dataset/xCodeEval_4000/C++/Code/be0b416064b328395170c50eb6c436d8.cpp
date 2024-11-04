#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,abm,mmx,popcnt")
#define _CRT_SECURE_NO_WARNINGS







#include <set>
#include <map>
#include <deque>
#include <string>
#include <cstdint>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <time.h>

#include <ctime>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <complex>
#include <chrono>
#include <unordered_set>





using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define pbc push_back
#define pob pop_back()
#define vin(a) for (auto& i : a) cin >> i
#define sp system("pause")
#define mp make_pair



template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y)
{
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y)
{
    if (x < y) x = y;
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ld asdasdcl = 0;
double getTime() { return (clock() - asdasdcl) / (double)CLOCKS_PER_SEC; }
pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
    return { a.first - b.first, a.second - b.second };
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
    return { a.first + b.first, a.second + b.second };
}

#define getchar_unlocked _getchar_nolock
inline int readInt()
{
    char x;
    while (x = getchar_unlocked())
    {
        if (x >= '0' && x <= '9')
        {
            int ans = x - '0';
            while (x = getchar_unlocked())

            {
                if (!(x >= '0' && x <= '9')) return ans;
                ans = ans * 10 + x - '0';
            }
        }
    }
}

const int inf = 1e9 + 228;
using namespace chrono;
const ld EPS = 1e-25;
const ld PI = acos(-1.0);
const int mod = 1000000007;
const int MAXN = 2e6 + 228;
int mul(int a, int b)
{
    return 1ll * a * b % mod;
}
int add(int a, int b)
{
    if (a + b >= mod) return a + b - mod;
    return a + b;
}
int sub(int a, int b)
{
    if (a - b < 0) return a - b + mod;
    return a - b;
}
int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int x)
{
    return binpow(x, mod - 2);
}
int fact[MAXN]; int rfact[MAXN];
int cnk(int n, int k)
{
    if (k<0 || k>n) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}
int pw[MAXN];
void init()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; --i)rfact[i] = mul(rfact[i + 1], i + 1);
}
int sum4[MAXN];
int sum2[MAXN];
int ipw[MAXN];
int calcf(int i, int x)
{
    if (i > x)
    {
        return 1;
    }
    int funcx = inv(2);
    if (x > 3)
    {
        int tms = (x - 2) / 2;

        int newval = mul(funcx, inv(pw[2 * tms]));
        newval = add(newval, sum4[tms]);
        funcx = newval;
        

        

        

        

        

    }
    int tms = i - 2;
    int newval = mul(funcx, inv(pw[tms]));
    newval = add(newval, sum2[tms]);
    funcx = newval;
    return funcx;
}
const int MAXA = 100;
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) pw[i] = mul(pw[i - 1], 2);
    ipw[0] = 1;
    int mmt = inv(2);
    for (int i = 1; i < MAXN; ++i) ipw[i] = mul(ipw[i - 1], mmt);
    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    
    sum4[0] = 0;
    for (int i = 1; i < MAXN / 2; ++i)
    {
        sum4[i] = sum4[i - 1];
        sum4[i] = add(sum4[i], ipw[2 * i]);
    }
    sum2[0] = 0;
    for (int i = 1; i < MAXN; ++i)
    {
        sum2[i] = sum2[i - 1];
        sum2[i] = add(sum2[i], ipw[i]);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n + 1);
        if (n == 2)
        {
            cout << "0\n1\n";
            continue;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1)
            {
                if (n == 1)
                {
                    ans[i] = 1;
                }
                else
                    ans[i] = 0;
                continue;
            }
            int prob = inv(2);
            int l = i / 2;
            int kek = i - l - 1;
            prob = mul(prob, inv(pw[kek]));
            ans[i] = prob;
        }
        vector<int> dp(n + 1);
        int sm = 0;
        bool kek = 0;
        for (int i = n; i >= 1; --i)
        {
            if (i > n - i)
            {
                dp[i] = 1;
            }
            else
            {
             

                if (!kek)
                {
                    for (int j = 1; j < i; ++j)
                    {
                        sm = add(sm, mul(ipw[j], dp[i + j]));
                    }
                    kek = 1;
                }
                else
                {
                }
                dp[i] = sm;
         
                int tid = i + i - 1;
                if(i!=2)
                sm = add(sm, dp[i]);
                if (i != 1)
                {
                    sm = sub(sm, mul(ipw[i - 1], dp[tid]));
                    sm = sub(sm, mul(ipw[i - 2], dp[tid - 1]));
                    sm = mul(sm, inv(2));
                }
            }
        }
        for (int i = 1; i < n; ++i) ans[i] = mul(ans[i], dp[i]);
        ans[n] = 1;
        for (int i = 1; i < n; ++i) ans[n] = sub(ans[n], ans[i]);
        for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
    }
    

}