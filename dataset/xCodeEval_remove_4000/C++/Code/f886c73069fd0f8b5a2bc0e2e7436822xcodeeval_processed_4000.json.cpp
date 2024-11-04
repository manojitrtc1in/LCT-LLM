










































typedef          long long int  int64;
typedef unsigned long long int uint64;








    if (!( expr )) \
        throw std::runtime_error(__FILE__ ":" STR(__LINE__) " - " msg);


    typedef       shared_ptr < X >  X 
    typedef const shared_ptr < X >  X 


    
    
        { std::cout << 
    
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
inline void id27 ( ForwardIterator first, ForwardIterator last, T val )
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
class id6
{
    public:
        id6 ( const RAIter & first, Compare comp ):  m_first ( first ), m_comp( comp ) { }
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

    std::stable_sort ( idx.begin( ), idx.end( ), id6< RAIter, Compare > ( first, comp ) );
}

template < class RAIter, class Compare >
class id14
{
    public:
        id14 ( Compare comp ): m_comp ( comp ) { }
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

    std::sort ( idx.begin( ), idx.end( ), id14< RAIter, Compare > (comp ) );
}




inline void erase ( std::string & str, const char & ch )
{
    std::binder2nd < std::equal_to < char > > isch ( std::equal_to < char > ( ), ch );
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), isch );
    str.erase ( iter, str.end() );
}

inline void erase ( std::string & str, const std::string & chrs )
{
    isin < char, std::string > id18 ( chrs );
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), id18 );
    str.erase ( iter, str.end() );
}

template < typename value_type>
inline std::string id26 ( const value_type & x )
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
             const bool id7,
             std::list < std::string > & str_list )
{
    str_list.clear( );

    if ( id7 )
        
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



template < class T >
void id19( T n, std::map < T, size_t > & fac )
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
    std::pair < T, T > id30 ( const T & x0, const T & y0,
                                  const T & x1, const T & y1,
                                  const T & r0, const T & r1 )
    {
        const T q  = r0 / r1;
        const T r2 = r0 % r1;

        if ( ! ( r1 % r2 ) )
            return std::make_pair < T, T > ( x0 - q * x1, y0 - q * y1 );

        const T x2 = x0 - q * x1;
        const T y2 = y0 - q * y1;

        return id30 ( x1, y1, x2, y2, r1, r2 );
    }
}


template < class value_type > inline
std::pair < value_type, value_type > id3 ( value_type a, value_type b )
{
    return a % b
        ? id30 < value_type > ( 1, 0, 0, 1, a, b )
        : std::make_pair < value_type, value_type > ( 0, 1 );
}



template < class value_type > inline
value_type modinv ( value_type a, value_type m )
{
    const std::pair < value_type, value_type > coef ( id3( a, m ) );

    
    if ( a * coef.first + m * coef.second != 1 )
        throw std::runtime_error ( id26( a ) + " is not coprime to " + id26( m ));

    
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

    isin < char, std::string > id15 ( digit );
    assert ( find_if ( num.begin( ), num.end( ), std::not1 ( id15 ) ) == num.end( ));

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


inline bool id31 ( const long long & a )
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
std::vector < value_type > id24 ( const value_type n )
{

    ScopeTimer scope_timer ( "std::vector < value_type > id24 ( const value_type n )" );


    typedef typename std::vector < value_type >::iterator iterator;
    std::vector < value_type > primes;

    for ( value_type k = 2 ; k <= n; ++ k )
        if ( id31 ( k ) )
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
T id9 ( T n, T k )
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

    
    std::less    < value_type > id23;
    std::greater < value_type > id21;

    if ( first == last )  
        throw std::runtime_error ( "median of an empty vector is undefined!" );

    InputIter iter = first;
    max_heap.push_back ( * iter );

    for ( ++iter ; iter != last; ++ iter )
        if ( * iter < max_heap.front() )
        {
            max_heap.push_back ( * iter );
            std::push_heap ( max_heap.begin(), max_heap.end(), id23 );

            if ( min_heap.size() + 1 < max_heap.size() )
            {
                
                min_heap.push_back( max_heap.front() );
                std::push_heap( min_heap.begin(), min_heap.end(), id21 );

                std::pop_heap( max_heap.begin(), max_heap.end(), id23 );
                max_heap.pop_back();
            }
        }
        else
        {
            min_heap.push_back ( * iter );
            std::push_heap ( min_heap.begin(), min_heap.end(), id21 );

            if ( max_heap.size() + 1 < min_heap.size() )
            {
                
                max_heap.push_back( min_heap.front() );
                std::push_heap( max_heap.begin(), max_heap.end(), id23 );

                std::pop_heap( min_heap.begin(), min_heap.end(), id21 );
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

inline double id16 ( const xyPoint & a, const xyPoint & b )
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
        double id5;
        double id10;
        double id28;   

        bool   m_vertical;  
        double id8;    
};

xyLine::xyLine ( const xyPoint & a, const xyPoint & b )
{
    if ( a.x == b.x )  
    {
        m_vertical  = true;
        id8    = a.x;

        id10 = id20;
        id5     = DOUBLE_INF;
        id28   = id20;
    }
    else
    {
        m_vertical  = false;
        id8    = id20;

        id5     = ( b.y - a.y ) / ( b.x - a.x );
        id10 = a.y - id5 * a.x;
        id28   = std::sqrt ( id5 * id5 + 1.0 );
    }
}

xyLine::xyLine ( const double slope, const double intercept ):
    id5 ( slope ),  id10 ( intercept )
{
     m_vertical = false;
     id8   = id20;
     id28  = std::sqrt ( id5 * id5 + 1.0 );
}

double xyLine::orth_dist ( const xyPoint & o ) const 
{
    if ( m_vertical )
        return o.x - id8;
    else
        return ( id5 * o.x - o.y + id10 ) / id28;
}

inline double triangle_area ( const xyPoint & a, const xyPoint & b, const xyPoint & c )
{
    const xyLine l ( a, b );
    const double h = std::abs ( l.orth_dist ( c ) );
    const double e = id16 ( a, b );
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
void id22 ( const size_t & source,
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
    
    std::queue < size_t > id12;

    
    for ( std::vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++v )
        if ( m_pair[ *v ] == NIL )
        {
            m_dist[ *v ] = 0;
            id12.push ( *v );
        }
        else
            m_dist[ *v ] = INF;

    m_dist[ NIL ] = INF;

    
    while ( ! id12.empty() )
    {
        const size_t v = id12.front( );
        id12.pop ( );

        if ( m_dist[ v ] < m_dist[ NIL ] )
            for ( std::list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
                if ( m_dist[ m_pair[ * u ] ] == INF )
                {
                    m_dist[ m_pair[ * u ] ] = m_dist[ v ] + 1;
                    id12.push ( m_pair[ * u ] );
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



class id4
{
    public:
        id4( const std::vector< std::list < size_t > > & adj ):
            n( adj.size( ) ),
            depth( std::vector < size_t > ( n, id4::INF ) ),
            parent( std::vector < size_t > ( n ) ),
            dist( std::vector < std::vector < unsigned short > > ( n ) )
        {

            
            
            std::queue< size_t > id12;
            id12.push( 0 );
            depth[ 0 ]  = 0;
            parent[ 0 ] = 0;

            while ( ! id12.empty( ) )
            {
                const size_t u = id12.front( );
                id12.pop( );

                for ( std::list< size_t >::const_iterator j = adj[ u ].begin( ); j != adj[ u ].end( ); ++ j )
                    if ( depth[ u ] + 1 < depth[ *j ] )
                    {
                        depth[ *j ]  = depth[ u ] + 1;
                        parent[ *j ] = u;
                        id12.push( *j );
                    }
            }

            
            for ( size_t j = 1; j < n; ++ j )
                dist[ j ].resize( j, id4::INF );
        }

        
        size_t operator( )( const size_t u, const size_t v )
        {
            if ( u == v )
                return 0;
            else if ( u < v)
                return (*this)( v, u );
            else if ( dist[ u ][ v ] == id4::INF )
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
            std::vector < size_t > depth;   
            std::vector < size_t > parent;  
            std::vector < std::vector < unsigned short > > dist; 
};

const unsigned short id4::INF = std::numeric_limits< unsigned short >::max( );



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





































struct Comp
{
    bool operator()( const pair < string, size_t > & a,
                     const pair < string, size_t > & b )
    {
        return a.second < b.second
            || ( a.second == b.second && a.first < b.first );
    }
};

void c141()
{
    vector < pair < string, size_t > > a;
    cin >> a;
    const size_t n = a.size( );
    vector < int > h( n );

    sort( a.begin(), a.end(), Comp() );

    size_t j = 0;
    for ( ; j < n && ! a[ j ].second; ++ j )
        h[ j ] = j;

    for ( ; j < n; ++ j )
        if ( j < a[ j ].second )
        {
            cout << -1 << '\n';
            return;
        }
        else
        {
            Heap < int, greater< int > > heap;
            for ( size_t i = 0; i < j; ++ i )
            {
                heap.push( h[ i ] );
                if ( heap.size( ) > a[ j ].second )
                    heap.pop( );
            }
            h[ j ] = heap.front();

            for ( size_t i = 0; i < j; ++ i )
                h[ i ] += h[ i ] < h[ j ] ? -1 : 1;
        }

    const int id25 = * min_element( h.begin( ), h.end( ) );
    if ( id25 < 1 )
        transform( h.begin( ), h.end( ), h.begin( ), bind1st( plus< int >( ), 1 - id25 ));

    for ( size_t j = 0; j < n; ++ j )
        cout << a[ j ].first << ' ' << h[ j ] << '\n';
}

void b75( )
{
    string name;
    cin >> name;

    map < string, size_t > point;

    size_t n;
    cin >> n;

    string line;
    getline( cin, line );

    for ( size_t j = 0; j < n; ++ j )
    {
        getline( cin, line );

        vector < string > tok = tokenize( line, ' ');
        DEBUG( tok );

        const size_t k = tok[ 1 ] == "posted" ? 15 : tok[ 1 ] == "commented" ? 10 : 5,
                     i = tok.size( ) - 2;

        const string fst = tok[ 0 ],
                     snd = tok[ i ].substr( 0, tok[ i ].length( ) - 2 );

        point[ fst ] += snd == name ? k : 0;
        point[ snd ] += fst == name ? k : 0;
    }

    point.erase( name );
    vector < pair < int, string > > xs; 

    for ( map < string, size_t >::const_iterator j = point.begin(); j != point.end( ); ++ j )
        xs.push_back( make_pair( - j->second, j->first ) );

    sort( xs.begin( ), xs.end( ) );

    for ( vector < pair < int, string > >::const_iterator j = xs.begin( ); j != xs.end( ); ++j )
        cout << j->second << '\n';
}

size_t c46( )
{
    size_t n;
    string str;
    cin >> n >> str;

    const size_t k = count( str.begin( ), str.end( ), 'T' );
    str += str;

    size_t m = count( str.begin(), str.begin() + k, 'H' );
    size_t val = m;

    for ( size_t j = 0; j + 1 < n; ++ j )
    {
        m += ( str[ j ] == 'H' ? -1 : 0 ) +
            ( str[ j + k ] == 'H' ? 1 : 0 );

        val = min(val, m);
    }
    return val;
}

size_t d120()
{
    fstream fin("input.txt", std::fstream::in);
    size_t n, m;
    vector< size_t > xs(3);
    fin >> n >> m;
    vector < vector < size_t > > grid( n, vector < size_t >( m ));
    fin >> grid >> xs;

    vector < size_t > col(m, 0), row(n, 0);
    transform( grid.begin(), grid.end(), row.begin(),
            [](const vector < size_t > & xs)
            { return accumulate(xs.begin(), xs.end(), 0); });

    if (accumulate(xs.begin(), xs.end(), 0) != accumulate(row.begin(), row.end(), 0))
        return 0;

    for(size_t i = 0; i < n; ++ i)
        for(size_t j = 0; j < m; ++j)
            col[j] += grid[i][j];

    partial_sum(row.begin(), row.end(), row.begin());
    partial_sum(col.begin(), col.end(), col.begin());

    sort(xs.begin(), xs.end());
    

    size_t id13 = 0;
    do
    {
        auto i = equal_range(col.begin(), col.end(), xs[0]);
        auto j = equal_range(col.begin(), col.end(), xs[0] + xs[1]);

        size_t k = i.second - i.first, l = j.second - j.first;
        if ( !(k *l) )
            continue;

        if (j.second == col.end())
            -- k;

        size_t n = k * l;

        if (i.second <= j.first)
            n -= i.second - j.first + 1;

        id13 += n;
    } while(next_permutation(xs.begin(), xs.end()));

    sort(xs.begin(), xs.end());
    

    size_t id17 = 0;
    do
    {
        auto i = equal_range(row.begin(), row.end(), xs[0]);
        auto j = equal_range(row.begin(), row.end(), xs[0] + xs[1]);

        if (j.second == row.end())
        {
            -- j.second;
            if (j.second < j.first)
                -- j.first;
        }

        size_t k = i.second - i.first, l = j.second - j.first;
        if ( !(k *l) )
            continue;

        size_t n = k * l;
        COND_DEBUG( n > 0, n );
        if (j.first  + 1 <= i.second)
        {
            DEBUG( i.second - row.begin());
            DEBUG( j.first - row.begin());
            

            size_t r = j.first - i.second + 3;
            n -= r*r;
            

        }

        id17 += n;
        COND_DEBUG( n > 0, xs );
        COND_DEBUG( n > 0, n );
    } while(next_permutation(xs.begin(), xs.end()));

    sort(xs.begin(), xs.end());
    size_t k = xs.end() - unique(xs.begin(), xs.end()) + 1, acc = 1;
    for (size_t j = 0; j < k; ++ j )
        acc *= ( j + 1 );

    DEBUG( id13 );
    DEBUG( id17 );
    

    return (id13 + id17) / acc;
}

pair < size_t, size_t > id11(
        const size_t root,
        const size_t ban,
        const vector < vector < size_t > > & adj)
{
    
    typedef vector < size_t > adj_list;
    typedef adj_list::const_iterator adj_list_iter;

    pair <size_t, size_t> dist(0, 0);
    Heap < size_t, greater< size_t> > h;

    for(adj_list_iter j = adj[root].begin(); j != adj[root].end(); ++ j)
        if ( *j != ban )
        {
            const auto pr = id11(*j, root, adj);
            dist.second = max(dist.second, pr.second + 1);
            dist.first  = max(dist.first, pr.first);
            h.push(pr.second + 1);

            if (h.size() > 2)
                h.pop();
        }

    if ( h.size() > 1 )
    {
        const size_t d1 = h.front(); h.pop();
        const size_t d2 = h.front();
        dist.first = max(dist.first, d1 + d2);
    }

    dist.first = max(dist.first, dist.second);
    DEBUG(root);
    DEBUG(dist);
    return dist;
}


size_t xcope( const vector < vector < size_t > > & adj )
{

    
    typedef vector < size_t > adj_list;
    


    const size_t n = adj.size();

    
    const size_t root = max_element(adj.begin(), adj.end(), []
            ( const adj_list & a, const adj_list & b )
            {
                return a.size() < b.size();
            }) - adj.begin();

    DEBUG(root);
    DEBUG(adj);
    return id11(root, n + 1, adj).first;
}

void f120()
{

    fstream cin("input.txt", std::fstream::in);
    fstream cout("output.txt", std::fstream::out);


    size_t m, acc = 0;
    cin >> m;
    for ( size_t j = 0; j < m; ++ j )
    {
        size_t n;
        cin >> n;
        vector < vector < size_t > > adj(n);

        for ( size_t j = 0; j + 1< n; ++ j )
        {
            size_t u, v;
            cin >> u >> v;
            -- u; -- v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        const size_t id29 = xcope(adj);
        DEBUG(id29);
        acc += id29;
    }
    cout << acc;
}


int main ( const int argc, char * argv [ ])
{
    f120();
    

    

    


    return EXIT_SUCCESS;
}



