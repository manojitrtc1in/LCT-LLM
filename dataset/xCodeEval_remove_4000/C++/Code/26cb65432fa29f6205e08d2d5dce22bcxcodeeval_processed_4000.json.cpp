




















 








using namespace std;

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
    template<typename First, typename Second> string to_string( pair<First, Second> );
    template<typename Collection> string to_string( Collection );

    template<typename First, typename Second> string to_string( pair<First, Second> p ){ return "{" + to_string( p.first ) + ", " + to_string( p.second ) + "}"; }
    template<typename Type> string to_string( vector<Type> v ) { bool sep = false; string s = "["; for( Type x: v ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "]"; return s; }
    template<typename Collection> string to_string( Collection collection ) { bool sep = false; string s = "{"; for( auto x: collection ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "}"; return s; }

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

    template<typename T> auto max( T a, T b, char c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, unsigned char c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, int32_t c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, unsigned int c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, float c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, double c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, int64_t c ) { return max( a, max( b, c ) ); }
    template<typename T> auto max( T a, T b, unsigned long long c ) { return max( a, max( b, c ) ); }

    template<typename T> inline T max( T t ) { return t; }
    template<typename First, typename ...Others> inline auto max( First first, Others ...others ) { auto result = max( others... ); return result > first ? result : first; }
    
    template<typename T> inline T min( T t ) { return t; }
    template<typename First, typename ...Others> inline auto min( First first, Others ...others ) { auto result = min( others... ); return result < first ? result : first; }

    template<typename T1, typename T2> inline void updmax ( T1 &a, T2 b ) { a = a > b ? a : b; }
    template<typename T1, typename T2> inline void updmin ( T1 &a, T2 b ) { a = a < b ? a : b; }

    template<typename T1, typename T2> inline bool chkmax ( T1 &a, T2 b ) { if( a < b ) { a = b; return true; } return false; }
    template<typename T1, typename T2> inline bool chkmin ( T1 &a, T2 b ) { if( a > b ) { a = b; return true; } return false; }
 
    constexpr long long operator"" _E ( unsigned long long n ){ long long p = 1, a = 10; for( int i = 0; i < n; i++ ) p *= a; return p; }
    long double operator"" _deg ( long double deg ){ long double PI = acos( -1 ); return deg * PI / 180; }

    random_device rd; mt19937 mt( rd( ) );
    template<typename T> T rand ( T l, T r ) { uniform_int_distribution<T> dist( l, r ); return dist( mt ); }; 

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
    
    T max(){ return *std::max_element( _data, _data + this -> _size ); }
    T max( size_t index ){ assert( index < _size ); if( _max == nullptr ) __maxrecalc(); return _max[index]; }

    T min(){ return *std::min_element( _data, _data + _size ); }
    T min( size_t index ){ assert( index < _size ); if( _min == nullptr ) __minrecalc(); return _min[index]; }

    T* begin() { return _data; }
    T* end() { return _data + _size; }

    T* cbegin() { return _data + _size - 1; }
    T* cend() { return _data - 1; }

    void fill( int value ){ std::fill( _data, _data + _size, value ); }
    void reverse( ){ std::reverse( _data, _data + _size ); if( _sum != nullptr ) std::reverse( _sum, _sum + _size ); if( _max != nullptr ) std::reverse( _max, _max + _size ); if( _min != nullptr ) std::reverse( _min, _min + _size ); }
    void sort( ){ std::sort( _data, _data + _size ); if( _sum != nullptr ) __sumrecalc(); if( _max != nullptr ) __maxrecalc(); if( _min != nullptr ) __minrecalc(); }
    void shift( int count ) { count %= ( int32_t )_size; T *temp = new T[_size]; int j = ( count < 0 ? _size + count: count ); for( size_t i = 0; i < _size; i++, j++ ){ if( j == _size ) j = 0; temp[j] = _data[i]; } for( size_t i = 0; i < _size; i++ ){ _data[i] = temp[i]; } delete temp; }
    void random_shuffle( ){ std::random_shuffle( this->_data, this->_data + this->_size );  }
    bool is_sorted( ){ for( int i = 1; i < _size; i++ ){ if( _data[i - 1] > _data[i + 1] ){ return false; } } return true; }
    void resize( size_t size ) { __clear(); __init( size ); }

    void __clear() { _size = 0; delete _data; if( _max ) delete _max; if( _min ) delete _min; if( _sum ) delete _sum; }
    void __sumrecalc(){ _sum = new T[_size]; _sum[0] = _data[0]; for( int i = 1; i < _size; i++ ){ _sum[i] = _sum[i - 1] + _data[i]; } }
    void __maxrecalc(){ _max = new T[_size]; _max[0] = _data[0]; for( int i = 1; i < _size; i++ ){ _max[i] = ( _data[i] > _max[i - 1] ? _data[i] : _max[i - 1]); } }
    void __minrecalc(){ _min = new T[_size]; _min[0] = _data[0]; for( int i = 1; i < _size; i++ ){ _min[i] = ( _data[i] < _min[i - 1] ? _data[i] : _min[i - 1]); } }

    T& operator [] ( int index ){ if( index < 0 ){ assert( -index <= _size ); return _data[_size + index]; } else { assert( index < _size ); return _data[index]; } }
    size_t size() { return _size; }
    bool empty(){ return ( _size == 0 ); }

    friend ostream& operator << ( ostream &os, id0<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { if( i ) os << " "; os << array[i]; } return os; }
    friend istream& operator >> ( istream &is, id0<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { is >> array[i]; } return is; }
    
    friend string to_string( id0<T> &array ){ string s = "{"; for( size_t i = 0; i < array.size(); i++ ) { if( i ) s += ", "; s += to_string( array[i] ); } s += "}"; return s; }
    ~id0() { __clear(); }
  
};











const int MOD = 1'000'000'007; // 998'244'353
const double EPS = 1e-9;
const double PI = acos( -1. );
long long LLINF = 18_E + 10;
int INF = 9_E + 10;

const int MAXN = 200005;
const int N = 5 * 3_E + 5;

int p[MAXN];
vector<int> pr[MAXN];
int ord[MAXN];

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
struct SegmentTree {

    struct node {
        int mn = 0;

        void apply( int l, int r, int x ) {
            mn += x;
        }

        static node unite( const node &a, const node &b ) {
            node res;
            res.mn = min( a.mn, b.mn );
            return res;
        }
    };

    inline void pull( int x, int z ) {
        tree[x] = node::unite( tree[x + 1], tree[z] );
    }

    inline void push( int v, int l, int r ) {

    }

    int n, tl, tr;
    vector<node> tree;

    void build( int v, int l, int r ) {
        if( l == r ) {
            return;
        }
        int y = ( l + r ) >> 1;
        int z = v + ( ( y - l + 1 ) << 1 );
        build( v  + 1, l, y );
        build( z, y + 1, r);
        pull( v, z );
    }

    template <typename ValueType> void build( int v, int l, int r, const vector<ValueType> &a ) {
        if( l == r ) {
            tree[v].apply( l, r, a[l] );
            return;
        }
        int y = ( l + r ) >> 1;
        int z = v + ( ( y - l + 1 ) << 1 );
        build( v + 1, l, y, a );
        build( z, y + 1, r, a );
        pull( v, z );
    }

    template <typename ValueType> void build( int v, int l, int r, ValueType a[] ) {
        if( l == r ) {
            tree[v].apply( l, r, a[l] );
            return;
        }
        int y = ( l + r ) >> 1;
        int z = v + ( ( y - l + 1 ) << 1 );
        build( v + 1, l, y, a );
        build( z, y + 1, r, a );
        pull( v, z );
    }

    node get( int x, int l, int r, int ql, int qr ){
        if( ql <= l && r <= qr ) {
            return tree[x];
        }
        int y = ( l + r ) >> 1;
        int z = x + ( ( y - l + 1 ) << 1 );
        push( x, l, r );
        node res;
        if ( qr <= y ) {
            res = get( x + 1, l, y, ql, qr );
        } else {
            if ( ql > y ) {
                res = get( z, y + 1, r, ql, qr );
            } else {
                res = node::unite( get( x + 1, l, y, ql, qr ), get( z, y + 1, r, ql, qr ) );
            }
        }
        pull( x, z );
        return res;
    }

    template <typename... M> void modify( int x, int l, int r, int ql, int qr, const M&... v ) {
        if ( ql <= l && r <= qr ) {
            tree[x].apply( l, r, v... );
            return;
        }
        int y = ( l + r ) >> 1;
        int z = x + ( ( y - l + 1 ) << 1 );
        push(x, l, r);
        if ( ql <= y ) {
            modify( x + 1, l, y, ql, qr, v... );
        }
        if ( qr > y ) {
            modify( z, y + 1, r, ql, qr, v... );
        }
        pull(x, z);
    }

    int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, l, y, f);
        } else {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }

    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y) {
            res = find_first(x + 1, l, y, ll, rr, f);
        }
        if (rr > y && res == -1) {
            res = find_first(z, y + 1, r, ll, rr, f);
        }
        pull(x, z);
        return res;
    }

    int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[z])) {
            res = find_last_knowingly(z, y + 1, r, f);
        } else {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }

    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y) {
            res = find_last(z, y + 1, r, ll, rr, f);
        }
        if (ll <= y && res == -1) {
            res = find_last(x + 1, l, y, ll, rr, f);
        }
        pull(x, z);
        return res;
    }

    SegmentTree( int _n ) : n( _n ), tl( 0 ), tr( n - 1 ) {
        assert( n > 0 );
        tree.resize( 2*n - 1 );
        build( 0, 0, n - 1 );
    }

    SegmentTree( int l, int r ) : tl( l ), tr( r ), n( r - l + 1 ) {
        assert( n > 0 );
        tree.resize( 2*n + 1 );
        build( tl, tl, tr );
    }

    template <typename ValueType> SegmentTree( const vector<ValueType> &v ) {
        n = v.size();
        tl = 0;
        tr = n-1;
        assert( n > 0 );
        tree.resize( 2*n - 1 );
        build( tl, tl, tr, v );
    }

    template <typename ValueType> SegmentTree( ValueType a[], int n_ ): n( n_ ), tl( 1 ), tr( n_ ) {
        assert( n > 0 );
        tree.resize( 2*n + 1 );
        build( tl, tl, tr, a );
    }

    node get( int l, int r ) {
        assert( tl <= l && l <= r && r <= tr );
        return get( tl, tl, tr, l, r );
    }

    node get( int p ) {
        assert( tl <= p && p <= tr );
        return get( tl, tl, tr, p, p );
    }

    template <typename... ValueType> void modify( int l, int r, const ValueType&... v ) {
        assert( tl <= l && l <= r && r <= tr );
        modify( tl, tl, tr, l, r, v... );
    }

    int find_first( int l, int r, const function<bool(const node&)> &f ) {
        assert( tl <= l && l <= r && r <= tr );
        return find_first( tl, tl, tr, l, r, f );
    }

    int find_last( int l, int r, const function<bool(const node&)> &f ) {
        assert( tl <= l && l <= r && r <= tr );
        return find_last( tl, tl, tr, l, r, f );
    }
};

int mn[MAXN];

void solution( istream &cin, ostream &cout, const int &test_case )
{
    for( int i = 2; i < MAXN; i++ ){
        if( !p[i] ){
            p[i] = i;
            if( 1ll*i*i < MAXN ){
                for( int j = i*i; j < MAXN; j +=i ){
                    p[j] = i;
                }
            }
        }
    }
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ ){
        int x;
        cin >> x;
        while( x > 1 ){
            int t = p[x];
            while( x % t == 0 ){
                pr[t].push_back( i );
                x /= t;
            }
        }
    }

    vector<pair<int, int>> q;
    modular<int> ans( 1 );
    for( int _ = 0; _ < m; _++ ){
        int i, x;
        cin >> i >> x; 
        q.push_back( { i, x } );
        while( x > 1 ){
            int t = p[x];
            while( x % t == 0 ){
                pr[t].push_back( i );
                x /= t;
            }
        }
    }

    vector<SegmentTree> sgs;
    for( int i = 1; i < MAXN; i++ ){
        if( pr[i].size() >= n ){
            vector<int> c( n, 0 );
            for( int j: pr[i] ){
                c[j - 1]++;
            }
            int mn = *min_element( c.begin(), c.end() );
            if( mn > 0 ){
                SegmentTree sg( c );
                for( int j = 0; j < mn; j++ ) ans *= i;
                ::mn[i] = mn;
                sgs.push_back( sg );
                ord[i] = sgs.size();
            }
        }
    }

    vector<int> an( m );
    for( int i = m - 1; i >= 0; i-- ){
        an[i] = ans;
        int ind = q[i].first - 1;
        int x = q[i].second;
        while( x > 1 ){
            int t = p[x];
            while( x % t == 0 ){
                if( ord[t] ){
                    int j = ord[t] - 1;
                    sgs[j].modify( ind, ind, -1 );
                }
                x /= t;
            }
            if( ord[t] ){
                int j = ord[t] - 1;
                while( sgs[j].get( 0, n - 1 ).mn != mn[t] ){
                    mn[t]--;
                    ans /= t;
                    if( mn[t] == 0 ){
                        ord[t] = 0;
                    }
                }
            }
        }
    }
    for( int x: an ){
        cout << x << endl;
    }
}

int32_t main()
{

    

    


    srand( time( 0 ) );

    ios_base::sync_with_stdio( false ); cin.tie( nullptr ); cout.tie( nullptr );
    

    int32_t queries = 1;
    


    for( int32_t test_case: range( 1, queries + 1 ) ){
        solution( cin, cout, test_case );
    }

    

    return EXIT_SUCCESS;
 
}