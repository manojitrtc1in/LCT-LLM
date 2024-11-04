




























typedef          long long int int64;
typedef unsigned long long int uint64;





    

    



    << 

















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



inline void erase ( std::string & str, const char & ch )
{
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), std::bind2nd( std::equal_to < char > ( ), ch ) );
    str.erase ( iter, str.end() );
}

template < typename value_type>
inline std::string id6 ( const value_type & x )
{
    std::ostringstream sout ( std::ios_base::out );
    sout << x;
    return sout.str();
}

template < typename value_type>
inline value_type id0 ( const std::string & str )
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


std::string chmod ( std::string num, const unsigned n, const unsigned m )
{
    const char * digit = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::transform ( num.begin(), num.end(), num.begin(), tolower );

    isin < char, std::string > id3 ( digit );
    assert ( find_if ( num.begin( ), num.end( ), std::not1 ( id3 ) ) == num.end( ));

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


template < typename value_type >
std::vector < value_type > id4 ( const value_type n )
{
    typedef typename std::vector < value_type >::iterator iterator;

    std::vector < value_type > primes;
    primes.reserve (( n + 2 ) / 3 + 3 );

    primes.push_back ( 2 );
    primes.push_back ( 3 );

    
    for ( value_type j = 6; j <= n + 1 ; j += 6 )
    {
        

        

        

        

        

        


        primes.push_back ( j - 1 );
        primes.push_back ( j + 1 );
    }

    iterator iend = primes.end( );

    
    for ( iterator iter = primes.begin( ) + 2; iter != iend; ++ iter )
        iend = std::remove_if ( iter + 1, iend, std::not1 ( std::bind2nd ( std::modulus < value_type > (), *iter )));

    iend = std::remove_if ( primes.begin(), iend, std::bind2nd ( std::greater < int > ( ), n ));
    primes.erase ( iend, primes.end( ));

    return primes;
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



class id1
{
    public:
        id1 ( const std::vector < std::list < size_t > > & adj,
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


std::map < size_t, size_t > id1::get_map ( )
{
    std::map < size_t, size_t > m;

    for ( size_t j = 0; j < m_pair.size( ); ++ j )
        if ( m_pair[ j ] != NIL  && m_tag[ j ])
            m[ j ] = m_pair[ j ];

    return m;
}


id1::id1 ( const std::vector < std::list < size_t > > & adj,
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

bool id1::mf_breadth_first_search( )
{
    
    std::queue < size_t > id2;

    
    for ( std::vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++v )
        if ( m_pair[ *v ] == NIL )
        {
            m_dist[ *v ] = 0;
            id2.push ( *v );
        }
        else
            m_dist[ *v ] = INF;

    m_dist[ NIL ] = INF;

    
    while ( ! id2.empty() )
    {
        const size_t v = id2.front( );
        id2.pop ( );

        if ( m_dist[ v ] < m_dist[ NIL ] )
            for ( std::list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
                if ( m_dist[ m_pair[ * u ] ] == INF )
                {
                    m_dist[ m_pair[ * u ] ] = m_dist[ v ] + 1;
                    id2.push ( m_pair[ * u ] );
                }
    }

    return m_dist[ NIL ] != INF;
}


bool id1::mf_depth_first_search( const size_t v )
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

    isin < char, string > id5 ( "aieou" );

    for ( int j = 0; j < 3; ++ j )
    {
        getline ( cin, str );
        if ( vowel_count[ j ] != count_if ( str.begin( ), str.end( ), id5 ) )
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

    
    const vector < unsigned int > primes = id4 < unsigned int > ( maxval + 75 );

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

int main ( const int argc, char * argv [ ])
{
    cout << b270 ( );

    


    


    

    


    

    


    


    return EXIT_SUCCESS;
}
