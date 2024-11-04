

































using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;




















const double EPS = 1e-9;
const double PI = acos ( -1. );
const int mod = ( int ) 1e9 + 7; 

long long llinf = id1;
int inf = INT_MAX;


template<typename T1, typename T2> auto max ( T1 a, T2 b ) { auto max = a > b ? a : b; return max; }
template<typename T1, typename T2> auto min ( T1 a, T2 b ) { auto min = a < b ? a : b; return min; }

template<typename T1, typename T2> void updmax ( T1 &a, T2 b ) { a = a > b ? a : b; }
template<typename T1, typename T2> void updmin ( T1 &a, T2 b ) { a = a < b ? a : b; }

template<class T, class C = null_type> using Tree = tree<T, C, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename A, typename B, typename C> struct triple{ A first; B second; C third; };
template<typename A, typename B, typename C, typename D> struct kvadruple{ A first; B second; C third; D fouth; };


namespace io{

	template<typename A, typename B> ostream& operator << ( ostream &os, pair<A, B> &p ) { return os << p.first << " " << p.second; }
	template<typename A, typename B, typename C> ostream& operator << ( ostream &os, triple<A, B, C> &p ) { return os << p.first << " " << p.second << " " << p.third; }
	template<typename A, typename B, typename C, typename D> ostream& operator << ( ostream &os, kvadruple<A, B, C, D> &p ) { return os << p.first << " " << p.second << " " << p.third << " " << p.fouth; }
	template<typename A> ostream& operator << ( ostream &os, vector<A> &v ) { for( A p : v ) cout << p << " "; return os; }
	template<typename A, typename B> ostream& operator << ( ostream &os, vector<pair<A, B>> &v ) { for( auto p : v ) cout << p << endl; return os; }
	template<typename A, typename B> ostream& operator << ( ostream &os, map<A, B> &mp ) { for( auto it : mp ) os << it.first << " " << it.second << endl; return os; }
	template<typename A> ostream& operator << ( ostream &os, set<A> &st ) { for( A p : st ) cout << p << " "; return os; }

	template<typename A, typename B> istream& operator >> ( istream &is, pair<A, B> &p ) { return is >> p.first >> p.second; }
	template<typename A, typename B, typename C> istream& operator >> ( istream &is, triple<A, B, C> &p ) { return is >> p.first >> p.second >> p.third; }
	template<typename A, typename B, typename C, typename D> istream& operator >> ( istream &is, kvadruple<A, B, C, D> &p ) { return is >> p.first >> p.second >> p.third >> p.fouth; }
	template<typename A> istream& operator >> ( istream &is, vector<A> &v ) { for( A &p : v ) is >> p; return is; }
	template<typename A, typename B> istream& operator >> ( istream &is, vector<pair<A, B>> &v ) { for( auto &p : v ) is >> p.first >> p.second; return is; }

	template<typename A, typename B> inline void output( pair<A, B> &p ) { cout << "pair = {" << p.first << ", " << p.second << "}" << endl; }
	template<typename A, typename B, typename C> inline void output( triple<A, B, C> &t ) { cout << "triple = {" << t.first << ", " << t.second << ", " << t.third << "}" << endl; }
	template<typename A, typename B, typename C, typename D> inline void output( kvadruple<A, B, C, D> &k ) { cout << "kvadruple = {" << k.first << ", " << k.second << ", " << k.third << ", " << "}" << endl; }
	template<typename A, typename B> inline void output( map<A, B> &mp ){ cout << "map:" << endl; for( auto it: mp ) cout << "{" << it.first << ", " << it.second << "}" << endl; }
	template<typename A> inline void output( vector<A> &v ){ cout << "vector = {"; for( int i = 0; i < v.size(); i++ ){ cout << v[i]; if( i < v.size() - 1 ) cout << ", "; } cout << "}"; cout << endl; }
	template<typename A, typename B> inline void output( vector<pair<A, B>> &v ) { cout << "vector: " << endl; for( auto p : v ) cout << "{" << p.first << ", " << p.second << "}" << endl; }
	template<typename A> inline void output( set<A> &st ){ cout << "set = {"; for( A p : st ){ cout << p; if( p != *st.rbegin() ) cout << ", "; } cout << "}"; cout << endl; }

	int read(){ char c; int d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x;}

}

using namespace io;


namespace bit{

	inline void set( int &x, int i ){ x |= ( 1 << i ); }
	inline void reset( int &x, int i ){ x ^= ( 1 << i ); }
	inline bool check( int x, int i ){ return ( ( 1 << i ) & x ); }
	inline bool is_pow( int x ){ return x && !( x & ( x - 1 ) ); }
	inline short count( int x ){ return __builtin_popcount( x ); }
	inline int sub( int a, int b ){ return a & ( ~b ); }
	inline int low_bit( int x ){ return x & ( x - 1 ); }
	inline int high_bit( int x ){ x |= x >> 1; x |= x >> 2; x |= x >> 4; x |= x >> 8; x |= x >> 16; x |= x >> 32; return x - ( x >> 1 );  }

}

template<typename T> struct modular {

	static const T mod = ( int ) 1e9 + 7;

	T x = 0;
	modular(){}
	modular( int x ){ this -> x = norm( x ); }

	T norm( int a ) { while( a >= mod ) a -= mod; while( a < 0 ) a += mod; return a; }
	modular norm( modular m ){ return m.x = norm( m.x ); }

	modular operator - () { return modular( -x ); }
	modular operator ++ () { return modular( ++x ); }

	modular & operator += ( const modular &m ){ this -> x = norm( this -> x + m.x ); return *this; }
	modular & operator -= ( const modular &m ){ this -> x = norm( this -> x - m.x ); return *this; }
	modular & operator *= ( const modular &m ){ this -> x = ( 1ll * this -> x * m.x ) % mod; return *this; }
	modular & operator /= ( const modular &m ){ return *this *= inv( m ); }

	modular & operator += ( const int &x ){ this -> x = norm( this -> x + x ); return *this; }
	modular & operator -= ( const int &x ){ this -> x = norm( this -> x - x ); return *this; }
	modular & operator *= ( const int &x ){ this -> x = ( 1ll * this -> x * x) % mod; return *this; }
	modular & operator /= ( const int &x ){ return *this *= inv( modular( x ) ); }

	friend bool operator < ( modular &a, modular &b ) { return a.x < b.x; }
	friend bool operator == ( modular &a, modular &b ) { return a.x == b.x; }
	friend bool operator != ( modular &a, modular &b ) { return a.x != b.x; }

	friend modular operator + ( modular a, modular b ){ return a += b; }
	friend modular operator - ( modular a, modular b ){ return a -= b; }
	friend modular operator * ( modular a, modular b ){ return a *= b; }
	friend modular operator / ( modular a, modular b ){ return a /= b; }

	friend modular inv( modular m ){ return pow( m, mod - 2 ); }
	friend modular pow( modular m, long long n ){ modular res( 1 ); while( n ){ if( n & 1 ) res *= m; m *= m; n >>= 1; } return res; }
	friend modular mul( modular m, long long n ){ modular res; while( n ){ if( n & 1 ) res += m; m += m; n >>= 1; } return res; }

	friend ostream & operator << ( ostream &os, modular m ){ return os << m.x; }
	friend istream & operator >> ( istream &is, modular m ){ return is >> m.x; }

};


namespace number {

	int mod = ( int ) 1e9 + 7;

	inline int norm( int a ) { while( a < 0 ) a += mod; while( a >= mod ) a -= mod; return a; }
	inline int add( int a, int b ) { return norm( a + b ); }
	inline int sub( int a, int b ) { return norm( a - b ); }
	inline int mul( int a, int b, int m = mod ) { return ( 1ll * a * b ) % m; }

	int pow_mod( int a, int n, int m = mod ) { int p = 1; while( n ) { if( n & 1 ) p = mul( p, a, m ); a = mul( a, a, m ); n >>= 1; } return p; }
	int mul_mod( int a, int n, int m = mod ) { int s = 0; while( n ) { if( n & 1 ) s = ( s + a ) % m; a = ( a + a ) % m; n >>= 1; } return s; }

	inline int inv( int a ) { return pow_mod( a, mod - 2 ); }
	inline int div_mod( int a, int b ) { return mul( a, inv( b ) ); }

	bool id0( long long m ) {
		random_device rd; mt19937 mt( rd( ) );
		uniform_int_distribution<int> dist( 0, llinf );
		int s = 0, d = m - 1;
		while( d % 2 == 0 ) s++, d /= 2;
		int a = 1 + dist( mt ) % ( m - 1 );
		int x = pow_mod( a, d, m );
		if( x == 1 ) return true;
		for( int r = 0; r < s; r++ ) { if( x == m - 1 ) return true; x = mul_mod( x, x, m ); }
		return false;
	}

	bool is_prime( long long n ) {
		if( n <= 4 ) return n == 2 || n == 3; if( n > 1e12 ) return id0( n );
		for( int i = 5; i * i <= n; i += 6 ) if( n % i == 0 || n % ( i + 2 ) == 0 ) return 0; return 1;
	}

	long long id3( long long n, int it = 50000 ) {
		random_device rd; mt19937 mt( rd( ) );
		uniform_int_distribution<int> dist( 0, llinf );
		long long b0 = dist( mt ) % n, b1 = b0, g;
		b1 = mul_mod( b1, b1, n );
		if( ++b1 == n ) b1 = 0;
		g = gcd( abs( b1 - b0 ), n );
		for( int count = 0; count < it && ( g == 1 || g == n ); count++ ) {
			b0 = mul_mod( b0, b0, n );
			if( ++b0 == n ) b0 = 0;
			b1 = mul_mod( b1, b1, n ); ++b1;
			b1 = mul_mod( b1, b1, n );
			if( ++b1 == n )	b1 = 0;
			g = gcd( abs( b1 - b0 ), n );
		}
		return g;
	}

	int id2( int a, int b, int & x, int & y ) {
		if( a == 0 ) { x = 0; y = 1; return b; }
		int x1, y1, d = id2( b % a, a, x1, y1 );
		x = y1 - ( b / a ) * x1; y = x1;
		return d;
	}
}


int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int Dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int Dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };


static const int MAXN = ( int ) 5e5 + 10;
static int a[MAXN], b[MAXN];


int n, m, k;
int res, ans[51][51], cnt;
string s, t;


void solution()
{
	cin >> n;
	ans[1][1] = 1;
	if( n <= 50 ) {
		int v[55][55] = { 0 };
		long long m, i, j, mx1 = 0, mx2 = 0, s = 0, id4 = 0, cnt1 = 0, cnt0 = 0;
		for( i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j )
				v[i][j] = -1;
		m = n;
		v[1][1] = v[1][2] = 1;
		v[n][n] = 0;
		for( i = 1; i <= n; ++i ) {
			for( j = 1; j <= n; ++j ) {
				if( ( i + j ) % 2 || v[i][j] != -1 )
					continue;
				if( i > 1 && j > 1 && v[i - 1][j - 1] != -1 ) {
					cout << "? " << i - 1 << ' ' << j - 1 << ' ' << i << ' ' << j << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 )
						v[i][j] = v[i - 1][j - 1];
					else
						v[i][j] = 1 - v[i - 1][j - 1];
				} else if( i > 2 && v[i - 2][j] != -1 ) {
					cout << "? " << i - 2 << ' ' << j << ' ' << i << ' ' << j << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 )
						v[i][j] = v[i - 2][j];
					else
						v[i][j] = 1 - v[i - 2][j];
				} else if( j > 2 && v[i][j - 2] != -1 ) {
					cout << "? " << i << ' ' << j - 2 << ' ' << i << ' ' << j << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 )
						v[i][j] = v[i][j - 2];
					else
						v[i][j] = 1 - v[i][j - 2];
				}
			}
		}
		for( i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j ) {
				if( v[i][j] != -1 )
					continue;
				if( i > 1 && j > 1 && v[i - 1][j - 1] != -1 ) {
					cout << "? " << i - 1 << ' ' << j - 1 << ' ' << i << ' ' << j << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 )
						v[i][j] = v[i - 1][j - 1];
					else
						v[i][j] = 1 - v[i - 1][j - 1];
				} else if( i > 2 && v[i - 2][j] != -1 ) {
					cout << "? " << i - 2 << ' ' << j << ' ' << i << ' ' << j << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 )
						v[i][j] = v[i - 2][j];
					else
						v[i][j] = 1 - v[i - 2][j];
				} else if( j > 2 && v[i][j - 2] != -1 ) {
					cout << "? " << i << ' ' << j - 2 << ' ' << i << ' ' << j << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 )
						v[i][j] = v[i][j - 2];
					else
						v[i][j] = 1 - v[i][j - 2];
				}
			}
		for( i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j ) {
				if( v[i][j] == -1 ) {
					cout << "? " << i << ' ' << j << ' ' << i << ' ' << j + 2 << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 )
						v[i][j] = v[i][j + 2];
					else
						v[i][j] = 1 - v[i][j + 2];
				}
			}
		int okt = -1;
		for( i = 1; i <= n - 3 && okt == -1; ++i )
			for( j = 1; j <= n - 3 && okt == -1; ++j ) {
				if( v[i][j] == v[i][j + 2] && v[i][j + 1] == v[i][j + 3] ) {
					cout << "? " << i << ' ' << j << ' ' << i << ' ' << j + 3 << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 ) {
						if( v[i][j] == v[i][j + 3] )
							okt = 0;
						else
							okt = 1;
					} else {
						if( v[i][j] == v[i][j + 3] )
							okt = 1;
						else
							okt = 0;
					}
				} else if( v[i][j] == v[i + 2][j] && v[i + 1][j] == v[i + 3][j] ) {
					cout << "? " << i << ' ' << j << ' ' << i + 3 << ' ' << j << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 ) {
						if( v[i][j] == v[i + 3][j] )
							okt = 0;
						else
							okt = 1;
					} else {
						if( v[i][j] == v[i + 3][j] )
							okt = 1;
						else
							okt = 0;
					}
				} else if( v[i][j] != v[i][j + 2] && v[i][j + 1] != v[i][j + 3] ) {
					cout << "? " << i << ' ' << j << ' ' << i << ' ' << j + 3 << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 ) {
						if( v[i][j] == v[i][j + 3] )
							okt = 0;
						else
							okt = 1;
					} else {
						if( v[i][j] == v[i][j + 3] )
							okt = 1;
						else
							okt = 0;
					}
				} else if( v[i][j] != v[i + 2][j] && v[i + 1][j] != v[i + 3][j] ) {
					cout << "? " << i << ' ' << j << ' ' << i + 3 << ' ' << j << '\n';
					cout.flush();
					int a;
					cin >> a;
					if( a == 1 ) {
						if( v[i][j] == v[i + 3][j] )
							okt = 0;
						else
							okt = 1;
					} else {
						if( v[i][j] == v[i + 3][j] )
							okt = 1;
						else
							okt = 0;
					}
				}
			}
		if( okt == -1 ) {
			for( i = 1; i < n; ++i )
				for( j = 1; j < n; ++j ) {
					if( j <= n - 2 && v[i][j] == v[i + 1][j + 2] &&
					    v[i + 1][j] == v[i + 1][j + 1] && v[i + 1][j + 1] == v[i][j + 1] &&
					    v[i][j + 1] == v[i][j + 2] || j <= n - 2 && v[i][j] != v[i + 1][j + 2] &&
									  v[i + 1][j] != v[i + 1][j + 1] &&
									  v[i + 1][j + 1] != v[i][j + 1] &&
									  v[i][j + 1] != v[i][j + 2] ) {
						cout << "? " << i << ' ' << j << ' ' << i + 1 << ' ' << j + 2 << '\n';
						cout.flush();
						int a;
						cin >> a;
						if( a == 1 ) {
							if( v[i][j] == v[i + 1][j + 2] )
								okt = 0;
							else
								okt = 1;
						} else {
							if( v[i][j] == v[i + 1][j + 2] )
								okt = 1;
							else
								okt = 0;
						}
					} else if( i <= n - 2 && v[i][j] == v[i + 2][j + 1] &&
						   v[i][j + 1] == v[i + 1][j + 1] && v[i + 1][j + 1] == v[i + 1][j] &&
						   v[i + 1][j] == v[i + 2][j] ||
						   i <= n - 2 && v[i][j] != v[i + 2][j + 1] &&
						   v[i][j + 1] != v[i + 1][j + 1] && v[i + 1][j + 1] != v[i + 1][j] &&
						   v[i + 1][j] != v[i + 2][j] ) {
						cout << "? " << i << ' ' << j << ' ' << i + 1 << ' ' << j + 2 << '\n';
						cout.flush();
						int a;
						cin >> a;
						if( a == 1 ) {
							if( v[i][j] == v[i + 2][j + 1] )
								okt = 0;
							else
								okt = 1;
						} else {
							if( v[i][j] == v[i + 2][j + 1] )
								okt = 1;
							else
								okt = 0;
						}
					}
				}
		}
		cout << "!\n";
		for( i = 1; i <= n; ++i ) {
			for( j = 1; j <= n; ++j ) {
				if( ( i + j ) % 2 == 1 )
					v[i][j] = ( v[i][j] + okt ) % 2;
				cout << v[i][j];
			}
			cout << '\n';
		}
		cout.flush();
		return;
	}
	cout << "? 1 1 1 3 " << endl;
	int x, y;
	cin >> x;
	ans[1][3] = x;
	cout << "? 1 1 1 4" << endl;
	cin >> x;
	cout << "? 1 2 1 4" << endl;
	cin >> y;

	int id = 3;
	if( x ){
		ans[1][4] = 1;
		ans[1][2] = ans[1][3];
	} else {
		if( y )
			ans[1][4] = ans[1][2] = 1 - ans[1][3];
		else{
			id = 4;
			cout << "? 1 1 1 5" << endl;
			cin >> x;
			cout << "? 1 3 1 5" << endl;
			cin >> y;
			if( x + y == 0 ){
				ans[1][2] = 0;
				ans[1][4] = 1;
				ans[1][5]= 0;
			} else if( x == 1 && y == 0 ){
				ans[1][2] = ans[1][4] = ans[1][5] = 1;
			} else if( x == 0 && y == 1 ){
				ans[1][5] = 0;
				ans[1][2] = ans[1][4] = 1;
			} else {
				ans[1][2] = 0;
				ans[1][4] = 1;
				ans[1][5] = 1;
			}
		}
	}
	for( int i = id; i <= n - 2; i++ ){
		cout << "? " << 1 << " " << id << " " << 1 << " " << id + 2 << endl;
		int x;
		cin >> x;
		if( x )
			ans[1][id + 2] = ans[1][id];
		else
			ans[1][id + 2] = 1 - ans[1][id];
	}


	cout << "? 1 1 3 1 " << endl;
	cin >> x;
	ans[3][1] = x;
	cout << "? 1 1 4 1" << endl;
	cin >> x;
	cout << "? 2 1 4 1" << endl;
	cin >> y;
	id = 3;
	if( x ){
		ans[4][1] = 1;
		ans[2][1] = ans[3][1];
	} else {
		if( y )
			ans[4][1] = ans[2][1] = 1 - ans[3][1];
		else{
			id = 4;
			cout << "? 1 1 5 1" << endl;
			cin >> x;
			cout << "? 3 1 5 1" << endl;
			cin >> y;
			if( x + y == 0 ){
				ans[2][1] = 0;
				ans[4][1] = 1;
				ans[5][1]= 0;
			} else if( x == 1 && y == 0 ){
				ans[2][1] = ans[4][1] = ans[5][1] = 1;
			} else if( x == 0 && y == 1 ){
				ans[5][1] = 0;
				ans[2][1] = ans[4][1] = 1;
			} else {
				ans[2][1] = 0;
				ans[4][1] = 1;
				ans[5][1] = 1;
			}
		}
	}
	for( int i = id; i <= n - 2; i++ ){
		cout << "? " << id << " " << 1 << " " << id + 2 << " " << 1 << endl;
		int x;
		cin >> x;
		if( x )
			ans[id + 2][1] = ans[id][1];
		else
			ans[id + 2][1] = 1 - ans[id][1];
	}
	for( int i = 2; i <= n; i++ ){
		cout << "? " << i << " " << 1 << " " << i << " " << 3 << endl;
		int x, y;
		cin >> x;
		ans[i][3] = x;
		cout << "? " << i << " " << 1 << " " << i << " " << 4 << endl;
		cin >> x;
		cout << "? " << i << " " << 2 << " " << i << " " << 4 << endl;
		cin >> y;

		int id = 3;
		if( x ){
			ans[i][4] = 1;
			ans[i][2] = ans[i][3];
		} else {
			if( y )
				ans[i][4] = ans[i][2] = 1 - ans[i][3];
			else{
				id = 4;
				cout << "? " << i << " " << 1 << " " << i << " " << 5 << endl;
				cin >> x;
				cout << "? " << i << " " << 3 << " " << i << " " << 5 << endl;
				cin >> y;
				if( x + y == 0 ){
					ans[i][2] = 0;
					ans[i][4] = 1;
					ans[i][5]= 0;
				} else if( x == 1 && y == 0 ){
					ans[i][2] = ans[i][4] = ans[i][5] = 1;
				} else if( x == 0 && y == 1 ){
					ans[i][5] = 0;
					ans[i][2] = ans[i][4] = 1;
				} else {
					ans[i][2] = 0;
					ans[i][4] = 1;
					ans[i][5] = 1;
				}
			}
		}
		int d = ( i == n );
		for( int i = id; i <= n - 2 - d; i++ ){
			cout << "? " << i << " " << id << " " << i << " " << id + 2 << endl;
			int x;
			cin >> x;
			if( x )
				ans[i][id + 2] = ans[i][id];
			else
				ans[i][id + 2] = 1 - ans[i][id];
		}
	}
	cout << "!\n";
	for( int i = 1; i <= n; i++, cout << "\n" )
		for( int j = 1; j <= n; j++ )
			cout << ans[i][j];
	cout << endl;
}


int32_t main ( )
{

	int T1 = clock();

	

	


	ios_base::sync_with_stdio ( false ); cin.tie ( nullptr ); cout.tie ( nullptr );
	


	int query = 1;
	


	

	

	


	while ( query-- ) solution();

	int T2 = clock();

	cerr << "Time: " << ( T2 - T1 ) / 1000. << " s." << endl;

	return 0;

}