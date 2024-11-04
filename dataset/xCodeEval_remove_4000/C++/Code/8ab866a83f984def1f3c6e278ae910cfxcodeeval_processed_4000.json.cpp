




















 










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

template<typename T> class id0 {

private:
    T * _data = nullptr, * _max = nullptr, * _min = nullptr, * _sum = nullptr;
    size_t _size;

public:
    id0(){}
    id0( size_t size ) { __init( size ); }

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

    friend ostream& operator << ( ostream &os, const id0<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { if( i ) os << " "; os << array[i]; } return os; }
    friend istream& operator >> ( istream &is, id0<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { is >> array[i]; } return is; }
    
    friend string to_string( id0<T> &array ){ string s = "{ "; for( size_t i = 0; i < array.size(); i++ ) { if( i ) s += ", "; s += to_string( array[i] ); } s += "}"; return s; }
    ~id0() { __clear(); }
  
};









const int MOD = 1'000'000'007; // 998'244'353
const double EPS = 1e-9;
const double PI = acos ( -1. );
long long LLINF = 18_E;
int INF = 2 * 9_E;

const int MAXN = 6_E + 6;
const int N = 5 * 3_E;

template<typename T, int32_t MOD = 1'000'000'007> struct modular {

    T x = 0;

    modular(){}
    modular( const modular<T> &m ) { this -> x = m.x; } 
    template<typename C> modular( const C &x ) { this -> x = norm( x ); };
    
    modular<T, MOD> & operator -- () { return *this -= 1; }
    modular<T, MOD> & operator ++ () { return *this += 1; }
    
    modular<T, MOD> operator -- ( int32_t ) { modular<T, MOD> m( *this ); *this -= 1; return m; }
    modular<T, MOD> operator ++ ( int32_t ) { modular<T, MOD> m( *this ); *this += 1; return m; }

    modular<T, MOD> & operator += ( const modular<T, MOD> &m ){ x = norm( x + m.x ); return *this; }
    modular<T, MOD> & operator -= ( const modular<T, MOD> &m ){ x = norm( x - m.x ); return *this; }
    modular<T, MOD> & operator *= ( const modular<T, MOD> &m ){ x = 1ll * x * m.x % MOD; return *this; }
    modular<T, MOD> & operator /= ( const modular<T, MOD> &m ){ return *this *= inv( m.x ); }
    
    template<typename C> modular<T, MOD> & operator += ( const C &y ){ x = norm( x + y ); return *this; }
    template<typename C> modular<T, MOD> & operator -= ( const C &y ){ x = norm( x - y ); return *this; }
    template<typename C> modular<T, MOD> & operator *= ( const C &y ){ x = norm( x * norm( y ) ); return *this; }
    template<typename C> modular<T, MOD> & operator /= ( const C &y ){ assert( 0 <= y && y < MOD ); return *this *= inv( modular<T, MOD>( y ) ); }
    
    friend bool operator <  ( const modular<T, MOD> &a, const modular<T, MOD> &b ) { return a.x < b.x; }
    friend bool operator <= ( const modular<T, MOD> &a, const modular<T, MOD> &b ) { return a.x <= b.x; }
    friend bool operator >  ( const modular<T, MOD> &a, const modular<T, MOD> &b ) { return a.x > b.x; }
    friend bool operator >= ( const modular<T, MOD> &a, const modular<T, MOD> &b ) { return a.x >= b.x; }
    friend bool operator == ( const modular<T, MOD> &a, const modular<T, MOD> &b ) { return a.x == b.x; }
    friend bool operator != ( const modular<T, MOD> &a, const modular<T, MOD> &b ) { return a.x != b.x; }  

    friend modular<T, MOD> operator + ( const modular<T, MOD> &a, const modular<T, MOD> &b ){ return modular<T, MOD>( a.x + b.x ); }
    friend modular<T, MOD> operator - ( const modular<T, MOD> &a, const modular<T, MOD> &b ){ return modular<T, MOD>( a.x - b.x ); }
    friend modular<T, MOD> operator * ( const modular<T, MOD> &a, const modular<T, MOD> &b ){ return modular<T, MOD>( 1ll * a.x * b.x ); }
    friend modular<T, MOD> operator / ( const modular<T, MOD> &a, const modular<T, MOD> &b ){ return modular<T, MOD>( a * inv( b ) ); }
    
    friend modular inv( const modular<T, MOD> &m ){ return pow( m, MOD - 2 ); }
    template<typename C> friend modular pow( const modular<T, MOD> &m, C n ){ modular<T, MOD> res( 1 ), a( m ); while( n ){ if( n & 1 ) res *= a; a *= a; n >>= 1; } return res; }
    template<typename C> friend modular mul( const modular<T, MOD> &m, C n ){ modular<T, MOD> res( 0 ), a( m ); while( n ){ if( n & 1 ) res += a; a += a; n >>= 1; } return res; }

    modular<T, MOD> operator - () const { return modular<T, MOD>( -x ); }

    int32_t mod() { return MOD; }

    template<typename C> operator C() const { return ( C ) x; }
    const T& operator()() const { return x; }

    friend ostream & operator << ( ostream &os, const modular &m ){ return os << m.x; }
    friend istream & operator >> ( istream &is, const modular &m ){ return is >> m.x; }

    friend string to_string( const modular &m ){ return std::to_string( m.x ); }

    template<typename C> inline T norm( const C &a ) { 
        if( a >= MOD ) {
            if( a < MOD + MOD ){
                return a - MOD;
            } else {
                return a % MOD;
            }
        } else if( a < 0 ){
            return a % MOD + MOD;
        } else {
            return a;
        }
    }
};

struct fenwick{

    modular<int> fw[MAXN];

    void update( int i, int d ){
        while( i < MAXN ){
            fw[i] += d;
            i = ( i | ( i + 1 ) );
        }
    }

    modular<int> get( int n ){
        modular<int> result( 0 );
        while( n >= 0 ){
            result += fw[n];
            n = ( n & ( n + 1 ) ) - 1;
        }
        return result;
    }

    modular<int> get( int l, int r ){
        return get( r ) - get( l - 1 );
    }
};

fenwick fw, cnt;
modular<int> last[MAXN], lastlast[MAXN];
int used[MAXN];

void solution( istream &cin, ostream &cout, int test_case )
{
    modular<int> ans( 0 );
    int n;
    cin >> n;
    for( int i: range( n ) ){
        int x;
        cin >> x;
        int y = fw.get( x - 1 ) - last[x] + !used[x] + lastlast[x];
        ans += y * x;
        fw.update( x, y * x );
        used[x] = 1;
        lastlast[x] = y * x;
        last[x] = fw.get( x - 1 );
    }

    cout << ans << endl;

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