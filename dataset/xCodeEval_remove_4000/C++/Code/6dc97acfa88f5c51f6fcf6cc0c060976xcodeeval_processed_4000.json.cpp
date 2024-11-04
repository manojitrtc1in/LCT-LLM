



























using namespace std;


inline int read(void){
    char ch = getchar();
    int ans = 0;
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)){ ans = ans*10 + ch-'0'; ch = getchar();}
    return ans;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b){
     return a*b/gcd(a,b);
}



ll id1(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = id1(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 


ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = id1(a, m, x, y);
    ll res = (x % m + m) % m;
    return res;
}
 


ll C(ll n, ll k)
{
    ll res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
 


ll CM(ll n, ll k, ll mod)
{
    ll res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res = (res * (n - i)) % mod;
        res = (res * modInverse(i + 1, mod)) % mod;
    }
    return res % mod;
}
 


ll factorial(ll n)
{
    ll res = 1;
    for (int i = 2; i <= n ; i++)
        res = res * i;
    return res;
}
 


ll id2(ll n, ll m)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = ((res % m) * (i % m)) % m;
    return res % m;
}












const int MAXN = 1e6 + 10;
string t, p;
int pre[MAXN], Next[MAXN];
void get_next(string s){
    int len = int(s.size());
    pre[0] = 0;
    int j = 0;
    for(int i=1;i<len;i++){
        while(j>0 && s[i] != s[j]) j = pre[j-1];
        if(s[i] == s[j]) j++;
        pre[i] = j;
    }
    for(int i=len-1;i>=1;i--) Next[i] = pre[i-1];
    Next[0] = -1;
}


void id0(string t, string p){
    get_next(p);
    int len1 = int(t.size());
    int len2 = int(p.size());
    int i=0, j=0;
    while(i<len1){
        if(j == len2 - 1 && t[i] == p[j]){

            cout << i-j+1 << endl;
            j = Next[j];                 

        }
        if(t[i] == p[j]){
            i++; j++;
        }
        else{
            j = Next[j];
            if(j == -1){
                i++;
                j++;
            }
        }
    }
}



ll max(ll a, ll b){
    return a > b ? a : b;
}

bool is_ok( int n,  int x , int y){
    if(x != 0 || y == 0) return false;
    else if((n - 1) % y != 0) return false;
    return true;
}



void solve() {
  int n, x, y;
 
  cin >> n >> x >> y;
  if (x > y) swap(x, y);
 
  if (x != 0 || y == 0 || (n - 1) % y) {
    cout << "-1\n";
    return;
  }
 
  for (int i = 1; i < n; i += y) {
    for (int j = 0; j < y; j++) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        solve();
        }
    return 0;
}





  		  	      		  			 	 	   	 		