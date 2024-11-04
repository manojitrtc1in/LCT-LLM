



















using namespace std;













































int break_point(){ char c; while ((c = getchar()) != '\n'); return 0; }
template <typename T> void read_integer(T &r){ bool sign = 0; r = 0; char c; while (1){ c = getchar(); if (c == '-'){ sign = 1; break; }if (c != ' ' && c != '\n'){ r = c - '0'; break; } }while (1){ c = getchar(); if (c == ' ' || c == '\n')break; r = r * 10 + (c - '0'); }if (sign)r = -r; }
ll id1(ll a, ll b, ll mod){ if (b == 0)return 1; ll c = id1(a, b >> 1, mod); return (((c*c) % mod) * (b & 1 ? a : 1)) % mod; }
ll binpow(ll a, ll b){ if (b == 0)return 1; ll c = binpow(a, b >> 1); return c*c*(b & 1 ? a : 1); }
inline int getbit(int x, int b){ return (x >> b) & 1; }
inline int setbit(int x, int b){ return x | (1 << b); }
inline void _setbit(int &x, int b){ x = setbit(x, b); }
inline ll setbit(ll x, int b){ return x | (1ll << b); }
inline void _setbit(ll &x, int b){ x = setbit(x, b); }
inline int unsetbit(int x, int b){ return x & (INT_MAX - (1 << b)); }
inline void id2(int &x, int b){ x = unsetbit(x, b); }
inline int countbit(int x){ x = x - ((x >> 1) & 0x55555555); x = (x & 0x33333333) + ((x >> 2) & 0x33333333); return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline ll countbit(ll x){ return countbit(int(x & INT_MAX)) + countbit(int(x >> 32) & INT_MAX); }


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












int main()
{
    srand(time(NULL));

    freopen(FILES".in", "r", stdin);
    freopen(FILES".out", "w", stdout);


    freopen("file.in", "r", stdin);



    do
    {

        run();

        if (MODE)
        {
            LINE;
            LINE;
        }
    } while (MODE);

    return 0;
}












const int mod = 1e9+7;
const int N = 100005;

namespace FastIO
{
    const int BUF_SIZE = 50000000;
    char buf_in[BUF_SIZE], buf_out[BUF_SIZE], temp[30];
    int p_in = 0, p_out = 0;
 
    void init()
    {
        fread(buf_in, 1, BUF_SIZE, stdin);
    }
 
    void read_int(int &x)
    {
        while(!isdigit(buf_in[p_in]))
            ++p_in;
        x = 0;
        while(isdigit(buf_in[p_in]))
            x = x * 10 + buf_in[p_in++] - '0';
    }
 
    void put_char(char c)
    {
        buf_out[p_out++] = c;
    }
 
    void print_int(int x)
    {
        temp[0] = x % 10;
        x /= 10;
        int p = 1;
        while(x > 0)
            temp[p++] = x % 10, x /= 10;
        for(--p; p >= 0; --p)
            put_char(temp[p] + '0');
    }
 
    void flush()
    {
        fwrite(buf_out, 1, p_out, stdout);
    }
}

class Matrix
{
public:
    int a[2][2];
    int n, m;

    Matrix(int _n = 2, int _m = 2, bool init_one = false)
        : n(_n)
        , m(_m)
    {
        a[0][0] = init_one;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = init_one;
    }

    inline const int* operator[](int i) const
    {
        return a[i];
    }

    inline int* operator[](int i)
    {
        return a[i];
    }

    inline Matrix operator*(const Matrix &other)
    {
        Matrix ret(n, other.m);
        
        ret[0][0] = (a[0][0] * 1LL * other[0][0] + a[0][1] * 1LL * other[1][0]) % mod;
        ret[0][1] = (a[0][0] * 1LL * other[0][1] + a[0][1] * 1LL * other[1][1]) % mod;
        ret[1][0] = (a[1][0] * 1LL * other[0][0] + a[1][1] * 1LL * other[1][0]) % mod;
        ret[1][1] = (a[1][0] * 1LL * other[0][1] + a[1][1] * 1LL * other[1][1]) % mod;
        return ret;
    }
    inline Matrix operator+(const Matrix& other)
    {
        Matrix ret;
        ret[0][0] = a[0][0] + other[0][0];
        if(ret[0][0] >= mod)
            ret[0][0] -= mod;
        ret[0][1] = a[0][1] + other[0][1];
        if(ret[0][1] >= mod)
            ret[0][1] -= mod;
        ret[1][0] = a[1][0] + other[1][0];
        if(ret[1][0] >= mod)
            ret[1][0] -= mod;
        ret[1][1] = a[1][1] + other[1][1];
        if(ret[1][1] >= mod)
            ret[1][1] -= mod;
        return ret;        
    }
};

Matrix matrix_pow(Matrix m, ll pw)
{
    if(pw == 0)
        return Matrix(m.n, m.m, true);
    Matrix ret(m.n, m.m, true);
    while(pw)
    {
        if(pw & 1)
            ret = ret * m;
        m = m * m;
        pw >>= 1;
    }
    return ret;
}

Matrix id0(2, 2);


Matrix getFib(int a, int b, ll n)
{
    Matrix ret(1, 2);
   if(n == 0)
     return ret;
    ret[0][1] = a;
   if(n == 1)
      return ret;
  ret[0][0] = a;
    ret[0][1] = b;
   if(n == 2)
      return ret;
   Matrix t = matrix_pow(id0, n-2);
   ret = ret * t;
   return ret;
}

Matrix tr[4 * N];
bool psh[4 * N];
Matrix psh_matr[4 * N];

struct SegmentTree
{
   int n;

   SegmentTree(int _n, int *arr)
      : n(_n)
   {
      build(1, 0, n-1, arr);
   }

   void build(int v, int l, int r, int *arr)
   {
      if(l == r)
      {
        tr[v] = getFib(1, 1, arr[l]);
      }
      else
      {
         int mid = (l + r) >> 1;
         build(v+v, l, mid, arr);
         build(v+v+1, mid+1, r, arr);
         tr[v] = tr[v+v] + tr[v+v+1];
      }
   }

   inline void push(int v, int l, int r)
   {
      if(l < r && psh[v])
      {
        if(!psh[v+v])
            psh_matr[v+v] = psh_matr[v];
        else
            psh_matr[v+v] = psh_matr[v+v] * psh_matr[v];
        if(!psh[v+v+1])
            psh_matr[v+v+1] = psh_matr[v];
        else
            psh_matr[v+v+1] = psh_matr[v+v+1] * psh_matr[v];
        tr[v+v] = tr[v+v] * psh_matr[v];
        tr[v+v+1] = tr[v+v+1] * psh_matr[v];
         psh[v+v] = 1;
         psh[v+v+1] = 1;
      }
      psh[v] = 0;
   }

   Matrix get(int v, int l, int r, int L, int R)
   {
      if(L > R)
         return Matrix(1, 2);
      push(v, l, r);
      if(l == L && r == R)
         return tr[v];
      else
      {
         int mid = (l + r) >> 1;
         return get(v+v, l, mid, L, min(mid, R)) + get(v+v+1, mid+1, r, max(mid+1, L), R);
      }
   }

   int get(int l, int r)
   {
      return get(1, 0, n-1, l, r)[0][1];
   }

   void update(int v, int l, int r, int L, int R, const Matrix& x)
   {
      if(R < L)
         return;
      push(v, l, r);
      if(l == L && r == R)
      {
         tr[v] = tr[v] * x;
         psh_matr[v] = x;
         psh[v] = 1;
      }
      else
      {
         int mid = (l + r) >> 1;
         update(v+v, l, mid, L, min(mid, R), x);
         update(v+v+1, mid+1, r, max(mid+1, L), R, x);
         tr[v] = tr[v+v] + tr[v+v+1];
      }
   }

   void update(int l, int r, int x)
   {
        Matrix id3 = matrix_pow(id0, x);
      update(1, 0, n-1, l, r, id3);
   }
};

int a[N];

void run()
{
    FastIO::init();
   id0[0][0] = 0;
   id0[0][1] = 1;
   id0[1][0] = 1;
   id0[1][1] = 1;
   int n, m;
   FastIO::read_int(n);
   FastIO::read_int(m);
   for(int i = 0; i < n; ++i)
      FastIO::read_int(a[i]);
   SegmentTree tree(n, a);
   int tp, l, r, x;
   while(m--)
   {
      FastIO::read_int(tp);
      FastIO::read_int(l);
      FastIO::read_int(r);
      --l;
      --r;
      if(tp == 2)
      {
         FastIO::print_int(tree.get(l, r));
         FastIO::put_char('\n');
      }
      else
      {
         FastIO::read_int(x);
         tree.update(l, r, x);
      }
   }
   FastIO::flush();
}