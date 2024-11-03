#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cctype> 

#include <ctime>
#include <cmath>

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

#include <map>
#include <tuple>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <string>

#include <limits>
#include <utility>
#include <memory>

#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>













typedef          long long int  int64;
typedef unsigned long long int uint64;

#ifndef M_PI
#define M_PI 3.14159265358979323846L
#endif

#define DOUBLE_INF std::numeric_limits< double >::infinity()
#define DOUBLE_NAN std::numeric_limits< double >::quiet_NaN()

#define __STR__(a) #a
#define STR(a) __STR__(a)

#define ASSERT(expr, msg) \
    if (!( expr )) \
        throw std::runtime_error(__FILE__ ":" STR(__LINE__) " - " msg);

#ifdef BUG
    #define DEBUG(var) { std::cout << #var << ": " << (var) << std::endl; }
    #define COND_DEBUG(expr, var) if (expr) \
        { std::cout << #var << ": " << (var) << std::endl; }
    #define EXPECT(expr) if ( ! (expr) ) std::cerr << "Assertion " \
        << #expr " failed at " << __FILE__ << ":" << __LINE__ << std::endl;
#else
    #define DEBUG(var)
    #define COND_DEBUG(expr, var)
    #define EXPECT(expr)
#endif

#define DBG(v) std::copy( v.begin(), v.end(), std::ostream_iterator < typeof( *v.begin() )> ( std::cout, " " ) )

#if __cplusplus < 201100
    #define move( var ) var
#endif


#define SSTR( val ) dynamic_cast< std::ostringstream & >( std::ostringstream() << std::dec << val ).str()

using namespace std;


class ScopeTimer;



template < typename T >
struct abs_diff : binary_function < T, T, T >
{
    typedef T value_type;

    inline value_type operator( ) ( const value_type & x, const value_type & y ) const
    {
        return abs( x - y );
    }
};

template < typename value_type, typename cont_type >
class isin : public unary_function < value_type, bool >
{
    public:
        isin( const cont_type & vals ): m_vals ( vals ) { };

        bool operator ( ) ( const value_type & x ) const
        {
            return find ( m_vals.begin( ), m_vals.end( ), x ) != m_vals.end( );
        }

    private:
        const cont_type m_vals;
};


template < class T1, class T2, class BinaryOperation >
class Apply2nd : std::binary_function < typename std::pair < T1, T2 >,
                                        typename std::pair < T1, T2 >,
                                        typename BinaryOperation::result_type >
{
    public:
        typedef T1 first_type;
        typedef T2 second_type;

        typedef typename BinaryOperation::result_type result_type;
        typedef typename std::pair < first_type, second_type > value_type;

        inline result_type operator( ) ( const value_type & x, const value_type & y ) const
        {
            return binary_op ( x.second , y.second );
        }
    private:
        BinaryOperation binary_op;
};





template < class InputIterator >
typename iterator_traits<InputIterator>::difference_type
count_inv ( InputIterator first, InputIterator last )
{
    typedef typename iterator_traits<InputIterator>::difference_type difference_type;
    typedef typename iterator_traits<InputIterator>::value_type value_type;

    list < value_type > l; 
    difference_type cnt = 0;

    for ( difference_type n = 0; first != last; ++first, ++n )
    {
        
        typename list < value_type >::iterator iter = l.begin( );
        cnt += n;

        for ( ; iter != l.end( ) && * iter <= * first; ++ iter, -- cnt )
            ;
        l.insert( iter, * first );
    }

    return cnt;
}

template < class ForwardIterator, class T >
inline void fill_inc_seq ( ForwardIterator first, ForwardIterator last, T val )
{
    for ( ; first != last; ++first, ++val )
        * first = val;
}

template <class ForwardIterator, class InputIterator >
ForwardIterator remove ( ForwardIterator first, ForwardIterator last, InputIterator begin, InputIterator end )
{
    ForwardIterator result = first;

    for ( ; first != last; ++ first )
        if ( find ( begin, end, *first ) == end )
        {
            *result = *first;
            ++result;
        }

    return result;
}


template < class RAIter, class Compare >
class ArgSortComp
{
    public:
        ArgSortComp ( const RAIter & first, Compare comp ):  m_first ( first ), m_comp( comp ) { }
        inline bool operator() ( const size_t & i, const size_t & j ) const
        {
            return m_comp (  m_first[ i ] ,  m_first[ j ] );
        }
    private:
        const RAIter & m_first;
        const Compare m_comp;
};


template < class RAIter, class Compare=less< typename RAIter::value_type > >
void argsort( const RAIter & first,
              const RAIter & last,
              vector < size_t > & idx,
              Compare comp = Compare()) 

{
    const size_t n = last - first;
    idx.resize ( n );

    for ( size_t j = 0; j < n; ++ j )
        idx[ j ] = j ;

    stable_sort( idx.begin(), idx.end(), ArgSortComp< RAIter, Compare >( first, comp ));
}

template < class RAIter, class Compare >
class IterSortComp
{
    public:
        IterSortComp ( Compare comp ): m_comp ( comp ) { }
        inline bool operator( ) ( const RAIter & i, const RAIter & j ) const
        {
            return m_comp ( * i, * j );
        }
    private:
        const Compare m_comp;
};


template <class INIter, class RAIter, class Compare>
void itersort ( INIter first, INIter last, vector < RAIter > & idx, Compare comp )
{
    
    idx.resize ( distance ( first, last ) );
    for ( typename vector < RAIter >::iterator j = idx.begin( ); first != last; ++ j, ++ first )
        * j = first;

    sort ( idx.begin( ), idx.end( ), IterSortComp< RAIter, Compare > (comp ) );
}




inline void erase ( string & str, const char & ch )
{
    binder2nd < equal_to < char > > isch ( equal_to< char >(), ch );
    string::iterator iter = remove_if ( str.begin(), str.end(), isch );
    str.erase ( iter, str.end() );
}

inline void erase ( string & str, const string & chrs )
{
    isin < char, string > isin_chrs ( chrs );
    string::iterator iter = remove_if ( str.begin(), str.end(), isin_chrs );
    str.erase ( iter, str.end() );
}

template < typename value_type>
inline string val2str ( const value_type & x )
{
    ostringstream sout ( ios_base::out );
    sout << x;
    return sout.str();
}

template < typename value_type>
inline value_type str2val ( const string & str )
{
    istringstream iss ( str, ios_base::in );
    value_type val;

    iss >> val;
    return val;
}

vector< string > tokenize ( const string & str, const char & sep )
{
    

    vector < string > res;
    string::const_iterator follow = str.begin(),
                                lead   = str.begin();

    while ( true )
    {
        while ( lead != str.end() && * lead != sep )
            ++ lead;

        res.push_back ( string( follow, lead ) );

        if ( lead != str.end () )
            follow = 1 + lead ++ ;
        else
            break;
    }

    return res;
}


void chunk ( const string::const_iterator first,
             const string::const_iterator last,
             const size_t k,
             const bool right_to_left,
             list < string > & str_list )
{
    str_list.clear( );

    if ( right_to_left )
        
        for ( string::const_iterator i, j = last; j != first; j = i )
        {
            i = first + k < j ? j - k : first;
            str_list.push_back ( string ( i, j ) );
        }
    else
        
        for ( string::const_iterator i = first, j; i != last; i = j )
        {
            j = i + k < last ? i + k : last;
            str_list.push_back ( string ( i, j ) );
        }
}


string & operator++( string & s )
{
    
    string::reverse_iterator j = find_if( s.rbegin( ), s.rend( ),
            bind2nd( less < char > ( ), 'z' ));

    if ( j != s.rend( ))
    {
        ++ *j;
        fill( s.rbegin( ), j, 'a' );
    }
    else
        s.assign( s.length( ) + 1, 'a' );

    return s;
}


inline bool starts_with( const string & a, const string & b )
{
    return !( a.size() < b.size() ||
        mismatch( begin(b), end(b), begin(a) ).first != end(b) );
}


auto get_prefix_tree( const vector< string > & word )
    -> vector< map< char, size_t > >
{
    typedef map< char, size_t > node;
    
    vector< node > tree(1);
    for( const auto & w: word )
    {
        
        size_t root = 0;
        for( const auto & a : w )
        {
            auto & ref = tree[ root ][ a ];
            if ( ref == 0 ) 
            {
                ref = tree.size();
                tree.push_back( node() );
            }
            root = ref;
        }
    }
    return tree;
}








class BigInteger
{
#if ULONG_MAX <= 1 << 32
    typedef long long unsigned val_type;
#else
    typedef long unsigned val_type;
#endif
    const static int WSIZE = 32;
    const static val_type BASE = 1LL << WSIZE;
    public:
    private:
        list < val_type > val;  
        bool pos;                    
};


template < typename value_type > inline
value_type gcd ( value_type a, value_type b )
{
    return ! b ? a : gcd( b, a % b );
}


template < class T >
void prime_factors( T n, map < T, size_t > & fac )
{
    for ( T k = 2; n > 1; ++ k )
        if ( ! ( n % k ) )
        {
            size_t & ref = fac[ k ];
            while ( ! ( n % k ) )
            {
                ++ ref;
                n /= k;
            }
        }
}


template < class T >
inline T absdiff( T a, T b )
{
    return a < b ? b - a : a - b;
}

namespace
{
    template < class T >
    pair < T, T > __extgcd ( const T & x0, const T & y0,
                                  const T & x1, const T & y1,
                                  const T & r0, const T & r1 )
    {
        const T q  = r0 / r1;
        const T r2 = r0 % r1;

        if ( ! ( r1 % r2 ) )
            return make_pair < T, T > ( x0 - q * x1, y0 - q * y1 );

        const T x2 = x0 - q * x1;
        const T y2 = y0 - q * y1;

        return __extgcd ( x1, y1, x2, y2, r1, r2 );
    }
}


template < class value_type > inline
pair < value_type, value_type > extgcd ( value_type a, value_type b )
{
    return a % b
        ? __extgcd < value_type > ( 1, 0, 0, 1, a, b )
        : make_pair < value_type, value_type > ( 0, 1 );
}



template < class value_type > inline
value_type modinv ( value_type a, value_type m )
{
    const pair < value_type, value_type > coef ( extgcd( a, m ) );

    
    if ( a * coef.first + m * coef.second != 1 )
        throw runtime_error ( val2str( a ) + " is not coprime to " + val2str( m ));

    
    return ( m + coef.first % m ) % m;
}

inline bool isnan ( const double & a ) { return ! ( a == a ); }

template < typename value_type >
inline value_type mini ( int n, ... )
{
    va_list vl;
    va_start (vl, n);
    value_type res = va_arg ( vl, value_type );

    for ( int i = 1; i < n; ++i ) {
        const value_type val = va_arg ( vl, value_type );
        res = min ( res, val );
    }

    va_end( vl );
    return res;
}

template < typename value_type >
inline value_type maxi ( int n, ... )
{
    va_list vl;
    va_start (vl, n);
    value_type res = va_arg ( vl, value_type );

    for ( int i = 1; i < n; ++i ) {
        const value_type val = va_arg ( vl, value_type );
        res = max ( res, val );
    }

    va_end( vl );
    return res;
}



template < class T >
inline int sign ( const T & x )
{
    if ( x == T() )
        return 0;
    else if ( x < T() )
        return -1;
    else
        return 1;
}


string chmod ( string num, const unsigned n, const unsigned m )
{
    const char * digit = "0123456789abcdefghijklmnopqrstuvwxyz";
    transform ( num.begin(), num.end(), num.begin(), ::tolower );

    isin < char, string > is_alpha_num ( digit );
    assert ( find_if ( num.begin( ), num.end( ), not1 ( is_alpha_num ) ) == num.end( ));

    unsigned long long int val ( 0 );

    if ( n == 10U )
    {
        istringstream iss ( num, ios_base::in );
        iss >> val;
    }
    else
        for ( string::const_iterator iter = num.begin( ); iter != num.end( ); ++ iter )
            val = val * n + ( 'a' <= *iter ? *iter - 'a' + 10U : *iter - '0');

    if ( m == 10U )
    {
        ostringstream sout ( ios_base::out );
        sout << val;
        return sout.str ( );
    }
    else
    {
        string res;
        for ( ; val ; val /= m )
            res.push_back( digit [ val % m ] );

        return res.length( ) ? string( res.rbegin( ), res.rend( )) : "0";
    }
}

template < class value_type >  
value_type powmod ( value_type a, const value_type & n, const value_type & m )
{
    if ( a == 1 || ! n )
        return m != 1 ? 1 : 0;

    value_type res = 1;
    for ( value_type k = 1; k <= n; a = a * a % m, k = k << 1 )
        if ( k & n )
            res =  ( res * a ) % m;

    return res;
}

template < class T >
inline T atan(const T & x, const T & y) { return atan( y / x ) + ( x < 0 ) * M_PI; }


inline bool is_pseudo_prime ( const long long & a )
{
    
    const long long p [ ] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,
                              79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,
                              163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,
                              241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,
                              337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,
                              431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,
                              521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,
                              617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,
                              719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,
                              823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,
                              929,937,941,947,953,967,971,977,983,991,997 };

    const size_t n = sizeof( p ) / sizeof ( p[ 0 ] );

    if ( a < p[ n - 1 ] + 1)
        return binary_search ( p, p + n , a );

    if ( find_if ( p, p + n, not1 ( bind1st ( modulus< long long >( ), a ))) != p + n )
        return false;

    const size_t k = a <    9006401LL ? 3 :
                     a <   10403641LL ? 4 :
                     a <   42702661LL ? 5 :
                     a < 1112103541LL ? 6 : 7;

    for ( size_t j = 0; j < k; ++ j )
        if ( powmod ( p[ j ], a - 1, a ) != 1 )
            return false;

    return true;
}



template < typename value_type >
vector < value_type > get_primes ( const value_type n )
{
#ifdef BUG
    ScopeTimer scope_timer ( "vector < value_type > get_primes ( const value_type n )" );
#endif

    

    vector < value_type > primes;

    for ( value_type k = 2 ; k <= n; ++ k )
        if ( is_pseudo_prime ( k ) )
        {
            

            

            


            

            


            primes.push_back ( k );
        }

    return primes;
}


































template < class T >  
vector < pair < T, size_t > > get_prime_fac( T a )
{
    vector < pair < T, size_t > > fac;

    size_t k = 0;
    while (!(a % 2)) { a /= 2; ++ k; }
    if ( k != 0 ) fac.push_back( make_pair(2, k));

    k = 0;
    while (!(a % 3)) { a /= 3; ++ k; }
    if ( k != 0 ) fac.push_back( make_pair(3, k));

    for ( T j = 5; j * j < a + 1 && a > 1 && j < a + 1; j += 4 )
    {
        size_t k = 0;
        while (!(a % j)) { a /= j; ++ k; }
        if ( k != 0 ) fac.push_back( make_pair(j, k));

        j += 2; k = 0;
        while (!(a % j)) { a /= j; ++ k; }
        if ( k != 0 ) fac.push_back( make_pair(j, k));
    }

    if ( a > 1 ) fac.push_back( make_pair(a, 1));
    return fac;
}

template < class T > 
void gen_div( T a, vector < T > & divs,
        typename vector < pair < T, size_t > >::const_iterator iter,
        typename vector < pair < T, size_t > >::const_iterator last )
{
    if ( iter != last )
    {
        auto next = iter + 1;
        const auto k = iter->second + 1;
        const auto prime = iter->first;
        for ( size_t j = 0; j < k; ++ j )
        {
            gen_div(a, divs, next, last);
            a *= prime;
        }
    }
    else
        divs.push_back( a );
}



template < class T >
T n_choose_k ( T n, T k )
{
    if ( k > n )
        return 0;

    const T lb = min ( k, n - k ) + 1;
    const T ub = n - lb + 1;

    T res = 1, j = 2;
    while ( n > ub && j < lb)
    {
        res *= n--;
        while ( j < lb and ! (res % j) )
            res /= j++;
    }

    while ( n > ub )
        res *= n--;

    return res;
}



template < class InputIter >
inline pair < typename InputIter::value_type, typename InputIter::value_type >
median ( InputIter first, InputIter last )
{
    typedef typename InputIter::value_type      value_type;
    typedef pair< value_type, value_type > result_type;

    
    vector < value_type > max_heap, min_heap;

    
    less    < value_type > max_heap_comp;
    greater < value_type > min_heap_comp;

    if ( first == last )  
        throw runtime_error ( "median of an empty vector is undefined!" );

    InputIter iter = first;
    max_heap.push_back ( * iter );

    for ( ++iter ; iter != last; ++ iter )
        if ( * iter < max_heap.front() )
        {
            max_heap.push_back ( * iter );
            push_heap ( max_heap.begin(), max_heap.end(), max_heap_comp );

            if ( min_heap.size() + 1 < max_heap.size() )
            {
                
                min_heap.push_back( max_heap.front() );
                push_heap( min_heap.begin(), min_heap.end(), min_heap_comp );

                pop_heap( max_heap.begin(), max_heap.end(), max_heap_comp );
                max_heap.pop_back();
            }
        }
        else
        {
            min_heap.push_back ( * iter );
            push_heap ( min_heap.begin(), min_heap.end(), min_heap_comp );

            if ( max_heap.size() + 1 < min_heap.size() )
            {
                
                max_heap.push_back( min_heap.front() );
                push_heap( max_heap.begin(), max_heap.end(), max_heap_comp );

                pop_heap( min_heap.begin(), min_heap.end(), min_heap_comp );
                min_heap.pop_back();
            }
        }

    DEBUG( max_heap );
    DEBUG( min_heap );

    return min_heap.empty( )  
        ? result_type ( *first, *first )
        : result_type ( max_heap.size() < min_heap.size() ? min_heap.front() : max_heap.front(),
                        min_heap.size() < max_heap.size() ? max_heap.front() : min_heap.front() );
}



struct xyPoint
{
    double x, y;
    xyPoint( const double & a = .0, const double & b = .0 ): x ( a ), y( b ) { };
};


struct xyCircle
{
    xyPoint center;
    double radius;
};

ostream & operator<< ( ostream & out, const xyPoint & p )
{
    out << '(' << p.x << ", " << p.y << ')';
    return out;
}

istream & operator>> ( istream & ist, xyPoint & p )
{
    ist >> p.x >> p.y;
    return ist;
}

ostream & operator<< ( ostream & out, const xyCircle & o )
{
    out << "{(" << o.center.x << ", " << o.center.y << ") " << o.radius << '}';
    return out;
}

istream & operator>> ( istream & ist, xyCircle & o )
{
    ist >> o.center.x >> o.center.y >> o.radius;
    return ist;
}

inline double cartesian_dist ( const xyPoint & a, const xyPoint & b )
{
    const double d = a.x - b.x;
    const double e = a.y - b.y;
    return sqrt ( d * d + e * e );
}

class xyLine
{
    public:
        xyLine ( const xyPoint & , const xyPoint & );
        xyLine ( const double slope, const double intercept );

        
        inline double orth_dist ( const xyPoint & ) const;
    private:
        double m_slope;
        double m_intercept;
        double m_normfac;   

        bool   m_vertical;  
        double m_xcross;    
};

xyLine::xyLine ( const xyPoint & a, const xyPoint & b )
{
    if ( a.x == b.x )  
    {
        m_vertical  = true;
        m_xcross    = a.x;

        m_intercept = DOUBLE_NAN;
        m_slope     = DOUBLE_INF;
        m_normfac   = DOUBLE_NAN;
    }
    else
    {
        m_vertical  = false;
        m_xcross    = DOUBLE_NAN;

        m_slope     = ( b.y - a.y ) / ( b.x - a.x );
        m_intercept = a.y - m_slope * a.x;
        m_normfac   = sqrt ( m_slope * m_slope + 1.0 );
    }
}

xyLine::xyLine ( const double slope, const double intercept ):
    m_slope ( slope ),  m_intercept ( intercept )
{
     m_vertical = false;
     m_xcross   = DOUBLE_NAN;
     m_normfac  = sqrt ( m_slope * m_slope + 1.0 );
}

double xyLine::orth_dist ( const xyPoint & o ) const 
{
    if ( m_vertical )
        return o.x - m_xcross;
    else
        return ( m_slope * o.x - o.y + m_intercept ) / m_normfac;
}

inline double triangle_area ( const xyPoint & a, const xyPoint & b, const xyPoint & c )
{
    const xyLine l ( a, b );
    const double h = abs ( l.orth_dist ( c ) );
    const double e = cartesian_dist ( a, b );
    return h * e;
}



namespace
{
    
    template < typename T >
    ostream & __output ( ostream & out, const T & a )
    {
        typedef typename T::const_iterator const_iterator;
        out << "{ ";

        

        


        for ( const_iterator iter = a.begin(); iter != a.end(); ++ iter )
             out << ( iter != a.begin( ) ? ", " : "" ) << *iter ;

        return out << " }";
    }
}

template < typename key_type, typename value_type >
ostream & operator<< ( ostream & out, const pair < key_type, value_type > & p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template < typename T0, typename T1, typename T2 >
ostream & operator<< ( ostream & out, const tuple < T0, T1, T2 > & t )
{
    out << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")";
    return out;
}

template < typename T0, typename T1 >
ostream & operator<< ( ostream & out, const tuple < T0, T1 > & t )
{
    out << "(" << get<0>(t) << ", " << get<1>(t) << ")";
    return out;
}

template < typename key_type, typename value_type, typename comp >
ostream & operator<< ( ostream & out, const map < key_type, value_type, comp > & m )
{
    return __output ( out, m );
}

template < typename value_type, typename comp >
ostream & operator<< ( ostream & out, const set < value_type, comp > & s )
{
    return __output ( out, s );
}

template < typename value_type >
ostream & operator<< ( ostream & out, const vector < value_type > & a )
{
    return __output ( out, a );
}

template < typename value_type >
ostream & operator<< ( ostream & out, const list < value_type > & a )
{
    return __output ( out, a );
}

template < typename value_type >
ostream & operator<< ( ostream & out, const vector < vector < value_type > > & a )
{
    typedef typename vector < vector < value_type > >::const_iterator const_iterator;

    for ( const_iterator iter = a.begin( ); iter != a.end( ); ++ iter )
        out << '\n' << *iter ;

    return out;
}



template < typename key_type, typename value_type >
istream & operator>> ( istream & in, pair < key_type, value_type > & p)
{
    in >> p.first >> p.second;
    return in;
}

template < typename T0, typename T1, typename T2 >
istream & operator>> ( istream & fin, tuple < T0, T1, T2 > & t )
{
    fin >> get<0>(t) >> get<1>(t) >> get<2>(t);
    return fin;
}

template < typename value_type >
istream & operator>> ( istream & in, vector < value_type > & a )
{
    typedef typename vector < value_type >::iterator iterator;

    if ( ! a.size( ) )
    {
        size_t n;
        in >> n;
        a.resize( n );
    }

    for ( iterator iter = a.begin(); iter != a.end(); ++ iter )
        in >> * iter;

    return in;
}










































template < typename T1, typename T2 >
inline pair < T1, T2 > operator+ ( const pair < T1, T2 > & a, const pair < T1, T2 > & b )
{
    return make_pair < T1, T2 > ( a.first + b.first, a.second + b.second );
}

template < typename T1, typename T2 >
inline pair < T1, T2 > operator- ( const pair < T1, T2 > & a, const pair < T1, T2 > & b )
{
    return make_pair < T1, T2 > ( a.first - b.first, a.second - b.second );
}










namespace
{
    
    template < size_t J, class T1, class T2 >
    struct Get;

    template < class T1, class T2 >
    struct Get < 0, T1, T2 >
    {
        typedef typename pair < T1, T2 >::first_type result_type;

        static       result_type & elm (       pair < T1, T2 > & pr ) { return pr.first; }
        static const result_type & elm ( const pair < T1, T2 > & pr ) { return pr.first; }
    };

    template < class T1, class T2 >
    struct Get < 1, T1, T2 >
    {
        typedef typename pair < T1, T2 >::second_type result_type;

        static       result_type & elm (       pair < T1, T2 > & pr ) { return pr.second; }
        static const result_type & elm ( const pair < T1, T2 > & pr ) { return pr.second; }
    };
}

template < size_t J, class T1, class T2 >
typename Get< J, T1, T2 >::result_type & get ( pair< T1, T2 > & pr )
{
    return Get < J, T1, T2 >::elm( pr );
}

template < size_t J, class T1, class T2 >
const typename Get< J, T1, T2 >::result_type & get ( const pair< T1, T2 > & pr )
{
    return Get < J, T1, T2 >::elm( pr );
}




void get_indist( const size_t root,
        const vector < vector < size_t > > & tree,
        vector < tuple< size_t, size_t > > & indist )
{
    const auto NIL = numeric_limits< size_t >::max();
    size_t a = 0, b = NIL;

    for ( const auto u: tree[ root ] )
    {
        get_indist( u, tree, indist );
        if ( a < 1 + get< 0 >( indist[ u ] ) )
        {
            b = a;
            a = 1 + get< 0 >( indist[ u ] );
        }
        else
            b = b != NIL
                ? max( b, 1 + get< 0 >( indist[ u ] ))
                : 1 + get< 0 >( indist[ u ] );
    }

    indist[ root ] = make_tuple(a, b);
}


void get_outdist( const size_t root,
        const vector< vector< size_t > > & tree,
        const vector< tuple< size_t, size_t > > & indist,
        vector < size_t > & outdist )
{
    const auto NIL = numeric_limits< size_t >::max();

    for( const auto u: tree[ root ] )
    {
        if ( 1 + get< 0 >( indist[ u ] ) == get< 0 >( indist[ root ] ) )
            outdist[ u ] = get< 1 >( indist[ root ] ) != NIL
                ? 1 + max( get< 1 >( indist[ root ] ), outdist[ root ] )
                : 1 + outdist[ root ];
        else
            outdist[ u ] = 1 +
                max( get< 0 >( indist[ root ] ), outdist[ root ] );

        get_outdist( u, tree, indist, outdist );
    }
}



template < typename DistType >
void Dijekstra ( const size_t & source,
                 const vector < list < size_t > > & adj,          

                 const vector < vector < DistType > > & edge_len, 

                 vector < DistType > & dist,  

                 vector < size_t > prev )     

{
    

}







class HopcroftKarp
{
    public:
        HopcroftKarp ( const vector < list < size_t > > & adj,
                       const vector < bool > & tag );

        size_t get_npair ( ) { return npair; };
        map < size_t, size_t > get_map ( );

    private:
        bool mf_breadth_first_search ( );  

        bool mf_depth_first_search ( const size_t v ); 


        const vector < list < size_t > > & m_adj;  

        const vector < bool > & m_tag;  


        size_t npair;
        const size_t NIL;  

        const size_t INF;  


        vector < size_t > m_g1;    

        vector < size_t > m_dist;  

        vector < size_t > m_pair;
};


map < size_t, size_t > HopcroftKarp::get_map ( )
{
    map < size_t, size_t > m;

    for ( size_t j = 0; j < m_pair.size( ); ++ j )
        if ( m_pair[ j ] != NIL  && m_tag[ j ])
            m[ j ] = m_pair[ j ];

    return m;
}


HopcroftKarp::HopcroftKarp ( const vector < list < size_t > > & adj,
                             const vector < bool > & tag ):
    m_adj ( adj ),
    m_tag ( tag ),
    npair ( 0 ),
    NIL ( adj.size( )),
    INF ( adj.size( ) + 1 ),
    m_dist ( vector < size_t > ( adj.size( ) + 1, INF)),
    m_pair ( vector < size_t > ( adj.size( ), NIL ))  

{
    assert ( m_adj.size() == m_tag.size() );

    for ( size_t j = 0; j < tag.size( ); ++ j )
        if ( tag[ j ] )
            m_g1.push_back ( j );

    while ( mf_breadth_first_search ( ) )
        for ( vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++ v )
            if ( m_pair[ *v ] == NIL && mf_depth_first_search ( *v ) )
                ++ npair;
}

bool HopcroftKarp::mf_breadth_first_search( )
{
    
    queue < size_t > bfs_queue;

    
    for ( vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++v )
        if ( m_pair[ *v ] == NIL )
        {
            m_dist[ *v ] = 0;
            bfs_queue.push ( *v );
        }
        else
            m_dist[ *v ] = INF;

    m_dist[ NIL ] = INF;

    
    while ( ! bfs_queue.empty() )
    {
        const size_t v = bfs_queue.front( );
        bfs_queue.pop ( );

        if ( m_dist[ v ] < m_dist[ NIL ] )
            for ( list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
                if ( m_dist[ m_pair[ * u ] ] == INF )
                {
                    m_dist[ m_pair[ * u ] ] = m_dist[ v ] + 1;
                    bfs_queue.push ( m_pair[ * u ] );
                }
    }

    return m_dist[ NIL ] != INF;
}


bool HopcroftKarp::mf_depth_first_search( const size_t v )
{
    if ( v == NIL )
        return true;
    else
    {
        for ( list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
            if ( m_dist[ m_pair[ *u ] ] == m_dist[ v ] + 1  && mf_depth_first_search( m_pair[ *u ] ))
            {
                
                m_pair [ *u ] = v;
                m_pair [  v ] = *u;
                return true;
            }
        m_dist[ v ] = INF;
        return false;
    }
}



class All_Pairs_Tree_Shortest_Path
{
    public:
        All_Pairs_Tree_Shortest_Path( const vector< list < size_t > > & adj ):
            n( adj.size( ) ),
            depth( vector < size_t > ( n, All_Pairs_Tree_Shortest_Path::INF ) ),
            parent( vector < size_t > ( n ) ),
            dist( vector < vector < unsigned short > > ( n ) )
        {

            
            
            queue< size_t > bfs_queue;
            bfs_queue.push( 0 );
            depth[ 0 ]  = 0;
            parent[ 0 ] = 0;

            while ( ! bfs_queue.empty( ) )
            {
                const size_t u = bfs_queue.front( );
                bfs_queue.pop( );

                for ( list< size_t >::const_iterator j = adj[ u ].begin( ); j != adj[ u ].end( ); ++ j )
                    if ( depth[ u ] + 1 < depth[ *j ] )
                    {
                        depth[ *j ]  = depth[ u ] + 1;
                        parent[ *j ] = u;
                        bfs_queue.push( *j );
                    }
            }

            
            for ( size_t j = 1; j < n; ++ j )
                dist[ j ].resize( j, All_Pairs_Tree_Shortest_Path::INF );
        }

        
        size_t operator( )( const size_t u, const size_t v )
        {
            if ( u == v )
                return 0;
            else if ( u < v)
                return (*this)( v, u );
            else if ( dist[ u ][ v ] == All_Pairs_Tree_Shortest_Path::INF )
            {
                if ( depth[ u ] < depth[ v ] )
                    
                    dist[ u ][ v ] = 1 + (*this)( u, parent[ v ]);
                else if ( depth[ v ] < depth[ u ] )
                    
                    dist[ u ][ v ] = 1 + (*this)( parent[ u ], v );
                else
                    
                    dist[ u ][ v ] = 2 + (*this)( parent[ u ], parent[ v ] );
           }
            return dist[ u ][ v ];
        }

        

    private:
            
            static const unsigned short INF;

            const size_t n;                 
            vector < size_t > depth;   
            vector < size_t > parent;  
            vector < vector < unsigned short > > dist; 
};

const unsigned short All_Pairs_Tree_Shortest_Path::INF = numeric_limits< unsigned short >::max( );



template < class T, class Comp = less< T > >
class Heap  
{
    typedef T value_type;
    typedef typename vector < value_type >::size_type size_type;
    public:
        
        Heap(): m_val( vector < value_type >() ), m_comp( Comp() ) {}

        template < class InputIter >
        Heap ( InputIter first, InputIter last ):
            m_val ( vector < value_type > ( ) ), m_comp( Comp( ) )
        {
            for ( ; first != last ; ++ first )
                m_val.push_back ( * first );

            make_heap( m_val.begin( ), m_val.end( ), m_comp );
        }

        
        inline const value_type & front( ) const { return m_val.front( ); }
        inline bool empty( ) const { return m_val.empty( ); }
        inline size_type size( ) const { return m_val.size( );  }

        inline void push ( const value_type & a )
        {
            m_val.push_back( a );
            push_heap( m_val.begin( ), m_val.end( ), m_comp );
        }
        inline void pop( )
        {
            pop_heap ( m_val.begin( ), m_val.end( ), m_comp );
            m_val.pop_back( );
        }

        

        

        

        

    private:
        vector < value_type > m_val;
        const Comp m_comp;
};


class UnionFind
{
    public:
        UnionFind( const size_t n ):
            parent ( vector < size_t > ( n ) ),   
            rank   ( vector < size_t > ( n, 0 ))  
        {
            for ( size_t j = 0; j < n; ++ j )
                parent[ j ] = j ;
        }

        inline size_t find( const size_t s )
        {
            
            const size_t p = parent[ s ];
            return parent[ p ] == p ? p : parent[ s ] = find( p ) ;
        }

        inline void lazy_union ( size_t i, size_t j )
        {
            
            i = find( i );
            j = find( j );

            if ( i != j )
            {
                if ( rank [ i ] < rank[ j ] )
                    parent[ i ] = j;
                else
                {
                    parent[ j ] = i;
                    rank[ i ]  += rank[ i ] == rank[ j ];
                }
            }
        }
    private:
        vector < size_t > parent;
        vector < size_t > rank;
};



























class ScopeTimer
{
    public:
        ScopeTimer ( const string & msg = "" ): tic ( clock ( )), m_msg( msg ) { };

        ~ ScopeTimer ( )
        {
            const clock_t toc = clock();
            const uint64 dt   = 1000L * ( toc - tic ) / CLOCKS_PER_SEC;

            const uint64 mil = dt % 1000L;
            const uint64 sec = ( dt / 1000L ) % 60L;
            const uint64 min = ( dt / 60000L ) % 60L;
            const uint64 hrs = ( dt / 3600000L );

            cout << '\n' << m_msg << "\n\telapsed time: ";

            if ( hrs )  cout << hrs << " hrs, ";
            if ( min )  cout << min << " min, ";
            if ( sec )  cout << sec << " sec, ";
            cout << mil << " mil-sec\n";
        }

    private:
        typedef unsigned long long int  uint64;
        const clock_t tic;
        const string m_msg;
};

class RandInt
{
    public:
        RandInt ( int a = 0, int b = 100 ): m ( a ), f ( static_cast < double > ( b - a ) / RAND_MAX ) { }
        inline int operator() ( ) { return m + ceil ( f * rand( ) ); }
    private:
        const int m;
        const double f;
};


class RandDouble
{
    public:
        RandDouble ( double a = 0.0, double b = 1.0 ): m ( a ), f ( ( b - a ) / RAND_MAX ) { }
        inline double operator() ( ) { return m + f * rand( ); }
    private:
        const double m, f;
};

class Noisy
{
    public:
        Noisy ( string str ): msg ( str )
        {
            cout << " Noisy ( " << msg << " )\t@ " << this << endl;
        }
        ~Noisy ( )
        {
            cout << "~Noisy ( " << msg << " )\t@ " << this << endl;
        }
        void beep ( )
        {
            cout << " beep ( " << msg << " )\t@ " << this << endl;
        }
        void beep ( ) const
        {
            cout << " const beep ( " << msg << " )\t@ " << this << endl;
        }
    private:
        const string msg;
};



size_t a417()
{
    size_t c, d, n, m, k;
    cin >> c >> d >> n >> m >> k;

    size_t w = n * m < k ? 0 : ( n * m - k + n - 1 ) / n;
    size_t val = static_cast< size_t >( -1 );

    for ( size_t j = 0; j < w + 1; ++ j )
    {
        const size_t f = k + j * n;
        const size_t i = n * m < f ? 0 : n * m - f;
        val = min( val, j * c + i * d );
    }

    return val;
}

int64 b2_177()
{
    int64 a;
    cin >> a;

    auto val = a;
    for ( auto pr: get_prime_fac( a ) )
        for ( size_t j = 0; j < pr.second; ++ j )
        {
            a /= pr.first;
            val += a;
        }

    return val;
}

void c53()
{
    int n;
    cin >> n;

    cout << 1;
    for ( int pos = 1, jump = n - 1; jump != 0; )
    {
        pos += jump;
        cout << ' ' << pos;
        jump = ( jump > 0 ? 1 : -1 ) - jump;
    }
}

inline size_t getn( const int k )
{
    int n = 1 + pow(k * 6, 1.0 / 3.0 );
    while ( ( n + 1 ) * n * ( n - 1 ) < 1 + k * 6 )
        ++ n;
    return n;
}

void b413()
{
    size_t n, m, k;
    cin >> n >> m >> k;

    vector < vector < size_t > > room( m );
    for( size_t i = 0; i < n; ++ i )
        for ( size_t j = 0; j < m ; ++ j )
        {
            size_t u;
            cin >> u;
            if ( u == 1 )
                room[ j ].push_back( i );
        }

    vector < pair < size_t, size_t > > event( k );
    cin >> event;

    transform( begin(event), end(event), begin(event),
               []( const pair< size_t, size_t > & pr )
               { return pr - pair< size_t, size_t>(1, 1); });

    vector < int64 > notf( n ), room_notf( m );
    for( const auto & pr: event )
    {
        ++ room_notf[ pr.second ];
        -- notf[ pr.first ];
    }

    for( size_t j = 0; j < m; ++ j )
        for ( const auto & i: room[ j ] )
            notf[ i ] += room_notf[ j ];

    copy( begin( notf ), end( notf ),
          ostream_iterator< size_t >( cout, " "));
}

size_t b22()
{
    size_t n, m;
    cin >> n >> m;
    vector < string > grid( n );
    cin >> grid;

    vector < vector < size_t > > xs( n + 1,
            vector < size_t >( m + 1, 0 ));

    for( size_t i = 1; i < n + 1; ++ i )
        for( size_t j = 1; j < m + 1; ++ j )
            xs[ i ][ j ] = xs[ i - 1 ][ j ]
                + xs[ i ][ j - 1 ]
                - xs[ i - 1 ][ j - 1 ]
                + ( grid[ i - 1][ j - 1] == '1' ? 1 : 0 );

    DEBUG( xs );

    size_t val = 0;
    for( size_t i = 0; i < n + 1; ++ i )
        for( size_t j = i + 1; j < n + 1; ++ j )
            for( size_t l = 0; l < m + 1; ++ l )
                for( size_t k = l + 1; k < m + 1; ++ k )
                    if ( xs[ j ][ k ] + xs[ i ][ l ]
                            - xs[ i ][ k ] - xs[ j ][ l ] == 0 )
                        val = max(val, j + k - i - l);

    return 2 * val;
}


int main ( const int argc, char * argv [ ])
{
    cout << b22();
    


    return EXIT_SUCCESS;
}


