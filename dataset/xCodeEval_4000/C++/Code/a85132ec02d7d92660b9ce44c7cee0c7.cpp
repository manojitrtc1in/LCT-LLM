













#pragma GCC optimize("O3")
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <stack>
#include <ctime>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


#define en "\n"
#define int long long
#define double long double
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int step2[1001000];
const int MOD=998244353;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,sum=0,x;
    step2[0]=1;
    for (int i=1; i<1001000; ++i){
        step2[i]=step2[i-1]*2;
        step2[i]%=MOD;
    }
    ll ans=0;
    cin>>n;
    for (int i=1; i<=n; ++i){
        cin>>x;
        sum+=x;
        sum%=MOD;
        if (i==n){
            ans+=x;
            ans%=MOD;
        }else{
            ans+=(((n-i+2)*step2[n-i-1])%MOD)*x;
            ans%=MOD;
        }
        

    }
    cout<<ans<<en;
    return 0;
    
}
