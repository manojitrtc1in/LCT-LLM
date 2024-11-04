#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <typeinfo>

#include <vector>
#include <array>
#include <valarray>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <any>
#include <unordered_map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

    dtime get_current_time() {
        return dtime();
    }

} using namespace utils;

template<typename T> class nparray {

private:
    T * _data = nullptr, * _max = nullptr, * _min = nullptr, * _sum = nullptr;
    size_t _size;

public:
    nparray(){}
    nparray( size_t size ) { __init( size ); }

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

    friend ostream& operator << ( ostream &os, nparray<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { if( i ) os << " "; os << array[i]; } return os; }
    friend istream& operator >> ( istream &is, nparray<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { is >> array[i]; } return is; }
    
    friend string to_string( nparray<T> &array ){ string s = "{ "; for( size_t i = 0; i < array.size(); i++ ) { if( i ) s += ", "; s += to_string( array[i] ); } s += "}"; return s; }
    ~nparray() { __clear(); }
  
};



#ifdef LOCAL_JUDGE
#define print( ... ) cerr << "[" << #__VA_ARGS__ << "]: "; io::print( __VA_ARGS__ );
#else
#define print( ... )
#endif

const int MOD = 2000000033; 

const double EPS = 1e-9;
const double PI = acos( -1. );
long long LLINF = 18_E + 10;
int INF = 2 * 8_E + 10;

const int MAXN = 2 * 6_E + 1000;
const int N = 5_E + 5;

int t[MAXN];
int a[MAXN];
int ans[MAXN];

void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = min( t[v*2], t[v*2+1] );
	}
}

int min (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 1e9;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return min( min (v*2, tl, tm, l, min(r,tm)),
		min(v*2+1, tm+1, tr, max(l,tm+1), r) );
}

void solution(  )
{
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
        a[i + n] = a[i + n + n] = a[i];
        ans[i] = ans[i + n] = ans[i + n + n] = -1;
    }
    build( a, 1, 1, 3 * n );
    for( int i = 2 * n - 1; i >= 1; i-- ){
        ans[i] = ans[i + 1];
        if( a[i] <= a[i + 1] ){
            continue;
        }
        int l = i, r = ( ans[i + 1] != -1 ? ans[i + 1] : 3 * n );
        while( r - l > 1 ){
            int m = ( l + r ) >> 1;
            if( min( 1, 1, 3 * n, i, m ) * 2 < a[i] ){
                r = m;
            } else {
                l = m;
            }
        }
        int y = min( 1, 1, 3 * n, i, r );
        if( y * 2 < a[i] ){
            if( ans[i] == -1 || ans[i] > r ){
                ans[i] = r;
            }
        } 
    }
    for( int i = 1; i <= n; i++ ){
        cout << max( -1, ans[i] - i ) << " ";
    }
}


int32_t main()
{
  
    int32_t queries = 1;
    


    for( int32_t test_case: range( 1, queries + 1 ) ){
        solution( );
    }
 
    return EXIT_SUCCESS;
 
}