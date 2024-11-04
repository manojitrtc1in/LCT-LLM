


 

  

 

 

 

 

 


 

 

 

  

   

#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b)       for(int i = (a); i <= (b); i++)
#define pb              push_back
#define f               first
#define se              second
#define pii             pair < int , int >
#define mp              make_pair
#define LOGMAX          17
#define FIND(N,pos)     ((N) & (1 << (pos)))
#define sf(h)           scanf("%d",&h)
#define sff(h,b)        scanf("%d%d",&h,&b)
#define sfff(h,b,c)     scanf("%d%d%d",&h,&b,&c)
#define TCASE(test)     for(int z = 1;z <= test;z++)
#define PRINT           printf("Case %d:\n",z)
#define en              "\n"
#define lwb             lower_bound
#define upb             upper_bound
#define IOS             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define rep(i,l,r)      for(int i = (l);i <= (r);i++)

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;

const int maxn = int(1.5 * 1e7);
const int inf = ~0U;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;

int all,m,n,x,i,j,k,mn,mx,a,b,c,MN[111],MX[111];
bool good[111];
char s[111];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&all,&m);
    for (i = 0; i < m; i++) {
        scanf("%d",&x);
        good[x] = 1;
    }
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%s",s);
        scanf("%d",&k);
        for (a = b = c = j = 0; j < k; j++) {
            scanf("%d",&x);
            if (x == 0)
                b++;
            else if (good[x])
                a++;
            else
                c++;
        }
        MN[i] =  k - min(all - m,b + c);
        MX[i] = min(m , a + b);
        mn = max(mn , MN[i]);
        mx = max(mx , MX[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (i != j && MX[j] > MN[i])
                break;
        if (j >= n) puts("0");
        else if (MX[i] >= mn)
            puts("2");
        else puts("1");
    }
}
