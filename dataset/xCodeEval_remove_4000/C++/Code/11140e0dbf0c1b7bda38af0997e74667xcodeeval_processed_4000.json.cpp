



using namespace std ;




typedef long long int LLI ;
typedef long double LD ;
typedef pair < int , int > PII ;
typedef pair < LLI , LLI > PLLILLI ;

typedef vector < int > VI ;
typedef vector < LLI > VLLI ;
typedef vector < bool > VB ;
typedef vector < string > VS ;
typedef vector < float > VF ;
typedef vector < double > VD ;
typedef vector < LD > VLD ;
typedef vector < PII > VPII ;
typedef vector < PLLILLI > VPLLILLI ;

typedef vector < VI > VVI ;
typedef vector < VVI > VVVI ;
typedef vector < VVVI > VVVVI ;
typedef vector < VLLI > VVLLI ;
typedef vector < VVLLI > VVVLLI ;
typedef vector < VVVLLI > VVVVLLI ;
typedef vector < VB > VVB ;
typedef vector < VS > VVS ;
typedef vector < VF > VVF ;
typedef vector < VD > VVD ;
typedef vector < VLD > VVLD ;
typedef vector < VPII > VVPII ;
typedef vector < VPLLILLI > VVPLLILLI ;

typedef set < int > SI ;
typedef set < LLI > SLLI ;
typedef set < PII > SPII ;
typedef set < PLLILLI > SPLLILLI ;
typedef set < string > SS ;

typedef unordered_set < int > USI ;
typedef unordered_set < LLI > USLLI ;
typedef unordered_set < PII > USPII ;
typedef unordered_set < PLLILLI > USPLLILLI ;
typedef unordered_set < string > USS ;

typedef map < int , int > MII ;
typedef map < LLI , LLI > MLLILLI ;
typedef map < int , PII > MIPII ;
typedef map < PII , PII > MPIIPII ;
typedef map < PII , int > MPIII ;
typedef map < int , string > MIS ;
typedef map < string , int > MSI ;
typedef map < string , string > MSS ;

typedef unordered_map < int , int > UMII ;
typedef unordered_map < LLI , LLI > UMLLILLI ;
typedef unordered_map < int , PII > UMIPII ;
typedef unordered_map < PII , PII > UMPIIPII ;
typedef unordered_map < PII , int > UMPIII ;
typedef unordered_map < int , string > UMIS ;
typedef unordered_map < string , int > UMSI ;
typedef unordered_map < string , string > UMSS ;





















template < class T > void id4 ( const char * s , T arr , int n , int m )
{
    cout << "> " << s << endl ;
    cout << "[" << endl ;
    FIE ( i , 0 , n )
    {
        cout << "{" ;
        FIE ( j , 0 , m )
        {
            cout << arr [ i ] [ j ] << ( j == m - 1 ? "" : "," ) ;
        }
        cout << "}" << endl ;
    }
    cout << "]" << endl ;
}

template < class T > void id4 ( const char * s , T arr , int n )
{
    cout << "> " << s << endl ;
    cout << "[" << endl ;
    FIE ( i , 0 , n )
    {
        cout << i << " - {" ;
        FIE ( j , 0 , ( int ) arr [ i ].size () )
        {
            cout << arr [ i ] [ j ] << ( j == ( int ) arr [ i ].size () - 1 ? "" : "," ) ;
        }
        cout << "}" << endl ;
    }
    cout << "]" << endl ;
}

template < class T > void id6 ( const char * s , T arr , int n )
{
    cout << "> " << s << endl ;
    cout << "[" << endl ;
    FIE ( i , 0 , n )
    {
        cout << arr [ i ] << ( i == n - 1 ? "" : "," ) ;
    }
    cout << endl << "]" << endl ;
}

template < class T > void id6 ( const char * s , T arr )
{
    cout << "> " << s << endl ;
    cout << "[" << endl ;
    FIE ( i , 0 , arr.size () )
    {
        cout << arr [ i ] << ( i == ( int ) arr.size () - 1 ? "" : "," ) ;
    }
    cout << endl << "]" << endl ;
}

template < class T > void print_set ( const char * s , set < T > & myset )
{
    cout << "> " << s << endl ;
    cout << "[" << endl ;
    TR ( it , myset )
    {
        cout << * it << " " ;
    }
    cout << endl << "]" << endl ;
}

template < class T > void id0 ( const char * s , unordered_set < T > & myset )
{
    cout << "> " << s << endl ;
    cout << "[" << endl ;
    TR ( it , myset )
    {
        cout << * it << " " ;
    }
    cout << endl << "]" << endl ;
}

template < class T1 , class T2 > void print_map ( const char * s , map < T1 , T2 > & id2 )
{
    cout << "> " << s << endl ;
    cout << "[" << endl ;
    TR ( it , id2 )
    {
        cout << "{" << it->f << "->" << it->s << "}" << endl ;
    }
    cout << "]" << endl ;
}

template < class T1 , class T2 > void id3 ( const char * s , unordered_map < T1 , T2 > & id2 )
{
    cout << "> " << s << endl ;
    cout << "[" << endl ;
    TR ( it , id2 )
    {
        cout << "{" << it->f << "->" << it->s << "}" << endl ;
    }
    cout << "]" << endl ;
}





    






const int N = 1000 ;
LLI MOD = 1e9 + 7 , ans = 1 , d , x , y ;
int n ;
LLI no [ N ][ N ] ;
int d1 [ N ] [ N ] ;
LD dist1 [ N ] [ N ] ;
int d2 [ N ] [ N ] ;
LD dist2 [ N ] [ N ] ;
int d3 [ N ] [ N ] ;
LD dist3 [ N ] [ N ] ;
int d4 [ N ] [ N ] ;
LD dist4 [ N ] [ N ] ;
int I , J , min_d ;
LD min_ans , id5 ;

bool valid ( int x )
{
    return ( x >= 0 && x < n ) ;
}

LLI mul ( LLI a , LLI b )
{
    return ( a * b ) % MOD ;
}

void id7 ()
{
    FIE ( i , 0 , n )
    {
        FIE ( j , 0 , n )
        {
            if ( no [ i ] [ j ] == 0 )
            {
                continue ;
            }
            LD temp = 0 ;
            d = min ( d1 [ i ] [ j ] , min ( d2 [ i ] [ j ] , min ( d3 [ i ] [ j ] , d4 [ i ] [ j ] ) ) ) ;
            d -- ;
            if ( valid ( i - d - 1 ) && valid ( j ) )
            {
                temp -= dist1 [ i - d - 1 ] [ j ] ;
            }
            temp += dist1 [ i ] [ j ] ;
            if ( valid ( i ) && valid ( j + d + 1 ) )
            {
                temp -= dist2 [ i ] [ j + d + 1 ] ;    
            }
            temp += dist2 [ i ] [ j ] ;
            if ( valid ( i + d + 1 ) && valid ( j ) )
            {
                temp -= dist3 [ i + d + 1 ] [ j ] ;    
            }
            temp += dist3 [ i ] [ j ] ;
            if ( valid ( i ) && valid ( j - d - 1 ) )
            {
                temp -= dist4 [ i ] [ j - d - 1 ] ;    
            }
            temp += dist4 [ i ] [ j ] ;
            temp -= 3 * log ( no [ i ] [ j ] ) ;
            if ( temp > min_ans )
            {
                min_ans = temp ;
                min_d = d ;
                I = i ;
                J = j ;
            }
        }
    }
    if ( id5 == min_ans )
    {
        return ;
    }
    
        cout << "updated" << endl ;
    
    ans = no [ I ] [ J ] ;
    FII ( i , 1 , min_d )
    {
        ans = mul ( ans , no [ I - i ] [ J ] ) ;
        ans = mul ( ans , no [ I ] [ J + i ] ) ;
        ans = mul ( ans , no [ I + i ] [ J ] ) ;
        ans = mul ( ans , no [ I ] [ J - i ] ) ;
    }
}

void set44 ()
{
    FDEI ( i , n , 0 )
    {
        FIE ( j , 0 , n )
        {
            if ( no [ i ] [ j ] )
            {
                x = i ;
                y = j - 1 ;
                if ( valid ( x ) && valid ( y ) )
                {
                    d4 [ i ] [ j ] += d4 [ x ] [ y ] ;
                    dist4 [ i ] [ j ] += dist4 [ x ] [ y ] ;
                }
                d4 [ i ] [ j ] ++ ;
                dist4 [ i ] [ j ] += log ( no [ i ] [ j ] ) ;
            }
        }
    }
}

void set33 ()
{
    FDEI ( i , n , 0 )
    {
        FIE ( j , 0 , n )
        {
            if ( no [ i ] [ j ] )
            {
                x = i + 1 ;
                y = j ;
                if ( valid ( x ) && valid ( y ) )
                {
                    d3 [ i ] [ j ] += d3 [ x ] [ y ] ;
                    dist3 [ i ] [ j ] += dist3 [ x ] [ y ] ;
                }
                d3 [ i ] [ j ] ++ ;
                dist3 [ i ] [ j ] += log ( no [ i ] [ j ] ) ;
            }
        }
    }
}

void set22 ()
{
    FIE ( i , 0 , n )
    {
        FDEI ( j , n , 0 )
        {
            if ( no [ i ] [ j ] )
            {
                x = i ;
                y = j + 1 ;
                if ( valid ( x ) && valid ( y ) )
                {
                    d2 [ i ] [ j ] += d2 [ x ] [ y ] ;
                    dist2 [ i ] [ j ] += dist2 [ x ] [ y ] ;
                }
                d2 [ i ] [ j ] ++ ;
                dist2 [ i ] [ j ] += log ( no [ i ] [ j ] ) ;
            }
        }
    }
}

void set11 ()
{
    FIE ( i , 0 , n )
    {
        FIE ( j , 0 , n )
        {
            if ( no [ i ] [ j ] )
            {
                x = i - 1 ;
                y = j ;
                if ( valid ( x ) && valid ( y ) )
                {
                    d1 [ i ] [ j ] += d1 [ x ] [ y ] ;
                    dist1 [ i ] [ j ] += dist1 [ x ] [ y ] ;
                }
                d1 [ i ] [ j ] ++ ;
                dist1 [ i ] [ j ] += log ( no [ i ] [ j ] ) ;
            }
        }
    }
}

void id1 ()
{
    FIE ( i , 0 , n )
    {
        FIE ( j , 0 , n )
        {
            if ( no [ i ] [ j ] == 0 )
            {
                continue ;
            }
            LD temp = 0 ;
            d = min ( d1 [ i ] [ j ] , min ( d2 [ i ] [ j ] , min ( d3 [ i ] [ j ] , d4 [ i ] [ j ] ) ) ) ;
            d -- ;
            if ( valid ( i - d - 1 ) && valid ( j - d - 1 ) )
            {
                temp -= dist1 [ i - d - 1 ] [ j - d - 1 ] ;
            }
            temp += dist1 [ i ] [ j ] ;
            if ( valid ( i - d - 1 ) && valid ( j + d + 1 ) )
            {
                temp -= dist2 [ i - d - 1 ] [ j + d + 1 ] ;    
            }
            temp += dist2 [ i ] [ j ] ;
            if ( valid ( i + d + 1 ) && valid ( j - d - 1 ) )
            {
                temp -= dist3 [ i + d + 1 ] [ j - d - 1 ] ;    
            }
            temp += dist3 [ i ] [ j ] ;
            if ( valid ( i + d + 1 ) && valid ( j + d + 1 ) )
            {
                temp -= dist4 [ i + d + 1 ] [ j + d + 1 ] ;    
            }
            temp += dist4 [ i ] [ j ] ;
            temp -= 3 * log ( no [ i ] [ j ] ) ;
            if ( temp > min_ans )
            {
                min_ans = temp ;
                min_d = d ;
                I = i ;
                J = j ;
            }
            
                if ( i == 2 && j == 2 )
                {
                    

                }
            
        }
    }
    
        PRINT3 ( I , J , min_d ) ;
    
    ans = no [ I ] [ J ] ;
    FII ( i , 1 , min_d )
    {
        ans = mul ( ans , no [ I - i ] [ J - i ] ) ;
        ans = mul ( ans , no [ I - i ] [ J + i ] ) ;
        ans = mul ( ans , no [ I + i ] [ J - i ] ) ;
        ans = mul ( ans , no [ I + i ] [ J + i ] ) ;
        
            PRINT1 ( ans ) ;
        
    }
    id5 = min_ans ;
}

void set4 ()
{
    FDEI ( i , n , 0 )
    {
        FDEI ( j , n , 0 )
        {
            if ( no [ i ] [ j ] )
            {
                x = i + 1 ;
                y = j + 1 ;
                if ( valid ( x ) && valid ( y ) )
                {
                    d4 [ i ] [ j ] += d4 [ x ] [ y ] ;
                    dist4 [ i ] [ j ] += dist4 [ x ] [ y ] ;
                }
                d4 [ i ] [ j ] ++ ;
                dist4 [ i ] [ j ] += log ( no [ i ] [ j ] ) ;
            }
        }
    }
}

void set3 ()
{
    FDEI ( i , n , 0 )
    {
        FIE ( j , 0 , n )
        {
            if ( no [ i ] [ j ] )
            {
                x = i + 1 ;
                y = j - 1 ;
                if ( valid ( x ) && valid ( y ) )
                {
                    d3 [ i ] [ j ] += d3 [ x ] [ y ] ;
                    dist3 [ i ] [ j ] += dist3 [ x ] [ y ] ;
                }
                d3 [ i ] [ j ] ++ ;
                dist3 [ i ] [ j ] += log ( no [ i ] [ j ] ) ;
            }
        }
    }
}

void set2 ()
{
    FIE ( i , 0 , n )
    {
        FDEI ( j , n , 0 )
        {
            if ( no [ i ] [ j ] )
            {
                x = i - 1 ;
                y = j + 1 ;
                if ( valid ( x ) && valid ( y ) )
                {
                    d2 [ i ] [ j ] += d2 [ x ] [ y ] ;
                    dist2 [ i ] [ j ] += dist2 [ x ] [ y ] ;
                }
                d2 [ i ] [ j ] ++ ;
                dist2 [ i ] [ j ] += log ( no [ i ] [ j ] ) ;
            }
        }
    }
}

void set1 ()
{
    FIE ( i , 0 , n )
    {
        FIE ( j , 0 , n )
        {
            if ( no [ i ] [ j ] )
            {
                
                    

                
                x = i - 1 ;
                y = j - 1 ;
                if ( valid ( x ) && valid ( y ) )
                {
                    d1 [ i ] [ j ] += d1 [ x ] [ y ] ;
                    dist1 [ i ] [ j ] += dist1 [ x ] [ y ] ;
                }
                d1 [ i ] [ j ] ++ ;
                dist1 [ i ] [ j ] += log ( no [ i ] [ j ] ) ;
            }
        }
    }
}

int main ()
{
    ios::sync_with_stdio ( false ) ; cin.tie ( NULL ) ;
    
    cin >> n ;
    bool all_zero = true ;
    char ch ;
    FIE ( i , 0 , n )
    {
        FIE ( j , 0 , n )
        {
            cin >> ch ;
            no [ i ] [ j ] = ch - 48 ;
            

            if ( no [ i ] [ j ] )
            {
                all_zero = false ;
            }
        }
    }
    if ( all_zero )
    {
        cout << 0 ;
        return 0 ;
    } 
    set1 () ;
    set2 () ;
    set3 () ;
    set4 () ;
    id1 () ;
    
        id4 ( "d1" , d1 , n , n ) ;
        id4 ( "dist1" , dist1 , n , n ) ;
        id4 ( "d2" , d2 , n , n ) ;
        id4 ( "dist2" , dist2 , n , n ) ;
        id4 ( "d3" , d3 , n , n ) ;
        id4 ( "dist3" , dist3 , n , n ) ;
        id4 ( "d4" , d4 , n , n ) ;
        id4 ( "dist4" , dist4 , n , n ) ;
        PRINT3 ( I , J , min_d ) ;
    
    fill_n ( & d1 [ 0 ] [ 0 ] , N * N , 0 ) ;
    fill_n ( & dist1 [ 0 ] [ 0 ] , N * N , 0 ) ;
    fill_n ( & d2 [ 0 ] [ 0 ] , N * N , 0 ) ;
    fill_n ( & dist2 [ 0 ] [ 0 ] , N * N , 0 ) ;
    fill_n ( & d3 [ 0 ] [ 0 ] , N * N , 0 ) ;
    fill_n ( & dist3 [ 0 ] [ 0 ] , N * N , 0 ) ;
    fill_n ( & d4 [ 0 ] [ 0 ] , N * N , 0 ) ;
    fill_n ( & dist4 [ 0 ] [ 0 ] , N * N , 0 ) ;
    set11 () ;
    set22 () ;
    set33 () ;
    set44 () ;
    id7 () ;
    
        id4 ( "d1" , d1 , n , n ) ;
        id4 ( "dist1" , dist1 , n , n ) ;
        id4 ( "d2" , d2 , n , n ) ;
        id4 ( "dist2" , dist2 , n , n ) ;
        id4 ( "d3" , d3 , n , n ) ;
        id4 ( "dist3" , dist3 , n , n ) ;
        id4 ( "d4" , d4 , n , n ) ;
        id4 ( "dist4" , dist4 , n , n ) ;
        PRINT3 ( I , J , min_d ) ;
    

    cout << ans ;

    
        cout.flush () ; cin.clear () ; cin.get () ; cin.get () ;
    
    return 0 ;
}