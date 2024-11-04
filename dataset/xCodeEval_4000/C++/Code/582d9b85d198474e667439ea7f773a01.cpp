


 

  

 

 

 

 

 


 

 

 

  

   

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


const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;
const int MAXN = 200 * 1001;

ll n,m,W[1100][1100],E[1100][1100],N[1100][1100],S[1100][1100],k;
pair < char , int > b[(int)(1e6)];
char a[1100][1100];
vpii v;
vector < char > ans;

main(void){
    IOS;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> a[i][j];
            if(a[i][j] >= 'A' && a[i][j] <= 'Z'){
                v.pb(mp(i,j));
            }
            if(a[i - 1][j] != '#' && i - 1 > 0){
                N[i][j] = N[i - 1][j] + 1;
            }
            else{
                N[i][j] = 0;
            }
            if(a[i][j - 1] != '#' && j - 1 > 0){
                W[i][j] = W[i][j - 1] + 1;
            }
            else{
                W[i][j] = 0;
            }
        }
    }
    for(int i = n;i >= 1;--i){
        for(int j = m;j >= 1;--j){
            if(a[i + 1][j] != '#' && i + 1 <= n){
                S[i][j] = S[i + 1][j] + 1;
            }
            else{
                S[i][j] = 0;
            }
            if(a[i][j + 1] != '#' && j + 1 <= m){
                E[i][j] = E[i][j + 1] + 1;
            }
            else{
                E[i][j] = 0;
            }
        }
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            

        }
    }
    cin >> k;
    for(int i = 1;i <= k;i++){
        cin >> b[i].f >> b[i].se;
    }
    for(int i0 = 0;i0 < v.size();++i0){
        int x = v[i0].f;
        int y = v[i0].se;
        bool q = 1;
        for(int i = 1;i <= k;++i){
            

            if(b[i].f == 'N'){
                if(N[x][y] < b[i].se){
                    q = 0;
                    break;
                }
                else{
                    x -= b[i].se;
                }
            }
            if(b[i].f == 'S'){
                if(S[x][y] < b[i].se){
                    q = 0;
                    break;
                }
                else{
                    x += b[i].se;
                }
            }
            if(b[i].f == 'E'){
                if(E[x][y] < b[i].se){
                    q = 0;
                    break;
                }
                else{
                    y += b[i].se;
                }
            }
            if(b[i].f == 'W'){
                if(W[x][y] < b[i].se){
                    q = 0;
                    break;
                }
                else{
                    y -= b[i].se;
                }
            }
        }
        if(q){
            ans.pb(a[v[i0].f][v[i0].se]);
        }
    }
    if(!ans.size()){
        cout << "no solution";
    }
    else{
        sort(ans.begin(),ans.end());
        for(int i = 0;i < ans.size();++i){
            cout << ans[i];
        }
    }
    return !true && !false;
}
