


 

  

 

 

 

 

 


 

 

 

  

   



using namespace std;




















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
const int MAXN = 200 * 1001;

int n,a[110],b[110],d;
pii mas[110];

bool check(int x){
    memset(b,-1,sizeof(b));
    b[0] = x;
    queue < int > q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0;i < n;++i){
            if(i == v || i == 0)
                continue;
            int nn = d * (abs(mas[i].f - mas[v].f) + abs(mas[i].se - mas[v].se));
            if(nn > b[v])
                continue;
            int cur = b[v] - nn + a[i];
            if(cur > b[i]){
                b[i] = cur;
                q.push(i);
            }
        }
    }
    return b[n - 1] != -1;
}

main(void){
    IOS;
    cin >> n >> d;
    for(int i = 1;i <= n - 2;++i){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> mas[i].f >> mas[i].se;
    }
    int l = -1,r = 1e9;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << r;
    return !true && !false;
}
