



#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<chrono>
#include<cstring>
#include<string>



using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define inf 9999999999999
#define endl '\n'
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>




using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod1 = 998244353;
const ll mod = 1e9 + 7;
const ll MOD = 1e18 + 1e16;
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
































































class STable
{
public:
    int LOG = 0;
    int n;
    vector<vector<int>> T;
    STable(vector<int> &a)
    {
        n = (int)a.size();
        while (1 << (LOG + 1) <= n)
            LOG++;
        T.resize(LOG + 1);
        for (int i = 0; i <= LOG; i++)
            T[i].resize(n);
        for (int i = 0; i < n; i++)
            T[0][i] = a[i];
        for (int i = 1; i <= LOG; i++)
        {
            for (int j = 0; j < n - (1 << i) + 1; j++)
            {
                T[i][j] = combine(T[i - 1][j], T[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int combine(int a, int b)
    {
        return max(a, b);
    }
    int qry(int l, int r)
    {
        int exp = 0;
        while (1 << (exp + 1) <= r - l + 1)
            exp++;
        return combine(T[exp][l], T[exp][r - (1 << exp) + 1]);
    }
};





















ll findMinNumber(ll n)
{
    ll count = 0, ans = 1;

    

    

    while (n % 2 == 0)
    {
        count++;
        n /= 2;
    }

    

    

    if (count % 2)
        ans *= 2;

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }

        

        

        if (count % 2)
            ans *= i;
    }

    if (n > 2)
        ans *= n;

    return ans;
}






























mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());









































































































































































































































const auto start_time = chrono::high_resolution_clock::now();
void output_run_time() {
    

#ifndef ONLINE_JUDGE
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end_time - start_time;
    cout << "\n\n\nTime Taken : " << diff.count();
#endif
}

int main() {

    fio;

    ll n, m;
    cin >> n >> m;
    ll a[n][m], i, j;
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    vector<pll> v;
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            if (a[i][j] != 1)
            {
                ll res = 0;
                if (i and a[i - 1][j] < a[i][j])
                    res = 1;
                else if (j and a[i][j - 1] < a[i][j])
                    res = 1;
                else if (i + 1 < n and a[i + 1][j] < a[i][j])
                    res = 1;
                else if (j + 1 < m and a[i][j + 1] < a[i][j])
                    res = 1;
                if (res == 0)
                {
                    

                    v.pb({i, j});
                }
            }
        }
    }
    if (v.size() == 0)
        cout << 0 << endl;
    else if (v.size() > 2)
        cout << 2 << endl;
    else
    {
        ll k, l, ans = 0;
        set<pll> s;
        ll a1 = v[0].first;
        ll b1 = v[0].second;
        if (a1)
            v.pb({a1 - 1, b1});
        if (b1)
            v.pb({a1, b1 - 1});
        if (a1 + 1 < n)
            v.pb({a1 + 1, b1});
        if (b1 + 1 < m)
            v.pb({a1, b1 + 1});
        fo(k, 0, v.size())
        {
            ll x = v[k].first;
            ll y = v[k].second;
            

            fo(i, 0, n)
            {
                fo(j, 0, m)
                {
                    ll res = 0, res2 = 0;
                    swap(a[x][y], a[i][j]);
                    ll min1 = min(a[x][y], a[i][j]);
                    ll max1 = max(a[x][y], a[i][j]);
                    if (i and a[i - 1][j] < a[i][j])
                        res2 = 1;
                    else if (j and a[i][j - 1] < a[i][j])
                        res2 = 1;
                    else if (i + 1 < n and a[i + 1][j] < a[i][j])
                        res2 = 1;
                    else if (j + 1 < m and a[i][j + 1] < a[i][j])
                        res2 = 1;
                    if (a[x][y] != 1)
                    {
                        if (x and a[x - 1][y] < a[x][y])
                            res = 1;
                        else if (y and a[x][y - 1] < a[x][y])
                            res = 1;
                        else if (x + 1 < n and a[x + 1][y] < a[x][y])
                            res = 1;
                        else if (y + 1 < m and a[x][y + 1] < a[x][y])
                            res = 1;
                    }
                    else
                        res = 1;
                    if (res == 1 and res2 == 1)
                    {



                        ll flag = 0;
                        vector<pll> v1;
                        if (x )
                            v1.pb({x - 1, y});
                        if (y )
                            v1.pb({x, y - 1});
                        if (x + 1 < n )
                            v1.pb({x + 1, y});
                        if (y + 1 < m )
                            v1.pb({x, y + 1});
                        if (i)
                            v1.pb({i - 1, j});
                        if (j)
                            v1.pb({i, j - 1});
                        if (i + 1 < n)
                            v1.pb({i + 1, j});
                        if (j + 1 < m)
                            v1.pb({i, j + 1});
                        fo(l, 0, v1.size())
                        {
                            ll res1 = 0;
                            ll x1 = v1[l].first;
                            ll y1 = v1[l].second;
                            if (a[x1][y1] == 1)
                                continue;
                            if (x1 and a[x1 - 1][y1] < a[x1][y1])
                                res1 = 1;
                            else if (y1 and a[x1][y1 - 1] < a[x1][y1])
                                res1 = 1;
                            else if (x1 + 1 < n and a[x1 + 1][y1] < a[x1][y1])
                                res1 = 1;
                            else if (y1 + 1 < m and a[x1][y1 + 1] < a[x1][y1])
                                res1 = 1;
                            if (res1 == 0)
                            {
                                flag = 1;
                                break;
                            }
                        }

                        fo(l, 0, v.size())
                        {
                            ll res1 = 0;
                            ll x1 = v[l].first;
                            ll y1 = v[l].second;
                            if (a[x1][y1] == 1)
                                continue;
                            if (x1 and a[x1 - 1][y1] < a[x1][y1])
                                res1 = 1;
                            else if (y1 and a[x1][y1 - 1] < a[x1][y1])
                                res1 = 1;
                            else if (x1 + 1 < n and a[x1 + 1][y1] < a[x1][y1])
                                res1 = 1;
                            else if (y1 + 1 < m and a[x1][y1 + 1] < a[x1][y1])
                                res1 = 1;
                            if (res1 == 0)
                            {
                                flag = 1;
                                break;
                            }
                        }

                        if (flag == 0)
                        {
                            


                            s.insert({min1, max1});
                            

                            ans++;
                        }
                    }
                    swap(a[x][y], a[i][j]);
                }
            }
        }
        if (ans == 0)
            cout << 2 << endl;
        else
        {

            cout << 1 << " " << s.size() << endl;
        }
    }

    output_run_time();

    return 0;
}

