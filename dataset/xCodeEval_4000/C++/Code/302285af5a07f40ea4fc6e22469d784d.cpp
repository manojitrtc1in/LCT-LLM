#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
typedef pair<ll, ll> pll;
typedef double rl;

typedef pii int2;


typedef tuple<int, int, int, int>      int4;
typedef tuple<int, int, int, int, int> int5;

typedef pll ll2;
typedef tuple<ll, ll, ll>         ll3;
typedef tuple<ll, ll, ll, ll>     ll4;
typedef tuple<ll, ll, ll, ll, ll> ll5;

#define g0(x) get<0>(x)
#define g1(x) get<1>(x)
#define g2(x) get<2>(x)
#define g3(x) get<3>(x)
#define g4(x) get<4>(x)

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<pll> vll_ll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vll_ll> vvll_ll;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define xx first
#define yy second

#define FOR(i,N) for(int i=0; i<N; i++)

#define popc __builtin_popcountll



template<typename A>
string to_string(A* ptr)
{
    stringstream ss; ss << "0x" << std::setw(16) << std::setfill ('0') << std::hex << (uint64_t)(uintptr_t)ptr;
    return ss.str();
}

string to_string(char c)
{
    return ((string)"'"+c)+ "'";
}

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#if !ONLINE_JUDGE && 0
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#if ONLINE_JUDGE || 0
#define assert
#endif



const short INF=20000;
typedef tuple<int, int, int> int3;
typedef pair<short, short> short2;

struct node_data_normal
{
    int3 min_nx_ny;
    int3 min_px_ny;
    int3 min_nx_py;
    int3 min_px_py;
};

string to_string(const node_data_normal& u)
{
    return "["
    + to_string(u.min_nx_ny)
    + to_string(u.min_px_ny)
    + to_string(u.min_nx_py)
    + to_string(u.min_px_py) + "]";
}

constexpr int MAX_BITS=11;

constexpr int OFFSET_0=0;
constexpr int OFFSET_1=MAX_BITS;
constexpr int OFFSET_2=MAX_BITS*2;
constexpr int OFFSET_3=MAX_BITS*3;
constexpr int OFFSET_4=MAX_BITS*4;
constexpr int OFFSET_5=MAX_BITS*5;

typedef unsigned int ui;
constexpr uint64_t MASK=(1ULL<<MAX_BITS)-1ULL;
constexpr int MX_POW2=2048;
constexpr int OUTSIDE=MX_POW2-1;

constexpr uint64_t MASK_2BITS=(1ULL<<2)-1ULL;

struct __attribute__ ((packed)) node_data_new
{
    uint64_t lo;
    uint16_t mi;
     uint8_t hi;
};

typedef node_data_new node_data;

inline int3 calc_xy(int x, int y, int res)
{
    if(x==OUTSIDE)
    {
        assert(y==OUTSIDE);
        return {INF, OUTSIDE, OUTSIDE};
    }
    assert(x!=OUTSIDE && y!=OUTSIDE);
    return {res, x, y};
}

inline int3 unpack_1(const node_data_new& x)
{
    int x1=(x.lo>>OFFSET_0)&MASK;
    int y1=(x.lo>>OFFSET_1)&MASK;
    return calc_xy(x1, y1, -x1-y1);
}
inline int3 unpack_2(const node_data_new& x)
{
    int x2=(x.lo>>OFFSET_2)&MASK;
    int y2=(x.lo>>OFFSET_3)&MASK;
    return calc_xy(x2, y2, +x2-y2);
}
inline int3 unpack_3(const node_data_new& x)
{
    int x3=(x.lo>>OFFSET_4)&MASK;
    int y3=(int)(((x.lo>>OFFSET_5)&MASK) | ((x.mi & MASK_2BITS) << 9));
    return calc_xy(x3, y3, -x3+y3);
}
inline int3 unpack_4(const node_data_new& x)
{
    int x4=(x.mi >> 2) & MASK; 

    int y4=(x.mi >> 13) | ((int)x.hi << 3); 

    return calc_xy(x4, y4, +x4+y4);
}

inline node_data_normal unpack(const node_data_new& x)
{
    node_data_normal y=
    {
        .min_nx_ny=unpack_1(x),
        .min_px_ny=unpack_2(x),
        .min_nx_py=unpack_3(x),
        .min_px_py=unpack_4(x),
    };
    return y;
}

inline node_data_new pack(const node_data_normal& y)
{
    uint64_t x1=g1(y.min_nx_ny);
    uint64_t y1=g2(y.min_nx_ny);

    uint64_t x2=g1(y.min_px_ny);
    uint64_t y2=g2(y.min_px_ny);

    uint64_t x3=g1(y.min_nx_py);
    uint64_t y3=g2(y.min_nx_py);

    uint64_t x4=g1(y.min_px_py);
    uint64_t y4=g2(y.min_px_py);

    node_data_new x;
    x.lo=x1|(y1<<OFFSET_1)|(x2<<OFFSET_2)|(y2<<OFFSET_3)|(x3<<OFFSET_4)|(y3<<OFFSET_5);
    x.mi=(y3>>9) | (x4<<2) | (y4<<13);
    x.hi=y4>>3;

    return x;
}

inline node_data_normal unite(const node_data_normal& A, const node_data_normal& B)
{
    return {
        .min_nx_ny=min(A.min_nx_ny, B.min_nx_ny),
        .min_px_ny=min(A.min_px_ny, B.min_px_ny),
        .min_nx_py=min(A.min_nx_py, B.min_nx_py),
        .min_px_py=min(A.min_px_py, B.min_px_py),
    };
}

inline node_data_new unite(const node_data_new& A, const node_data_new& B)
{
    node_data_normal AA=unpack(A), BB=unpack(B), RR;
    RR=unite(AA, BB);

    node_data_new R=pack(RR);
    return R;
}

inline int3 unite(const int3& A, const int3& B)
{
    return min(A, B);
}

constexpr node_data NEUTRAL={.lo=UINT64_MAX, .mi=UINT16_MAX, .hi=UINT8_MAX};
constexpr int3 NEUTRAL_INT3={INF, OUTSIDE, OUTSIDE};
constexpr node_data_normal NEUTRAL_NORMAL=
{
    NEUTRAL_INT3,
    NEUTRAL_INT3,
    NEUTRAL_INT3,
    NEUTRAL_INT3,
};


inline node_data from_xy(int x, int y)
{
    node_data_normal tmp
    {
        .min_nx_ny={-x-y, x, y},
        .min_px_ny={+x-y, x, y},
        .min_nx_py={-x+y, x, y},
        .min_px_py={+x+y, x, y},
    };

    node_data res=pack(tmp);
    return res;
}

node_data A[2*MX_POW2][2*MX_POW2];

struct seg_tree_2D
{
    int nn, mm, pow2n, pow2m;
    constexpr static int ROOT=1;

    seg_tree_2D(int n_, int m_):
        nn(n_),
        mm(m_),
        pow2n(1),
        pow2m(1)
    {
        while(pow2n<nn) pow2n*=2;
        while(pow2m<mm) pow2m*=2;

        memset(A, 255, sizeof(A));
        for(int i=0; i<nn; i++)
        {
            for(int j=0; j<mm; j++) A[pow2n+i][pow2m+j]=from_xy(i,j);
        }

        for(int vx=pow2n-1; vx>=ROOT; vx--)
        {
            

            for(int vy=pow2m; vy<2*pow2m; vy++) 

                A[vx][vy] = unite(A[vx*2][vy], A[vx*2+1][vy]);
        }

        for(int vx=0; vx<2*pow2n; vx++)
        {
            for(int vy=pow2m-1; vy>=ROOT; vy--)
            {
                A[vx][vy] = unite(A[vx][vy*2], A[vx][vy*2+1]);
            }
        }
    }

#define REGISTER_sum_y(IDX) \
    int3 sum_y##IDX(int vx, int vy, int tly, int try_, int ly, int ry) { \
        if (ly > ry) \
            return NEUTRAL_INT3; \
        if (ly == tly && try_ == ry) \
            return unpack_##IDX(A[vx][vy]); \
        int tmy = (tly + try_) / 2; \
        return \
        unite(sum_y##IDX(vx, vy*2, tly, tmy, ly, min(ry, tmy)), \
              sum_y##IDX(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry)); \
    } \

    REGISTER_sum_y(1)
    REGISTER_sum_y(2)
    REGISTER_sum_y(3)
    REGISTER_sum_y(4)

    node_data_normal sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry)
            return NEUTRAL_NORMAL;
        if (ly == tly && try_ == ry)
            return unpack(A[vx][vy]);
        int tmy = (tly + try_) / 2;
        return
        unite(sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)),
              sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
    }

#define REGISTER_sum_x(IDX) \
    int3 sum_x##IDX(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) { \
        if (lx > rx) \
            return NEUTRAL_INT3; \
        if (lx == tlx && trx == rx) \
            return sum_y##IDX(vx, ROOT, 0, pow2m-1, ly, ry); \
\
        int tmx = (tlx + trx) / 2;\
        return\
        unite(sum_x##IDX(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry),\
              sum_x##IDX(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));\
    }\

    REGISTER_sum_x(1)
    REGISTER_sum_x(2)
    REGISTER_sum_x(3)
    REGISTER_sum_x(4)

    node_data_normal sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx)
            return NEUTRAL_NORMAL;
        if (lx == tlx && trx == rx)
            return sum_y(vx, ROOT, 0, pow2m-1, ly, ry);

        int tmx = (tlx + trx) / 2;
        return
        unite(sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry),
              sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
    }

#define REGISTER_query_LRDU(IDX) \
    int3 query_LRDU##IDX(int x1, int x2, int y1, int y2) \
    {\
        return sum_x##IDX(ROOT, 0, pow2n-1, x1, x2, y1, y2);\
    }\

    REGISTER_query_LRDU(1)
    REGISTER_query_LRDU(2)
    REGISTER_query_LRDU(3)
    REGISTER_query_LRDU(4)

    node_data_normal query_LRDU(int x1, int x2, int y1, int y2)
    {
        

        return sum_x(ROOT, 0, pow2n-1, x1, x2, y1, y2);
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y) {
        if (ly == ry) {
            if (lx == rx)
                A[vx][vy] = NEUTRAL;
            else
                A[vx][vy] = unite(A[vx*2][vy], A[vx*2+1][vy]);
        } else {
            int my = (ly + ry) / 2;
            if (y <= my)
                update_y(vx, lx, rx, vy*2, ly, my, x, y);
            else
                update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y);
            A[vx][vy] = unite(A[vx][vy*2], A[vx][vy*2+1]);
        }
    }

    void update_x(int vx, int lx, int rx, int x, int y) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx)
                update_x(vx*2, lx, mx, x, y);
            else
                update_x(vx*2+1, mx+1, rx, x, y);
        }
        update_y(vx, lx, rx, ROOT, 0, pow2m-1, x, y);
    }

    void update(int x, int y)
    {
        update_x(ROOT, 0, pow2n-1, x, y);
    }

    pii solve(int x, int y)
    {
        int3 result={INF, -1, -1};

        {
            auto LD=query_LRDU1(0, x,    0, y);
            auto [d, x2, y2]=LD;

            result=min(result, {+x+y+d, x2, y2});
        }

        {
            auto LU=query_LRDU3(0, x,    y, pow2m-1);
            auto [d, x2, y2]=LU;

            result=min(result, {+x-y+d, x2, y2});
        }

        {
            auto RD=query_LRDU2(x, pow2n-1, 0, y);
            auto [d, x2, y2]=RD;

            result=min(result, {-x+y+d, x2, y2});
        }

        {
            auto RU=query_LRDU4(x, pow2n-1, y, pow2m-1);
            auto [d, x2, y2]=RU;

            result=min(result, {-x-y+d, x2, y2});
        }

        auto [resD, resX, resY]=result;
        assert(0<=resX && resX<nn && 0<=resY && resY<mm);

        update(resX, resY);
        return {resX, resY};
    }
};

int main()
{
#if ONLINE_JUDGE || 1
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    seg_tree_2D ST(n, m);

    for(int qq=0; qq<k; qq++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        auto [ansx, ansy]=ST.solve(x, y);
        cout << ansx+1 << ' ' << ansy+1 << '\n';
    }

    return 0;
}
