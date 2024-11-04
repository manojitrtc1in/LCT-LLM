








































using namespace std;


template <typename T> inline void _debug(const char* names, T && t) { cerr << names << " = " << t << endl; cerr.flush(); }
template <typename T1, typename ... T> inline void _debug(const char* names, T1 && t1, T && ... t) { const char* comma = __builtin_strchr(names, ','); cerr.write(names, comma - names) << " = " << t1 << ", "; cerr.flush(); _debug(comma + 1, t ...); }






extern "C" {
inline int id10(int* a, int x) { int sum = 0; for (; x; x -= x & -x) sum += a[x]; return sum; }
__attribute__((always_inline)) inline int id7(int* a, int l, int r) { return id10(a, r - 1) - id10(a, l - 1); }
inline void id2(int* a, int len, int x, int val) { for (; x <= len; x += x & -x) a[x] += val; }
__attribute__((always_inline)) inline int id15(int* a, int x) { return id7(a, x, x + 1); }
__attribute__((always_inline)) inline void id5(int* a, int len, int x, int val) { id2(a, len, x, val - id15(a, x)); }
void id11(int* a, int len) { int *b = new int [len + 1]; for (int i = 1; i <= len; i ++) id5(b, len, i, a[i]); for (int i = 1; i <= len; ++ i) a[i] = b[i]; delete b; }
}


extern "C" {
__attribute__((always_inline)) inline void id19(int n, long long fact[], long long mod) { fact[0] = 1; for (int i = 1; i <= n; i ++) fact[i] = fact[i - 1] * i % mod; }
bool isprime(const long long & x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3; for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return false; return true; }
long long modpower(long long x, long long p, long long mod) { long long ans = 1; while (p) { if (p & 1) ans = ans * x % mod; x = x * x % mod; p >>= 1; } return ans; }
__attribute__((always_inline)) inline long long inverse(long long x, long long mod) { return modpower(x, mod - 2, mod); }
__attribute__((always_inline)) inline long long combination(long long N, long long K, long long fact[], long long mod) { return fact[N] * inverse(fact[K], mod) % mod * inverse(fact[N - K], mod) % mod; }
__attribute__((always_inline)) inline long long id4(long long N, long long K, long long fact[], long long invf[], long long mod) { return fact[N] * invf[K] % mod * invf[N - K] % mod;}
}
vector <int> id18(int n, bool isp[]) { vector <int> ans; memset(isp, true, sizeof isp); isp[0] = isp[1] = false; for (int i = 2; i <= n; i ++) if (isp[i]) { ans.push_back(i); for (int j = i << 1; j <= n; j += i) isp[j] = false; } return ans; }
template <typename Tp> inline Tp power(Tp x, long long p) { Tp ans = 1; while (p) { if (p & 1) ans *= x; x *= x; p >>= 1; } return ans; }
template <typename Tp> inline Tp gcd(Tp A, Tp B) { while (B) { Tp C = A % B; A = B; B = C; } return A; }
template <typename Tp> inline Tp lcm(Tp A, Tp B) { if (A == 0 || B == 0) return A + B; return A / gcd(A, B) * B; }
template <typename T> T id6(T a, T b, T & x, T & y) { if (!b) { x = y = 1; return a; } T nx, ny; T val = id6(b, a % b, y, x); y -= x * (a / b); return val; }
template <typename T> void mod_function(T a, T b, T res, T & x, T & y) { T val = id6(a, b, x, y); x = x * res / val; y = y * res / val; }
namespace ISPRIME {
template < typename T > T mod_add ( const T & a , const T & b , const T & m ) { if ( a < m - b ) return a + b ; return a - ( m - b ) ; } template 
< typename T > T mod_sub ( const T & a , const T & b , const T & m ) { if ( a < b ) return a + ( m - b ) ; return a - b ; } template < typename T >
T mod_mul ( T a , T b , const T & m ) { if ( b > a ) swap( a , b ) ; T r { 0 } ; while ( b > 0 ) { if ( b % 2 == 1 ) r = mod_add( r , a , m ) ; a 
= mod_add ( a , a , m ) ; b >>= 1 ; } return r ; } template < typename T1 , typename T2 > T1 mod_pow ( T1 a , T2 n , const T1 & m ) { if ( m == 1 )
return 0 ; T1 r { 1 } ; while ( n > 0 ) { if ( n % 2 == 1 ) r = mod_mul ( r , a , m ) ; a = mod_mul ( a , a , m ) ; n >>= 1 ; } return r ; }
void id20 ( uint64_t a , uint64_t b , uint64_t & lo , uint64_t & hi ) {

uint64_t a_hi = a >> 32 ; uint64_t a_lo = a & 0xffffffffULL ; uint64_t b_hi = b >> 32 ; uint64_t b_lo = b & 0xffffffffULL ; uint64_t id16 = 
a_hi * b_hi ; uint64_t id3 = a_hi * b_lo ; uint64_t id9 = a_lo * b_hi ; uint64_t id14 = a_lo * b_lo ; uint64_t middle = id3 
+ id9 ; hi = id16 + ( middle >> 32 ) ; lo = id14 + ( middle << 32 ) ; if ( middle < id3 ) hi += 1ULL << 32 ; hi += lo < 
id14 ;

asm ( "mulq %3" : "=a" ( lo ) , "=d" ( hi ) : "a" ( a ) , "rm" ( b ) ) ;

} uint64_t id0 ( uint64_t a , uint64_t b , uint64_t m ) { if ( a >= m ) a %= m ; if ( b >= m ) b %= m ;

if ( ( a | b ) < 1ULL << 32 ) return ( a * b ) % m ; uint64_t r = mod_mul ( a , b , m ) ;

uint64_t r , u ; asm ( "mulq %3\n\tdivq %4" : "=a" ( u ) , "=&d" ( r ) : "a" ( a ) , "rm" ( b ) , "rm" ( m ) : "cc" ) ;

return r ; } bool id1 ( uint32_t n , uint32_t a ) { uint32_t d = n - 1 ; int s = __builtin_ctz ( d ) ; d >>= s ; uint64_t b = a, r = 1 ; while 
( d > 0 ) { if ( d & 1 ) r = ( r * b ) % n ; b = ( b * b ) % n ; d >>= 1 ; } if ( r == 1 ) return true ; b = n - 1 ; for ( int i = 1 ; i < s ; ++ 
i ) { if ( r == b ) return true ; r = ( r * r ) % n ; } return r == b ; } bool id1 ( uint64_t n, const std :: vector < uint64_t > & v ) { auto 
id17 = [ & ] ( ) -> uint64_t { if ( n <= ( 1ULL << 63 ) ) { uint64_t res = ( ( 1ULL << 63 ) % n ) << 1 ; return res < n ? res : res - n ;
} return 0ULL - n ; } ; auto mont_inv = [ & ] ( ) -> uint64_t { uint64_t j , s = 1 ; uint32_t i, t ; static const uint8_t masks [ 128 ] = { 255, 
85, 51, 73, 199, 93, 59, 17, 15, 229, 195, 89, 215, 237, 203, 33, 31, 117, 83, 105, 231, 125, 91, 49, 47, 5, 227, 121, 247, 13, 235, 65, 63, 149, 
115, 137, 7, 157, 123, 81, 79, 37, 3, 153, 23, 45, 11, 97, 95, 181, 147, 169, 39, 189, 155, 113, 111, 69, 35, 185, 55, 77, 43, 129, 127, 213, 179, 
201, 71, 221, 187, 145, 143, 101, 67, 217, 87, 109, 75, 161, 159, 245, 211, 233, 103, 253, 219, 177, 175, 133, 99, 249, 119, 141, 107, 193, 191, 
21, 243, 9, 135, 29, 251, 209, 207, 165, 131, 25, 151, 173, 139, 225, 223, 53, 19, 41, 167, 61, 27, 241, 239, 197, 163, 57, 183, 205, 171, 1 } ;
uint8_t mask = masks [ ( n >> 1 ) & 127 ] ; i = ( uint32_t ) ( ( mask * ( s & 255 ) ) & 255 ) ; j = i ; s = ( s + n * i ) >> 8 ; i = ( uint32_t ) 
( ( mask * ( s & 255 ) ) & 255 ) ; j |= ( uint64_t ) i << 8 ; s = ( s + n * i ) >> 8 ; i = ( uint32_t ) ( ( mask * ( s & 255 ) ) & 255 ) ; j |= (
uint64_t ) i << 16 ; s = ( s + n * i ) >> 8 ; i = ( uint32_t ) ( ( mask * ( s & 255 ) ) & 255 ) ; j |= ( uint64_t ) i << 24 ; t = ( uint32_t ) ( (
s + n * i ) >> 8 ) ; i = ( mask * ( t & 255 ) ) & 255 ; j |= ( uint64_t ) i << 32 ; t = (uint32_t) ( ( t + n * i ) >> 8 ) ; i = ( mask * ( t & 
255 ) ) & 255 ; j |= ( uint64_t ) i << 40 ; t = ( uint32_t ) ( ( t + n * i ) >> 8 ) ; i = ( mask * ( t & 255 ) ) & 255 ; j |= ( uint64_t ) i << 48
; t = ( uint32_t ) ( ( t + n * i ) >> 8 ) ; i = ( mask * ( t & 255 ) ) & 255 ; j |= ( uint64_t ) i << 56 ; return j ; } ; auto id8 = [=]
( uint64_t a , uint64_t b , uint64_t npi ) -> uint64_t { uint64_t ab_lo , ab_hi , mn_lo , mn_hi ; uint64_t m , u ; int carry ; id20 ( a , b , 
ab_lo , ab_hi ) ; m = ab_lo * npi ; id20 ( m , n , mn_lo , mn_hi) ; carry = ab_lo + mn_lo < ab_lo ? 1 : 0 ; u = ab_hi + mn_hi + carry ; return 
( u < ab_hi || u >= n ) ? u - n : u ; } ; if ( n % 2 == 0 ) return n == 2 ; if ( n % 3 == 0 ) return n == 3 ; if ( n % 5 == 0 ) return n == 5 ; if 
( n % 7 == 0 ) return n == 7 ; if ( n < 121 ) return n > 1 ; uint64_t d = n - 1; int s = __builtin_ctzll ( d ) ; d >>= s ; uint64_t npi =mont_inv 
( ) ; uint64_t r = id17 ( ) ; uint64_t nr = n - r ; for ( uint32_t i = 0 ; i < v. size ( ) ; ++ i ) { uint64_t a = id0 ( v[i] , r
, n ) ; uint64_t b = r, k = d ; if ( a == 0 ) continue ; while ( k > 0 ) { if ( k & 1 ) b = id8 ( b , a , npi ) ; a = id8 ( a, a
, npi ) ; k >>= 1 ; } if ( b == r || b == nr ) continue ; int j ; for ( j = 1 ; j < s ; ++ j ) { b = id8 ( b , b , npi ) ; if ( b == r )
return false ; if ( b == nr ) break ; } if ( j == s ) return false ; } return true ; }
bool isprime ( uint32_t n ) { static const uint32_t bases [ ] = { 0x3ce7, 0x07e2, 0x00a6, 0x1d05, 0x1f80, 0x3ead, 0x2907, 0x112f, 0x079d, 0x050f, 
0x0ad8, 0x0e24, 0x0230, 0x0c38, 0x145c, 0x0a61, 0x08fc, 0x07e5, 0x122c, 0x05bf, 0x2478, 0x0fb2, 0x095e, 0x4fee, 0x2825, 0x1f5c, 0x08a5, 0x184b, 
0x026c, 0x0eb3, 0x12f4, 0x1394, 0x0c71, 0x0535, 0x1853, 0x14b2, 0x0432, 0x0957, 0x13f9, 0x1b95, 0x0323, 0x04f5, 0x0f23, 0x01a6, 0x02ef, 0x0244, 
0x1279, 0x27ff, 0x02ea, 0x0b87, 0x022c, 0x089e, 0x0ec2, 0x01e1, 0x05f2, 0x0d94, 0x01e1, 0x09b7, 0x0cc2, 0x1601, 0x01e8, 0x0d2d, 0x1929, 0x0d10, 
0x0011, 0x3b01, 0x05d2, 0x103a, 0x07f4, 0x075a, 0x0715, 0x01d3, 0x0ceb, 0x36da, 0x18e3, 0x0292, 0x03ed, 0x0387, 0x02e1, 0x075f, 0x1d17, 0x0760, 
0x0b20, 0x06f8, 0x1d87, 0x0d48, 0x03b7, 0x3691, 0x10d0, 0x00b1, 0x0029, 0x4da3, 0x0c26, 0x33a5, 0x2216, 0x023b, 0x1b83, 0x1b1f, 0x04af, 0x0160, 
0x1923, 0x00a5, 0x0491, 0x0cf3, 0x03d2, 0x00e9, 0x0bbb, 0x0a02, 0x0bb2, 0x295b, 0x272e, 0x0949, 0x076e, 0x14ea, 0x115f, 0x0613, 0x0107, 0x6993, 
0x08eb, 0x0131, 0x029d, 0x0778, 0x0259, 0x182a, 0x01ad, 0x078a, 0x3a19, 0x06f8, 0x067d, 0x020c, 0x0df9, 0x00ec, 0x0938, 0x1802, 0x0b22, 0xd955, 
0x06d9, 0x1052, 0x2112, 0x00de, 0x0a13, 0x0ab7, 0x07ef, 0x08b2, 0x08e4, 0x0176, 0x0854, 0x032d, 0x5cec, 0x064a, 0x1146, 0x1427, 0x06bd, 0x0e0d, 
0x0d26, 0x3800, 0x0243, 0x00a5, 0x055f, 0x2722, 0x3148, 0x2658, 0x055b, 0x0218, 0x074b, 0x2a70, 0x0359, 0x089e, 0x169c, 0x01b2, 0x1f95, 0x44d2, 
0x02d7, 0x0e37, 0x063b, 0x1350, 0x0851, 0x07ed, 0x2003, 0x2098, 0x1858, 0x23df, 0x1fbe, 0x074e, 0x0ce0, 0x1d1f, 0x22f3, 0x61b9, 0x021d, 0x4aab, 
0x0170, 0x0236, 0x162a, 0x019b, 0x020a, 0x0403, 0x2017, 0x0802, 0x1990, 0x2741, 0x0266, 0x0306, 0x091d, 0x0bbf, 0x8981, 0x1262, 0x0480, 0x06f9, 
0x0404, 0x0604, 0x0e9f, 0x01ed, 0x117a, 0x09d9, 0x68dd, 0x20a2, 0x0360, 0x49e3, 0x1559, 0x098f, 0x002a, 0x119f, 0x067c, 0x00a6, 0x04e1, 0x1873, 
0x09f9, 0x0130, 0x0110, 0x1c76, 0x0049, 0x199a, 0x0383, 0x0b00, 0x144d, 0x3412, 0x1b8e, 0x0b02, 0x0c7f, 0x032b, 0x039a, 0x015e, 0x1d5a, 0x1164, 
0x0d79, 0x0a67, 0x1264, 0x01a2, 0x0655, 0x0493, 0x0d8f, 0x0058, 0x2c51, 0x019c, 0x0617, 0x00c2 } ; if ( n % 2 == 0 ) return n == 2 ; if ( n % 3 == 
0 ) return n == 3 ; if ( n % 5 == 0 ) return n == 5 ; if ( n % 7 == 0 ) return n == 7 ; if ( n < 121) return n > 1 ; uint64_t h = n ; h = ( ( h >> 
16 ) ^ h ) * 0x45d9f3b ; h = ( ( h >> 16 ) ^ h ) * 0x45d9f3b ; h = ( ( h >> 16 ) ^ h ) & 0xff ; return id1 ( n , bases [ h ] ) ; } bool isprime 
( int32_t n ) { return isprime ( static_cast < uint32_t > ( n ) ) ; } bool isprime ( uint64_t n ) { static const std :: vector < uint64_t > bases 
[ ] = { { 4230279247111683200ULL, 14694767155120705706ULL , 16641139526367750375ULL } , { 2ULL , 141889084524735ULL , 1199124725622454117ULL , 
11096072698276303650ULL } , { 2ULL , 4130806001517ULL , 149795463772692060ULL , 186635894390467037ULL , 3967304179347715805ULL } , { 2ULL , 
123635709730000ULL , 9233062284813009ULL , 43835965440333360ULL , 761179012939631437ULL , 1263739024124850375ULL } , { 2ULL , 325ULL , 9375ULL , 
28178ULL , 450775ULL , 9780504ULL , 1795265022ULL } } ; if ( n < 7999252175582851ULL ) { if ( n < 350269456337ULL ) { if ( n < 4294967296ULL ) 
{ return isprime ( static_cast < uint32_t > ( n ) ) ; } else { return id1 ( n , bases [ 0 ] ) ; } } else { if ( n < 55245642489451ULL ) { return 
id1 ( n , bases [ 1 ] ) ; } else { return id1 ( n , bases [ 2 ] ) ; } } } else { if ( n < 585226005592931977ULL ) { return id1 ( n , bases 
[ 3 ] ) ; } else { return id1 ( n , bases [ 4 ] ) ; } } } bool isprime ( int64_t n ) { return isprime ( static_cast < uint64_t > ( n ) ) ; } }



template <typename T> vector <T> split(string s, string ch = " ") { s += ch; T x; vector <T> res; string cnt = ""; for (int i = 0; i < s.size(); ++ i) { if (ch.find(s[i]) == ch.npos) cnt += s[i]; else { stringstream ss(cnt); ss >> x; res.push_back(x); cnt = ""; } } return res; }

extern "C" {
__attribute__((always_inline)) inline unsigned long long id12() { unsigned long long ret = 0; asm volatile("id12" : "=A" (ret) : :); return ret; }
__attribute__((always_inline)) inline void id21() { fflush(stdout); eprintf("\n\n\nCost time: %d ms\n",int(clock() * 1000 / CLOCKS_PER_SEC)); }
__attribute__((always_inline)) inline void id13(int count) { fflush(stdout); eprintf("\n\narray megebytes: %.3lf MB\n\n", count*1.0/1024*1.0/1024); }
}

using ll = long long; using ld = long double; using ull = unsigned long long; using pii = pair <int, int>;
template <typename T> using min_queue = priority_queue <T, vector <T>, greater <T> >;
template <typename T> using max_queue = priority_queue <T>;
template <typename T> void chmax(T &a, T b) { if (b > a) a = b; }
template <typename T> void chmin(T &a, T b) { if (b < a) a = b; }

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3f;
const int mod1 = 1000000007, mod2 = 998244353;
const int randnumber = 19260817;
const long double PI = 3.141592653589793238462643383279, EPS = 1e-9;



bool solve(const int & test_number);
int main(int argc,char *argv[])
{

	freopen(TASK".in","r",stdin);
	freopen(TASK".out","w",stdout);

	atexit(id21);
	id12();
	srand(time(0));
	srand(rand() | (rand() << 15));
	
	scanf("%d", argc);
	
	for (int _Test = 1; _Test <= argc; ++ _Test) solve(_Test);
	return 0;
}

const int Maxn=1000005;
int go[Maxn][2],a[Maxn],b[Maxn],n,i,j,p,sz[Maxn],tsz;
ll k,x[Maxn];

bool solve(const int & test_number)
{
	scanf("%d %lld",&n,&k);
	for (int i=2;i<=n;i++) scanf("%d %lld",&p,&x[i]),x[i]^=x[p];
	for (int i=1;i<=n;i++) a[i]=b[i]=1;
	ll ans=0;
	for (int j=61;~j;j--)
	{
		for (int i=1;i<=tsz;i++) go[i][0]=go[i][1]=sz[i]=0;
		tsz=0;
		for (int i=1;i<=n;i++)
		{
			int g=(x[i]>>j)&1;
			if (!go[a[i]][g]) go[a[i]][g]=++tsz;
			sz[a[i]=go[a[i]][g]]++;
		}
		ll sum=0;
		for (int i=1;i<=n;i++) sum+=sz[go[b[i]][(x[i]>>j)&1]];
		if (sum<k)
		{
			ans+=(ll)1<<j;k-=sum;
			for (int i=1;i<=n;i++) b[i]=go[b[i]][((x[i]>>j)&1)^1];
		}
		else for (int i=1;i<=n;i++) b[i]=go[b[i]][(x[i]>>j)&1];
	}
	printf("%lld\n",ans);
	return false;
}


