#include <bits/stdc++.h>
using namespace std;
typedef    long long ll;
typedef long double dbl;
const int INF = 1e9+7;
#define speed ios::sync_with_stdio(false)
#define N 2001
char c[300000];
ll ans;
int main(){ speed;

scanf("%s",c);
int n=strlen(c);
if( c[ 0 ] == '0' ||
        c[ 0 ] == '4' ||
        c[ 0 ] == '8' )
        ans ++;
 for( int i = 1 ; i < n ; i ++ ){
    if( c[ i ] == '0' ||
        c[ i ] == '4' ||
        c[ i ] == '8' )   ans ++;
      if( ( ( c[ i - 1 ] - '0' ) * 10 + (c[ i ] - '0')) % 4 == 0 )
                          ans += i ;
    }
  cout << ans << endl;
return 0;}
























