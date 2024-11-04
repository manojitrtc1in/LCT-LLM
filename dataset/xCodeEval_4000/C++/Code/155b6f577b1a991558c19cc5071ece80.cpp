













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
#define sqrt(n) sqrt((long double) n)


#define all(c) (c).begin() , (c).end()
#define int long long
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int q[100100],a[100100];
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>m;
    for (int i=0; i<m; ++i)
        cin>>q[i];
    sort(q, q+m);
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    sort(a, a+n);
    int now=0;
    int sum=0;
    bool flag=0;
    for (int i=n-1; i>=0; --i){
        if (now==q[0]){
            if (flag)
                now=0;
            else
                flag=1;
        }else{
            ++now;
            sum+=a[i];
            flag=0;
        }
    }
    cout<<sum<<en;
    return 0;
}
