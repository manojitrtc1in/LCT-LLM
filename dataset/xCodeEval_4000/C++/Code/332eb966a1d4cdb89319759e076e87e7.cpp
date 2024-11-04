
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


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
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

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

const int MOD = 1'000'000'007; // 998'244'353
const double EPS = 1e-9;
const double PI = acos( -1. );
long long LLINF = 18_E + 10;
int INF = 9_E + 10;

const int MAXN = 6_E + 6;
const int N = 5_E + 5;

template < typename T >
struct treap {
private:
	struct node {
		T sum = 0, x = 0;
		int y, cnt = 1, rev = 0;
		node * l, * r;

		node( T x ) {
			this -> sum = x;
			this -> x = x;
			this -> y = rand() | ( 1 << ( rand() % 31 ) );
			this -> l = this -> r = nullptr;
		}

		~node( ) {
			if ( l )
				delete l;
			if ( r )
				delete r;
		}
	};
public:
	node * root = nullptr;
	pair<node *, node *> split( node * Node, int k ) {
		if ( Node == nullptr )
			return { nullptr, nullptr };
		push( Node );
		if ( cnt ( Node ) <= k )
			return { Node, nullptr };
		if ( k == 0 )
			return { nullptr, Node };
		if ( cnt ( Node -> l ) < k ) {
			pair<node *, node *> res = split( Node -> r, k - cnt ( Node -> l ) - 1 );
			Node -> r = res.first;
			update( Node );
			return { Node, res.second };
		} else {
			pair<node *, node *> res = split( Node -> l, k );
			Node -> l = res.second;
			update( Node );
			return { res.first, Node };
		}
	}
	node * merge( node * First, node * Second ) {
		if ( First == nullptr )
			return Second;
		if ( Second == nullptr )
			return First;
		if ( First -> y <= Second -> y ) {
			push( First );
			First -> r = merge( First -> r, Second );
			update( First );
			return First;
		} else {
			push( Second );
			Second -> l = merge( First, Second -> l );
			update( Second );
			return Second;
		}
	}
	void insert( int pos, T x ){
		if ( pos > size() || pos < 0 ) return;
		pair< node *, node * > res = split( root, pos );
		node * new_node = new node( x );
		root = merge( merge( res.first, new_node ), res.second );
	}

	void erase( int pos ) {
		pair<node *, node *> res_1 = split( root, pos );
		pair<node *, node *> res_2 = split( res_1.second, 1 );
		root = merge( res_1.first, res_2.second );
	}

	node * erase( int l, int r ){
		pair < node *, node * > res_1 = split( root, l );
		pair < node *, node * > res_2 = split( res_1.second, r - l + 1 );
		root = merge( res_1.first, res_2.second );
		return res_2.first;
	}

	void reverse( int l, int r ){
		pair < node *, node * > res_1 = split( root, l );
		pair < node *, node * > res_2 = split( res_1.second, r - l + 1 );
		res_2.first -> rev ^= 1;
		merge( merge( res_1.first, res_2.first ), res_2.second );
	}

	T sum( int l, int r ){
		pair < node *, node * > res_1 = split( root, l );
		pair < node *, node * > res_2 = split( res_1.second, r - l + 1 );
		T res = res_2.first -> sum;
		merge( merge( res_1.first, res_2.first ), res_2.second );
		return res;
	}


	T& operator []( int pos ){
		return order( root, pos + 1 );
	}
	T& order ( node *root, int pos ){
		push( root );
		T *res = nullptr;
		if( cnt( root ) - cnt( root -> r ) == pos )
			res = &root -> x;
		else if( pos > cnt( root ) - cnt( root -> r ) )
			res = &order( root -> r, pos - ( cnt( root ) - cnt( root -> r ) ) );
		else
			res = &order( root -> l, pos);
		update( root );
		return *res;
	}

	inline void push( node * Node ){
		if( Node == nullptr || Node -> rev == 0 ) return;
		swap( Node -> l, Node -> r );
		if( Node -> l != nullptr ) Node -> l -> rev ^= 1;
		if( Node -> r != nullptr ) Node -> r -> rev ^= 1;
		Node -> rev = 0;
	}

	inline void update( node * Node ) {
		if ( Node == nullptr )
			Node -> cnt = 0;
		else {
			Node -> sum = Node -> x;
			Node -> cnt = 1;
			if ( Node -> l != nullptr ){
				Node -> sum = Node -> sum + Node -> l -> sum;
				Node -> cnt += cnt( Node -> l );
			}
			if ( Node -> r != nullptr ){
				Node -> sum = Node -> sum + Node -> r -> sum;
				Node -> cnt += cnt( Node -> r );
			}
		}
	}

	node * find( node * Node, T x ) {
		if ( Node == nullptr )
			return nullptr;
		if ( Node -> x == x )
			return Node;
		if ( Node -> x < x )
			return find( Node -> r, x );
		return find( Node -> l, x );
	}

	inline int size( ) { return root == nullptr ? 0 : root -> cnt; }
	inline bool empty( ) { return size(); }
	inline void clear( ) { root = nullptr; }
	inline int cnt( node * Node ) { return Node == nullptr ? 0 : Node -> cnt; }
	int count( T x ) { return find( root, x ) != nullptr; }
	node * find( T x ) { return find( root, x ); }

};



void solution( istream &cin, ostream &cout, const int &test_case )
{
    string s;
    cin >> s;
    treap<int> tr;
    for( int i = 0; i < s.size(); i++ ){
        tr.insert( i, s[i] );
    }    
    vector<int> v;
    for( int i = 0; i < s.size(); i++ ){
        if( i + 1 < s.size() && s[i + 1] != s[i] || i && s[i - 1] != s[i] ){
            v.push_back( i );
        }  
    }
    print( v );
    int ret = 0;
    while( true ){
        vector<int> dels;
        for( int i = v.size() - 1; i >= 0; i-- ){
            if( v[i] && tr[v[i]] != tr[v[i] - 1] || v[i] + 1 < tr.size() && tr[v[i]] != tr[v[i] + 1] ){
                dels.push_back( v[i] );
            }
        }
        if( dels.empty() ) break;
        set<int> st;
        for( int i = 0; i < dels.size(); i++ ){
            tr.erase( dels[i] );
            int d = dels.size() - i - 1;
            if( dels[i] < tr.size() ){
                st.insert( dels[i] - d );
            }
            if( i == dels.size() - 1 && dels[i] || i + 1 < dels.size() && dels[i + 1] + 1 != dels[i] ){
                st.insert( dels[i] - 1 - d );
            }
        }
        v.clear();
        for( int i: st ) v.push_back( i );
        ret++;
    }
    cout << ret << endl;
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