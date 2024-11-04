
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
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


#define en "\n"

#define all(c) (c).begin() , (c).end()
#define MOD 998244353
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define double long double
#define sqrt(n) sqrt((double) n)
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second


#define int long long

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef pair<double, double> pdd;

const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;
const double INFD32=1000000000;

const int MAXN=1000100;

int cnt[MAXN];

int prevv[3][3];
int nextt[3][3];

signed main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    while (n--){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for (int i=1; i<=m; ++i){
        mem0(nextt);
        for (int i1=0; i1<3; ++i1)
            for (int i2=0; i2<3; ++i2)
                for (int i3=0; i3<3; ++i3){
                    if (i1+i2+i3>cnt[i]) continue;
                    nextt[i2][i3]=max(nextt[i2][i3],(cnt[i]-i1-i2-i3)/3+prevv[i1][i2]+i3);
                }
        for (int i1=0; i1<3; ++i1)
            for (int j=0; j<3; ++j)
            prevv[i1][j]=nextt[i1][j];
    }
    cout<<prevv[0][0];
    return 0;
}
