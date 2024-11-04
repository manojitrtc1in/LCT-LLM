#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cctype> 


#include <iostream>
#include <sstream>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <string>

#include <limits>
#include <utility>
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











inline void erase ( std::string & str, const char & ch )
{
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), std::bind2nd( std::equal_to < char > ( ), ch ) );
    str.erase ( iter, str.end() );
}

template < typename value_type>
inline std::string to_string ( const value_type & x )
{
    std::ostringstream sout ( std::ios_base::out );
    sout << x;
    return sout.str();
}

template < typename value_type>
inline value_type valstr ( const std::string & str )
{
    std::istringstream iss ( str, std::ios_base::in );
    value_type val;

    iss >> val;
    return val;
}

std::vector< std::string > tokenize ( const std::string & str, const char & sep )
{
    

    std::vector < std::string > res;
    std::string::const_iterator follow = str.begin( ), lead = str.begin( );

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

template < typename T> struct abs_diff : std::binary_function < T, T, T >
{
    inline T operator( ) (const T& x, const T& y) const { return abs(x - y); }
};



std::string chmod ( std::string num, const unsigned n, const unsigned m )
{
    const char * digit = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::transform ( num.begin(), num.end(), num.begin(), tolower );

    unsigned long long int val ( 0 );
    for ( std::string::const_iterator iter = num.begin( ); iter != num.end( ); ++ iter )
        val = val * n + ( 'a' <= *iter ? *iter - 'a' + 10U : *iter - '0');

    std::string res;
    for ( ; val ; val /= m )
        res.push_back( digit [ val % m ] );

    return res.length( ) ? std::string( res.rbegin( ), res.rend( )) : "0";
}




template < typename key_type, typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::pair < key_type, value_type > & p)
{
    out << "( " << p.first << ", " << p.second << " )";
    return out;
}

template < typename key_type, typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::map < key_type, value_type > & m )
{
    typedef typename std::map < key_type, value_type >::const_iterator  const_iterator;
    out << "{ ";

    

        


    for ( const_iterator iter = m.begin(); iter != m.end(); ++ iter )
        out << *iter << ", ";

    return out << "}";
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::set < value_type > & s )
{
    out << "{ ";

    for ( typename std::set < value_type>::const_iterator iter = s.begin(); iter != s.end(); ++ iter )
        out << *iter << ", ";

    return out << "}";
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::vector < value_type > & a )
{
    typedef typename std::vector < value_type>::const_iterator const_iterator;

    out << "{ ";
    for ( const_iterator iter = a.begin(); iter != a.end(); ++ iter )
        out << *iter << ", ";

    return out << "}";
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::list < value_type > & a )
{
    typedef typename std::list < value_type>::const_iterator const_iterator;

    out << "{ ";
    for ( const_iterator iter = a.begin(); iter != a.end(); ++ iter )
        out << *iter << ", ";

    return out << "}";
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



template < typename T >
inline T pair_sum ( const T & a, const T & b )
{
    

    typedef typename T::first_type   first_type;
    typedef typename T::second_type  second_type;

    return std::make_pair < first_type, second_type > ( a.first + b.first, a.second + b.second );
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

int main ( const int argc, char * argv [ ])
{
    a63 ( );

    return EXIT_SUCCESS;
}
