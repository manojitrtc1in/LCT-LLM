









using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int id0(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
int Mod(int x, int m){ return (x%m+m)%m;}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}




void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned int x) {cerr << x;}

void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}











int f[500001][26];
int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    fastio;
    int n;
    cin>>n;
    string last;
    vector<string>v;
    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;
    	v.pb(s);
    	last = s;
    }
    vector<string>ans;
    ans.pb(last);

    for(int i=n-2;i>=0;i--){
       if(last==v[i]){
          ans.pb(last);
       }
       else{
           string s = v[i];
           string h = "
           bool ok=false;
           for(int i=1;i<min(last.size(),s.size());i++){
              if(s[i]==last[i]){
              	h.pb(s[i]);
              }
              else if(s[i]<last[i]){
              	 ok=true;
              	 break;
              }
              else{
              	break;
              }
           }
           last = h;
           if(ok){
           	last = s;
           	h.clear();
           	h+=s;
           }
           ans.pb(h);
       }
    }
    reverse(all(ans));
    for(auto x:ans)cout<<x<<endl;
   

  return 0;


}



