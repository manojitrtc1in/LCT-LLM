




















using namespace std;

template <class T>
inline vector < T > readin (int n = 0)
{
    


    if ( ! n ) cin >> n;
    vector < T > a ( n );

    copy_n ( istream_iterator <int> ( cin ), n, a.begin() );

    return a;
}

template <class T>
inline vector < T > id7 ( int n = 0 )
{
    typedef typename vector < T >::iterator iterator;

    if ( ! n )
        cin >> n;

    vector < T > a ( n );
    for ( iterator iter = a.begin(); iter != a.end(); ++iter )
        cin >> iter->first >> iter->second;

    return a;
}

string capslock()
{
    string str;
    cin >> str;

    string::iterator iter = str.begin();

    
    while (iter != str.end() && isupper(*iter))
        ++iter;

    bool swap_case = false;

    if (iter == str.end())  
        swap_case = true;
    else if (iter == str.begin())  
    {
        ++iter;
        while (iter != str.end() && isupper(*iter))
            ++iter;

        swap_case = (iter == str.end());  
    }

    if (swap_case)
        for (iter = str.begin(); iter != str.end(); ++iter)
            *iter = isupper(*iter) ? tolower(*iter) : toupper(*iter);

    return str;
}

int gcd(const int a, const int b)  
{
    int x = max(abs(a), abs(b));
    int y = min(abs(a), abs(b));
    int r = x % y;

    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }

    return y ? y : x;
}

int id16() 
{
    int a, b, n;
    cin >> a >> b >> n;

    while (true)
    {
        if ( n != 0 )
            n -= gcd(n, a);
        else
            return 1;

        if ( n != 0 )
            n -= gcd( n, b );
        else
            return 0;
    }
}

int team()  
{
    int n, res = 0;
    cin >> n;

    for ( int j = 0; j < n; ++j )
    {
        int s = 0, a;
        for ( int  k = 0; k < 3; ++k )
        {
            cin >> a;
            s += a;
        }

        res += (s > 1);
    }

    return res;
}

int id9()  
{
    vector < string > str;

    for (int j = 0; j < 2; ++j)
    {
        string s;
        cin >> s;
        str.push_back (s);
    }

    

    

    

    for_each ( str.begin(), str.end(),
            [](string & a) { transform ( a.begin(), a.end(), a.begin(), ::tolower );} );  


    return str[0] < str[1] ? -1 :
        str[0] > str[1] ? 1 : 0;
}

int id10()  
{
    int n, k = 0;
    string colstr;

    cin >> n >> colstr;

    for (string::const_iterator iter = colstr.begin() + 1; iter != colstr.end(); ++iter)
        k += *iter == *(iter-1);

    return k;
}

int bitpp()  
{
    int n, res = 0;
    string str;

    cin >> n;

    for ( int j=0; j < n; ++j )
    {
        cin >> str;
        res += (str[0] == '+' || str[2] == '+') ? 1 : -1;
    }

    return res;
}

int id14 ()  
{
    vector <int> k;
    int d, a, res = 0;

    for (int j = 0; j < 4; ++j) {
        cin >> a;
        k.push_back(a);
    }

    cin >> d;

    for ( int j = 1; j <= d; ++j )
        for ( vector<int>::const_iterator iter = k.begin(); iter != k.end(); ++iter )
            if (! (j % *iter) ) {
                ++res;
                break;
            }

    return res;
}

string id1()  
{
    string str;
    cin >> str;

    return str.find_first_of ( "HQ9" ) != string::npos ?
        "YES" : "NO";
}

string football()  
{
    string str;
    cin >> str;

    return str.find ( "1111111" ) != string::npos
        || str.find ( "0000000" ) != string::npos ?
        "YES" : "NO";
}

int twin ()  
{
    int n, id3 = 0;
    cin >> n;

    vector <int> a(n);

    

    


    

    for_each ( a.begin(), a.end(), [&](int &x) {
            cin >> x;
            id3 += x;
            } );

    

    sort ( a.begin(), a.end(), greater <int> () );
    partial_sum ( a.begin(), a.end(), a.begin() );

    return upper_bound ( a.begin(), a.end(), id3 / 2)
        - a.begin() + 1;
}

int id11 ()  
{
    vector <int> s(4);

    for (vector <int>::iterator iter = s.begin(); iter != s.end(); ++iter)
        cin >> *iter;

    set <int> x ( s.begin(), s.end() );
    

    

    


    return 4 - x.size();

    

    

}

int id13 ()  
{
    int n;
    cin >> n;

    vector <int> a ( n );
    for (vector <int>::iterator iter = a.begin(); iter != a.end(); ++iter)
        cin >> *iter;

    

    pair<vector <int>::const_iterator, vector <int>::const_iterator>
        min_max = minmax_element (a.begin (), a.end ());

    const int jmax = find( a.begin(), a.end(), *min_max.second ) - a.begin();
    const int jmin = find( a.rbegin(), a.rend(), *min_max.first ) - a.rbegin(); 


    return jmax + jmin - (jmin + jmax > n - 2);
}

string id6 ()  
{
    string str;
    std::cin >> str;

    int ln = count( str.begin(), str.end(), '4' )
        + count( str.begin(), str.end(), '7' );

    


    

    


    do
    {
        const int res = ln % 10;

        if ( res != 7 && res != 4 )
            return "NO";

        ln /= 10;

    } while ( ln );

    return "YES";
}

void presents ()  
{
    int n;
    cin >> n;

    vector<int> a( n );
    for (vector <int>::iterator iter = a.begin(); iter != a.end(); ++iter)
        cin >> *iter;

    vector<int> x( n );

    vector<int>::const_iterator iter = a.begin();

    for ( int j = 1; iter != a.end(); ++j, ++iter )
        x[ *iter - 1] = j;

    

    

    ostream_iterator <int> out_iter (cout, " ");
    copy ( x.begin(), x.end(), out_iter );
}

string id12 ()  
{
    int n, t;
    cin >> n >> t;

    string str;
    cin >> str;

    for ( int j = 0; j < t; ++j )
        for ( string::iterator iter = str.begin (); iter < str.end (); ++iter)
            if ( *iter == 'B' && *(iter + 1) == 'G' ) {
                *iter = 'G';
                *(iter + 1) = 'B';
                ++iter;
            }

    return str;
}

string id4 ()  
{
    string str;
    cin >> str;

    const set <char> chset(str.begin(), str.end());

    return chset.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!";

}

int games () 
{
    int n;
    cin >> n;

    

    vector < pair<int, int> > col( n );

    for ( vector < pair<int, int> >::iterator iter = col.begin (); iter != col.end(); ++iter )
        cin >> iter->first >> iter->second;

    int res = 0;

    

    for_each ( col.begin (), col.end (), [&col, &res] ( const pair<int, int> & x )
            {
            for_each ( col.begin (), col.end (), [&x, &res] ( const pair <int, int> & y )
                {
                res += x.first == y.second;
                } );
            } );

    return res;
}

int beautiful_year ()  
{
    int n;
    cin >> n;

    set <int> s;

    for ( ; s.size() != 4; ++n )
    {
        s.clear();
        for ( int j = n + 1; j; j /= 10 )
            s.insert ( j % 10 );
    }

    return n;
}

string id0 ()  
{
    string str;
    cin >> str;

    str[0] = toupper(str[0]);
    return str;
}

int beautiful_matrix ()  
{
    bool bit;

    for ( int i = 0; ; ++i )
        for ( int j = 0; j < 5; ++j )
        {
            cin >> bit;
            if (bit)
                return abs(i-2) + abs(j-2);
        }
}

string id8 ()  
{
    string a, b, x;
    cin >> a >> b;

    for ( string::const_iterator i = a.begin(), j = b.begin();
            i != a.end() && j != b.end(); ++i, ++j )
        x.push_back( *i == *j ? '0' : '1' );

    return x;
}

void b118 ( ) 
{
    int n;
    cin >> n;

    for ( int i = 0; i <= 2*n; ++i, cout << '\n' )
    {
        const int k = i < n ? i : 2*n - i;

        for ( int j = 0; j < n - k; ++ j )
            cout << "  ";

        for ( int j = 0; j <= k; ++j, cout << ( j <= k ? " " : "" ) )
            cout << j;

        for ( int j = k-1; j >= 0; --j)
            cout << ' ' << j;
    }
}

int a155 ( )  
{
    int n;
    cin >> n;

    vector < int > a(n);

    

    


    

    copy_n ( istream_iterator <int> ( cin ), n, a.begin() );

    int k = 0, rmin = a[0], rmax = a[0];

    for_each ( a.begin(), a.end (), [&rmin, &rmax, &k] ( const int x )
            {
                if ( x > rmax )
                {
                    rmax = x;
                    ++k;
                }
                else if ( x < rmin )
                {
                    rmin = x;
                    ++k;
                }
            } );

    return k;
}

int a149 ( )  
{
    int k;
    cin >> k;

    if ( ! k ) return 0;

    vector <int> a ( 12 );
    copy_n ( istream_iterator <int> ( cin ), 12, a.begin() );

    sort ( a.begin(), a.end(), greater<int> ( ) );
    partial_sum ( a.begin(), a.end(), a.begin () );

    vector <int>::const_iterator iter = lower_bound ( a.begin(), a.end (), k );

    return iter != a.end() ? iter - a.begin() + 1: -1;
}

string a208 ( )  
{
    string str;
    cin >> str;

    

    for ( size_t pos = str.find ( "WUB" ); pos != string::npos; pos = str.find ( "WUB" ) )
        str.replace ( pos, 3, pos > 0 && str[ pos - 1 ] != ' ' ? " " : "" );

    return str;
}

int d158 ( )  
{
    int n;
    cin >> n;

    vector <int> t ( n );
    copy_n ( istream_iterator <int> ( cin ), n, t.begin () );

    int maxsum ( numeric_limits< int >::min() ); 


    

    for ( int k = 1 ; k <= n / 3 ; ++k )  
        if ( ! (n % k) )
            for ( vector <int>::const_iterator j = t.begin() ; j != t.begin() + k ; ++j )
            {
                int sum = 0L;

                for ( vector <int>::const_iterator iter = j; iter < t.end();
                        sum += *iter, iter += k ) ;

                if ( sum > maxsum ) maxsum = sum;
            }

    return maxsum;
}

int a124 ( )  
{
    int n, a, b;
    cin >> n >> a >> b;

    

    return n - max ( a, n - b - 1);
}

int a278 ( )  
{
    int n, s, t;
    cin >> n;

    vector <int> d(n);
    copy_n ( istream_iterator < int > ( cin ), n, d.begin () );

    cin >> s >> t;

    const int total = accumulate ( d.begin(), d.end(), 0 );

    vector < int >::const_iterator first = d.begin() + min(s, t) - 1;
    vector < int >::const_iterator last  = d.begin() + max(s, t) - 1;

    const int partial = accumulate ( first, last, 0 );
    return min ( partial, total - partial );
}

void a270 ( )  
{
    int n;
    cin >> n;

    vector < int > alpha(n);
    copy_n ( istream_iterator < int >( cin ), n, alpha.begin () );

    for_each ( alpha.begin (), alpha.end (), [](const int a ) {
            cout << ( 360 % (180 - a) ? "NO" : "YES" ) << '\n' ; } );
}

const char * a230 ( )  
{
    int s, n;
    cin >> s >> n;

    vector < pair <int, int> > drg ( n );
    for ( vector < pair <int, int> >::iterator iter = drg.begin(); iter != drg.end(); ++iter )
        cin >> iter->first >> iter->second;

    

    

    struct Comp
    {
        bool operator ()( const pair <int, int> & a, const pair <int, int> & b )
        {
            return a.first < b.first
                || ( a.first == b.first && a.second > b.second );
        };
    } ; 


    


    

    

    



    return "YES";
}

double b200 ( ) 
{
    int n; cin >> n;

    vector <int> x ( n );

    copy_n ( istream_iterator <int> ( cin ), n, x.begin() );

    return accumulate ( x.begin(), x.end(), 0.0 ) / n;
}

int a48 ( ) 
{
    int n; cin >> n;

    return n * 3 / 2;
}

void b263 ( )  
{
    int n, k;
    cin >> n >> k;

    if ( k > n )
    {
        cout << -1;
        return;
    }

    vector <int> a ( n );
    copy_n ( istream_iterator < int > ( cin ), n, a.begin() );

    partial_sort ( a.begin(), a.begin() + n - k + 1, a.end() );

    cout << a[n - k] << ' ' << 0;
}

int a265 ( )  
{
    string s, t;
    cin >> s >> t;

    string::const_iterator pos = s.begin();

    for ( string::const_iterator ins = t.begin();
          ins != t.end();
          pos += *pos == *ins++ )
        ;

    return pos - s.begin() + 1;
}

int a168 ( )  
{
    int n, x, y;
    cin >> n >> x >> y;

    return static_cast < int > ( ceil ( max ( n * y / 100.0  - x, .0 )));
}

long long a318 ( ) 
{
    long long n, k;
    cin >> n >> k;

    return ( k > ( n + 1 ) / 2 )
        ? 2 * ( k - ( n + 1 ) / 2 )
        : 2 * k - 1;
}

template < class InputIterator >  

inline map < typename iterator_traits< InputIterator >::value_type,
             typename iterator_traits< InputIterator >::difference_type >
count_each ( InputIterator first, InputIterator last )
{
    typedef typename iterator_traits<InputIterator>::value_type      key_type; 

    typedef typename iterator_traits<InputIterator>::difference_type mapped_type;
    


    map < key_type, mapped_type > count;
    for ( ; first != last; ++count[ *first++ ] )  

        ;
    return count;
}

string a219 ( ) 
{
    int k; cin >> k;
    string str; cin >> str;

    

    typedef typename iterator_traits< string::iterator >::difference_type  difference_type;

    map <string::value_type, difference_type> count (
            count_each< string::iterator > ( str.begin(), str.end() ));

    string wrd;
    for ( map <char, difference_type>::const_iterator iter = count.begin();
            iter != count.end(); ++iter )

        if ( iter->second % k ) return "-1";
        else wrd += string ( iter->second / k, iter->first );

    string res;
    for ( int j = 0; j < k; ++j, res += wrd )
        ;

    return res;
}

string a59 ( )  
{
    string str;
    cin >> str;

    const unsigned k = count_if ( str.begin(), str.end(), ::isupper ); 


    int (* oper ) ( int ) ( k > str.length() / 2 ? ::toupper : ::tolower );  

    transform ( str.begin(), str.end(), str.begin(), oper );  


    return str;
}

void a221 ( )  
{
    int n; cin >> n;

    cout << n;
    for ( int j = 1; j < n; cout << ' ' << j++ )
        ;
}

int a129 ( ) 
{
    int n; cin >> n;

    vector <int> a ( n );
    copy_n ( istream_iterator <int> ( cin ), n, a.begin() );

    const int sum = accumulate (a.begin(), a.end(), 0 );

    

    

    

    

    


    

    const int nodd = count_if ( a.begin(), a.end(), [](const int & x) { return x % 2; });

    return sum % 2 ? nodd : n - nodd;
}

int a224 ( )  
{
    int x, y, z;
    cin >> x >> y >> z;

    int a = sqrt ( x * y / z ),
        b = sqrt ( x * z / y ),
        c = sqrt ( y * z / x );

    return 4 * ( a + b + c );
}

int a262 ( ) 
{
    int n, k;
    cin >> n >> k;

    vector < string > str ( n );
    copy_n ( istream_iterator < string > ( cin ), n, str.begin () );

    

    return count_if ( str.begin(), str.end(), [ &k ] ( const string & a )
            { return count_if ( a.begin(), a.end(), [] ( const char & ch )
                { return ch == '4' || ch == '7'; } ) <= k; } );
}

const char * a146 ( )  
{
    int n; cin >> n;

    string str;
    cin >> str;

    if ( find_if ( str.begin(), str.end(), [] ( const char & ch )
                { return ch != '4' && ch != '7'; } ) != str.end() )
        return "NO";

    const int s0 = accumulate ( str.begin(), str.begin() + n/2, 0,  

            [] ( int a, const char & ch ) { return a + ( ch - '0' ); } );

    const int s1 = accumulate ( str.begin() + n/2, str.end(), 0,
            [] ( int a, const char & ch ) { return a + ( ch - '0' ); } );

    return s0 == s1 ? "YES" : "NO";
}

void a114 ( ) 
{
    int k, l;
    cin >> k >> l;

    const int p = ::round ( ::log ( l ) / ::log ( k ));

    const double err = ::pow(k, p) - l;  

    const double id5 = err > 0 ? err : -err;

    if ( id5 < 1e-8 )
        cout << "YES\n" << p - 1;
    else
        cout << "NO";
}

void a330 ( )  
{
    int n; cin >> n;

    vector <int> a ( n );
    copy_n ( istream_iterator < int > ( cin ), n, a.begin( ));

    


    int n1 = 0, n2 = 0, n3 = 0;
    for_each ( a.begin(), a.end(), [ &n1, &n2, &n3 ] ( const int & x ) {
            if      ( x > 0 ) ++n2;
            else if ( x < 0 ) ++n1;
            else              ++n3; } );

    if ( ! ( n1 % 2 ))
        n2 = n - ++n3 - 1;
    else
        n2 = n - n3 - 1;

    vector< int >::iterator iter1 = find_if ( a.begin(), a.end(),
            bind2nd ( less <int> ( ), 0 ) );

    const vector< int >::const_iterator iter2 = ! ( n1 % 2 )
        ? find_if ( iter1 + 1, a.end(), bind2nd ( less <int> ( ), 0 ))
        : iter1;

    cout << 1 << ' ' << *iter1 << '\n' << n2;

    for ( vector <int>::const_iterator j = a.begin(); j != a.end(); ++ j )
        if ( *j && j != iter1 && j != iter2 )
            cout << ' ' << *j;

    ostream_iterator <int> out_iter (cout, " ");

    

    


    

    


    cout << '\n' << n3 << " ";
    copy_if ( a.begin(), a.end(), out_iter, bind2nd ( equal_to < int > (), 0 ));

    if ( ! ( n1 % 2 ))
        cout << ' ' << * iter2;

}

int a215 ( )  
{
    int n, m;
    cin >> n;
    vector < int > a ( n );
    copy_n ( istream_iterator < int > ( cin ), n, a.begin() );

    cin >> m;
    vector < int > b ( m );
    copy_n ( istream_iterator < int > ( cin ), m, b.begin() );

    int ratio = 1, k = 0;

    for_each ( a.begin(), a.end(), [&k, &ratio, &b]( const int & x ) {
            for_each ( b.begin(), b.end(), [&k, &x, &ratio] (const int & y) {
                if ( ! (y % x) )
                {
                    const int frac = y / x;
                    if ( frac > ratio )
                    {
                        ratio = frac;
                        k = 0;
                    }

                    k +=  frac == ratio;
                } } ); } );
    return k;
}

int a152 ( )  
{
    int n, m;
    cin >> n >> m;

    vector < vector < char > > score (m, vector < char > ( n ));

    for ( int j = 0; j < n; ++j )
        for ( vector < vector < char > >::iterator iter = score.begin(); iter != score.end(); ++iter )
            cin >> (*iter)[ j ];

    set <int > top;
    for ( vector < vector < char > >::iterator iter = score.begin(); iter != score.end(); ++iter )
    {
        vector<char>::iterator j = max_element ( iter->begin(), iter->end() );
        const char max_score = *j;

        do
        {
            top.insert ( j - iter->begin() );
            j = find ( j + 1, iter->end(), max_score );
        }
        while ( j != iter->end() );
    }

    return top.size();
}

int a139 ( )  
{
    int n; cin >> n;

    vector <int> m ( 7 );
    copy_n ( istream_iterator <int>( cin ), 7, m.begin() );

    const int k = m.rend() - find_if ( m.rbegin(), m.rend(), bind2nd ( greater <int>(), 0 ));
    partial_sum ( m.begin(), m.end(), m.begin() );

    return n % m.back()
        ? lower_bound ( m.begin(), m.end(), n % m.back() ) - m.begin() + 1 : k;
}

void b1 ( )  
{
    int n; cin >> n;

    vector < string > str ( n );
    copy_n ( istream_iterator < string > ( cin ), n, str.begin() );

    for ( vector < string >::const_iterator iter = str.begin(); iter != str.end(); ++ iter )
    {
        vector <string> tok (1, "");
        bool digit = false;

        for ( string::const_iterator j = iter->begin(); j != iter->end(); ++ j )

            if ( digit == ( *j >= '0' && *j <= '9' ))
                tok.back().push_back ( *j );
            else
            {
                tok.push_back ( string(1, *j ));
                digit = ! digit;
            }

        if ( tok.size() == 2 )
        {
            int col = 0;
            for ( string::const_iterator i = tok.front().begin(); i != tok.front().end(); ++ i)
                col = 26 * col + ( *i - 'A' + 1);

            cout << 'R' << tok.back() << 'C' << col << '\n';
        }
        else
        {
            string id2;
            for ( int col = ::atoi ( tok.back().c_str() ); col; col = (col - 1) / 26 ) 

                id2.push_back ( static_cast <char> ( 'A' + ( col + 25 ) % 26 )); 


            cout << string ( id2.rbegin(), id2.rend() ) << tok[ 1 ] << '\n';
        }
    }
}

int a38 ( )  
{
    int n, a, b;
    cin >> n;

    vector < int > d ( n );
    copy_n ( istream_iterator < int > ( cin ), n - 1, d.begin() + 1);

    cin >> a >> b;
    partial_sum ( d.begin(), d.end(), d.begin() );

    return d[ b - 1 ] - d[ a - 1 ];
}

template < class T >
struct Divisor : public binary_function<T, T,bool>
{
    bool operator() ( const T & a, const T & b ) const { return ( b < a ) && ! ( a % b ); }
};

void b230 ( )
{
    vector < long long > a ( readin < long long > ( ));

    list < long long > id15;

    for ( vector< long long>::const_iterator iter = a.begin(); iter != a.end(); ++iter )
    {
        const long long s = static_cast < long long > ( sqrt ( *iter ));
        const long long r = s % 6;

        if ( s > 3 && r != 1 && r != 5 )
            continue;

        if ( s * s == *iter && s != 1 ) 

            id15.push_back ( s );
    }

    

    


    const long long max_val = * max_element ( id15.begin(), id15.end() );

    vector < long long > vp;
    vp.reserve ( id15.size() );

    for ( long long j = 6; j < max_val / 5 + 1 && ! id15.empty(); j += 6 )
    {
        const long long a = j - 1, b = j + 1;

        for ( list < long long >::iterator iter = id15.begin(); iter != id15.end(); )
        {
            if ( *iter <= a )  

                vp.push_back ( (*iter) * (*iter) );
            else if ( ( *iter % a ) && ( *iter == b || ( *iter % b ) ) )
            {
                ++iter;
                continue;
            }

            iter = id15.erase( iter );
        }
    }


    for ( list < long long >::iterator iter = id15.begin(); iter != id15.end(); ++iter)
        vp.push_back ( (*iter) * (*iter) );

    set < long long > tprime ( vp.begin(), vp.end() );

    

    

    

    

    

    

    

        


    


    

    


    for ( vector < long long>::const_iterator iter = a.begin(); iter != a.end(); ++iter )
        cout << (tprime.count( *iter ) ? "YES" : "NO") << '\n';

        

        

        

        

        


    

    


    

    

    

    


    


    

    

    

    

    

}

void b327( )
{
    long long n; cin >> n;

    

    for ( long long j = n; j < 2*n; ++ j )
        cout << j << ' ';

    

    


    

    


    

    

    

    


    

    

    


    

    

}

template < class T >
T maxi ( int n, ... )
{
    va_list vl;
    va_start ( vl, n );
    T res = va_arg ( vl, T );

    for ( int j = 1; j < n; ++j )
    {
        const T val = va_arg ( vl, T);
        res = max ( res, val );
    }

    va_end ( vl );
    return res;
}

void b259 ( )  
{
    int x, a, b, c, y, d, e, f, z;

    cin >> x >> a >> b;
    cin >> c >> y >> d;
    cin >> e >> f >> z;

    

    

    

    

    

    

    


    


    x = a + b + ( d + f ) / 2 - c - e;

    y = x + c + e - ( a + f );
    z = x + c + e - ( b + d );

    

    

    

    

    


    cout << x << ' ' << a << ' ' << b << '\n';
    cout << c << ' ' << y << ' ' << d << '\n';
    cout << e << ' ' << f << ' ' << z << '\n';
}

int a166 ( )  
{
    int n, k;
    cin >> n >> k;

    vector < pair < int, int > > x( n );
    for ( vector < pair < int , int > >::iterator iter = x.begin(); iter != x.end(); ++ iter )
        cin >> iter->first >> iter->second;

    

    sort ( x.begin(), x.end(),  []( const pair<int, int> & a , const pair<int, int> &b) -> bool {
            return a.first > b.first || ( a.first == b.first && a.second < b.second ); } );

    

    


    const int i = find ( x.begin(), x.end(), x[ k - 1 ] ) - x.begin();
    const int j = x.rend() - find ( x.rbegin(), x.rend(), x[ k - 1] );

    return j - i;
}

void b330 ( )  
{
    string str;
    cin >> str;

    int n; cin >> n;
    vector < pair < int, int > > x ( n );

    for_each ( x.begin(), x.end(), []( pair <int, int> & a ) { cin >> a.first >> a.second; } );

    vector < int > s ( str.length () );

    for ( unsigned j = 1; j < str.length(); ++ j )
        s [ j ] = s[ j - 1 ] + ( str[ j ] == str[ j - 1 ] );

    for_each ( x.begin(), x.end(), [ &s ]( const pair <int, int> & a )
            { cout << s[ a.second - 1] - s[ a.first - 1 ] << '\n' ; } );
}

const char * a225 ( )  
{
    int n, top;
    cin >> n >> top;

    vector < pair < int, int > > x = id7 < pair <int, int> > ( n );

    for ( vector < pair < int , int > >::const_iterator iter = x.begin() + 1 ; iter != x.end(); ++iter )
        if ( top == iter->first || top == 7 - iter->first || top == iter->second || top == 7 - iter->second )
            return "NO";

    return "YES";
}

void a322 ( )  
{
    int n, m;
    cin >> n >> m;

    cout << n + m - 1 << '\n';

    for ( int j = 0; j < m; cout << 1 << ' ' << ++j  << '\n' )
        ;

    for ( int j = 1; j < n; cout << ++j << ' ' << m << '\n' )
        ;
}

template < class T >
typename T::value_type sum ( const T & x )
{
    return accumulate ( x.begin(), x.end(), typename T::value_type ( 0 ) );
}

int a157 ( ) 
{
    int n;    cin >> n;

    vector < vector < int > > x ( n, vector < int > ( n ) );

    for ( vector < vector < int > >::iterator iter = x.begin(); iter != x.end(); ++ iter )
        copy_n ( istream_iterator < int > ( cin ), n, iter->begin() );

    vector < int > rowsum ( n ), colsum ( n );
    transform ( x.begin(), x.end(), rowsum.begin(), sum < vector <int > > );

    for_each ( x.begin(), x.end(), [ & colsum ] ( const vector < int > & a ) {
            transform ( a.begin(), a.end(), colsum.begin(), colsum.begin(), plus < int > () ); } );

    int res = 0;

    for ( vector < int >::const_iterator iter = colsum.begin(); iter != colsum.end(); ++ iter )
        res += count_if ( rowsum.begin(), rowsum.end(), bind2nd ( less <int> (), *iter ));

    return res;
}

template <class T> 

class Counter
{
    public:
        template <class InputIterator>
            Counter (InputIterator first, InputIterator last) { upsert (first, last); };

        template <class InputIterator>
            void upsert (InputIterator first, InputIterator last);

        

    private:
        map <T, int> count;
};

template <class T>  

template <class InputIterator>
void Counter<T>::upsert (InputIterator first, InputIterator last)
{
    for (InputIterator iter = first; iter != last; ++iter )
        ++ count [ * iter ];
    

    


    

    

    

    

    

}


































int b127 ( )  
{
    const vector < int > x ( readin < int > ( ) );

    map < int, int > count;
    for ( vector < int >::const_iterator iter = x.begin (); iter != x.end(); ++ iter )
        ++ count [ * iter ];

    vector < int > k ;
    for ( map < int, int >::const_iterator iter = count.begin(); iter != count.end(); ++ iter )
        k.push_back ( iter -> second / 2 );

    return accumulate ( k.begin(), k.end(), 0 ) / 2;
}

template < class T >
map < typename T::value_type, typename T::difference_type >
count_each ( const T & x )
{
    map < typename T::value_type, typename T::difference_type > count;

    for ( typename T::const_iterator iter = x.begin(); iter != x.end(); ++iter )
        ++ count [ * iter ];

    return count;
}

const char * a296 ( ) 
{
    const vector < int > x ( readin < int > ( ) );

    typedef typename vector < int >::difference_type value_type;

    map < int, value_type > count = count_each ( x );

    value_type k = 0;
    for ( map < int, value_type >::const_iterator iter = count.begin(); iter != count.end(); ++ iter )
        k = max ( k, iter->second );

    return k <= static_cast < value_type > ( ( x.size() + 1 ) / 2 ) ? "YES" : "NO";
}

void a253( )  
{
    ifstream fin ( "input.txt" );
    int n, m;

    fin >> n >> m;
    fin.close();

    string res;

    for ( int j = 0; j < min(n, m); ++j )
        res += string ( m < n ? "BG" : "GB" );

    res += string ( max(n, m) - min(n, m), m < n ? 'B' : 'G' );

    ofstream fout ( "output.txt" );
    fout << res;
    fout.close();
}


int main()
{
    a253 ();

    return EXIT_SUCCESS;
}
