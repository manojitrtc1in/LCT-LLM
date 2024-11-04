


 

  

 

 

 

 

 


 

 

 

  

   



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
const int inf = ~0U >> 1;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;

int n,k,a[N];

main(void){
    IOS;
    cin >> n >> k;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int p = n + 1,len = 1;
    string s = "";
    while(k){
        for(int i = 1;i < p;++i){
            if(!k)
                break;
            k--;
            cout << len << " " << a[i] << s << en;
        }
        p--;
        int x = a[p];
        string t;
        while(x > 0){
            t += (x % 10) + '0';
            x /= 10;
        }
        reverse(t.begin(),t.end());
        s = " " + t + s;
        len++;
    }
}