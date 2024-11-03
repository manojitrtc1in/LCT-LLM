










































typedef          long long int  int64;
typedef unsigned long long int uint64;





    typedef       shared_ptr < X >  X 
    typedef const shared_ptr < X >  X 


    
    
        << 

    
    


















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
inline void id21 ( ForwardIterator first, ForwardIterator last, T val )
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
class id5
{
    public:
        id5 ( const RAIter & first, Compare comp ):  m_first ( first ), m_comp( comp ) { }
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

    std::sort ( idx.begin( ), idx.end( ), id5< RAIter, Compare > ( first, comp ) );
}

template < class RAIter, class Compare >
class id11
{
    public:
        id11 ( Compare comp ): m_comp ( comp ) { }
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

    std::sort ( idx.begin( ), idx.end( ), id11< RAIter, Compare > (comp ) );
}




inline void erase ( std::string & str, const char & ch )
{
    std::binder2nd < std::equal_to < char > > isch ( std::equal_to < char > ( ), ch );
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), isch );
    str.erase ( iter, str.end() );
}

inline void erase ( std::string & str, const std::string & chrs )
{
    isin < char, std::string > id14 ( chrs );
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), id14 );
    str.erase ( iter, str.end() );
}

template < typename value_type>
inline std::string id20 ( const value_type & x )
{
    std::ostringstream sout ( std::ios_base::out );
    sout << x;
    return sout.str();
}

template < typename value_type>
inline value_type id1 ( const std::string & str )
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
             const bool id6,
             std::list < std::string > & str_list )
{
    str_list.clear( );

    if ( id6 )
        
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

    typedef long long unsigned val_type;

    typedef long unsigned val_type;

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

namespace
{
    template < class T >
    std::pair < T, T > id23 ( const T & x0, const T & y0,
                                  const T & x1, const T & y1,
                                  const T & r0, const T & r1 )
    {
        const T q  = r0 / r1;
        const T r2 = r0 % r1;

        if ( ! ( r1 % r2 ) )
            return std::make_pair < T, T > ( x0 - q * x1, y0 - q * y1 );

        const T x2 = x0 - q * x1;
        const T y2 = y0 - q * y1;

        return id23 ( x1, y1, x2, y2, r1, r2 );
    }
}


template < class value_type > inline
std::pair < value_type, value_type > id3 ( value_type a, value_type b )
{
    return a % b
        ? id23 < value_type > ( 1, 0, 0, 1, a, b )
        : std::make_pair < value_type, value_type > ( 0, 1 );
}



template < class value_type > inline
value_type modinv ( value_type a, value_type m )
{
    const std::pair < value_type, value_type > coef ( id3( a, m ) );

    
    if ( a * coef.first + m * coef.second != 1 )
        throw std::runtime_error ( id20( a ) + " is not coprime to " + id20( m ));

    
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

    isin < char, std::string > id12 ( digit );
    assert ( find_if ( num.begin( ), num.end( ), std::not1 ( id12 ) ) == num.end( ));

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


inline bool id24 ( const long long & a )
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
std::vector < value_type > id19 ( const value_type n )
{

    ScopeTimer scope_timer ( "std::vector < value_type > id19 ( const value_type n )" );


    typedef typename std::vector < value_type >::iterator iterator;
    std::vector < value_type > primes;

    for ( value_type k = 2 ; k <= n; ++ k )
        if ( id24 ( k ) )
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
inline std::list < std::pair < T, size_t > > id0 ( T a )
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
T id8 ( T n, T k )
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

    
    std::less    < value_type > id18;
    std::greater < value_type > id16;

    if ( first == last )  
        throw std::runtime_error ( "median of an empty vector is undefined!" );

    InputIter iter = first;
    max_heap.push_back ( * iter );

    for ( ++iter ; iter != last; ++ iter )
        if ( * iter < max_heap.front() )
        {
            max_heap.push_back ( * iter );
            std::push_heap ( max_heap.begin(), max_heap.end(), id18 );

            if ( min_heap.size() + 1 < max_heap.size() )
            {
                
                min_heap.push_back( max_heap.front() );
                std::push_heap( min_heap.begin(), min_heap.end(), id16 );

                std::pop_heap( max_heap.begin(), max_heap.end(), id18 );
                max_heap.pop_back();
            }
        }
        else
        {
            min_heap.push_back ( * iter );
            std::push_heap ( min_heap.begin(), min_heap.end(), id16 );

            if ( max_heap.size() + 1 < min_heap.size() )
            {
                
                max_heap.push_back( min_heap.front() );
                std::push_heap( max_heap.begin(), max_heap.end(), id18 );

                std::pop_heap( min_heap.begin(), min_heap.end(), id16 );
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

inline double id13 ( const xyPoint & a, const xyPoint & b )
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
        double id4;
        double id9;
        double id22;   

        bool   m_vertical;  
        double id7;    
};

xyLine::xyLine ( const xyPoint & a, const xyPoint & b )
{
    if ( a.x == b.x )  
    {
        m_vertical  = true;
        id7    = a.x;

        id9 = id15;
        id4     = DOUBLE_INF;
        id22   = id15;
    }
    else
    {
        m_vertical  = false;
        id7    = id15;

        id4     = ( b.y - a.y ) / ( b.x - a.x );
        id9 = a.y - id4 * a.x;
        id22   = std::sqrt ( id4 * id4 + 1.0 );
    }
}

xyLine::xyLine ( const double slope, const double intercept ):
    id4 ( slope ),  id9 ( intercept )
{
     m_vertical = false;
     id7   = id15;
     id22  = std::sqrt ( id4 * id4 + 1.0 );
}

double xyLine::orth_dist ( const xyPoint & o ) const 
{
    if ( m_vertical )
        return o.x - id7;
    else
        return ( id4 * o.x - o.y + id9 ) / id22;
}

inline double triangle_area ( const xyPoint & a, const xyPoint & b, const xyPoint & c )
{
    const xyLine l ( a, b );
    const double h = std::abs ( l.orth_dist ( c ) );
    const double e = id13 ( a, b );
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
void id17 ( const size_t & source,
                 const std::vector < std::list < size_t > > & adj,          

                 const std::vector < std::vector < DistType > > & edge_len, 

                 std::vector < DistType > & dist,  

                 std::vector < size_t > prev )     

{
    

}







class id2
{
    public:
        id2 ( const std::vector < std::list < size_t > > & adj,
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


std::map < size_t, size_t > id2::get_map ( )
{
    std::map < size_t, size_t > m;

    for ( size_t j = 0; j < m_pair.size( ); ++ j )
        if ( m_pair[ j ] != NIL  && m_tag[ j ])
            m[ j ] = m_pair[ j ];

    return m;
}


id2::id2 ( const std::vector < std::list < size_t > > & adj,
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

bool id2::mf_breadth_first_search( )
{
    
    std::queue < size_t > id10;

    
    for ( std::vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++v )
        if ( m_pair[ *v ] == NIL )
        {
            m_dist[ *v ] = 0;
            id10.push ( *v );
        }
        else
            m_dist[ *v ] = INF;

    m_dist[ NIL ] = INF;

    
    while ( ! id10.empty() )
    {
        const size_t v = id10.front( );
        id10.pop ( );

        if ( m_dist[ v ] < m_dist[ NIL ] )
            for ( std::list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
                if ( m_dist[ m_pair[ * u ] ] == INF )
                {
                    m_dist[ m_pair[ * u ] ] = m_dist[ v ] + 1;
                    id10.push ( m_pair[ * u ] );
                }
    }

    return m_dist[ NIL ] != INF;
}


bool id2::mf_depth_first_search( const size_t v )
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





































void c216( )
{
    size_t m, n, k;
    cin >> n >> m >> k;

    size_t ub = m + n + 1; 


    map < size_t, size_t > start, end;

    size_t wrk = 0, total = 0; 

    list < pair < size_t, size_t > > sched;

    size_t day = 1;
    while ( day <= ub )
    {
        

        

        

        

        if ( start.count( day ) )
        {
            const size_t cnt = start[ day ];
            wrk += cnt;
            end[ day + n - 1] += cnt;
            start.erase( day );
        }

        


        

        if ( wrk < k )
        {
            const size_t cnt = k - wrk;
            sched.push_back( make_pair ( day, cnt ) );
            total += cnt;

            wrk += cnt;
            end[ day + n - 1] += cnt;

            ub += m + n + 1;
            

        }

        

        if ( end.count( day ) )
        {
            const size_t cnt = end[ day ];
            wrk -= cnt;
            start[ day + m + 1] += cnt;
            end.erase( day );
        }

        

        if ( !wrk )
        {
            const size_t cnt = 1;
            sched.push_back( make_pair ( day, cnt ) );
            total += cnt;
            wrk += cnt;
            end[ day + n - 1] += cnt;

            ub += m + n + 1;

        }

        

        

        

        

        

        ++day;

    }

    

    

    cout << total << '\n';
    for ( list < pair < size_t, size_t > >::const_iterator j = sched.begin( ); j != sched.end( ); ++j )
        for ( size_t i = 0; i < j->second; ++ i )
            cout << j->first << ' ';
}

bool xless ( map < size_t, size_t > & a, map < size_t, size_t > & b )
{
    const size_t ub = max ( a.rbegin( )->first, b.rbegin( )->first ) + 1;

    


    for ( size_t j = 0; j < ub ; ++j )
        if ( a[ j ] < b[ j ] )
            return true;
        else if ( a[ j ] > b[ j ] )
            return false;

    return false;
}


void b24( )
{
    size_t t, n;
    cin >> t;
    string name;

    size_t p[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

    map <string, size_t > score;
    map <string, map < size_t, size_t > > rank;

    for ( size_t j = 0; j < t; ++ j )
    {
        cin >> n;
        for ( size_t i = 0; i < n; ++ i )
        {
            cin >> name;
            if ( i < 10 )
                score[ name ] += p[ i ];
            ++ rank[ name ][ i ];
        }
    }

    DEBUG( score );
    DEBUG( rank );

    string winner = score.begin( )->first;

    for ( map<string, size_t >::iterator j = score.begin( ); j != score.end( ); ++ j )
        if ( j->second > score[ winner ] || ( j->second == score[ winner ] && xless( rank[ winner ], rank[ j->first ] ) ) )
            winner = j->first;

    cout << winner << '\n';

    for ( map <string, map < size_t, size_t > >::iterator j = rank.begin( ); j != rank.end( ); ++ j )
        

        if ( rank[ winner ][ 0 ] < rank[ j->first ][ 0 ] ||
                ( rank[ winner ][ 0 ] == rank[ j->first ][ 0 ] && score[ winner ] < score[ j->first ] ) ||
                ( rank[ winner ][ 0 ] == rank[ j->first ][ 0 ] && score[ winner ] == score[ j->first ]
                  && xless( rank[ winner ], rank[ j->first ] )))
            winner = j->first;

    cout << winner << '\n';
}

void c82( )
{
    vector < size_t > a;
    cin >> a;

    const size_t n = a.size( );

    size_t u, v, c;


    vector < list < pair < size_t, size_t > > > adj( n );
    map < pair< size_t, size_t >, size_t > edge; 


    for ( size_t j = 0; j < n - 1; ++ j )
    {
        cin >> v >> u >> c;
        -- v; -- u;

        edge[ make_pair( u, v ) ] = c;
        edge[ make_pair( v, u ) ] = c;

        adj[ u ].push_back ( make_pair( v, c ) );
        adj[ v ].push_back ( make_pair( u, c ) );
    }


    

    const size_t NIL = numeric_limits < size_t >::max( );

    queue < size_t > q;
    vector < size_t > parent( n, NIL );
    

    vector < list < size_t > > next( n );

    q.push( 0 );
    parent[ 0 ] = 0;

    while ( ! q.empty( ) )
    {
        const size_t src = q.front( );
        q.pop( );

        for ( list < pair < size_t, size_t > >::const_iterator j = adj[ src ].begin( ); j != adj[ src ].end( ); ++ j )
            if ( parent[ j->first ] == NIL )
            {
                parent[ j->first ] = src;
                q.push( j->first );
                next[ src ].push_back( j->first  );
            }
    }

    vector < size_t > t( n, 0 );

    

    vector < Heap< pair < size_t, size_t > , greater< pair < size_t, size_t > > > > h( n );
    for ( size_t j = 0; j < n; ++ j )
        h[ j ].push( make_pair( a[ j ], j ) );

    size_t day = 0, counter = 1, touch;

    DEBUG( next );

    while ( counter < n ) 

    {
        queue< size_t > q;
        q.push( 0 );
        ++ day;

        touch = counter;

        while ( touch < n && ! q.empty( ) )
        {
            const size_t v = q.front( );
            q.pop( );

            for ( list < size_t >::const_iterator j = next[ v ].begin( ); j != next[ v ].end( ); ++ j )
            {
                const size_t u = *j, cap = edge[ make_pair( u, v ) ];
                q.push( u );
                touch += h[ u ].size( );

                for ( size_t cnt = 0; cnt < cap && ! h[ u ].empty( ); ++ cnt )
                {
                    if ( ! v )
                    {
                        t[ h[ u ].front( ).second ] = day;
                        ++ counter;
                    }
                    else
                        h[ v ].push( h[ u ].front( ) );

                    h[ u ].pop( );
                }
            }
        }
    }

    copy ( t.begin( ), t.end( ), ostream_iterator < size_t > ( cout, " " ));
}

int main ( const int argc, char * argv [ ])
{
    c82( );
    

    


    return EXIT_SUCCESS;
}