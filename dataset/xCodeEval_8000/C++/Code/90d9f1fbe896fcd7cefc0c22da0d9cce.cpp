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

template < typename key_type, typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::map < key_type, value_type > & m )
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




template < typename T, typename S >
inline std::pair < T, S > operator+ ( const std::pair < T, S > & a, const std::pair < T, S > & b )
{
    return std::make_pair < T, S > ( a.first + b.first, a.second + b.second );
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

void a161( )  
{
    size_t n, m, x, y;
    cin >> n >> m >> x >> y;

    const vector < size_t > a ( readin < size_t > ( n ) );
    const vector < size_t > b ( readin < size_t > ( m ) );

    vector < pair < size_t, size_t > > join;
    

    size_t i = 0, j = 0;

    

    while ( i < a.size( ) && j < b.size( ))
        if ( a[ i ] <= b[ j ] + x && b[ j ] <= a[ i ] + y )
            join.push_back( make_pair< size_t, size_t > ( i++,  j++) );
        else if ( a[ i ] > b[ j ] + x )
            ++ j;
        else
            ++ i;

    
    


    

    

    

    

    

    

    


    

    


    

    


    cout << join.size() << '\n';

    for ( vector < pair < size_t, size_t >  >::const_iterator iter = join.begin(); iter != join.end(); ++ iter )
        cout << iter->first + 1 << ' ' << iter->second + 1 << '\n';
}


int a332 ( ) 
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    int res ( 0 );

    for ( unsigned j = n; j < str.size(); j += n)
        res += ( str[ j - 1 ] == str[ j - 2] && str[ j - 2 ] == str[ j - 3 ] );

    return res;
}

string b136 ( ) 
{
    string a, c, b;
    cin >> a >> c;

    a = chmod ( a, 10, 3 );
    c = chmod ( c, 10, 3 );

    if ( a.size( ) > c.size( ) )
        c = string( a.size( ) - c.size( ), '0' ) + c;
    else
        a = string( c.size( ) - a.size( ), '0' ) + a;

    DEBUG( a );
    DEBUG( c );

    const char * digit = "012";

    for ( string::const_iterator i = a.begin(), j = c.begin(); i != a.end(); ++ i, ++ j )
        b.push_back ( digit[ ( *j + 3 - *i ) % 3 ] );

    DEBUG( b );
    return chmod ( b, 3, 10);
}

void a63 ( ) 
{
    const vector < pair < string, string > > a ( readin < pair < string, string > > ( ));
    map < string, list < string > > ord;

    for ( vector < pair < string, string > >::const_iterator iter = a.begin( ); iter != a.end ( ); ++ iter )
        if ( iter->second == "woman" || iter->second == "child" )
            ord[ "woman" ].push_back ( iter->first );
        else
            ord[ iter->second ].push_back ( iter->first );

    DEBUG ( ord );

    const char * status[ ] = { "rat", "woman", "man", "captain" };
    ostream_iterator < string > out ( cout, "\n" );

    for ( unsigned j = 0; j < 4U; ++ j)
        copy ( ord[ status[ j ] ].begin( ), ord[ status[ j ] ].end( ), out );
}

const char * a203 ( ) 
{
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    if ( ! x )
        return "YES";

    for ( int j = 0; j < t; ++ j )
        if ( x == a - j * da || x == b - j * db)
            return "YES";

    for ( int i = 0; i < t; ++ i )
        for ( int j = 0; j < t; ++j )
            if ( x == a - j * da + b - i * db )
                return "YES";

    return "NO";
}


const char * a78 ( )
{
    const unsigned vowel_count[ ] = { 5, 7, 5 };
    string str;

    isin < char, string > isvowel ( "aieou" );

    for ( int j = 0; j < 3; ++ j )
    {
        getline ( cin, str );
        if ( vowel_count[ j ] != count_if ( str.begin( ), str.end( ), isvowel ) )
            return "NO";
    }

    return "YES";
}

void a34( )  
{
    const vector < int > a ( readin < int > ( ) );
    const size_t n = a.size( );

    vector < int > adj_diff( n );
    adjacent_difference ( a.begin(), a.end(), adj_diff.begin( ), abs_diff < int > ( ) );

    adj_diff[ 0 ] = abs ( a[ 0 ] - a[ n - 1 ] );
    const int j = min_element ( adj_diff.begin( ), adj_diff.end( ) ) - adj_diff.begin( ) + 1;

    cout << j << ' ' << ( j > 1 ? j - 1 : n );
}

string a74( ) 
{
    int n;
    cin >> n;

    string hdl;
    int plus, minus, a, b, c, d, e;

    list < pair < int, string > > score;

    for ( int j = 0; j < n; ++ j )
    {
        cin >> hdl >> plus >> minus >> a >> b >> c >> d >> e;
        const int this_score = a + b + c + d + e + 100 * plus - 50 * minus;

        score.push_back ( make_pair ( this_score, hdl) );
    }

    DEBUG ( score );
    return max_element( score.begin(), score.end())->second;
}

unsigned b271( ) 
{
    unsigned n, m;
    cin >> n >> m;

    vector < vector < unsigned int > > a ( n );
    for ( vector < vector < unsigned int > >::iterator iter = a.begin( ); iter != a.end( ); ++ iter )
        *iter = readin < unsigned int > ( m );

    
    unsigned int maxval = 0;
    for ( vector < vector < unsigned int > >::const_iterator iter = a.begin( ); iter != a.end( ); ++ iter )
        maxval = max ( maxval, * max_element ( iter->begin( ), iter->end( ) ));

    
    const vector < unsigned int > primes = get_primes < unsigned int > ( maxval + 75 );

    vector < unsigned int > row ( n, 0 ), col ( m, 0 );
    for ( unsigned i = 0; i < n; ++ i )
        for ( unsigned j = 0; j < m; ++ j )
        {
            const unsigned inc = * lower_bound( primes.begin( ), primes.end( ), a[ i ][ j ] ) - a[ i ][ j ];
            row[ i ] += inc;
            col[ j ] += inc;
        }

    return min ( * min_element ( row.begin( ), row.end( ) ),
                 * min_element ( col.begin( ), col.end( ) ));
}

unsigned b270 ( ) 
{
    vector < unsigned > a ( readin < unsigned > ( ) );

    vector < unsigned >::const_reverse_iterator iter = a.rbegin() + 1;
    while ( iter != a.rend() && *iter < *( iter - 1 ) )
        ++ iter;

    return a.size( ) - ( iter - a.rbegin() );
}

void a9 ( )  
{
    int y, w;
    cin >> y >> w;

    const int z = 7 - max(y, w);
    const int g = gcd ( 6, z );

    cout << z / g << '/' << 6 / g;
}

typedef pair < double, double > Point;

inline pair < double, int > orth_dist ( const Point & a, const Point & b, const Point & o )
{
    if ( a.first == b.first )
    {
        const double d = o.first - a.first;
        return make_pair < double, int > ( abs ( d ), sign ( d ) );
    }
    else
    {
        const double slope = ( a.second - b.second ) / ( a.first - b.first );

        const double c_x = slope;
        const double c_y = -1.0;
        const double c_d = a.second - slope * a.first;

        const double num = c_x * o.first + c_y * o.second + c_d;
        const double den = sqrt ( c_x * c_x + c_y * c_y ); 


        return make_pair < double, int > ( abs( num ) / den, sign( num ) ) ;
    }
}

inline double cart_dist ( const Point & a, const Point & b )
{
    const double x = a.first - b.first;
    const double y = a.second - b.second;

    return sqrt ( x * x +  y * y );
}

double area ( const Point & a, const Point & b, const Point & c, const Point & d )
{
    const pair < double, int > h1 = orth_dist ( a, c, b );
    const pair < double, int > h2 = orth_dist ( a, c, d );

    if ( h1.second == h2.second )
        return -1;

    const double e = cart_dist ( a, c );

    

    

    


    

    return ( h1.first + h2.first ) * e / 2.0 ;
}


double b340 ( )
{
    const vector < pair < double, double > > p ( readin < double, double > ( ) );
    const size_t n = p.size( );

    double res = 0.0;
    for ( size_t i = 0; i < n; ++ i )  

        for ( size_t j = i + 1; j < n; ++ j )  

        {
            const double e = cart_dist ( p[i], p[j] );  

            const double slope = ( p[i].second - p[j].second ) / ( p[i].first - p[j].first );
            const double c_x = slope;
            const double c_y = -1.0;
            const double c_d = p[i].second - slope * p[i].first;
            const double den = sqrt ( c_x * c_x + c_y * c_y ); 


            double h_pos = 0.0, h_neg = 0.0;

            for ( size_t k = 0 ; k < n; ++ k )   

            {
                if ( k == j || k == i)
                    continue;

                const double h = ( c_x * p[k].first + c_y * p[k].second + c_d ) / den;

                if ( h > 0 && h > h_pos )
                    h_pos = h;

                if ( h < 0 && h < h_neg )
                    h_neg = h;

            }

            const double d = ( h_pos - h_neg ) * e / 2;
            if ( d > res && h_pos > 0 && h_neg < 0)
                res = d;
        }
    return res;
}

void c198 ( )
{
    vector < uint64 > a ( readin < uint64 > ( ) );

    

    


    


    


    

    


    uint64 sum_diff = 0;
    uint64 k = 0;
    const uint64 count = a.size( );

    for ( vector< uint64 >::const_iterator i = a.begin( ); i != a.end( ); ++ i )
    {
        for ( vector< uint64 >::const_iterator j = i + 1; j != a.end( ); ++ j )
        {

            const uint64 diff = ( *i > *j ) ? *i - *j : *j - *i;
            sum_diff += 2 * diff;

        }
            k += sum_diff / count;
            sum_diff %= count;
    }

    

    

    


    for ( vector <uint64>::const_iterator i = a.begin( ); i != a.end( ); ++ i )
    {
        sum_diff += *i;

        k += sum_diff / count;
        sum_diff %= count;
    }


    DEBUG ( sum_diff );

    const uint64 g = gcd ( sum_diff, count );

    cout << k * count / g + sum_diff / g << ' ' << count / g;
}

void b230( )
{
    const vector < int64 > a ( readin < int64 >( ) );

    for ( vector < int64 >::const_iterator iter = a.begin( ); iter != a.end( ); ++ iter )
    {
        const int64 s = static_cast < int64 > ( sqrt ( * iter ) );
        cout << ( s * s == *iter && is_pseudo_prime( s ) ? "YES" : "NO" ) << '\n';
    }
}


int main ( const int argc, char * argv [ ])
{
    

    

    

    



    cout << setprecision( 15 ) << b340 ( );

    return EXIT_SUCCESS;
}
