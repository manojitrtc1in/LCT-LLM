
























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

    namespace Color {
        string 
        HEADER = "\033[95m",
        OKBLUE = "\033[94m",
        OKGREEN = "\033[92m",
        WARNING = "\033[93m",
        FAIL = "\033[91m",
        ENDC = "\033[0m",
        BOLD = "\033[1m",
        UNDERLINE = "\033[4m",
        BGGREEN = "\x1b[6;30;42m";
    }

    struct dtime {
        int h, m, s;
        
        dtime( int h, int m, int s ) : h( h ), m( m ), s( s ) {}
    
        dtime() { 
            h = ( ( time( 0 ) / 60 / 60 ) % 24 + 5 ) % 24;
            m  = ( time( 0 ) / 60 ) % 60;
            s = time( 0 ) % 60;
        }

        friend bool operator < ( const dtime &t1, const dtime &t2 ){
            if( t1.h == t2.h ){
                if( t1.m == t2.m ){
                    return t1.s < t2.s;
                }
                return t1.m < t2.m;
            }
            return t1.h < t2.h;
        }
        
        friend ostream& operator << ( ostream &os, const dtime &t ){
            os << t.h << " " << t.m << " " << t.s << endl;
            return os;
        }

        friend string to_string( const dtime &t ){
            return to_string( t.h ) + ":" + to_string( t.m ) + ":" + to_string( t.s );  
        }
    };

    dtime id1() {
        return dtime();
    }

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

    T* begin() { return _data; }
    T* end() { return _data + _size; }

    T* cbegin() { return _data + _size - 1; }
    T* cend() { return _data - 1; }

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

    friend ostream& operator << ( ostream &os, id0<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { if( i ) os << " "; os << array[i]; } return os; }
    friend istream& operator >> ( istream &is, id0<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { is >> array[i]; } return is; }
    
    friend string to_string( id0<T> &array ){ string s = "{ "; for( size_t i = 0; i < array.size(); i++ ) { if( i ) s += ", "; s += to_string( array[i] ); } s += "}"; return s; }
    ~id0() { __clear(); }
  
};









const int MOD = 1'000'000'007; // 998'244'353
const double EPS = 1e-9;
const double PI = acos( -1. );
long long LLINF = 18_E + 10;
int INF = 9_E + 10;

const int MAXN = 6_E + 6;
const int N = 5_E + 5;

template<typename node_value> struct segment_tree {

    private:
        struct node{
            int32_t l, r;
            node *left, *right;
            node_value val;
        } * root = nullptr;

        node * _build( int32_t l, int32_t r, function<node_value( int32_t )> f ){
            node * parent = new node;
            parent -> l = l;
            parent -> r = r;
            if( l == r ){
                parent -> left = nullptr;
                parent -> right = nullptr;
                parent -> val = f( l );
            } else {
                int32_t m = ( l + r ) >> 1;
                parent -> left = _build( l, m, f );
                parent -> right = _build( m + 1, r, f );
                parent -> val = node_value::unite( parent -> left -> val, parent -> right -> val );
            }
            return parent;
        }

        node_value get( node * parent, int32_t l, int32_t r ){
            if( parent -> l > r || parent -> r < l )
                return node_value();
    
            if( parent -> l >= l && parent -> r <= r )
                return parent -> val;
    
            node_value left = get( parent -> left, l, r );
            node_value right = get( parent -> right, l, r );
    
            return node_value::unite( left, right );
        }
    
        void update( node * parent, int32_t pos, node_value new_val ){
            if( parent -> l == parent -> r ){
                parent -> val = new_val;
            } else {
                if( pos >= parent -> left -> l && pos <= parent -> left -> r ){
                    update( parent-> left, pos, new_val );
                } else {
                    update( parent -> right, pos, new_val );
                }
                parent -> val = node_value::unite( parent -> left -> val, parent -> right -> val );
            }
        }

    public:
        void build( int32_t l, int32_t r, function<node_value( int32_t )> f ){
            root = _build( l, r, f );
        }

        node_value get( int32_t l, int32_t r ){
            return get( root, l, r );
        }

        void update( int32_t pos, node_value val ){
            update( root, pos, val );
        }

};

struct node_min {
    int min;
    node_min() : min( INT_MAX ) { }
    node_min( int min ) : min( min ) { }
    static node_min unite( const node_min &left, const node_min &right ){
        return left.min < right.min ? left.min : right.min;
    }

    friend string to_string( const node_min& val ){
        return "{ min: " + to_string( val.min ) + " }";
    }
};

int l_min[MAXN];
map<int, int> last;
int a[MAXN];
int d[MAXN];

void solution( istream &cin, ostream &cout, const int &test_case )
{
    int n, m;
    cin >> n >> m;
    fill( l_min + 1, l_min + 1 + n, INF );
    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
        if( last[a[i]] ){
            l_min[last[a[i]]] = i;
        }
        last[a[i]] = i;
    }
    int mn = INF;
    int diff = INF;
    for( int i = n; i >= 1; i-- ){
        if( l_min[i] < mn ){
            mn = l_min[i];
            diff = l_min[i] - i;
        }
        l_min[i] = mn;
        d[i] = diff;
    }
    segment_tree<node_min> sg;
    sg.build( 1, n, []( int i ){ return node_min( d[i] ); } );
    for( int i = 1; i <= m; i++ ){
        int l, r;
        cin >> l >> r;
        int L = l, R = r + 1;
        while( R - L > 1 ){
            int M = ( L + R ) >> 1;
            if( l_min[M] <= r ){
                L = M;
            } else {
                R = M;
            }
        }
        if( l_min[L] <= r ){
            cout << sg.get( l, L ).min << endl;
        } else {
            cout << -1 << endl;
        }
    }
}


int32_t main()
{

    srand( time( 0 ) );

    ios_base::sync_with_stdio( false ); cin.tie( nullptr ); cout.tie( nullptr );
    
    std::istream& in( std::cin ); 
    std::ostream& out( std::cout );
    
    int32_t queries = 1;
    


    for( int32_t test_case: range( 1, queries + 1 ) ){
        solution( cin, cout, test_case );
    }
 
    return EXIT_SUCCESS;
 
}