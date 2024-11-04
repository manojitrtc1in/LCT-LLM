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
#include <stdlib.h>
#include <bitset>
#include <ctime>

using namespace std;

#define ARGS_NUM(...) ARGS_NUM_IMPL_((0,__VA_ARGS__,5,4,3,2,1))
#define ARGS_NUM_IMPL_(arg) ARGS_NUM_IMPL arg
#define ARGS_NUM_IMPL(_0,_1,_2,_3,_4,_5, N,...) N
#define FUNC_CALL(func, ...) FUNC_CALL_NUM(func, ARGS_NUM(__VA_ARGS__))
#define FUNC_CALL_NUM(func, args) FUNC_CALL_NUM_(func, args)
#define FUNC_CALL_NUM_(func, args) FUNC_CALL_NUM__(func, args)
#define FUNC_CALL_NUM__(func, args) func ## args


#define I64_IO



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
#define pi 3.14159265359
#define eps (1e-8)
#define minn(a, b) a = min((a), (b))
#define maxx(a, b) a = max((a), (b))
#define all(v) v.begin(),v.end()
#define sz(v) ((int)v.size())
#define ln putchar('\n')
#define space putchar(' ')
#define pair_i pair <int,int>
#define pair_ll pair <ll,ll>





#define __PRINT(...) MODE ? (FUNC_CALL(__PRINT, __VA_ARGS__)(__VA_ARGS__)) : cout << ""
#define __PRINT1(a) cout << #a << " = " << (a) << "\n"
#define __PRINT2(a,b) cout << #a << " = " << (a) << "," << #b << " = " << (b) << "\n"
#define __PRINT3(a,b,c) cout << #a << " = " << (a) << "," << #b << " = " << (b) << "," << #c << " = " << (c) << "\n"
#define __PRINT4(a,b,c,d) cout << #a << " = " << (a) << "," << #b << " = " << (b) << "," << #c << " = " << (c) << "," << #d << " = " << (d) << "\n"
#define __BP MODE ? break_point() : 0
#define __LINE MODE ? printf("-------------------------------\n") : 0
#define __LOG(...) MODE ? printf(__VA_ARGS__) : 0;




int break_point(){ char c; while ((c = getchar()) != '\n'); return 0; }
template <typename T> void read_integer(T &r){ bool sign = 0; r = 0; char c; while (1){ c = getchar(); if (c == '-'){ sign = 1; break; }if (c != ' ' && c != '\n'){ r = c - '0'; break; } }while (1){ c = getchar(); if (c == ' ' || c == '\n')break; r = r * 10 + (c - '0'); }if (sign)r = -r; }
ll binpowmod(ll a, ll b, ll mod){if (b == 0)return 1; ll c = binpowmod(a, b >> 1, mod);return (((c*c) % mod) * (b & 1 ? a : 1)) % mod;}
ll binpow(ll a, ll b){if (b == 0)return 1;ll c = binpow(a, b >> 1);return c*c*(b & 1 ? a : 1);}
inline int getbit(int x, int b){return (x >> b) & 1;}
inline ll getbit(ll x, int b){return (x >> b) & 1;}
inline ull getbit(ull x, int b){return (x >> b) & 1;}
inline int setbit(int x, int b){return x | (1 << b);}
inline void _setbit(int &x, int b){x = setbit(x, b);}
inline ll setbit(ll x, int b){ return x | (1ll << b);}
inline void _setbit(ll &x, int b){x = setbit(x, b);}
inline int unsetbit(int x, int b){return x & (INT_MAX - (1 << b));}
inline void _unsetbit(int &x, int b){x = unsetbit(x, b);}
inline int countbit(int x){x = x - ((x >> 1) & 0x55555555);x = (x & 0x33333333) + ((x >> 2) & 0x33333333);return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;}
inline ll countbit(ll x){int p1 = (x >> 32) & ((1ll << 32)-1);int p2 = x & ((1ll << 32)-1);return countbit(p1) + countbit(p2);}
template <typename T> void printbit(T x, int len){for(int i = len-1; i >= 0; i--) print_int(getbit(x, i));}
int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }

template <typename A,typename B> ostream& operator<<(ostream& stream, const pair <A, B> &p){stream << "{" << p.first << "," << p.second << "}";return stream;}
template <typename A> ostream& operator<<(ostream &stream, const vector <A> &v){stream << "[";for (auto itr = v.begin(); itr != v.end(); itr++)stream << *itr << " ";stream << "]";return stream;}
template <typename A, typename B> ostream& operator<<(ostream &stream, const map <A, B> &v){stream << "[";for (auto itr = v.begin(); itr != v.end(); itr++)stream << *itr << " ";stream << "]";return stream;}
template <typename A> ostream& operator<<(ostream &stream, const set <A> &v){stream << "[";for (auto itr = v.begin(); itr != v.end(); itr++)stream << *itr << " ";stream << "]";return stream;}
template <typename A> ostream& operator<<(ostream &stream, const stack <A> &v){stack <A> st;stream << "["; while (!st.empty()){ stream << st.top() << " "; st.pop(); }stream << "]";return stream;}
template <typename A> ostream& operator<<(ostream &stream, const priority_queue <A> &v){priority_queue <A> q = v;stream << "[";while (!q.empty()){stream << q.top() << " ";q.pop();}stream << "]";return stream;}

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
    do
    {
        run();
        if (MODE)
        {
            __LINE;
            __LINE;
        }
    } while (MODE);
    return 0;
}







#define N 1003

int a[N][N];

struct SegmentTree
{
    struct val
    {
        int lv, rv, tv;
        int l, r;
        val(int _l = 0, int _r = 0, int _lv = 0, int _rv = 0, int _tv = 0)
            : l(_l)
            , r(_r)
            , lv(_lv)
            , rv(_rv)
            , tv(_tv)
        {}
    };
    vector <val> tr;
    int n;

    SegmentTree(int cnt, int m, bool t)
        : n(cnt)
    {
        tr.resize(4 * n);
        build(1, 0, n-1, m, t);
    }

    val combine(val &a, val &b)
    {
        if(a.l == -1)
            return b;
        if(b.l == -1)
            return a;
        val ret;
        ret.lv = a.lv + (a.lv == a.r - a.l + 1 ? b.lv : 0);
        ret.rv = b.rv + (b.rv == b.r - b.l + 1 ? a.rv : 0);
        ret.tv = max(max(a.tv, b.tv),max(max(ret.lv, ret.rv), a.rv + b.lv));
        ret.l = a.l;
        ret.r = b.r;
        return ret;
    }

    void build(int v, int l, int r, int m, bool t)
    {
        if(l == r)
        {
            if(t)
                tr[v].tv = a[m][l];
            else 
                tr[v].tv = a[l][m];
            tr[v].lv = tr[v].rv = tr[v].tv;
            tr[v].l = l;
            tr[v].r = r;
        }
        else
        {
            int mid = (l + r) >> 1;
            build(v+v, l, mid, m, t);
            build(v+v+1, mid+1, r, m, t);
            tr[v] = combine(tr[v+v], tr[v+v+1]);
        }
    }

    val get_value_impl(int v, int l, int r, int L, int R)
    {
        if(R < L)
            return val(-1);
        if(l == L && r == R)
            return tr[v];
        else
        {
            int mid = (l + r) >> 1;
            val lval = get_value_impl(v+v, l, mid, L, min(R, mid));
            val rval = get_value_impl(v+v+1, mid+1, r, max(mid+1, L), R);
            val ret = combine(lval, rval);
            return ret;
        }
    }

    void update_impl(int v, int l, int r, int pos)
    {
        if(l == r)
        {
            tr[v].tv ^= 1;
            tr[v].lv = tr[v].rv = tr[v].tv;
        }
        else
        {
            int mid = (l + r) >> 1;
            if(pos <= mid)
                update_impl(v+v, l, mid, pos);
            else
                update_impl(v+v+1, mid+1, r, pos);
            tr[v] = combine(tr[v+v], tr[v+v+1]);

        }
    }

    val get_value(int l, int r)
    {
        return get_value_impl(1, 0, n-1, l, r);
    }

    void update(int pos)
    {
        update_impl(1, 0, n-1, pos);
    }
};

SegmentTree* row[N];
SegmentTree* col[N];

void run()
{
    int n, m, q;
    read_int(n, m, q);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            read_integer(a[i][j]);
    for(int i = 0; i < n; i++)
        row[i] = new SegmentTree(m, i, true);
    for(int i = 0; i < m; i++)
        col[i] = new SegmentTree(n, i, false);
    int t, x, y;
    while(q--)
    {
        read_int(t, x, y);
        --x;
        --y;
        if(t == 1)
        {
            row[x]->update(y);
            col[y]->update(x);
            a[x][y] ^= 1;
        }
        else
        {
            int res = 0;
            if(a[x][y])
            {
                

                int p1 = x - col[y]->get_value(0, x-1).rv;
                int p2 = x + col[y]->get_value(x+1, n-1).lv;
                res = p2-p1 + 1;
                for(int k = y+1; k < m; k++)
                {
                    if(!a[x][k])
                        break;
                    if((p2 - p1 + 1) * (m-y) <= res)
                        break;
                    int h1 = x - col[k]->get_value(0, x-1).rv;
                    int h2 = x + col[k]->get_value(x+1, n-1).lv;
                    maxx(p1, h1);
                    minn(p2, h2);
                    maxx(res, (k-y+1)*(p2 - p1 + 1));
                }

                

                p1 = x - col[y]->get_value(0, x-1).rv;
                p2 = x + col[y]->get_value(x+1, n-1).lv;
                maxx(res, p2-p1 + 1);
                for(int k = y-1; k >= 0; k--)
                {
                    if(!a[x][k])
                        break;
                    if((p2 - p1 + 1) * (y+1) <= res)
                        break;
                    int h1 = x - col[k]->get_value(0, x-1).rv;
                    int h2 = x + col[k]->get_value(x+1, n-1).lv;
                    maxx(p1, h1);
                    minn(p2, h2);
                    maxx(res, (y-k+1)*(p2 - p1 + 1));
                }

                

                p1 = y - row[x]->get_value(0, y-1).rv;
                p2 = y + row[x]->get_value(y+1, m-1).lv;
                maxx(res, p2-p1 + 1);
                for(int k = x-1; k >= 0; k--)
                {
                    if(!a[k][y])
                        break;
                    if((p2 - p1 + 1) * (x+1) <= res)
                        break;
                    int h1 = y - row[k]->get_value(0, y-1).rv;
                    int h2 = y + row[k]->get_value(y+1, m-1).lv;
                    maxx(p1, h1);
                    minn(p2, h2);
                    maxx(res, (x-k+1)*(p2 - p1 + 1));
                }

                

                p1 = y - row[x]->get_value(0, y-1).rv;
                p2 = y + row[x]->get_value(y+1, m-1).lv;
                maxx(res, p2-p1 + 1);
                for(int k = x+1; k < n; k++)
                {
                    if(!a[k][y])
                        break;
                    if((p2 - p1 + 1) * (n-x) <= res)
                        break;
                    int h1 = y - row[k]->get_value(0, y-1).rv;
                    int h2 = y + row[k]->get_value(y+1, m-1).lv;
                    maxx(p1, h1);
                    minn(p2, h2);
                    maxx(res, (k-x+1)*(p2 - p1 + 1));
                }
            }
            print_int(res);ln;
        }
    }
}



