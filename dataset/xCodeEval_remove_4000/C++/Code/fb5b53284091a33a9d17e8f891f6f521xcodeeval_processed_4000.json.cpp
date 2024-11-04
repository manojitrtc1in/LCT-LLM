















using namespace std;

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

int id12() 
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

int id6()  
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

int id7()  
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

int id11 ()  
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
    int n, id2 = 0;
    cin >> n;

    vector <int> a(n);

    

    


    

    for_each ( a.begin(), a.end(), [&](int &x) {
            cin >> x;
            id2 += x;
            } );

    

    sort ( a.begin(), a.end(), greater <int> () );
    partial_sum ( a.begin(), a.end(), a.begin() );

    return upper_bound ( a.begin(), a.end(), id2 / 2)
        - a.begin() + 1;
}

int id8 ()  
{
    vector <int> s(4);

    for (vector <int>::iterator iter = s.begin(); iter != s.end(); ++iter)
        cin >> *iter;

    set <int> x ( s.begin(), s.end() );
    

    

    


    return 4 - x.size();

    

    

}

int id10 ()  
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

string id4 ()  
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

string id9 ()  
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

string id3 ()  
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

string id5 ()  
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

int main()
{
    cout << a262 ();

    return EXIT_SUCCESS;
}
