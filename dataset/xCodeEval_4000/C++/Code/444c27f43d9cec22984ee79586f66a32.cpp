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















typedef          long long int  int64;
typedef unsigned long long int uint64;

#define DOUBLE_INF std::numeric_limits< double >::infinity()
#define DOUBLE_NAN std::numeric_limits< double >::quiet_NaN()

#define DECLARE( X ) \
    typedef       shared_ptr < X >  X ## _shared_ptr; \
    typedef const shared_ptr < X >  X ## _const_shared_ptr;

#ifdef BUG
    #define DEBUG(var) { std::cout << #var << ": " << (var) << std::endl; }
    #define EXPECT(expr) if ( ! (expr) ) std::cerr << "Assertion " \
        << #expr " failed at " << __FILE__ << ":" << __LINE__ << std::endl;
#else
    #define DEBUG(var)
    #define EXPECT(expr)
#endif


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





template < class InputIterator >
typename std::iterator_traits<InputIterator>::difference_type
count_inv ( InputIterator first, InputIterator last )
{
    typedef typename std::iterator_traits<InputIterator>::difference_type difference_type;
    typedef typename std::iterator_traits<InputIterator>::value_type value_type;

    std::list < value_type > l; 
    difference_type cnt = 0;

    for ( difference_type n = 0; first != last; ++first, ++n )
    {
        
        typename std::list < value_type >::iterator iter = l.begin( );
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


template < class RAIter, class Compare >
void argsort ( const RAIter & first, const RAIter & last, std::vector < size_t > & idx, Compare comp )
{
    const size_t n = last - first;
    idx.resize ( n );

    for ( size_t j = 0; j < n; ++ j )
        idx[ j ] = j ;

    std::sort ( idx.begin( ), idx.end( ), ArgSortComp< RAIter, Compare > ( first, comp ) );
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
void itersort ( INIter first, INIter last, std::vector < RAIter > & idx, Compare comp )
{
    
    idx.resize ( std::distance ( first, last ) );
    for ( typename std::vector < RAIter >::iterator j = idx.begin( ); first != last; ++ j, ++ first )
        * j = first;

    std::sort ( idx.begin( ), idx.end( ), IterSortComp< RAIter, Compare > (comp ) );
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


void chunk ( const std::string::const_iterator first,
             const std::string::const_iterator last,
             const size_t k,
             const bool right_to_left,
             std::list < std::string > & str_list )
{
    str_list.clear( );

    if ( right_to_left )
        
        for ( std::string::const_iterator i, j = last; j != first; j = i )
        {
            i = first + k < j ? j - k : first;
            str_list.push_back ( std::string ( i, j ) );
        }
    else
        
        for ( std::string::const_iterator i = first, j; i != last; i = j )
        {
            j = i + k < last ? i + k : last;
            str_list.push_back ( std::string ( i, j ) );
        }
}


std::string & operator++( std::string & s )
{
    
    std::string::reverse_iterator j = find_if( s.rbegin( ), s.rend( ),
            std::bind2nd( std::less < char > ( ), 'z' ));

    if ( j != s.rend( ))
    {
        ++ *j;
        std::fill( s.rbegin( ), j, 'a' );
    }
    else
        s.assign( s.length( ) + 1, 'a' );

    return s;
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


template < typename value_type > inline
value_type gcd ( value_type a, value_type b )
{
    return ! b ? a : gcd( b, a % b );

    

    

    


    
    


    

    

    

    

    


    

}



template < class T >
void prime_factors( T n, std::map < T, size_t > & fac )
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
    std::pair < T, T > __extgcd ( const T & x0, const T & y0,
                                  const T & x1, const T & y1,
                                  const T & r0, const T & r1 )
    {
        const T q  = r0 / r1;
        const T r2 = r0 % r1;

        if ( ! ( r1 % r2 ) )
            return std::make_pair < T, T > ( x0 - q * x1, y0 - q * y1 );

        const T x2 = x0 - q * x1;
        const T y2 = y0 - q * y1;

        return __extgcd ( x1, y1, x2, y2, r1, r2 );
    }
}


template < class value_type > inline
std::pair < value_type, value_type > extgcd ( value_type a, value_type b )
{
    return a % b
        ? __extgcd < value_type > ( 1, 0, 0, 1, a, b )
        : std::make_pair < value_type, value_type > ( 0, 1 );
}



template < class value_type > inline
value_type modinv ( value_type a, value_type m )
{
    const std::pair < value_type, value_type > coef ( extgcd( a, m ) );

    
    if ( a * coef.first + m * coef.second != 1 )
        throw std::runtime_error ( val2str( a ) + " is not coprime to " + val2str( m ));

    
    return ( m + coef.first % m ) % m;
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

    DEBUG( primes.size() );
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



template < class InputIter >
inline std::pair < typename InputIter::value_type, typename InputIter::value_type >
median ( InputIter first, InputIter last )
{
    typedef typename InputIter::value_type      value_type;
    typedef std::pair< value_type, value_type > result_type;

    
    std::vector < value_type > max_heap, min_heap;

    
    std::less    < value_type > max_heap_comp;
    std::greater < value_type > min_heap_comp;

    if ( first == last )  
        throw std::runtime_error ( "median of an empty vector is undefined!" );

    InputIter iter = first;
    max_heap.push_back ( * iter );

    for ( ++iter ; iter != last; ++ iter )
        if ( * iter < max_heap.front() )
        {
            max_heap.push_back ( * iter );
            std::push_heap ( max_heap.begin(), max_heap.end(), max_heap_comp );

            if ( min_heap.size() + 1 < max_heap.size() )
            {
                
                min_heap.push_back( max_heap.front() );
                std::push_heap( min_heap.begin(), min_heap.end(), min_heap_comp );

                std::pop_heap( max_heap.begin(), max_heap.end(), max_heap_comp );
                max_heap.pop_back();
            }
        }
        else
        {
            min_heap.push_back ( * iter );
            std::push_heap ( min_heap.begin(), min_heap.end(), min_heap_comp );

            if ( max_heap.size() + 1 < min_heap.size() )
            {
                
                max_heap.push_back( min_heap.front() );
                std::push_heap( max_heap.begin(), max_heap.end(), max_heap_comp );

                std::pop_heap( min_heap.begin(), min_heap.end(), min_heap_comp );
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
    xyPoint ( const double & a = .0, const double & b = .0 ): x ( a ), y( b ) { };
};


struct xyCircle
{
    xyPoint center;
    double radius;
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

std::ostream & operator<< ( std::ostream & out, const xyCircle & o )
{
    out << "{(" << o.center.x << ", " << o.center.y << ") " << o.radius << '}';
    return out;
}

std::istream & operator>> ( std::istream & ist, xyCircle & o )
{
    ist >> o.center.x >> o.center.y >> o.radius;
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
    typedef typename std::vector < value_type >::iterator iterator;

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
inline std::pair < T1, T2 > operator+ ( const std::pair < T1, T2 > & a, const std::pair < T1, T2 > & b )
{
    return std::make_pair < T1, T2 > ( a.first + b.first, a.second + b.second );
}

template < typename T1, typename T2 >
inline std::pair < T1, T2 > operator- ( const std::pair < T1, T2 > & a, const std::pair < T1, T2 > & b )
{
    return std::make_pair < T1, T2 > ( a.first - b.first, a.second - b.second );
}










namespace
{
    
    template < size_t J, class T1, class T2 >
    struct Get;

    template < class T1, class T2 >
    struct Get < 0, T1, T2 >
    {
        typedef typename std::pair < T1, T2 >::first_type result_type;

        static       result_type & elm (       std::pair < T1, T2 > & pr ) { return pr.first; }
        static const result_type & elm ( const std::pair < T1, T2 > & pr ) { return pr.first; }
    };

    template < class T1, class T2 >
    struct Get < 1, T1, T2 >
    {
        typedef typename std::pair < T1, T2 >::second_type result_type;

        static       result_type & elm (       std::pair < T1, T2 > & pr ) { return pr.second; }
        static const result_type & elm ( const std::pair < T1, T2 > & pr ) { return pr.second; }
    };
}

template < size_t J, class T1, class T2 >
typename Get< J, T1, T2 >::result_type & get ( std::pair< T1, T2 > & pr )
{
    return Get < J, T1, T2 >::elm( pr );
}

template < size_t J, class T1, class T2 >
const typename Get< J, T1, T2 >::result_type & get ( const std::pair< T1, T2 > & pr )
{
    return Get < J, T1, T2 >::elm( pr );
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

        template < class InputIter >
        Heap ( InputIter first, InputIter last ):
            m_val ( std::vector < value_type > ( ) ) , m_comp( Comp( ) )
        {
            for ( ; first != last ; ++ first )
                m_val.push_back ( * first );

            std::make_heap( m_val.begin( ), m_val.end( ), m_comp );
        }

        
        inline const value_type & front( ) const { return m_val.front( ); }
        inline bool empty( ) const { return m_val.empty( ); }
        inline size_type size( ) const { return m_val.size( );  }

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


template < class Type >
class shared_ptr
{
    typedef Type value_type;
    public:
        explicit shared_ptr ( value_type * p = NULL ) : ptr ( p ), count ( new size_t ( 1U ) ) { }
        shared_ptr ( const shared_ptr < value_type > & sp ): ptr ( sp.ptr ), count ( sp.count ) { ++ * count; }
        ~ shared_ptr ( ) { release( ); }

        bool operator== ( const shared_ptr < value_type > & sp ) { return ptr == sp.ptr; }
        bool operator!= ( const shared_ptr < value_type > & sp ) { return ptr != sp.ptr; }

        shared_ptr < value_type > & operator= ( const shared_ptr < value_type > & sp )
        {
            if ( this != & sp && ptr != sp.ptr )
            {
                release( );
                ptr   = sp.ptr;
                count = sp.count;
                ++ * count;
            }
            return * this;
        }

        value_type * operator-> ( ) { return ptr ; }
        value_type & operator* ( ) { return *ptr ; }
        const value_type * operator-> ( ) const { return ptr ; }
        const value_type & operator* ( ) const { return *ptr; }

        void swap ( shared_ptr < value_type > & sp )
        {
            if ( this != &sp && ptr != sp.ptr )
            {
                std::swap ( ptr, sp.ptr );
                std::swap ( count, sp.count );
            }
        }

    private:
        void release ( )
        {
            
            -- * count;
            if ( ! * count )
            {
                delete count;
                delete ptr;
                count = NULL;
                ptr   = NULL;
            }
        }
        value_type * ptr;
        size_t     * count;
};


class UnionFind
{
    public:
        UnionFind( const size_t n ):
            parent ( std::vector < size_t > ( n ) ),   
            rank   ( std::vector < size_t > ( n, 0 ))  
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
        std::vector < size_t > parent;
        std::vector < size_t > rank;
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

class RandInt
{
    public:
        RandInt ( int a = 0, int b = 100 ): m ( a ), f ( static_cast < double > ( b - a ) / RAND_MAX ) { }
        inline int operator() ( ) { return m + std::ceil ( f * rand( ) ); }
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
        Noisy ( std::string str ): msg ( str )
        {
            std::cout << " Noisy ( " << msg << " )\t@ " << this << std::endl;
        }
        ~Noisy ( )
        {
            std::cout << "~Noisy ( " << msg << " )\t@ " << this << std::endl;
        }
        void beep ( )
        {
            std::cout << " beep ( " << msg << " )\t@ " << this << std::endl;
        }
        void beep ( ) const
        {
            std::cout << " const beep ( " << msg << " )\t@ " << this << std::endl;
        }
    private:
        const std::string msg;
};

DECLARE ( Noisy );






using namespace std;





































template <class ForwardIter>
void optimize(ForwardIter iter, ForwardIter first, ForwardIter last)
{
    typedef typename ForwardIter::value_type value_type;

    if ( *first < 0 )
        *first = - *first;

    ++iter;

    for ( value_type lag = *first++; first != last; lag = *first++, ++iter )
        *first = maxi< value_type >(3, *first, -*first, *iter + lag);
}



int c33()
{
    vector < int > xs;
    cin >> xs;

    const size_t n = xs.size();
    map < string, vector< int > > acc;

    acc["left"].resize( n );
    acc["right"].resize( n );

    partial_sum( xs.begin(), xs.end(), acc["left"].begin() );
    partial_sum( xs.rbegin(), xs.rend(), acc["right"].rbegin() );

    DEBUG( acc["left"] );
    DEBUG( acc["right"] );

    optimize( xs.begin(), acc["left"].begin(), acc["left"].end() );
    optimize( xs.rbegin(), acc["right"].rbegin(), acc["right"].rend() );

    DEBUG( acc["left"] );
    DEBUG( acc["right"] );

    int val = acc["right"][0];

    for( vector < int >::const_iterator i = acc["left"].begin(),
                                        j = acc["right"].begin() + 1;
                                        j != acc["right"].end(); ++ j, ++ i )
        val = max(val, *i + *j );

    return val;
}

void c7()
{
    int64 a, b, c;
    cin >> a >> b >> c;

    const int64 g = gcd(a, b);
    DEBUG( g );

    if ( c == 0 )
        cout << "0 0\n";
    else if ( c % g != 0 )
        cout << -1 << '\n';
    else
    {
        const pair < int64, int64 > pr = extgcd(a / g, b / g);
        const int64 f = - c / g;
        

        DEBUG( pr );

        cout << pr.first * f << ' ' << pr.second * f;
    }

}

void b23()
{
    size_t t, n;

    for( cin >> t; t > 0; --t)
    {
        cin >> n;
        cout << ( n > 2 ? n - 2 : 0 ) << '\n';
    }
}

long double bar(const int64 b, const int64 k, const int64 p)
{
    const long double expn = pow<long double>(k, p);
    return (expn - 1) * b / ( k - 1 ) + expn;
}

int64 a198()
{
    int64 k, b, n, t;
    cin >> k >> b >> n >> t;

    if ( k == 1 )
        return max(0LL, (1 + b * n - t + b - 1) / b);
    else
    {
        int64 lb = 0, ub = 1;
        while( bar(b, k, ub) <= t )
            ++ub;

        while (lb + 1 < ub)
            if (bar(b, k, (lb + ub + 1) / 2 <= t ))
                lb = (lb + ub + 1) / 2;
            else
                ub = (lb + ub + 1) / 2;

        DEBUG( ub );
        DEBUG( lb );
        return bar(b, k, ub) <= t ? max(n - ub, 0LL) : max(n - lb, 0LL);
    }
}

void b168()
{
    vector < string > lines;
    string line;

    bool flag = true; 


    while ( getline( cin, line ) )
    {
        const size_t j = line.find( '#' );
        if ( j != string::npos && line.substr(0, j) == string(j, ' ') )
        {
            lines.push_back( line );
            flag = true;
        }
        else
        {
            string::iterator iter = remove( line.begin(), line.end(), ' ' );
            iter = remove( line.begin(), iter, '\n' );
            line.erase( iter, line.end( ) );

            if ( flag )
                lines.push_back( line );
            else
                lines.back( ).append( line );
                


            flag = false;
        }
    }

    copy( lines.begin(), lines.end( ), ostream_iterator< string > ( cout, "\n" ));
}

int64 b274( )
{
    size_t n;
    cin >> n;

    vector < list < size_t > > adj( n );
    for ( size_t j = 0; j + 1 < n; ++ j )
    {
        size_t u, v;
        cin >> u >> v;
        -- u; -- v;

        adj[ u ].push_back( v );
        adj[ v ].push_back( u );
    }

    vector < int64 > val( n );
    cin >> val;

    DEBUG( adj );

    map < size_t, list < size_t >, greater< size_t > > level;
    vector < size_t > parent( n, 0 );

    queue < pair < size_t, size_t > > q;
    q.push( make_pair ( 0, 0 ) );
    parent[ 0 ] = 0;
    level[ 0 ].push_back( 0 );

    while ( ! q.empty( ) )
    {
        const size_t u = q.front( ).first;
        const size_t depth = q.front( ).second;
        q.pop( );

        for ( list< size_t >::const_iterator j = adj[ u ].begin( ); j != adj[ u ].end( ); ++ j )
            if ( *j != parent[ u ] )
            {
                parent[ *j ] = u;
                q.push( make_pair( *j, depth + 1 ) );
                level[ depth + 1 ].push_back( *j );
            }
    }

    DEBUG( parent );
    DEBUG( level );

    vector < pair < int64, int64 > > cnt( n, make_pair ( 0, 0 ) );

    for ( map< size_t, list < size_t >, greater< size_t > >::const_iterator l = level.begin( ); l != level.end( ); ++ l )
        for ( list < size_t >::const_iterator j = l->second.begin( ); j != l->second.end( ); ++  j )
        {
            

            int64 negval = 0, 

                  posval = 0; 


            int64 poscnt = 0, negcnt = 0;

            for ( list < size_t >::const_iterator iter = adj[ *j ].begin( ); iter != adj[ *j ].end( ); ++ iter )
                if ( *iter != parent[ *j ] )
                {
                    negval = min<int64>( negval, val[ * iter ] );
                    posval = max<int64>( posval, val[ * iter ] );

                    poscnt = max<int64>( poscnt, cnt[ *iter ].first );
                    negcnt = max<int64>( negcnt, cnt[ *iter ].second );
                }

            poscnt += -negval;
            negcnt += posval;
            val[ *j ] += poscnt - negcnt;
            cnt[ *j ] = make_pair < int64, int64 >( poscnt, negcnt );
        }

    DEBUG( val );
    DEBUG( cnt );
    return abs<int64>( val[ 0 ] ) + cnt[ 0 ].first + cnt[ 0 ].second;
}

inline int xgcd( const int a, const int b, map < pair < int, int >, int > & hash )
{
    int & ref = hash[ make_pair < int, int >( a, b ) ];
    if ( ! ref )
        ref = !b ? a : xgcd( b, a % b, hash );

    return ref;
}

inline const list < int > & get_prime_factors( int a, vector < list < int > > & hash,
        const vector < int > & primes )
{
    


    list < int > & l = hash[ a ];

    if ( l.empty( ) && a > 1 )
        for ( vector < int >::const_iterator j = primes.begin( ); a > 1 ; ++ j )
            if ( ! ( a % *j ) )
            {
                l.push_back( *j );
                while ( ! ( a % *j ) )
                    a /= *j;
            }

    return l;
}

void b154( )
{
    size_t n, m;
    cin >> n >> m;

    


    const vector < int > xs = get_primes< int >( n + 1 );

    vector < list < int > > hash( n + 1 );
    vector < int > primes( n + 1, 0 );
    vector < bool > tag( n + 1, false );


    for ( size_t j = 0; j < m; ++ j, cout << '\n' )
    {
        char op;
        int k;
        cin >> op >> k;

        switch ( op )
        {
            case '+':
                if ( tag[ k ] )
                    cout << "Already on";
                else
                {
                    const list < int > & l = get_prime_factors( k, hash, xs );

                    list < int >::const_iterator iter = l.begin( );
                    for ( ; iter != l.end( ) && ! primes[ *iter ]; ++ iter )
                        ;

                    if ( iter != l.end( ) )
                        cout << "Conflict with " << primes[ *iter ];
                    else
                    {
                        tag[ k ] = true;
                        for ( iter = l.begin( ); iter != l.end( ); ++ iter )
                            primes[ *iter ] = k;

                        cout << "Success";
                    }
                }
                break;
            case '-':
                if ( ! tag[ k ] )
                    cout << "Already off";
                else
                {
                    tag[ k ] = false;
                    const list < int > & l = get_prime_factors( k, hash, xs );

                    for ( list < int >::const_iterator iter = l.begin( ); iter != l.end( ); ++ iter )
                        primes[ *iter ] = 0;

                    cout << "Success";
                }
        }
    }
}

int main ( const int argc, char * argv [ ])
{
    b154( );
    


    return EXIT_SUCCESS;
}



