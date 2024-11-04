#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define F first
#define S second
#define huyar char

using namespace std;

huyar a[1005][1005];


























int h[1005][1005],w[1005][1005];



























int no=0, ed=1023;

int main() {
    cin.tie( 0 );
    

























    cout.tie( 0 );
    

























    ios_base::sync_with_stdio( 0 );
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    

























    freopen("output.txt", "w", stdout);
#endif


























    int n;
    cin >> n;
    

























    for ( int i = 0; i<n; i++ ) {
        int y;
        huyar x;
        cin >> x >> y;
        if ( x=='^' ) {
            no=no^y;
            ed=ed^y;
        }
        

























        if ( x=='|' ) {
            no=no|y;
            ed=ed|y;
        }
        if ( x=='&' ) {
            no=no&y;
            ed=ed&y;
        }
    }


























    int os=1, xo=0, an=0, orr=0;
    

























    for ( int i( 0 ); i<10; i++ ) {
        if ( no%2==1 && ed%2==0 ) {
            xo+=os;
            an+=os;
        }
        if ( no%2==1 && ed%2==1 ) {
            orr+=os;
            an+=os;
        }
        

























        if ( no%2==0 && ed%2==1 ) {
            an+=os;
        }
        no/=2;
        ed/=2;
        os*=2;
    }
    

























    cout << 3 << endl;
    

























    cout << "^ " << xo << endl;
    

























    cout << "& " << an << endl;
    

























    cout << "| " << orr << endl;
}
