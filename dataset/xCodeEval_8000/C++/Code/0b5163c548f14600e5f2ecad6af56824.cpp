

























































































































































































































































































































































































































































































































































#include <iostream>
#include <bits/stdc++.h>
#define ll  long long

using namespace std;


int main()
{
    ll n, L, a, x, y, res = 0, i, yy ;
    cin >> n >> L >> a ;
    yy = 0 ;
    for(i=0 ; i<n  ; i++)
    {
        cin >> x >> y ;
        if(x - yy >= a ) res += (x - yy)/a ;
        yy = x + y ;
    }

    res += (L - yy)/a ;
    cout << res ;


    return 0;
}
