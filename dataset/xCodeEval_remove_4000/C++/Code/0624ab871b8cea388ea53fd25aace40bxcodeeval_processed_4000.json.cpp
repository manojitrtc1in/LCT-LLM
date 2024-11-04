





















 










using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
 
template<class T, class C = null_type> using ordered_tree = tree<T, C, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

namespace io{
    
    template<typename First, typename Second> ostream& operator << ( ostream &os, const pair<First, Second> &p ) { return os << p.first << " " << p.second; }
    template<typename First, typename Second> ostream& operator << ( ostream &os, const map<First, Second> &mp ) { for( auto it : mp ) { os << it << endl;  } return os; }
    template<typename First> ostream& operator << ( ostream &os, const vector<First> &v ) { bool space = false; for( First x : v ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const set<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const multiset<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }

    template<typename First, typename Second> istream& operator >> ( istream &is, pair<First, Second> &p ) { return is >> p.first >> p.second; }
    template<typename First> istream& operator >> ( istream &is, vector<First> &v ) { for( First &x : v ) { is >> x; } return is; }
    
    long long fastread(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x; }
    
    static bool sep = false;

    using std::to_string;

    string to_string( bool x ){ return ( x ? "true" : "false" ); }
    string to_string( const string & s ){ return "\"" + s + "\""; }
    string to_string( const char * s ){ return "\"" + string( s ) + "\""; }
    string to_string ( const char & c ) { string s; s += c; return "\'" + s + "\'"; }

    template<typename Type> string to_string( vector<Type> );
    template<typename Collection> string to_string( Collection );
    template<typename First, typename Second> string to_string( pair<First, Second> p ){ return "{" + to_string( p.first ) + ", " + to_string( p.second ) + "}"; }
    template<typename Collection> string to_string( Collection collection ) { bool sep = false; string s = "{"; for( auto x: collection ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "}"; return s; }
    template<typename Type> string to_string( vector<Type> v ) { bool sep = false; string s = "["; for( Type x: v ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "]"; return s; }

    void print() { cerr << endl; sep = false; }
    template <typename First, typename... Other> void print( First first, Other... other ) { if( sep ) cerr << " | "; sep = true; cerr << to_string( first ); print( other... ); }

} using namespace io;

namespace utils {

    class Range {
        private:
            const int start;
            const int stop;
            const int step;
            
        public:
            class iterator {
            private:
                int value;
                const int step;
                const int boundary;
                const bool sign;

            public:
                typedef std::forward_iterator_tag iterator_category;
                typedef int &reference;
                typedef int *pointer;

                iterator( int value, int step, int boundary ) : value( value ), step( step ), boundary( boundary ), sign( step > 0 ) {}
                iterator operator ++ () { value += step; return *this; }
                reference operator * () { return value; }
                const pointer operator -> () { return &value; }
                bool operator == ( const iterator& rhs ) { return sign ? ( value >= rhs.value && value > boundary ) : (value <= rhs.value && value < boundary ); }
                bool operator != ( const iterator& rhs ) { return sign ? ( value < rhs.value && value >= boundary ) : ( value > rhs.value && value <= boundary ); }
            };

            Range( const int &start, const int &stop, const int &step ) : start( start ), stop( stop ), step( step ) {}      
            iterator begin() const { return iterator( start, step, start ); }
            iterator end() const { return iterator( stop, step, start ); }
    };

    Range range( const int &stop ) { return Range( 0, stop, 1 ); }
    Range range( const int &start, const int &stop ) { return Range( start, stop, 1 ); }
    Range range( const int &start, const int &stop, const int &step ) { return Range( start, stop, step ); }

    template<typename T> inline T sum( T t ) { return t; }
    template<typename First, typename ...Others> inline auto sum( First first, Others ...others ) { return first + sum( others... ); }

    template<typename T> inline T max( T t ) { return t; }
    template<typename First, typename ...Others> inline auto max( First first, Others ...others ) { auto result = max( others... ); return result > first ? result : first; }
    
    template<typename T> inline T min( T t ) { return t; }
    template<typename First, typename ...Others> inline auto min( First first, Others ...others ) { auto result = min( others... ); return result < first ? result : first; }

    template<typename T1, typename T2> inline void updmax ( T1 &a, T2 b ) { a = a > b ? a : b; }
    template<typename T1, typename T2> inline void updmin ( T1 &a, T2 b ) { a = a < b ? a : b; }

    constexpr long long operator"" _E ( unsigned long long n ){ long long p = 1, a = 10; for( int i = 0; i < n; i++ ) p *= a; return p; }
    long double operator"" _deg ( long double deg ){ long double PI = acos( -1 ); return deg * PI / 180; }

} using namespace utils;

template<typename T> class id2 {

private:
    T * _data = nullptr, * _max = nullptr, * _min = nullptr, * _sum = nullptr;
    size_t _size;

public:
    id2(){}
    id2( size_t size ) { __init( size ); }

    void __init( size_t size ){ _size = size; _data = new T[size]; fill( 0 ); }
    
    T sum() { return std::accumulate( _data, _data + _size, 0 ); }
    T sum( size_t stop ) { return sum( 0, stop ); }
    T sum( size_t start, size_t stop ){ if( _sum == nullptr ) __sumrecalc(); T sum_ = _sum[stop]; if( start ) sum_ -= _sum[start - 1]; return sum_; }
    T sum( size_t start, size_t stop, size_t step ) { T sum_ = 0; for( size_t i = start; i < stop; i += step ) { sum_ += _data[i]; } return sum_; }
    
    T max(){ return std::max_element( _data, _data + this -> _size ); }
    T max( size_t index ){ assert( index < _size ); if( _max == nullptr ) __maxrecalc(); return _max[index]; }

    T min(){ return std::min_element( _data, _data + _size ); }
    T min( size_t index ){ assert( index < _size ); if( _min == nullptr ) __minrecalc(); return _min[index]; }

    void fill( int value ){ std::fill( _data, _data + _size, value ); }
    void reverse( ){ std::reverse( _data, _data + _size ); if( _sum != nullptr ) std::reverse( _sum, _sum + _size ); if( _max != nullptr ) std::reverse( _max, _max + _size ); if( _min != nullptr ) std::reverse( _min, _min + _size ); }
    void sort( ){ std::sort( _data, _data + _size ); if( _sum != nullptr ) __sumrecalc(); if( _max != nullptr ) __maxrecalc(); if( _min != nullptr ) __minrecalc(); }
    void shift( int count ) { count %= ( int32_t )_size; T *temp = new T[_size]; int j = ( count < 0 ? _size + count: count ); for( size_t i = 0; i < _size; i++, j++ ){ if( j == _size ) j = 0; temp[j] = _data[i]; } for( size_t i = 0; i < _size; i++ ){ _data[i] = temp[i]; } delete temp; }
    void random_shuffle( ){ std::random_shuffle( _data, _data + _size );  }
    bool is_sorted( ){ for( int i = 1; i < _size; i++ ){ if( _data[i - 1] > _data[i + 1] ){ return false; } } return true; }
    void resize( size_t size ) { __clear(); __init( size ); }

    void __clear() { _size = 0; delete _data; delete _max; delete _min; delete _sum; }
    void __sumrecalc(){ _sum = new T[_size]; _sum[0] = _data[0]; for( int i = 1; i < _size; i++ ){ _sum[i] = _sum[i - 1] + _data[i]; } }
    void __maxrecalc(){ _max = new T[_size]; _max[0] = _data[0]; for( int i = 1; i < _size; i++ ){ _max[i] = ( _data[i] > _max[i - 1] ? _data[i] : _max[i - 1]); } }
    void __minrecalc(){ _min = new T[_size]; _min[0] = _data[0]; for( int i = 1; i < _size; i++ ){ _min[i] = ( _data[i] < _min[i - 1] ? _data[i] : _min[i - 1]); } }

    T& operator [] ( int index ){ if( index < 0 ){ assert( -index <= _size ); return _data[_size + index]; } else { assert( index < _size ); return _data[index]; } }
    size_t size() { return _size; }
    bool empty(){ return ( _size == 0 ); }

    friend ostream& operator << ( ostream &os, const id2<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { if( i ) os << " "; os << array[i]; } return os; }
    friend istream& operator >> ( istream &is, id2<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { is >> array[i]; } return is; }
    
    friend string to_string( id2<T> &array ){ string s = "{ "; for( size_t i = 0; i < array.size(); i++ ) { if( i ) s += ", "; s += to_string( array[i] ); } s += "}"; return s; }
    ~id2() { __clear(); }
  
};









const int MOD = 1'000'000'007; // 998'244'353
const double EPS = 1e-9;
const double PI = acos ( -1. );
long long LLINF = 18_E;
int INF = 2 * 9_E;

const int MAXN = 6_E + 6;
const int N = 5 * 3_E;

namespace number {

    static const int MOD = 1'000'000'007;
    random_device rd; mt19937 mt( rd( ) );
    uniform_int_distribution<long long> dist( 0, 1ll * MOD * MOD );
 
    inline int norm( int a ) { while( a < 0 ) a += MOD; while( a >= MOD ) a -= MOD; return a; }
    inline int add( int a, int b ) { return norm( a + b ); }
    inline int sub( int a, int b ) { return norm( a - b ); }
    inline int mul( int a, int b, int mod = MOD ) { return ( 1ll * a * b ) % mod; }
 
    int mul_mod( int a, int b, const int &mod = MOD ) { int s = 0; while( b ) { if( b & 1 ) s = ( s + a ) % mod; a = ( a + a ) % mod; b >>= 1; } return s; }
    int pow_mod( int a, int n, const int &mod = MOD ) { int p = 1; while( n ) { if( n & 1 ) p = mul( p, a, mod ); a = mul( a, a, mod ); n >>= 1; } return p; }
    int _pow_mod( int a, int n, const int &mod = MOD ) { int p = 1; while( n ) { if( n & 1 ) p = mul_mod( p, a, mod ); a = mul_mod( a, a, mod ); n >>= 1; } return p; }
 
    inline int inv( int a ) { return pow_mod( a, MOD - 2 ); }
    inline int div_mod( int a, int b ) { return mul( a, inv( b ) ); }
    
    inline int gcd( int a, int b ){ while( b ){ a %= b; swap( a, b ); } return a; }
    inline int lcm( int a, int b ){ return a * ( b / gcd( a, b ) ); }

    long long sqr( int x ) { return 1ll * x * x; };
    
    int sqrt_n( long long n ){
        int x = sqrt( ( long double ) n );
        while( 1ll * x * x < n ) x++;
        while( 1ll * x * x > n ) x--;
        return x;
    }

    bool id1( long long m ) {
        int s = 0, d = m - 1;
        while( d % 2 == 0 ) s++, d /= 2;
        int a = 1 + dist( mt ) % ( m - 1 );
        int x = _pow_mod( a, d, m );
        if( x == 1 ) return true;
        for( int r = 0; r < s; r++ ) { if( x == m - 1 ) return true; x = mul_mod( x, x, m ); }
        return false;
    }
 
    bool is_prime( long long n ) {
        if( n <= 4 ) return ( n == 2 || n == 3 ); 
        if( n % 2 == 0 || n % 3 == 0 ) return false;
        for( long long i = 5; i * i <= n; i += 6 ) 
            if( n % i == 0 || n % ( i + 2 ) == 0 )
                return 0; 
        return 1;
    }
    
    long long id6( long long n, int32_t it = 50000 ) {
        long long b0 = dist( mt ) % n, b1 = b0, g;
        b1 = mul_mod( b1, b1, n );
        if( ++b1 == n ) b1 = 0;
        g = gcd( abs( b1 - b0 ), n );
        for( int count = 0; count < it && ( g == 1 || g == n ); count++ ) {
            b0 = mul_mod( b0, b0, n );
            if( ++b0 == n ) b0 = 0;
            b1 = mul_mod( b1, b1, n ); ++b1;
            b1 = mul_mod( b1, b1, n );
            if( ++b1 == n ) b1 = 0;
            g = gcd( abs( b1 - b0 ), n );
        }
        return g;
    }
 
    int id5( int a, int b, int & x, int & y ) {
        if( a == 0 ) { x = 0; y = 1; return b; }
        int x1, y1, d = id5( b % a, a, x1, y1 );
        x = y1 - ( b / a ) * x1; y = x1;
        return d;
    }

    vector<int> sieve( int n, bool id3 = false ){
        vector<int> p( n + 1, 1 );
        if( id3 == true ) p[0] = p[1] = 0;
        for( int i = 2; i <= n; i++ ){
            if( p[i] == 1 ){
                p[i] = ( id3 ? 1 : i );
                if( 1ll * i * i <= n ){
                    for( int j = i * i; j <= n; j += i ){
                        p[j] = ( id3 ? 0 : i );
                    }
                }
            }
        }
        return p;
    }

    vector<int> id4( int n ){
        vector<int> primes, sieve( n + 1, 0 );
        for( int i = 2; i <= n; i++ ){
            if( !sieve[i] ){
                primes.push_back( i );
                if( 1ll * i * i <= n ){
                    for( int j = i * i; j <= n; j += i ){
                        sieve[j] = 1;
                    }
                }
            }
        }
        return primes;
    }

    vector<int> id0( long long n ){
        vector<int> divs;
        for( int i = 1; 1ll * i * i <= n; i++ ){
            if( n % i == 0 ){
                divs.push_back( i );
                if( i * i != n ) {
                    divs.push_back( n / i );
                }
            }
        }
        sort( divs.begin(), divs.end() );
        return divs;
    }
    
    int id7( long long n ){
        int cnt = 0;
        for( int i = 1; 1ll * i * i <= n; i++ ){
            if( n % i == 0 ){
                cnt += 2;
                cnt -= ( i * i == n );
            }
        }
        return cnt;
    }

}

int sign( int x ){
    return x < 0 ? -1 : 1;
}

void solution( istream &cin, ostream &cout, int test_case )
{
    int a, b, c;
    cin >> a >> b >> c;
    if( a == 0 ){
        if( c % b == 0 ){
            cout << 0 << " " << -c / b << endl;
        } else {
            cout << -1 << endl;
        }
    } else if( b == 0 ){
        if( c % a == 0 ){
            cout << -c / a << " " << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        c = -c;
        int x, y;
        int d = number::id5( a, b, x, y );
        if( c % d ){
            cout << -1 << endl;
        } else {
            cout << c / d * x << " " << c / d * y << endl;
        }
    }
}

int32_t main ( )
{

    int T1 = clock();

    ios_base::sync_with_stdio ( false ); cin.tie ( nullptr ); cout.tie ( nullptr );

    std::istream& in( std::cin ); 
    std::ostream& out( std::cout );
    out.precision( 15 );

    int queries = 1;
    

    
    for( int test_case: range( 1, queries + 1 ) ){
        

        

        solution( in, out, test_case );
        

    }
    
    int T2 = clock();

    cerr << "Time: " << ( T2 - T1 ) / 1000. << " s." << endl;
 
    return EXIT_SUCCESS;
 
}