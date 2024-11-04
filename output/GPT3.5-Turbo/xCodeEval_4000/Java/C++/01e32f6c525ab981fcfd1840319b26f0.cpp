#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <cassert>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define mii map<int, int>
#define msi map<string, int>
#define mci map<char, int>
#define mli map<long long, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>
#define umci unordered_map<char, int>
#define umli unordered_map<long long, int>
#define si set<int>
#define usi unordered_set<int>
#define sl set<long long>
#define usl unordered_set<long long>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define mod 1000000007
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int n, int p)
{
    return power(n, p - 2, p);
}

int modBinomial(int n, int k, int p)
{
    int numerator = 1;
    for (int i = 0; i < k; i++)
    {
        numerator = (numerator * (n - i)) % p;
    }
    int denominator = 1;
    for (int i = 1; i <= k; i++)
    {
        denominator = (denominator * i) % p;
    }
    return (numerator * modInverse(denominator, p)) % p;
}

void solve()
{
    int n;
    cin >> n;
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    int min_val = 0;
    if (b1 >= a1 + a2)
    {
        min_val = a3 - b2 - b3;
    }
    else if (b2 >= a3 + a2)
    {
        min_val = a1 - b1 - b3;
    }
    else if (b3 >= a1 + a3)
    {
        min_val = a2 - b2 - b1;
    }
    else
    {
        min_val = 0;
    }

    int max_val = min(a1, b2) + min(a2, b3) + min(a3, b1);

    cout << min_val << " " << max_val << endl;
}

int32_t main()
{
    fastio;
    solve();
    return 0;
}
