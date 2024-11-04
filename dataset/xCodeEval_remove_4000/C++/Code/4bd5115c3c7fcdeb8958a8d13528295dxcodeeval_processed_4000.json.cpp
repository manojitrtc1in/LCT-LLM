









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











int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    fastio;
    int n,k;
    cin>>n>>k;
    int arr[n];
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
    	arr[i] = s[i]-'0';
    }
    vector<int>v;
    for(int i=0;i<k;i++){
    	v.pb(arr[i]);
    }
    bool check = true;
    for(int i=k;i<n;i++){
    	if(v[i%k]>arr[i]){
    		break;
    	}
    	if(arr[i]>v[i%k]){
    		check=false;
    		break;
    	}
    }
    bool ten = false;
    if(check==false){
    	for(int i=k-1;i>=0;i--){
    		if(v[i]<9){
    			v[i]++;
    			break;
    		}
    		else if(i==0 && v[i]==9){
    			v[i] = 10;
                ten = true;
    		}
    	}
    }
    

    debug(v);
    int sz = n;
    vector<int>ans;
    if(ten){
       for(int i=0;i<n;i++){
       	   if(i%k==0){
       	   	 sz++;
       	   }
       }
    }
    bool done = false;
    for(int i=0;i<(int)v.size();i++){
    	if(done){
    		v[i] = 0;
    	}
    	else{
    		if(v[i]>arr[i]){
    			done=true;
    		}
    	}
    }
    for(int i=0;i<sz;i++){
    	   ans.pb(v[i%k]);
    }
    cout<<sz<<endl;
    for(auto x:ans){
    	cout<<x;
    }
    cout<<endl;
    return 0;
}



