#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <bitset>
#include <ctime>
#include <iomanip>

using namespace std;

#define I64_IO

#define ARGS_NUM(...) ARGS_NUM_IMPL_((0,__VA_ARGS__,5,4,3,2,1))
#define ARGS_NUM_IMPL_(arg) ARGS_NUM_IMPL arg
#define ARGS_NUM_IMPL(_0,_1,_2,_3,_4,_5, N,...) N
#define FUNC_CALL(func, ...) FUNC_CALL_NUM(func, ARGS_NUM(__VA_ARGS__))
#define FUNC_CALL_NUM(func, args) FUNC_CALL_NUM_(func, args)
#define FUNC_CALL_NUM_(func, args) FUNC_CALL_NUM__(func, args)
#define FUNC_CALL_NUM__(func, args) func ## args




#define read_int1(v) scanf("%d", &v)
#define read_int2(v1, v2) scanf("%d%d", &v1, &v2)
#define read_int3(v1, v2, v3) scanf("%d%d%d", &v1, &v2, &v3)
#define read_int4(v1, v2, v3, v4) scanf("%d%d%d%d", &v1, &v2, &v3, &v4)
#define read_int(...) FUNC_CALL(read_int, __VA_ARGS__)(__VA_ARGS__)
#ifdef I64_IO
#define read_ll1(v) scanf(MODE ? "%lld" : "%I64d", &v)
#define read_ll2(v1, v2) scanf(MODE ? "%lld%lld" : "%I64d%I64d", &v1, &v2)
#define read_ll3(v1, v2, v3) scanf(MODE ? "%lld%lld%lld" : "%I64d%I64d%I64d", &v1, &v2, &v3)
#define read_ll4(v1, v2, v3, v4) scanf(MODE ?"%lld%lld%lld%lld" : "%I64d%I64d%I64d%I64d", &v1, &v2, &v3, &v4)
#define print_ll(v) printf(MODE ? "%lld" : "%I64d", v)
#else
#define read_ll1(v) scanf( "%lld" , &v)
#define read_ll2(v1, v2) scanf( "%lld%lld" , &v1, &v2)
#define read_ll3(v1, v2, v3) scanf( "%lld%lld%lld" , &v1, &v2, &v3)
#define read_ll4(v1, v2, v3, v4) scanf("%lld%lld%lld%lld", &v1, &v2, &v3, &v4)
#define print_ll(v) printf("%lld" , v)
#endif
#define read_ll(...) FUNC_CALL(read_ll, __VA_ARGS__)(__VA_ARGS__)
#define read_str(v) scanf("%s", v)
#define print_str(v) printf("%s", v)
#define read_f(v) scanf("%f", &v)
#define print_f(v, prec) printf("%.*f", prec, v)
#define read_lf1(v) scanf("%lf", &v)
#define read_lf2(v1, v2) scanf("%lf%lf", &v1, &v2)
#define read_lf3(v1, v2, v3) scanf("%lf%lf%lf", &v1, &v2, &v3)
#define read_lf(...) FUNC_CALL(read_lf, __VA_ARGS__)(__VA_ARGS__)
#define print_lf(v, prec) printf("%.*lf", prec, v)
#define print_int(v) printf("%d", v)



#define ll long long
#define ull unsigned long long
#define uchar unsigned char
#define pi 3.141592653589793238462643383279
#define eps (1e-8)
#define minn(a, b) a = min((a), (b))
#define maxx(a, b) a = max((a), (b))
#define all(v) v.begin(),v.end()
#define sz(v) ((int)v.size())
#define ln putchar('\n')
#define space putchar(' ')
#define pair_i pair <int, int>
#define pair_ll pair <ll,ll>




#define PRINT(...) MODE ? (FUNC_CALL(PRINT, __VA_ARGS__)(__VA_ARGS__)) : cout
#define PRINT1(a) cout << #a << " = " << (a) << "\n"
#define PRINT2(a,b) cout << #a << " = " << (a) << "," << #b << " = " << (b) << "\n"
#define PRINT3(a,b,c) cout << #a << " = " << (a) << "," << #b << " = " << (b) << "," << #c << " = " << (c) << "\n"
#define PRINT4(a,b,c,d) cout << #a << " = " << (a) << "," << #b << " = " << (b) << "," << #c << " = " << (c) << "," << #d << " = " << (d) << "\n"
#define BP MODE ? break_point() : 0
#define LINE MODE ? printf("-------------------------------\n") : 0
#define LOG(...) MODE ? printf(__VA_ARGS__) : 0




int break_point(){ char c; while ((c = getchar()) != '\n'); return 0; }
template <typename T> void read_integer(T &r){ bool sign = 0; r = 0; char c; while (1){ c = getchar(); if (c == '-'){ sign = 1; break; }if (c != ' ' && c != '\n'){ r = c - '0'; break; } }while (1){ c = getchar(); if (c == ' ' || c == '\n')break; r = r * 10 + (c - '0'); }if (sign)r = -r; }
ll binpowmod(ll a, ll b, ll mod){ if (b == 0)return 1; ll c = binpowmod(a, b >> 1, mod); return (((c*c) % mod) * (b & 1 ? a : 1)) % mod; }
ll binpow(ll a, ll b){ if (b == 0)return 1; ll c = binpow(a, b >> 1); return c*c*(b & 1 ? a : 1); }
inline int getbit(int x, int b){ return (x >> b) & 1; }
inline int setbit(int x, int b){ return x | (1 << b); }
inline void _setbit(int &x, int b){ x = setbit(x, b); }
inline ll setbit(ll x, int b){ return x | (1ll << b); }
inline void _setbit(ll &x, int b){ x = setbit(x, b); }
inline int unsetbit(int x, int b){ return x & (INT_MAX - (1 << b)); }
inline void _unsetbit(int &x, int b){ x = unsetbit(x, b); }
inline int countbit(int x){ x = x - ((x >> 1) & 0x55555555); x = (x & 0x33333333) + ((x >> 2) & 0x33333333); return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline ll countbit(ll x){ return countbit(int(x & INT_MAX)) + countbit(int(x >> 32) & INT_MAX); }
inline void printbit(int x, int len){ for (int i = len - 1; i >= 0; i--) print_int(getbit(x, i)); }
int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }

template <typename A, typename B> ostream& operator<<(ostream& stream, const pair <A, B> &p){ stream << "{" << p.first << "," << p.second << "}"; return stream; }
template <typename A> ostream& operator<<(ostream &stream, const vector <A> &v){ stream << "["; for (auto itr = v.begin(); itr != v.end(); itr++)stream << *itr << " "; stream << "]"; return stream; }
template <typename A, typename B> ostream& operator<<(ostream &stream, const map <A, B> &v){ stream << "["; for (auto itr = v.begin(); itr != v.end(); itr++)stream << *itr << " "; stream << "]"; return stream; }
template <typename A> ostream& operator<<(ostream &stream, const set <A> &v){ stream << "["; for (auto itr = v.begin(); itr != v.end(); itr++)stream << *itr << " "; stream << "]"; return stream; }
template <typename A> ostream& operator<<(ostream &stream, const stack <A> &v){ stack <A> st = v; stream << "["; while (!st.empty()){ stream << st.top() << " "; st.pop(); }stream << "]"; return stream; }
template <typename A> ostream& operator<<(ostream &stream, const priority_queue <A> &v){ priority_queue <A> q = v; stream << "["; while (!q.empty()){ stream << q.top() << " "; q.pop(); }stream << "]"; return stream; }
template <typename A> ostream& operator<<(ostream &stream, const queue <A> &v){queue <A> q = v;stream << "[";while (!q.empty()){stream << q.front() << " ";q.pop();}stream << "]";return stream;}
template <typename A> ostream& operator<<(ostream &stream, const deque <A> &v){deque <A> q = v;stream << "[";while (!q.empty()){stream << q.front() << " ";q.pop_front();}stream << "]";return stream;}


void run();

#ifndef MODE
#define MODE 0
#endif






int main()
{
    srand(time(NULL));
#ifdef FILES
    freopen(FILES".in", "r", stdin);
    freopen(FILES".out", "w", stdout);
#else
#ifdef FROM_FILE
    freopen("file.in", "r", stdin);
#endif
#endif
#ifdef MULTITEST
    do
    {
#endif
        run();
#ifdef MULTITEST
        if (MODE)
        {
            LINE;
            LINE;
        }
    } while (MODE);
#endif
    return 0;
}







#define time sgdtoe
#define tm sdofrhg

const int mod = 1e9+7;
const int N = 1003;

struct SegmentTree2D
{
    vector <vector <int> > tr;
    int n, m;

    SegmentTree2D(int _n, int _m, int arr[N][N])
        : n(_n)
        , m(_m)
    {
        tr.resize(4 * n);
        for(int i = 0; i < 4*n; ++i)
            tr[i].resize(4 * m);
        build(1, 1, 0, n-1, 0, m-1, arr);
    }

    void build(int vx, int vy, int lx, int rx, int ly, int ry, int arr[N][N])
    {
        if(lx == rx)
        {
            if(ly == ry)
                tr[vx][vy] = arr[lx][ly];
            else
            {
                int mid = (ly + ry) >> 1;
                build(vx, vy + vy, lx, rx, ly, mid, arr);
                build(vx, vy + vy + 1, lx, rx, mid+1, ry, arr);
                tr[vx][vy] = max(tr[vx][vy + vy], tr[vx][vy + vy + 1]);
            }
        }
        else
        {
            int mid = (lx + rx) >> 1;
            build(vx + vx, vy, lx, mid, ly, ry, arr);
            build(vx + vx + 1, vy, mid+1, rx, ly, ry, arr);
            tr[vx][vy] = max(tr[vx+vx][vy], tr[vx+vx+1][vy]);

            if(ly < ry)
            {
                int mid = (ly + ry) >> 1;
                build(vx, vy+vy, lx, rx, ly, mid, arr);
                build(vx, vy+vy+1, lx, rx, mid+1, ry, arr);
                tr[vx][vy] = max(tr[vx][vy+vy], tr[vx][vy+vy+1]);
            }
        }
    }

    int get(int vx, int vy, int lx, int rx, int ly, int ry, int Lx, int Rx, int Ly, int Ry)
    {
        if(Lx > Rx || Ly > Ry)
            return 0;
        if(lx == Lx && rx == Rx && ly == Ly && ry == Ry)
            return tr[vx][vy];
        else
        {
            if(lx == Lx && rx == Rx)
            {
                int mid = (ly + ry) >> 1;
                return max(
                        get(vx, vy+vy, lx, rx, ly, mid, Lx, Rx, Ly, min(Ry, mid)),
                        get(vx, vy+vy+1, lx, rx, mid+1, ry, Lx, Rx, max(mid+1, Ly), Ry)
                        );
            }
            else
            {
                int mid = (lx + rx) >> 1;
                return max(
                        get(vx+vx, vy, lx, mid, ly, ry, Lx, min(mid, Rx), Ly, Ry),
                        get(vx+vx+1, vy, mid+1, rx, ly, ry, max(mid+1, Lx), Rx, Ly, Ry)
                        );
            }
        }
    }

    int get(int x1, int y1, int x2, int y2)
    {
        return get(1, 1, 0, n-1, 0, m-1, x1, y1, x2, y2);
    }
};

int ARR[N][N][10][10];

struct SparseTable2D
{
    int max2[N];
    int n, m;

    inline int& tr(int x, int y, int i, int j)
    {
        return ARR[x][y][i][j];
    }

    SparseTable2D(int _n, int _m, int arr[N][N])
        : n(_n)
        , m(_m)
    {

        for(int i = 0; i < 10; ++i)
        {
            for(int j = 0; j < 10; ++j)
            {
                for(int x = 0; x < n; ++x)
                {
                    for(int y = 0; y < m; ++y)
                    {
                        if(i == 0)
                        {
                            if(j == 0)
                                tr(x, y, i, j) = arr[x][y];
                            else
                            {
                                if(y + (1 << j) > m)
                                    continue;
                                tr(x, y, i, j) = max(tr(x, y, i, j-1), tr(x, y + (1 << (j-1)), i, j-1));
                            }
                        }
                        else
                        {
                            if(x + (1 << i) > n || y + (1 << j) > m)
                                continue;
                            tr(x, y, i, j) = max(tr(x, y, i-1, j), tr(x + (1 << (i-1)), y, i-1, j));
                        }
                    }
                }
            }
        }

        max2[0] = 0;
        for(int i = 1; i < N; ++i)
            max2[i] = max2[i-1] + ((1 << (max2[i-1]+1)) <= i);
    }

    int get(int x1, int y1, int x2, int y2)
    {
        int maxlenx = max2[x2-x1+1];
        int maxleny = max2[y2-y1+1];
        int ret = 0;
        maxx(ret, tr(x1, y1, maxlenx, maxleny));
        maxx(ret, tr(x1, y2-(1<<maxleny)+1, maxlenx, maxleny));
        maxx(ret, tr(x2 - (1 << maxlenx)+1, y1, maxlenx, maxleny));
        maxx(ret, tr(x2-(1 << maxlenx)+1, y2-(1 << maxleny)+1, maxlenx, maxleny));
        return ret;
    }
};

int a[N][N];
int dp[N][N];

void run()
{
    int n, m;
    read_int(n, m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            read_integer(a[i][j]);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(a[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = min((i == 0 || j == 0) ? 0 : dp[i-1][j-1], min(i == 0 ? 0 : dp[i-1][j], j == 0 ? 0 : dp[i][j-1])) + 1;
    int q;
    read_int(q);
    

    SparseTable2D tree(n, m, dp);
    while(q--)
    {
        int x1, y1, x2, y2;
        read_integer(x1);
        read_integer(y1);
        read_integer(x2);
        read_integer(y2);
        --x1;
        --y1;
        --x2;
        --y2;
        int l = 1, r = min(x2-x1+1, y2-y1+1);
        int res = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            int fromx = x1+mid-1;
            int fromy = y1+mid-1;
            if(tree.get(fromx, fromy, x2, y2) >= mid)
            {
                res = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        print_int(res);ln;
    }
}
