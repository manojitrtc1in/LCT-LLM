














































typedef          long long int  int64;
typedef unsigned long long int uint64;












    if (!( expr )) \
        throw std::runtime_error(__FILE__ ":" STR(__LINE__) " - " msg);


    
    
        { std::cout << 
    
        << 

    
    
    





    





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

    stable_sort( idx.begin(), idx.end(), id6< RAIter, Compare >( first, comp ));
}

template < class RAIter, class Compare >
class id12
{
    public:
        id12 ( Compare comp ): m_comp ( comp ) { }
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

    sort ( idx.begin( ), idx.end( ), id12< RAIter, Compare > (comp ) );
}




inline void erase ( string & str, const char & ch )
{
    binder2nd < equal_to < char > > isch ( equal_to< char >(), ch );
    string::iterator iter = remove_if ( str.begin(), str.end(), isch );
    str.erase ( iter, str.end() );
}

inline void erase ( string & str, const string & chrs )
{
    isin < char, string > id17 ( chrs );
    string::iterator iter = remove_if ( str.begin(), str.end(), id17 );
    str.erase ( iter, str.end() );
}

template < typename value_type>
inline string id26 ( const value_type & x )
{
    ostringstream sout ( ios_base::out );
    sout << x;
    return sout.str();
}

template < typename value_type>
inline value_type id0 ( const string & str )
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
             const bool id7,
             list < string > & str_list )
{
    str_list.clear( );

    if ( id7 )
        
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


auto id22( const vector< string > & word )
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

    typedef long long unsigned val_type;

    typedef long unsigned val_type;

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
void id18( T n, map < T, size_t > & fac )
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
    pair < T, T > id29 ( const T & x0, const T & y0,
                                  const T & x1, const T & y1,
                                  const T & r0, const T & r1 )
    {
        const T q  = r0 / r1;
        const T r2 = r0 % r1;

        if ( ! ( r1 % r2 ) )
            return make_pair < T, T > ( x0 - q * x1, y0 - q * y1 );

        const T x2 = x0 - q * x1;
        const T y2 = y0 - q * y1;

        return id29 ( x1, y1, x2, y2, r1, r2 );
    }
}


template < class value_type > inline
pair < value_type, value_type > id2 ( value_type a, value_type b )
{
    return a % b
        ? id29 < value_type > ( 1, 0, 0, 1, a, b )
        : make_pair < value_type, value_type > ( 0, 1 );
}



template < class value_type > inline
value_type modinv ( value_type a, value_type m )
{
    const pair < value_type, value_type > coef ( id2( a, m ) );

    
    if ( a * coef.first + m * coef.second != 1 )
        throw runtime_error ( id26( a ) + " is not coprime to " + id26( m ));

    
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

    isin < char, string > id13 ( digit );
    assert ( find_if ( num.begin( ), num.end( ), not1 ( id13 ) ) == num.end( ));

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


inline bool id30 ( const long long & a )
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
vector < value_type > id25 ( const value_type n )
{

    ScopeTimer scope_timer ( "vector < value_type > id25 ( const value_type n )" );


    

    vector < value_type > primes;

    for ( value_type k = 2 ; k <= n; ++ k )
        if ( id30 ( k ) )
        {
            

            

            


            

            


            primes.push_back ( k );
        }

    return primes;
}


































template < class T >  
vector < pair < T, size_t > > id5( T a )
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
T id9 ( T n, T k )
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

    
    less    < value_type > id24;
    greater < value_type > id21;

    if ( first == last )  
        throw runtime_error ( "median of an empty vector is undefined!" );

    InputIter iter = first;
    max_heap.push_back ( * iter );

    for ( ++iter ; iter != last; ++ iter )
        if ( * iter < max_heap.front() )
        {
            max_heap.push_back ( * iter );
            push_heap ( max_heap.begin(), max_heap.end(), id24 );

            if ( min_heap.size() + 1 < max_heap.size() )
            {
                
                min_heap.push_back( max_heap.front() );
                push_heap( min_heap.begin(), min_heap.end(), id21 );

                pop_heap( max_heap.begin(), max_heap.end(), id24 );
                max_heap.pop_back();
            }
        }
        else
        {
            min_heap.push_back ( * iter );
            push_heap ( min_heap.begin(), min_heap.end(), id21 );

            if ( max_heap.size() + 1 < min_heap.size() )
            {
                
                max_heap.push_back( min_heap.front() );
                push_heap( max_heap.begin(), max_heap.end(), id24 );

                pop_heap( min_heap.begin(), min_heap.end(), id21 );
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

inline double id14 ( const xyPoint & a, const xyPoint & b )
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
        double id4;
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

        id10 = id19;
        id4     = DOUBLE_INF;
        id28   = id19;
    }
    else
    {
        m_vertical  = false;
        id8    = id19;

        id4     = ( b.y - a.y ) / ( b.x - a.x );
        id10 = a.y - id4 * a.x;
        id28   = sqrt ( id4 * id4 + 1.0 );
    }
}

xyLine::xyLine ( const double slope, const double intercept ):
    id4 ( slope ),  id10 ( intercept )
{
     m_vertical = false;
     id8   = id19;
     id28  = sqrt ( id4 * id4 + 1.0 );
}

double xyLine::orth_dist ( const xyPoint & o ) const 
{
    if ( m_vertical )
        return o.x - id8;
    else
        return ( id4 * o.x - o.y + id10 ) / id28;
}

inline double triangle_area ( const xyPoint & a, const xyPoint & b, const xyPoint & c )
{
    const xyLine l ( a, b );
    const double h = abs ( l.orth_dist ( c ) );
    const double e = id14 ( a, b );
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




void id15( const size_t root,
        const vector < vector < size_t > > & tree,
        vector < tuple< size_t, size_t > > & indist )
{
    const auto NIL = numeric_limits< size_t >::max();
    size_t a = 0, b = NIL;

    for ( const auto u: tree[ root ] )
    {
        id15( u, tree, indist );
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


void id16( const size_t root,
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

        id16( u, tree, indist, outdist );
    }
}



template < typename DistType >
void id23 ( const size_t & source,
                 const vector < list < size_t > > & adj,          

                 const vector < vector < DistType > > & edge_len, 

                 vector < DistType > & dist,  

                 vector < size_t > prev )     

{
    

}







class id1
{
    public:
        id1 ( const vector < list < size_t > > & adj,
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


map < size_t, size_t > id1::get_map ( )
{
    map < size_t, size_t > m;

    for ( size_t j = 0; j < m_pair.size( ); ++ j )
        if ( m_pair[ j ] != NIL  && m_tag[ j ])
            m[ j ] = m_pair[ j ];

    return m;
}


id1::id1 ( const vector < list < size_t > > & adj,
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

bool id1::mf_breadth_first_search( )
{
    
    queue < size_t > id11;

    
    for ( vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++v )
        if ( m_pair[ *v ] == NIL )
        {
            m_dist[ *v ] = 0;
            id11.push ( *v );
        }
        else
            m_dist[ *v ] = INF;

    m_dist[ NIL ] = INF;

    
    while ( ! id11.empty() )
    {
        const size_t v = id11.front( );
        id11.pop ( );

        if ( m_dist[ v ] < m_dist[ NIL ] )
            for ( list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
                if ( m_dist[ m_pair[ * u ] ] == INF )
                {
                    m_dist[ m_pair[ * u ] ] = m_dist[ v ] + 1;
                    id11.push ( m_pair[ * u ] );
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


class id3
{
    public:
        id3( const vector< list < size_t > > & adj ):
            n( adj.size( ) ),
            depth( vector < size_t > ( n, id3::INF ) ),
            parent( vector < size_t > ( n ) ),
            dist( vector < vector < unsigned short > > ( n ) )
        {

            
            
            queue< size_t > id11;
            id11.push( 0 );
            depth[ 0 ]  = 0;
            parent[ 0 ] = 0;

            while ( ! id11.empty( ) )
            {
                const size_t u = id11.front( );
                id11.pop( );

                for ( list< size_t >::const_iterator j = adj[ u ].begin( ); j != adj[ u ].end( ); ++ j )
                    if ( depth[ u ] + 1 < depth[ *j ] )
                    {
                        depth[ *j ]  = depth[ u ] + 1;
                        parent[ *j ] = u;
                        id11.push( *j );
                    }
            }

            
            for ( size_t j = 1; j < n; ++ j )
                dist[ j ].resize( j, id3::INF );
        }

        
        size_t operator( )( const size_t u, const size_t v )
        {
            if ( u == v )
                return 0;
            else if ( u < v)
                return (*this)( v, u );
            else if ( dist[ u ][ v ] == id3::INF )
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

const unsigned short id3::INF = numeric_limits< unsigned short >::max( );



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



inline size_t revfind(const int a, const size_t l,
        const map< int, vector< size_t > > & loc )
{
    const auto iter = loc.find( a );
    if ( iter == end( loc ) )
        return 0;

    const auto & b = iter->second;
    

    const auto j = upper_bound(begin(b), end(b), l, greater< size_t >());
    return j != end(b) ? *j : 0;
}

size_t recycle(const size_t i, const size_t j, const vector< int > & b,
        const map< int, vector< size_t > > & loc,
        map< pair< size_t, size_t >, size_t > & cache)
{
    if( i == 0 )
        return 0;

    const auto pr = make_pair(i, j);
    const auto iter = cache.find( pr );
    if( iter != end(cache) )
        return iter->second;

    for( size_t l = 0; l + 1 < i && l < j; ++ l )
        if( b[ i - l - 1] != b[ j - l ] )
            return cache[ pr ] = recycle( revfind(b[ i ], i, loc), j, b, loc, cache);

    return cache[ pr ] = i;
}

size_t d471()
{
    size_t n, m;
    cin >> n >> m;

    vector< int > a(n), b(m);
    cin >> a >> b;

    adjacent_difference(begin(b), end(b), begin(b));

    map< int, vector< size_t > > loc;
    for( size_t i = m; 0 < i; -- i )
        loc[ b[i - 1] ].push_back( i - 1 );

    size_t val = 0;
    map< pair< size_t, size_t >, size_t > cache;

    size_t i = 1;
    for( size_t j = 1; j < n; ++ j, ++ i )
        if( i == m )
        {
            ++ val;
            i = recycle(revfind(a[ j ] - a[j - 1], i, loc), i - 1, b, loc, cache);
        }
        else if( a[ j ] - a[ j - 1 ] != b[ i ] )
            i = recycle(revfind(a[ j ] - a[j - 1], i, loc), i - 1, b, loc, cache);

    return val + ( i == m );
}

const char * d472()
{
    size_t n;
    cin >> n;

    vector< vector< int > > dist(n, vector< int >( n ));
    cin >> dist;

    for( size_t j = 0; j < n; ++ j )
    {
        if ( dist[ j ][ j ] != 0 )
            return "NO";

        for( size_t i = j + 1; i < n; ++ i )
        {
            if( dist[ i ][ j ] != dist[ j ][ i ] || dist[ i ][ j ] == 0 )
                return "NO";
        }

        if( n < 2 )
            continue;

        size_t u = j != 0 ? 0 : 1;
        for( size_t i = 0; i < n; ++ i )
            if ( i != j && dist[j][i] < dist[j][u] )
                u = i;

        for( size_t i = 0; i < n; ++ i )
            if ( dist[j][u] + min(dist[j][i], dist[u][i]) != max(dist[j][i], dist[u][i]))
                return "NO";
    }

    return "YES";
}

void c370()
{
    size_t n, m;
    cin >> n >> m;
    vector< int > a(n);
    cin >> a;

    map< int, size_t > cnt;
    for( const auto val: a )
        ++ cnt[ val ];

    vector< pair< size_t, int > > id20;
    for(const auto & pr: cnt )
        id20.push_back(make_pair(pr.second, pr.first));

    sort( begin(id20), end(id20) );
    DEBUG( id20 );

    vector< int > xs;
    for( auto iter = id20.rbegin(); iter != id20.rend(); ++ iter )
        for( size_t i = 0; i < iter->first; ++ i )
            xs.push_back( iter->second );

    vector< int > ys( n );
    ys[ 0 ] = id20[ 0 ].second;
    -- id20[ 0 ].first;

    size_t i = 0, l = 0;

    for( size_t j = 1; j < n; ++ j )
    {
        while( id20[ i ].first == 0 )
            ++ i;

        if( i + 1 == id20.size() || xs[ j ] != id20[ i ].second ||
                ( xs[ j - 1 ] == ys[ j - 1 ] && xs[ j ] == xs[ j - 1 ] ))
        {
            ys[ j ] = id20[ i ].second;
            -- id20[ i ].first;
        }
        else
        {
            l = max( i + 1, l );
            while( l < id20.size() && id20[ l ].first == 0 )
                ++ l;

            auto & ref = l < id20.size() ? id20[ l ] : id20[ i ];
            ys[ j ] = ref.second;
            -- ref.first;
        }
    }

    size_t val = 0;
    for( size_t i = 0; i < n; ++ i )
        val += xs[ i ] != ys[ i ];

    cout << val << '\n';
    for( size_t i = 0; i < n; ++ i )
        cout << xs[ i ] << ' ' << ys[ i ] << '\n';
}

int b301()
{
    size_t n;
    int d;
    cin >> n >> d;

    vector< int > a( n, 0 );
    for( auto iter = begin(a) + 1; iter + 1 != end(a); ++ iter )
        cin >> *iter;

    vector< pair < int, int > > loc( n );
    cin >> loc;

    const auto f = [&loc, &d]( const size_t i, const size_t j )
    {
        const auto a = abs(loc[i].first - loc[j].first);
        const auto b = abs(loc[i].second - loc[j].second);
        return d *( a + b );
    };

    int ub = f(0, n - 1), lb = - 1;
    DEBUG( ub * d );

    while( lb + 1 < ub )
    {
        const auto m = (ub + lb) / 2;

        bool fail = true;
        vector< bool > tag(n, false);
        vector< int > load(n, -1);

        Heap< pair< int, size_t > > heap;
        heap.push( make_pair(m, 0));
        tag[ 0 ] = true;
        load[ 0 ] = 0;

        while( fail && ! heap.empty())
        {
            auto clock = heap.front().first;
            const auto i = heap.front().second;
            heap.pop();

            fail = i != n - 1;
            if( clock < load[ i ] )
                continue;

            tag[ i ] = true;
            clock += a[ i ];

            for( size_t j = 1; fail && j < n; ++ j )
                if( ! tag[ j ] && load[ j ] + f(i, j) < clock )
                {
                    fail = j != n - 1;
                    load[ j ] = clock - f(i, j);
                    heap.push( make_pair( load[ j ], j ));
                }
        }

        (fail ? lb : ub) = m;
    }

    return ub;
}


int main( const int argc, char * argv [ ])
{
    cout << b301();
    


    return EXIT_SUCCESS;
}


