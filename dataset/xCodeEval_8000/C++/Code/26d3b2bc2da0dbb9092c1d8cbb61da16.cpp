#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cctype> 

#include <ctime>
#include <cmath>

#include <iostream>
#include <sstream>
#include <iomanip>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <string>

#include <limits>
#include <utility>

#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>








typedef          long long int int64;
typedef unsigned long long int uint64;

#define DOUBLE_INF std::numeric_limits< double >::infinity()
#define DOUBLE_NAN std::numeric_limits< double >::quiet_NaN()

#ifdef BUG
    #define DEBUG(var) { std::cout << #var << ": " << (var) << std::endl; }
#else
    #define DEBUG(var)
#endif

#define EXPECT(expr) if ( ! (expr) ) std::cerr << "Assertion " \
    << #expr " failed at " << __FILE__ << ":" << __LINE__ << std::endl;

#define DBG(v) std::copy( v.begin(), v.end(), std::ostream_iterator < typeof( *v.begin() )> ( std::cout, " " ) )


#define SSTR( val ) dynamic_cast< std::ostringstream & >( std::ostringstream() << std::dec << val ).str()











class ScopeTimer;



template < typename T >
struct abs_diff : std::binary_function < T, T, T >
{
    typedef T value_type;

    inline value_type operator( ) ( const value_type & x, const value_type & y ) const
    {
        return std::abs( x - y );
    }
};


































template < typename value_type, typename cont_type >
class isin : public std::unary_function < value_type, bool >
{
    public:
        isin( const cont_type & vals ): m_vals ( vals ) { };

        bool operator ( ) ( const value_type & x ) const
        {
            return std::find ( m_vals.begin( ), m_vals.end( ), x ) != m_vals.end( );
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



inline void erase ( std::string & str, const char & ch )
{
    std::binder2nd < std::equal_to < char > > isch ( std::equal_to < char > ( ), ch );
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), isch );
    str.erase ( iter, str.end() );
}

inline void erase ( std::string & str, const std::string & chrs )
{
    isin < char, std::string > isin_chrs ( chrs );
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), isin_chrs );
    str.erase ( iter, str.end() );
}

template < typename value_type>
inline std::string val2str ( const value_type & x )
{
    std::ostringstream sout ( std::ios_base::out );
    sout << x;
    return sout.str();
}

template < typename value_type>
inline value_type str2val ( const std::string & str )
{
    std::istringstream iss ( str, std::ios_base::in );
    value_type val;

    iss >> val;
    return val;
}

std::vector< std::string > tokenize ( const std::string & str, const char & sep )
{
    

    std::vector < std::string > res;
    std::string::const_iterator follow = str.begin( ),
                                lead   = str.begin( );

    while ( true )
    {
        while ( lead != str.end() && * lead != sep )
            ++ lead;

        res.push_back ( std::string( follow, lead ) );

        if ( lead != str.end ( ) )
            follow = 1 + lead ++ ;
        else
            break;
    }

    return res;
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
        std::list < val_type > val;  
        bool pos;                    
};

template < typename value_type >  

inline value_type gcd ( const value_type & m, const value_type & n )
{
    value_type a = std::max ( std::abs( m ), std::abs( n ) );
    value_type b = std::min ( std::abs( m ), std::abs( n ) );

    
    if ( ! b )   return a;

    for ( value_type res = a % b; res ; res = a % b )
    {
        a = b;
        b = res;
    }

    return b;
}

inline bool isnan ( const double & a )
{
    return ! ( a == a );
}

template < typename value_type >
inline value_type mini ( int n, ... )
{
    va_list vl;
    va_start (vl, n);
    value_type res = va_arg ( vl, value_type );

    for ( int i = 1; i < n; ++i ) {
        const value_type val = va_arg ( vl, value_type );
        res = std::min ( res, val );
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
        res = std::max ( res, val );
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


std::string chmod ( std::string num, const unsigned n, const unsigned m )
{
    const char * digit = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::transform ( num.begin(), num.end(), num.begin(), tolower );

    isin < char, std::string > is_alpha_num ( digit );
    assert ( find_if ( num.begin( ), num.end( ), std::not1 ( is_alpha_num ) ) == num.end( ));

    unsigned long long int val ( 0 );

    if ( n == 10U )
    {
        std::istringstream iss ( num, std::ios_base::in );
        iss >> val;
    }
    else
        for ( std::string::const_iterator iter = num.begin( ); iter != num.end( ); ++ iter )
            val = val * n + ( 'a' <= *iter ? *iter - 'a' + 10U : *iter - '0');

    if ( m == 10U )
    {
        std::ostringstream sout ( std::ios_base::out );
        sout << val;
        return sout.str ( );
    }
    else
    {
        std::string res;
        for ( ; val ; val /= m )
            res.push_back( digit [ val % m ] );

        return res.length( ) ? std::string( res.rbegin( ), res.rend( )) : "0";
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
        return std::binary_search ( p, p + n , a );

    if ( std::find_if ( p, p + n, std::not1 ( std::bind1st ( std::modulus< long long >( ), a ))) != p + n )
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
std::vector < value_type > get_primes ( const value_type n )
{
#ifdef BUG
    ScopeTimer scope_timer ( "std::vector < value_type > get_primes ( const value_type n )" );
#endif

    typedef typename std::vector < value_type >::iterator iterator;
    std::vector < value_type > primes;

    for ( value_type k = 2 ; k <= n; ++ k )
        if ( is_pseudo_prime ( k ) )
        {
            const value_type sqrt_k = 1 + static_cast < value_type > ( sqrt ( k + 1 ) );
            iterator iend = upper_bound ( primes.begin( ), primes.end( ), sqrt_k );

            if ( find_if ( primes.begin( ), iend, std::not1 ( std::bind1st ( std::modulus< value_type >( ), k ) ) ) != iend )
                continue;

            primes.push_back ( k );
        }

    return primes;
}

template < class T >
inline std::list < std::pair < T, size_t > > get_prime_fact ( T a )
{
    std::list < std::pair < T, size_t > > fac;

    for ( T k = 2; a > 1; ++ k )
        if ( ! ( a % k ) )  

        {
            size_t m = 0;
            for ( ; ! ( a % k ) ; ++m, a/= k )
                ;

            fac.push_back ( std::pair < T, size_t > ( k, m ) );
        }
    return fac;
}


template < class T >
T n_choose_k ( T n, T k )
{
    if ( k > n )
        return 0;

    const T lb = std::min ( k, n - k ) + 1;
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



struct xyPoint
{
    double x, y;
    xyPoint ( const double & a = .0, const double & b = .0 ): x ( a ), y( b ) { };
};

std::ostream & operator<< ( std::ostream & out, const xyPoint & p )
{
    out << '(' << p.x << ", " << p.y << ')';
    return out;
}

std::istream & operator>> ( std::istream & ist, xyPoint & p )
{
    ist >> p.x >> p.y;
    return ist;
}

inline double cartesian_dist ( const xyPoint & a, const xyPoint & b )
{
    const double d = a.x - b.x;
    const double e = a.y - b.y;
    return std::sqrt ( d * d + e * e );
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
        m_normfac   = std::sqrt ( m_slope * m_slope + 1.0 );
    }
}

xyLine::xyLine ( const double slope, const double intercept ):
    m_slope ( slope ),  m_intercept ( intercept )
{
     m_vertical = false;
     m_xcross   = DOUBLE_NAN;
     m_normfac  = std::sqrt ( m_slope * m_slope + 1.0 );
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
    const double h = std::abs ( l.orth_dist ( c ) );
    const double e = cartesian_dist ( a, b );
    return h * e;
}



namespace
{
    
    template < typename T >
    std::ostream & __output ( std::ostream & out, const T & a )
    {
        typedef typename T::const_iterator const_iterator;
        out << "{ ";

        

        


        for ( const_iterator iter = a.begin(); iter != a.end(); ++ iter )
             out << ( iter != a.begin( ) ? ", " : "" ) << *iter ;

        return out << " }";
    }
}

template < typename key_type, typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::pair < key_type, value_type > & p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template < typename key_type, typename value_type, typename comp >
std::ostream & operator<< ( std::ostream & out, const std::map < key_type, value_type, comp > & m )
{
    return __output ( out, m );
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::set < value_type > & s )
{
    return __output ( out, s );
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::vector < value_type > & a )
{
    return __output ( out, a );
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::list < value_type > & a )
{
    return __output ( out, a );
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::vector < std::vector < value_type > > & a )
{
    typedef typename std::vector < std::vector < value_type > >::const_iterator const_iterator;

    for ( const_iterator iter = a.begin( ); iter != a.end( ); ++ iter )
        out << '\n' << *iter ;

    return out;
}



template < typename key_type, typename value_type >
std::istream & operator>> ( std::istream & in, std::pair < key_type, value_type > & p)
{
    in >> p.first >> p.second;
    return in;
}

template < typename value_type >
std::istream & operator>> ( std::istream & in, std::vector < value_type > & a )
{
    typedef typename std::vector < value_type>::iterator iterator;

    for ( iterator iter = a.begin(); iter != a.end(); ++ iter )
        in >> * iter;

    return in;
}



template < typename value_type >
std::vector < value_type > readin ( size_t n = 0 )
{
    if ( ! n ) std::cin >> n;
    std::vector < value_type > a ( n );

    std::cin >> a;
    return a;
}

template < typename key_type, typename value_type >
std::vector < std::pair < key_type , value_type > > readin ( size_t n = 0 )
{
    if ( !n ) std::cin >> n;
    std::vector < std::pair < key_type, value_type > > a ( n );

    std::cin >> a;
    return a;
}




template < typename T1, typename T2 >
inline std::pair < T1, T2 > operator+ ( const std::pair < T1, T2 > & a, const std::pair < T1, T2 > & b )
{
    return std::make_pair < T1, T2 > ( a.first + b.first, a.second + b.second );
}













template < typename DistType >
void Dijekstra ( const size_t & source,
                 const std::vector < std::list < size_t > > & adj,          

                 const std::vector < std::vector < DistType > > & edge_len, 

                 std::vector < DistType > & dist,  

                 std::vector < size_t > prev )     

{
    

}








class HopcroftKarp
{
    public:
        HopcroftKarp ( const std::vector < std::list < size_t > > & adj,
                       const std::vector < bool > & tag );

        size_t get_npair ( ) { return npair; };
        std::map < size_t, size_t > get_map ( );

    private:
        bool mf_breadth_first_search ( );  

        bool mf_depth_first_search ( const size_t v ); 


        const std::vector < std::list < size_t > > & m_adj;  

        const std::vector < bool > & m_tag;  


        size_t npair;
        const size_t NIL;  

        const size_t INF;  


        std::vector < size_t > m_g1;    

        std::vector < size_t > m_dist;  

        std::vector < size_t > m_pair;
};


std::map < size_t, size_t > HopcroftKarp::get_map ( )
{
    std::map < size_t, size_t > m;

    for ( size_t j = 0; j < m_pair.size( ); ++ j )
        if ( m_pair[ j ] != NIL  && m_tag[ j ])
            m[ j ] = m_pair[ j ];

    return m;
}


HopcroftKarp::HopcroftKarp ( const std::vector < std::list < size_t > > & adj,
                             const std::vector < bool > & tag ):
    m_adj ( adj ),
    m_tag ( tag ),
    npair ( 0 ),
    NIL ( adj.size( )),
    INF ( adj.size( ) + 1 ),
    m_dist ( std::vector < size_t > ( adj.size( ) + 1, INF)),
    m_pair ( std::vector < size_t > ( adj.size( ), NIL ))  

{
    assert ( m_adj.size() == m_tag.size() );

    for ( size_t j = 0; j < tag.size( ); ++ j )
        if ( tag[ j ] )
            m_g1.push_back ( j );

    while ( mf_breadth_first_search ( ) )
        for ( std::vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++ v )
            if ( m_pair[ *v ] == NIL && mf_depth_first_search ( *v ) )
                ++ npair;
}

bool HopcroftKarp::mf_breadth_first_search( )
{
    
    std::queue < size_t > bfs_queue;

    
    for ( std::vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++v )
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
            for ( std::list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
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
        for ( std::list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
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



template < class T, class Comp = std::less< T > >
class Heap  
{
    typedef T value_type;
    typedef typename std::vector < value_type >::size_type size_type;
    public:
        
        Heap ( ): m_val ( std::vector < value_type > ( ) ) , m_comp ( Comp( ) ){ }
        inline value_type & front ( ) { return m_val.front( ); }
        inline bool empty( ) const { return m_val.empty( ); }
        inline size_type size( ) const { return m_val.size( ); }
        inline void push ( const value_type & a )
        {
            m_val.push_back( a );
            std::push_heap( m_val.begin( ), m_val.end( ), m_comp );
        }
        inline void pop( )
        {
            std::pop_heap ( m_val.begin( ), m_val.end( ), m_comp );
            m_val.pop_back( );
        }
        

        

        

    private:
        std::vector < value_type > m_val;
        const Comp m_comp;
};








class ScopeTimer
{
    public:
        ScopeTimer ( const std::string & msg = "" ): tic ( clock ( )), m_msg( msg ) { };

        ~ ScopeTimer ( )
        {
            const clock_t toc = clock();
            const uint64 dt   = 1000L * ( toc - tic ) / CLOCKS_PER_SEC;

            const uint64 mil = dt % 1000L;
            const uint64 sec = ( dt / 1000L ) % 60L;
            const uint64 min = ( dt / 60000L ) % 60L;
            const uint64 hrs = ( dt / 3600000L );

            std::cout << '\n' << m_msg << "\n\telapsed time: ";

            if ( hrs )  std::cout << hrs << " hrs, ";
            if ( min )  std::cout << min << " min, ";
            if ( sec )  std::cout << sec << " sec, ";
            std::cout << mil << " mil-sec\n";
        }

    private:
        typedef unsigned long long int  uint64;
        const clock_t tic;
        const std::string m_msg;
};






using namespace std;


void d341( )
{
    int n, m;
    cin >> n >> m;

    map < int, map < int, uint64 > > w;

    int op, x0, y0, x1, y1;
    uint64 v;

    list < uint64 > out;

    for ( int j = 0; j < m; ++ j )
    {
        cin >> op >> x0 >> y0 >> x1 >> y1;
        if ( op == 2 )
        {
            cin >> v;

            map < int, uint64 > & wx1 = w[ x1 ];
            wx1[ y1 ] ^= v;
            wx1[ y0-1 ] ^= v;

            map < int, uint64 > & wx0 = w[ x0 - 1 ];
            wx0[ y1 ] ^= v;
            wx0[ y0-1 ] ^= v;
        }
        else
        {
            uint64 res = 0;
            for ( map < int, map < int, uint64 > >::const_iterator i = w.lower_bound ( x0 );
                    i != w.end( ) ; ++ i )
            {
                const int l = min ( i->first, x1 ) - x0 + 1;

                if ( l % 2 )
                    for ( map< int, uint64 >::const_iterator j = i->second.lower_bound( y0 ); j != i->second.end( ) ; ++j )
                    {
                        const int d = min ( j->first, y1 ) - y0 + 1;
                        if ( d % 2 )
                            res ^= j->second;
                        else if ( y1 <= j->first )
                            break;
                    }
                else if ( x1 <= i->first )
                    break;
            }
            out.push_back ( res );
        }
    }
    copy ( out.begin( ), out.end( ), ostream_iterator < uint64 > ( cout, "\n" ));
}


string b245( )
{
    string str, addr;
    cin >> str;

    string::iterator iru ;
    if ( str[ 0 ] == 'f' )
    {
        addr += "ftp://";
        iru = str.begin( ) + str.find ( "ru", 4 );
        addr.append ( str.begin( ) + 3, iru );
    }
    else
    {
        addr += "http://";
        iru = str.begin( ) + str.find ( "ru", 5 );
        addr.append ( str.begin( ) + 4, iru );
    }

    addr += ".ru";

    if ( iru + 2 != str.end ( ))
    {
        addr += "/";
        addr.append ( iru + 2, str.end( ) );
    }

    return addr;
}

uint64 c276( )
{
    size_t n, q;
    cin >> n >> q;
    vector < uint64 > a ( readin < uint64 > ( n ));
    vector < pair < uint64, uint64>  > irv ( readin < uint64, uint64 > ( q ));

    sort ( irv.begin( ), irv.end( ) );
    Heap < uint64, greater < uint64 > > heap;
    vector < uint64 > hit ( n );

    vector < pair < uint64, uint64 > >::const_iterator iter = irv.begin( );

    for ( uint64 j = 1; j <= n; ++j )
    {
        while ( ! heap.empty( ) && heap.front() < j )
            heap.pop( );

        for ( ; iter != irv.end( ) && iter->first <= j ; ++ iter )
            heap.push ( iter->second );

        hit[ j - 1 ] = heap.size( );
        

    }

    sort ( hit.begin( ), hit.end( ) );
    sort ( a.begin( ), a.end( ) );

    return inner_product ( a.begin( ), a.end( ), hit.begin( ), 0ULL );
}

int64 b262( )
{
    size_t n, k;
    cin >> n >> k;
    vector < int64 > a ( readin< int64 > ( n ) );

    const size_t n_neg = lower_bound( a.begin( ), a.end( ), 0 ) - a.begin( );

    DEBUG ( n_neg );

    if ( k <= n_neg)
        return accumulate ( a.begin( ) + k , a.end( ), 0 ) - accumulate ( a.begin( ), a.begin( ) + k, 0 );

    else if ( ( k - n_neg ) % 2 )
    {
        const int64 s = accumulate ( a.begin( ) + n_neg, a.end( ), 0 ) - accumulate ( a.begin( ), a.begin( ) + n_neg,0 );
        DEBUG ( s );
        if ( n_neg > 0 && n_neg < a.size( ) )
            return s - 2 * min ( a[n_neg], - a[n_neg - 1] );
        else if ( n_neg > 0 )
            return s + 2 * a.back( );
        else
            return s - 2 * a.front( );
    }
    else
        return accumulate ( a.begin( ) + n_neg , a.end( ), 0 ) - accumulate ( a.begin( ), a.begin( ) + n_neg, 0 );
}

void b4( )
{
    unsigned d, sumTime;
    cin >> d >> sumTime;
    vector < pair < unsigned, unsigned > > lm ( readin < unsigned, unsigned > ( d ) );

    const pair < unsigned, unsigned > sum_lm = accumulate ( lm.begin( ), lm.end( ), make_pair ( 0U, 0U ) , operator+ < unsigned, unsigned > );

    DEBUG ( sum_lm );

    if ( sumTime < sum_lm.first || sum_lm.second < sumTime )
    {
        cout << "NO\n";
    }
    else
    {
        unsigned k = sumTime - sum_lm.first;
        cout << "YES\n";
        for ( vector < pair< unsigned, unsigned> >::const_iterator iter = lm.begin( ); iter != lm.end( ); ++iter)
        {
            cout << min ( iter->second, iter->first + k ) << ' ';
            k -= min ( k, iter->second - iter->first );
        }
    }
}

struct Laptop;
bool operator< ( const Laptop & lhs, const Laptop & rhs );

struct Laptop
{
    unsigned speed, ram, hdd, cost;
    bool is_outdated ( const Laptop & other ) const
    {
        return speed < other.speed && ram < other.ram && hdd < other.hdd ;
    }
    bool operator== ( const Laptop & other ) const
    {
        return !( *this < other || other < *this );
    }

};

std::ostream & operator<< ( std::ostream & out, const Laptop & lp )
{
    out << "\nspeed: " << lp.speed << ", ram: " << lp.ram << ", hdd:" << lp.hdd << ", cost:" << lp.cost;
    return out;
}

istream & operator>> ( istream & ist, Laptop & lp )
{
    ist >> lp.speed >> lp.ram >> lp.hdd >> lp.cost;
    return ist;
}

bool operator< ( const Laptop & lhs, const Laptop & rhs )
{
    return lhs.cost < rhs.cost;
}

size_t b106( )
{
    vector < Laptop > lp ( readin < Laptop > ( ) );
    vector < Laptop > clp ( lp );
    sort ( lp.begin( ), lp.end( ) );

    DEBUG ( lp );

    for ( vector < Laptop >::const_iterator iter = lp.begin( ); iter != lp.end( ); ++ iter )
    {
        vector < Laptop >::const_iterator j = iter + 1;
        while ( j != lp.end( ) && ! iter->is_outdated ( *j ) )
            ++ j;

        if ( j == lp.end( ) )
            return find( clp.begin( ), clp.end( ), *iter ) - clp.begin( ) + 1;
    }

    return 0;
}

int main ( const int argc, char * argv [ ])
{
    cout << b106 ( );

    return EXIT_SUCCESS;
}