






































using namespace std;
























































const int MOD = 1e9 + 7;
int fx[] = {-1,+0,+1,+0,+1,+1,-1,-1,+0};
int fy[] = {+0,-1,+0,+1,+1,-1,+1,-1,+0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


template <typename T> inline bool isLeap(T y) {return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false); }
template <typename T> inline T GCD (T a,T b ) {a = abs(a);b = abs(b); if(a < b) swap(a, b); while ( b ) { a = a % b; swap ( a, b ); } return a;}
template <typename T> inline T EGCD(T a,T b,T &x,T &y){if(a == 0) {x = 0;y = 1;return b;}T x1, y1;T d = EGCD(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
template <typename T> inline T LCM(T x,T y){T tp = GCD(x,y);if( (x / tp) * 1. * y > 9e18) return 9e18;return (x / tp) * y;}
template <typename T> inline T BigMod(T A,T B,T M = MOD){A %= M;T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = MOD){return BigMod(A,M-2,M);}
template <typename T> void Compress(T * in, int n, int f = 0){vector <T> vv;for(int i = f; i < n + f; i++) vv.pb(in[i]);Unique(vv);for(int i = f; i < n + f; i++) in[i] = lower_bound(all(vv), in[i]) - vv.begin();}







template <typename T> T scani(T &n){n = 0;bool negative = false;char c = gc();while( c < '0' || c > '9'){if(c == '-') negative = true;c = gc();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = gc();}if(negative) n = ~(n-1);return n;}
template <typename T> void write(T n,int type = true){if(n<0) {pc('-');n = -n;}if(!n) {pc('0');if(type==32) pc(' '); else if(type) pc('\n'); return;}char buff[22];int len = 0;while(n) buff[len++] = n%10+48,n/=10;for(int i=len-1;i>=0;i--) pc(buff[i]);if(type==32) pc(' '); else if(type) pc('\n');}
int scans(char *a){int i=0;char c = 0;while(c < 33) c = gc();while(c > 33){a[i++] = c;c = gc();}a[i] = 0;return i;}




const int pSz = 2000006;
bool np[pSz + 10]; vi prime; int prime_size;void sieve(){np[0] = np[1] = 1;prime.pb(2);for(LL i = 4; i <= pSz; i+=2) np[i] = 1;for(LL i = 3; i <= pSz; i+=2){if(!np[i]){prime.pb(i);for(LL j = i * i; j <= pSz; j += (i << 1)) np[j] = 1;}}prime_size = prime.size();}



const int nSz = 2000006;
LL F[nSz + 1], tMod = MOD;
void Factorial(){ F[0] = 1; for(int i = 1; i <= nSz; i++) F[i] = (F[i - 1] * i) % tMod; }
inline LL nCr(int n, int r) { return (F[n] * InvMod((F[n - r] * F[r]) % tMod, tMod)) % tMod; }



void zAlgo(char *s, int *z){
    int L, R, sz; sz = strlen(s); z[0] = L = R = 0;
    For(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}void zAlgo(string &s, int *z){
    int L, R, sz; sz = s.size(); z[0] = L = R = 0;
    For(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}void zAlgo(int *s, int *z, int n){
    int L, R, sz; sz = n; z[0] = L = R = 0;
    For(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}






template <typename T> inline T id1(T x1, T y1, T x2, T y2){return SQR(x1 - x2) + SQR(y1 - y2);}
template <typename T> inline T Area2(T Ax, T Ay, T Bx, T By, T Cx, T Cy){T ret = Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By);
    if(ret < 0) return ret = -ret;
    return ret;
}

const int N = 200005; 
const int M = 200005;
const ULL hs = 3797;





struct complx{
    double real, img;

    inline complx(){
        real = img = 0.0;
    }

    inline complx(double x){
        real = x, img = 0.0;
    }

    inline complx(double x, double y){
        real = x, img = y;
    }

    inline void operator += (complx &other){
        real += other.real, img += other.img;
    }

    inline void operator -= (complx &other){
        real -= other.real, img -= other.img;
    }

    inline complx operator + (complx &other){
        return complx(real + other.real, img + other.img);
    }

    inline complx operator - (complx &other){
        return complx(real - other.real, img - other.img);
    }

    inline complx operator * (complx& other){
        return complx((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
    }
};

complx id0[MAX >> 1], A[MAX], B[MAX];

void FFT(complx *ar, int n, int inv){
    int i, j, l, len, len2;
    const double p = 4.0 * inv * acos(0.0);

    for (i = 1, j = 0; i < n; i++){
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }

    for (len = 2; len <= n; len <<= 1){
        len2 = len >> 1;
        double theta = p / len;
        complx mul(cos(theta), sin(theta));

        id0[0] = complx(1, 0);
        for (i = 1; i < len2; i++) id0[i] = (id0[i - 1] * mul);

        for (i = 0; i < n; i += len){
            complx t, *pu = ar + i, *pv = ar + i + len2, *pend = ar + i + len2, *pw = id0;
            for (; pu != pend; pu++, pv++, pw++){
                t = (*pv) * (*pw);
                *pv = *pu - t;
                *pu += t;
            }
        }
    }

    if (inv == -1){
        double tmp = 1.0 / n;
        for (i = 0; i < n; i++) ar[i].real *= tmp;
    }
}

const int base = 7000;
int box[150][N], len[222];
char a[N + 100], b[N + 100];
int na, nb, bit[(1 << 16) + 10];
int Bta[N], Btb[N];

void print(int x) {
    string s;
    Rep(i, 64) {
        s += (x & 1) + '0';
        x /= 2;
    } reverse(all(s));
    cout << s << '\n';
}
void precal() {
    for(int i = 0; i < (1 << 16) + 1; i++) bit[i] = __builtin_popcount(i);
    for(int l = 0; l < na; l += 32) for(int i = 0, bi = l / 32; i < 32; i++) if(a[i + l] == '1') Bta[bi] |= (1ULL << i);
    for(int l = 0; l < nb; l++) for(int i = 0; i < 32; i++) if(b[i + l] == '1') Btb[l] |= (1ULL << i);
}

int bitMatch(int x, int y) {
    int ret = 0;
    unsigned short tx, ty;
    Rep(i, 2) {
        tx = x; ty = y;
        ret += bit[tx ^ ty];
        x >>= 16;
        y >>= 16;
    }
    return ret;
}

int ans_me(int ai, int bi, int l) {
    int ret = 0;
    int x = ai;
    int y = (ai + l - 1);
    int ix = x / 32;
    int iy = y / 32;
    if(ix == iy) {
        Rep(i, l) ret += (a[ai + i] != b[bi + i]);
    }
    else {
        Rep(i, (ix + 1) * 32 - x) ret += (a[ai + i] != b[bi + i]);
        Rep(i, y - iy * 32 + 1) ret += (a[ (ai + l - 1) - i ] != b[ (bi + l - 1) - i ]);
        For(i, ix + 1, iy) ret += bitMatch(Bta[i] , Btb[ bi + (i * 32 - ai) ] );
    }
    return ret;
}

int main()
{
    na = scans(a);
    nb = scans(b);

    precal();

    int n = 1, sz = 0; while(n < nb + base) n = n << 1;
    Rep(i, nb) B[n - 1 - i] = complx(b[i] == '1' ? 1 : -1);
    FFT(B, n, 1);
    Rep(bi, N) {
        if(na < base || nb < base) break;
        int ix = bi * base;
        int iy = min(na, (bi + 1) * base) - 1;
        sz = bi;
        if(ix >= na) break;
        Rep(i, n) A[i] = complx();
        int m = (iy - ix + 1);
        len[bi] = nb - m + 1;
        Rep(i, m) A[i] = complx(a[ix + i] == '1' ? 1 : -1);
        FFT(A, n, 1);
        Rep(i, n) A[i] = A[i] * B[i];
        FFT(A, n, -1);
        Rep(i, nb - m + 1) box[bi][i] = (m - round(A[n - 1 - i].real)) / 2;
    }

    int qr; scani(qr);
    while(qr--) {
        int ai, bi, l; scani3(ai, bi, l);
        int x = ai;
        int y = (ai + l - 1);
        int ix = x / base;
        int iy = y / base;
        int res = 0;
        if(ix == iy || l < base) {
            res += ans_me(ai, bi, l);
        }
        else {
            int m = y - iy * base + 1;
            res += ans_me(ai, bi, (ix + 1) * base - x);
            res += ans_me(ai + l - m, bi + l - m, m);
            For(i, ix + 1, iy) res += box[i][ bi + (i * base - ai) ];
        }
        write(res);
    }
    return 0;
}