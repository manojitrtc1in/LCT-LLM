
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#include <iostream>
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
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

    
    template<typename T> inline T min( T t ) { return t; }
    template<typename First, typename ...Others> inline auto min( First first, Others ...others ) { auto result = min( others... ); return result < first ? result : first; }

    template<typename T1, typename T2> inline void updmax ( T1 &a, T2 b ) { a = a > b ? a : b; }
    template<typename T1, typename T2> inline void updmin ( T1 &a, T2 b ) { a = a < b ? a : b; }

    constexpr long long operator"" _E ( unsigned long long n ){ long long p = 1, a = 10; for( int i = 0; i < n; i++ ) p *= a; return p; }
    long double operator"" _deg ( long double deg ){ long double PI = acos( -1 ); return deg * PI / 180; }

} using namespace utils;

template<typename T> inline T maxx( T t ) { return t; }
template<typename First, typename ...Others> inline auto maxx( First first, Others ...others ) { auto result = max( others... ); return result > first ? result : first; }
   
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

    friend ostream& operator << ( ostream &os, const nparray<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { if( i ) os << " "; os << array[i]; } return os; }
    friend istream& operator >> ( istream &is, nparray<T> &array ) { for( size_t i = 0; i < array.size(); i++ ) { is >> array[i]; } return is; }
    
    friend string to_string( nparray<T> &array ){ string s = "{ "; for( size_t i = 0; i < array.size(); i++ ) { if( i ) s += ", "; s += to_string( array[i] ); } s += "}"; return s; }
    ~nparray() { __clear(); }
  
};

#define int long long

#ifndef ONLINE_JUDGE
#define print(...) cerr << "[" << #__VA_ARGS__ << "]: "; io::print(__VA_ARGS__);
#else
#define print(...)
#endif

const int MOD = 1'000'000'007; // 998'244'353
const double EPS = 1e-9;
const double PI = acos ( -1. );
long long LLINF = 18_E;
int INF = 2 * 9_E;

const int MAXN = 6_E + 6;
const int N = 5 * 3_E;

static const int MAX_H = 15_E + 100;

struct fenwick{
    
    unordered_map<int, pair<int, int>> fw;

    void update( int i, int x, int y ){
        while( i < MAX_H ){
            if( x > fw[i].first ){
                fw[i].first = x;
                fw[i].second = y;
            }
            i = ( i | ( i + 1 ) );
        }
    }

    pair<int, int> get( int n ){
        pair<int, int> result;
        while( n >= 0 ){
            if( fw[n].first > result.first )
                result = fw[n];
            
            n = ( n & ( n + 1 ) ) - 1;
        }
        return result;
    }

};

void solution( istream &cin, ostream &cout, int test_case )
{   
    int n, d;
    cin >> n >> d;
    fenwick max_suff, max_pref;
    vector<int> h( n + 1 ), p( n + 1 ), pos( n + 1 ), dp( n + 1 );
    for( int i: range( 1, n + 1 ) ) cin >> h[i];
    vector<pair<int, int>> a( n + 1 );
    for( int i: range( 1, n + 1 ) ){
        a[i] = { h[i], i };
    } 
    sort( begin( a ), end( a ) );
    for( int i: range( 1, n + 1 ) ){
        pos[a[i].second] = i;
    }
    print( a );
    int ans = 0, last;
    for( int i: range( 1, n + 1 ) ){
        dp[i] = 1;
        p[i] = 0;
        int pref_ind = lower_bound( begin( a ), end( a ), pair<int, int>{ h[i] - d, n } ) - begin( a ) - 1;
        int suff_ind = lower_bound( begin( a ), end( a ), pair<int, int>{ h[i] + d, -1 } ) - begin( a );
        if( pref_ind >= 1 ){
            auto mx_pref = max_pref.get( pref_ind );
            if( mx_pref.first + 1 > dp[i] ){
                dp[i] = mx_pref.first + 1;
                p[i] = mx_pref.second;
            }
            print( mx_pref, pref_ind, h[i] )
        }
        if( suff_ind <= n ){
            int rev_ind = n - suff_ind;
            auto mx_suf = max_suff.get( rev_ind );
            if( mx_suf.first + 1 > dp[i] ){
                dp[i] = mx_suf.first + 1;
                p[i] = mx_suf.second;
            }
            print( mx_suf, suff_ind, h[i] );
        }
        if( dp[i] > ans ){
            ans = dp[i];
            last = i;
        }
        max_pref.update( pos[i], dp[i], i );
        max_suff.update( n - pos[i], dp[i], i );
    }
    vector<int> v;
    while( last > 0 ){
        v.push_back( last );
        last = p[last];
    }
    cout << ans << endl;
    reverse( begin( v ), end( v ) );
    cout << v << endl;
    
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