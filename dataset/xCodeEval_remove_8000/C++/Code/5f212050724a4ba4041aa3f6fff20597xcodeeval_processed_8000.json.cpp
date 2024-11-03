












































































using namespace std;
int MOD = 1000000007; 

const int inf = 0x3f3f3f3f;
const int N = 110;

template <typename T>
inline bool scan_d(T& ret) { char c; int sgn; if (c = getchar(), c == EOF) return 0; while (c != '-' && (c < '0' || c > '9')) { if ((c = getchar()) == EOF) return 0; }sgn = (c == '-') ? -1 : 1; ret = (c == '-') ? 0 : (c - '0'); while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0'); ret *= sgn; return 1; }
template<typename T>
void print(T x) { static char s[33], * s1; s1 = s; if (!x) *s1++ = '0'; if (x < 0) putchar('-'), x = -x; while (x) *s1++ = (x % 10 + '0'), x /= 10; while (s1-- != s) putchar(*s1); }
template<typename T>
void println(T x) { print(x); putchar('\n'); }
struct TPoint {
    int x, y, id;
    bool operator<(const TPoint& comp) const { if (x != comp.x) return x < comp.x; if (y != comp.y) return y < comp.y; return id < comp.id; }
};



int norm(int x) { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
template<class T>
T power(T a, int b) { T res = 1; for (; b; b >>= 1, a *= a) { if (b & 1) { res *= a; } } return res; }
struct mint {
    int x;
    mint(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    mint operator-() const { return mint(norm(MOD - x)); }
    mint inv() const { return power(*this, MOD - 2); }
    mint& operator*=(const mint& rv) { x = (LL)x * rv.x % MOD; return *this; }
    mint& operator+=(const mint& rv) { x = norm(x + rv.x); return *this; }
    mint& operator-=(const mint& rv) { x = norm(x - rv.x); return *this; }
    mint& operator/=(const mint& rv) { return *this *= rv.inv(); }
    friend mint operator*(const mint& lv, const mint& rv) { mint res = lv; res *= rv; return res; }
    friend mint operator+(const mint& lv, const mint& rv) { mint res = lv; res += rv; return res; }
    friend mint operator-(const mint& lv, const mint& rv) { mint res = lv; res -= rv; return res; }
    friend mint operator/(const mint& lv, const mint& rv) { mint res = lv; res /= rv; return res; }
};

mint c[N][N];
void readycomb() {
    c[0][0] = 1;
    rep(i, 1, N) {
        c[i][0] = c[i][i] = 1;
        rep(j, 1, i) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
}
mint comb(int x, int y) {
    if (y < 0 || y > x) return 0ll;
    return c[x][y];
}

int table[N * N] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,0,
1,2,4,8,16,32,46,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,0,
1,2,4,8,16,32,46,46,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,0,
1,2,4,8,16,32,47,46,46,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,0,
1,2,4,8,16,32,48,47,46,46,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,0,
1,2,4,8,16,32,48,48,47,46,46,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,0,
1,2,4,8,16,32,48,48,48,47,46,46,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,0,
1,2,4,8,16,32,48,48,48,48,47,46,46,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1,0,
1,2,4,8,16,32,48,48,48,48,48,47,46,46,45,44,44,44,43,42,42,41,40,40,40,40,39,38,38,37,36,36,36,35,34,34,33,32,32,32,32,32,32,31,30,30,29,28,28,28,27,26,26,25,24,24,24,24,23,22,22,21,20,20,20,19,18,18,17,16,16,16,16,16,15,14,14,13,12,12,12,11,10,10,9,8,8,8,8,7,6,6,5,4,4,4,3,2,2,1 };

mint dp[N][N][N];
void fmain() {
    int n, m, k, p;
    scan_d(n), scan_d(m), scan_d(k), scan_d(p);
    MOD = p;

    auto getTable = [&](int i, int j) {
        return table[(i - 1) * 100 + (j - 1)];
    };
    if (k > getTable(n, m)) {
        puts("0");
        return;
    }

    readycomb();
    dp[0][0][0] = 1;
    rep(i, 1, N) dp[i][0][0] = dp[i - 1][0][0] * i;
    rep(j, 1, N) dp[0][j][0] = dp[0][j - 1][0];

    rep(j, 0, m) {
        rep(i1, 0, n + 1) {
            rep(k1, 0, k + 1) {
                if (dp[i1][j][k1].val() == 0) continue;

                rep(i2, 0, i1 + 1) {
                    if (i1 + i2 + 1 > n) break;
                    if (k1 > getTable(i1 + i2 + 1, j + 1)) break;

                    rep(k2, 0, k + 1) {
                        if (k1 + k2 > k) break;
                        if (k1 + k2 > getTable(i1 + i2 + 1, j + 1)) break;

                        

                        mint inc = comb(i1 + i2, i1) * dp[i1][j][k1] * dp[i2][j][k2];
                        if (i1 != i2) inc *= 2;

                        

                        int k3 = j + 1 == 1 ? 1 : 0;
                        dp[i1 + 1 + i2][j + 1][k1 + k2 + k3] += inc;
                    }
                }
            }
        }
    }
    println(dp[n][m][k].val());

    


    rep(i, 1, n + 1) rep(j, 1, m + 1) {
        int mx = 0;
        rep(k0, 0, k + 1) if (dp[i][j][k0].val() != 0) mx = k0;
        

        printf("%d,", mx);
        if (j == m) putchar('\n');
    }

}

int main() {

    IN;
    


    

    char ch; while (scanf(" %c", &ch) != EOF) { ungetc(ch, stdin); fmain(); }
    return 0;
}
