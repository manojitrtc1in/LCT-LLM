#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifdef anparvez10
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif 


    ios_base::sync_with_stdio(0); cin.tie(0);

    int n ;
    string a , b , s ="";
    cin >> n >> a >> b ;


    if( a == b && a != "aa" && a != "bb" && a != "cc")
    {

        if( a[0] == 'a' && a[1] == 'b' )
        {
            s = "acb" ;
        }
        else if( a[0] == 'a' && a[1] == 'c' )
        {
            s += "abc";
        }
        else if( a[0] == 'b' && a[1] == 'a' )
        {
            s += "bca";
        }
        else if( a[0] == 'b' && a[1] == 'c' )
        {
           s += "bac";
        }
        else if( a[0] == 'c' && a[1] == 'a' )
        {
            s += "cba";
        }
        else if( a[0] == 'c' && a[1] == 'b' )
        {
            s += "cab";
        }

        cout << "YES\n";
        for( int i = 0 ; i < n ; i ++ )
        {
            cout <<s ;
        }
        return 0 ;
    }



    if( a == "aa" && b == "ab" )
    {
        s = "bac";
    }
    else if( a == "aa" && b == "ac" )
    {
        s = "abc";
    }
    else if( a == "aa" && b == "bb" )
    {
        s = "abc";
    }
    else if( a == "aa" && b == "ba" )
    {
        s = "abc";
    }
    else if( a == "aa" && b == "bc" )
    {
        s = "acb";
    }
    else if( a == "aa" && b == "cc" )
    {
        s = "abc";
    }
    else if( a == "aa" && b == "ca" )
    {
        s = "acb";
    }
    else if( a == "aa" && b == "cb" )
    {
        s = "abc";
    }
    else if( a == "ab" && b == "ac" )
    {
        cout <<"YES\n";
        s = "cba";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        cout << s ;
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }

        return 0 ;
    }
    else if( a == "ab" && b == "bb" )
    {
        s = "acb";
    }
    else if( a == "ab" && b == "ba" )
    {
        cout << "YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "acb";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }

        return 0 ;

    }
    else if( a == "ab" && b == "bc" )
    {
        s = "bac";
    }
    else if( a == "ab" && b == "cc" )
    {
        s = "acb";
    }
    else if( a == "ab" && b == "ca" )
    {
        s = "bac";
    }
    else if( a == "ab" && b == "cb" )
    {
       cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        cout << "bac";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }

        return 0 ;
    }
    else if( a == "ac" && b == "bb" )
    {
        s = "cab";
    }
    else if( a == "ac" && b == "ba" )
    {
        s = "bca";
    }
    else if( a == "ac" && b == "bc" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        cout << "cba";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }

        return 0 ;

    }
    else if( a == "ac" && b == "cc" )
    {
        s = "abc";
    }
    else if( a == "ac" && b == "ca" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "abc";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }

        return 0 ;
    }
    else if( a == "ac" && b == "cb" )
    {
        s = "abc";
    }
    else if( a == "bb" && b == "ba" )
    {
        s = "bca";
    }
    else if( a == "bb" && b == "bc" )
    {
        s = "bac";
    }
    else if( a == "bb" && b == "cc" )
    {
        s = "abc";
    }
    else if( a == "bb" && b == "ca" )
    {
        s = "acb";
    }
    else if( a == "bb" && b == "cb" )
    {
        s = "cab";
    }
    else if( a == "ba" && b == "bc" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "acb";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }

        return 0 ;
    }
    else if( a == "ba" && b == "cc" )
    {
        s = "abc";
    }
    else if( a == "ba" && b == "ca" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "acb";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }

        return 0 ;
    }
    else if( a == "ba" && b == "cb" )
    {
        s = "abc";
    }
    else if( a == "bc" && b == "cc" )
    {
        s = "acb";
    }
    else if( a == "bc" && b == "ca" )
    {
        s = "acb";
    }

    else if( a == "bc" && b == "cb" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        cout <<"cab";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }

        return 0 ;
    }

    else if( a == "cc" && b == "ca" )
    {
        s = "acb";
    }
    else if( a == "cc" && b == "cb" )
    {
        s = "abc";
    }
    else if( a == "ca" && b == "cb" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "abc" ;
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }

        return 0 ;
    }
    else if( a == "aa" && b == "aa")
    {
        s = "abc";
    }
    else if( a == "bb" && b == "bb")
    {
        s = "abc";

    }
    else if( a == "cc" && b == "cc")
    {
        s = "abc";
    }

    if( s == "" )
    {
        swap( a , b );

    if( a == "aa" && b == "ab" )
    {
        s = "bac";
    }
    else if( a == "aa" && b == "ac" )
    {
        s = "abc";
    }
    else if( a == "aa" && b == "bb" )
    {
        s = "abc";
    }
    else if( a == "aa" && b == "ba" )
    {
        s = "abc";
    }
    else if( a == "aa" && b == "bc" )
    {
        s = "acb";
    }
    else if( a == "aa" && b == "cc" )
    {
        s = "abc";
    }
    else if( a == "aa" && b == "ca" )
    {
        s = "acb";
    }
    else if( a == "aa" && b == "cb" )
    {
        s = "abc";
    }
    else if( a == "ab" && b == "ac" )
    {
        cout <<"YES\n";
        s = "cba";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        cout << s ;
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }

        return 0 ;
    }
    else if( a == "ab" && b == "bb" )
    {
        s = "acb";
    }
    else if( a == "ab" && b == "ba" )
    {
        cout << "YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "acb";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }

        return 0 ;
    }
    else if( a == "ab" && b == "bc" )
    {
        s = "bac";
    }
    else if( a == "ab" && b == "cc" )
    {
        s = "acb";
    }
    else if( a == "ab" && b == "ca" )
    {
        s = "bac";
    }
    else if( a == "ab" && b == "cb" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        cout << "bac";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }

        return 0 ;
    }
    else if( a == "ac" && b == "bb" )
    {
        s = "cab";
    }
    else if( a == "ac" && b == "ba" )
    {
        s = "bca";
    }
    else if( a == "ac" && b == "bc" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        cout << "cba";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }

        return 0 ;
    }
    else if( a == "ac" && b == "cc" )
    {
        s = "abc";
    }
    else if( a == "ac" && b == "ca" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "abc";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }

        return 0 ;
    }
    else if( a == "ac" && b == "cb" )
    {
        s = "abc";
    }
    else if( a == "bb" && b == "ba" )
    {
        s = "bca";
    }
    else if( a == "bb" && b == "bc" )
    {
        s = "bac";
    }
    else if( a == "bb" && b == "cc" )
    {
        s = "abc";
    }
    else if( a == "bb" && b == "ca" )
    {
        s = "acb";
    }
    else if( a == "bb" && b == "cb" )
    {
        s = "cab";
    }
    else if( a == "ba" && b == "bc" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "acb";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }

        return 0 ;
    }
    else if( a == "ba" && b == "cc" )
    {
        s = "abc";
    }
    else if( a == "ba" && b == "ca" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "acb";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }

        return 0 ;
    }
    else if( a == "ba" && b == "cb" )
    {
        s = "abc";
    }
    else if( a == "bc" && b == "cc" )
    {
        s = "acb";
    }
    else if( a == "bc" && b == "ca" )
    {
        s = "acb";
    }

    else if( a == "bc" && b == "cb" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }
        cout <<"cab";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }

        return 0 ;
    }

    else if( a == "cc" && b == "ca" )
    {
        s = "acb";
    }
    else if( a == "cc" && b == "cb" )
    {
        s = "abc";
    }
    else if( a == "ca" && b == "cb" )
    {
        cout <<"YES\n";
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "b";
        }
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "a";
        }
        cout << "abc" ;
        for( int i = 1 ; i < n ; i ++ )
        {
            cout << "c";
        }

        return 0 ;
    }
    else if( a == "aa" && b == "aa")
    {
        s = "abc";
    }
    else if( a == "bb" && b == "bb")
    {
        s = "abc";

    }
    else if( a == "cc" && b == "cc")
    {
        s = "abc";
    }
    }

    cout <<"YES\n";
    for( int i = 1 ; i <= n ; i ++ )
    {
        cout << s ;
    }
    cout << endl;



    return 0;
}