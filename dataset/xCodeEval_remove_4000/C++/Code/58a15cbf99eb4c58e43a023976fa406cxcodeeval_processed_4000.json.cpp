









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
    int n;
    cin>>n;
    int s = 0;
    bool pos = true;
    int mini = inf;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	if(arr[i]<0){
    		pos=false;
    	}
    	mini = min(mini,arr[i]);
       s+=arr[i];
    }
    if(n==1){
    	cout<<arr[0]<<endl;
    	return 0;
    }
    if(pos){
    	cout<<s - 2*mini<<endl;;
    }
    else{
    	int anypos = false;
    	for(int i=0;i<n;i++){
    		if(arr[i]>=0){
    			anypos = true;
    		}
    	}
    	if(anypos){
    	 s = 0;
    	 for(int i=0;i<n;i++){
    	 	s+=abs(arr[i]);
    	 }	
    	 cout<<s<<endl;
    	}
    	else{
          int maxi = inf;
          int x = 0;
          int y = 0;
          for(int i=0;i<n;i++){
          	if(abs(arr[i])<maxi){
          		maxi = abs(arr[i]);
          		x = i;
          		if(i!=0){
          			y = i-1;
          		}
          		else{
          			y= i+1;
          		}
          	}
          }

          s = 0;
          s+= abs(abs(arr[x])-abs(arr[y]));
          for(int i=0;i<n;i++){
          	if(i==x||i==y){
          		continue;
          	}
          	else{
          		s+=abs(arr[i]);
          	}
          }
          cout<<s<<endl;

	   }          
    }


  return 0;


}



