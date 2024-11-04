
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







typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<pll> vll_ll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vll_ll> vvll_ll;













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

constexpr int id2=0;
constexpr int id4=MAX_BITS;
constexpr int id6=MAX_BITS*2;
constexpr int id0=MAX_BITS*3;
constexpr int id17=MAX_BITS*4;
constexpr int id3=MAX_BITS*5;

typedef unsigned int ui;
constexpr uint64_t MASK=(1ULL<<MAX_BITS)-1ULL;
constexpr int id5=2048;
constexpr int OUTSIDE=id5-1;

constexpr uint64_t id11=(1ULL<<2)-1ULL;

struct __attribute__ ((packed)) id7
{
    uint64_t lo;
    uint16_t mi;
     uint8_t hi;
};

typedef id7 node_data;

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

inline int3 id19(const id7& x)
{
    int x1=(x.lo>>id2)&MASK;
    int y1=(x.lo>>id4)&MASK;
    return calc_xy(x1, y1, -x1-y1);
}
inline int3 id18(const id7& x)
{
    int x2=(x.lo>>id6)&MASK;
    int y2=(x.lo>>id0)&MASK;
    return calc_xy(x2, y2, +x2-y2);
}
inline int3 id14(const id7& x)
{
    int x3=(x.lo>>id17)&MASK;
    int y3=(int)(((x.lo>>id3)&MASK) | ((x.mi & id11) << 9));
    return calc_xy(x3, y3, -x3+y3);
}
inline int3 id16(const id7& x)
{
    int x4=(x.mi >> 2) & MASK; 

    int y4=(x.mi >> 13) | ((int)x.hi << 3); 

    return calc_xy(x4, y4, +x4+y4);
}

inline node_data_normal unpack(const id7& x)
{

    int x1=(x.lo>>id2)&MASK;
    int y1=(x.lo>>id4)&MASK;

    int x2=(x.lo>>id6)&MASK;
    int y2=(x.lo>>id0)&MASK;

    int x3=(x.lo>>id17)&MASK;
    int y3=(int)(((x.lo>>id3)&MASK) | ((x.mi & id11) << 9));

    int x4=(x.mi >> 2) & MASK; 

    int y4=(x.mi >> 13) | ((int)x.hi << 3); 


    


    node_data_normal y;

    y.min_nx_ny=calc_xy(x1, y1, -x1-y1);
    y.min_px_ny=calc_xy(x2, y2, +x2-y2);
    y.min_nx_py=calc_xy(x3, y3, -x3+y3);
    y.min_px_py=calc_xy(x4, y4, +x4+y4);

    node_data_normal y=
    {
        .min_nx_ny=id19(x),
        .min_px_ny=id18(x),
        .min_nx_py=id14(x),
        .min_px_py=id16(x),
    };

    return y;
}

inline id7 pack(const node_data_normal& y)
{
    uint64_t x1=g1(y.min_nx_ny);
    uint64_t y1=g2(y.min_nx_ny);

    uint64_t x2=g1(y.min_px_ny);
    uint64_t y2=g2(y.min_px_ny);

    uint64_t x3=g1(y.min_nx_py);
    uint64_t y3=g2(y.min_nx_py);

    uint64_t x4=g1(y.min_px_py);
    uint64_t y4=g2(y.min_px_py);

    

    

    

    


    id7 x;
    x.lo=x1|(y1<<id4)|(x2<<id6)|(y2<<id0)|(x3<<id17)|(y3<<id3);
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

inline id7 unite(const id7& A, const id7& B)
{
    node_data_normal AA=unpack(A), BB=unpack(B), RR;
    RR=unite(AA, BB);

    id7 R=pack(RR);
    return R;
}

inline int3 unite(const int3& A, const int3& B)
{
    return min(A, B);
}




constexpr node_data id9={.lo=UINT64_MAX, .mi=UINT16_MAX, .hi=UINT8_MAX};
constexpr int3 id10={INF, OUTSIDE, OUTSIDE};
constexpr node_data_normal id8=
{
    id10,
    id10,
    id10,
    id10,
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



int ctr_calls=0;






ll sum_calls=0;
node_data A[2*id5][2*id5];

struct id13
{
    int nn, mm, id15, id12;
    constexpr static int ROOT=1;

    


    void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
    {
        if (ly == ry)
        {
            if (lx == rx)
            {
                A[vx][vy] = (lx < nn && ly<mm ? from_xy(lx, ly) : id9);
            }
            else
            {
                A[vx][vy] = unite(A[vx*2][vy], A[vx*2+1][vy]);
            }
        }
        else
        {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy*2, ly, my);
            build_y(vx, lx, rx, vy*2+1, my+1, ry);
            A[vx][vy] = unite(A[vx][vy*2], A[vx][vy*2+1]);
        }
    }

    void build_x(int vx, int lx, int rx) {
        if (lx != rx)
        {
            int mx = (lx + rx) / 2;
            build_x(vx*2, lx, mx);
            build_x(vx*2+1, mx+1, rx);
        }
        build_y(vx, lx, rx, ROOT, 0, id12-1);
    }

    id13(int n_, int m_):
        nn(n_),
        mm(m_),
        id15(1),
        id12(1)

        

    {
        while(id15<nn) id15*=2;
        while(id12<mm) id12*=2;

        


        

        

        



        build_x(ROOT, 0, id15-1);

        memset(A, 255, sizeof(A));
        for(int i=0; i<nn; i++)
        {
            for(int j=0; j<mm; j++) A[id15+i][id12+j]=from_xy(i,j);
        }

        for(int vx=id15-1; vx>=ROOT; vx--)
        {
            

            for(int vy=id12; vy<2*id12; vy++) 

                A[vx][vy] = unite(A[vx*2][vy], A[vx*2+1][vy]);
        }

        for(int vx=0; vx<2*id15; vx++)
        {
            for(int vy=id12-1; vy>=ROOT; vy--)
            {
                A[vx][vy] = unite(A[vx][vy*2], A[vx][vy*2+1]);
            }
        }


        for(int vx=2*id15-1; vx>=ROOT; vx--)
        {
            for(int vy=2*id12-1; vy>=ROOT; vy--)
            {
                int i=vx-id15, j=vy-id12;
                if(0<=j)
                {
                    if(0<=i)
                    {
                        A[vx][vy] = (i < nn && j<mm ? from_xy(i, j) : id9);
                        

                    }
                    else
                    {
                        A[vx][vy] = unite(A[vx*2][vy], A[vx*2+1][vy]);
                    }
                }
                else
                {
                    A[vx][vy] = unite(A[vx][vy*2], A[vx][vy*2+1]);
                }
            }
        }

    }


    int3 sum_y
        if (ly > ry) \
            return id10; \
        if (ly == tly && try_ == ry) \
            return unpack_
        int tmy = (tly + try_) / 2; \
        return \
        unite(sum_y
              sum_y
    } \

    id1(1)
    id1(2)
    id1(3)
    id1(4)

    node_data_normal sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry)
            return id8;
        if (ly == tly && try_ == ry)
            return unpack(A[vx][vy]);
        int tmy = (tly + try_) / 2;
        return
        unite(sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)),
              sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
    }


    int3 sum_x
        if (lx > rx) \
            return id10; \
        if (lx == tlx && trx == rx) \
            return sum_y
\
        int tmx = (tlx + trx) / 2;\
        return\
        unite(sum_x
              sum_x
    }\

    REGISTER_sum_x(1)
    REGISTER_sum_x(2)
    REGISTER_sum_x(3)
    REGISTER_sum_x(4)

    node_data_normal sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx)
            return id8;
        if (lx == tlx && trx == rx)
            return sum_y(vx, ROOT, 0, id12-1, ly, ry);

        int tmx = (tlx + trx) / 2;
        return
        unite(sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry),
              sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
    }


    int3 query_LRDU
    {\
        return sum_x
    }\

    REGISTER_query_LRDU(1)
    REGISTER_query_LRDU(2)
    REGISTER_query_LRDU(3)
    REGISTER_query_LRDU(4)

    node_data_normal query_LRDU(int x1, int x2, int y1, int y2)
    {
        

        return sum_x(ROOT, 0, id15-1, x1, x2, y1, y2);
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y) {
        if (ly == ry) {
            if (lx == rx)
                A[vx][vy] = id9;
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
        update_y(vx, lx, rx, ROOT, 0, id12-1, x, y);
    }

    void update(int x, int y)
    {
        update_x(ROOT, 0, id15-1, x, y);
    }

    pii solve(int x, int y)
    {
        

        int3 result={INF, -1, -1};

        {
            

            

            

            

            auto LD=query_LRDU1(0, x,    0, y);
            auto [d, x2, y2]=LD;
            

            dbg(d, x2, y2);
            dbg(+x+y+d, x2, y2);
            dbg("~~~~~~~~");

            result=min(result, {+x+y+d, x2, y2});
        }

        {
            

            

            

            auto LU=query_LRDU3(0, x,    y, id12-1);
            auto [d, x2, y2]=LU;
            dbg(d, x2, y2);
            dbg(+x-y+d, x2, y2);
            dbg("~~~~~~~~");

            result=min(result, {+x-y+d, x2, y2});
        }

        {
            

            

            

            auto RD=query_LRDU2(x, id15-1, 0, y);
            auto [d, x2, y2]=RD;
            dbg(d, x2, y2);
            dbg(-x+y+d, x2, y2);
            dbg("~~~~~~~~");

            result=min(result, {-x+y+d, x2, y2});
        }

        {
            

            

            

            auto RU=query_LRDU4(x, id15-1, y, id12-1);
            auto [d, x2, y2]=RU;
            dbg(d, x2, y2);
            dbg(-x-y+d, x2, y2);
            dbg("~~~~~~~~");

            result=min(result, {-x-y+d, x2, y2});
        }

        dbg("--------------------------");

        auto [resD, resX, resY]=result;
        assert(0<=resX && resX<nn && 0<=resY && resY<mm);

        

        

        update(resX, resY);

        return {resX, resY};
        

    }
};

void stress_test(int n, int m, int k)
{
    k=min(k, n*m);
    id13 ST(n, m);

    return;

    for(int qq=0; qq<k; qq++)
    {
        int x=rand()%n, y=rand()%m;
        auto [ansx, ansy]=ST.solve(x, y);

        if(qq%10000==0)
        {
            dbg(qq);
            rl avg=(sum_calls*1.0)/(4*(qq+1));
            dbg(avg, sqrt(avg));
        }
    }
}

int main()
{
    dbg(sizeof(A));
    dbg(sizeof(node_data));
    dbg(sizeof(id7));
    



    stress_test(2000, 2000, 100'000);
    return 0;



    freopen("200A.txt", "r", stdin);
    //freopen("200A_stderr.txt", "w", stderr);

    //freopen("output.txt", "w", stdout);


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    int TT;

    cin >> TT;

    TT=1;

    for(int ttt=0; ttt<TT; ttt++)
    {

    }

    int n, m, k;
    cin >> n >> m >> k;
    id13 ST(n, m);

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
