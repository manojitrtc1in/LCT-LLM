



using namespace std;





























































typedef pair<int, int> PII; 
typedef pair<ll, ll> PLL;
typedef pair<double,double> PDD;
typedef pair<string, string> PSS; 
typedef pair<string, ll> PSL; 
typedef long double lld;

typedef vector<int> VI;  
typedef vector<ll> VL;  
typedef vector<double> VD;
typedef vector<string> VS; 
typedef vector<VI> VVI;  
typedef vector<VL> VVL; 
typedef vector<VS> VVS; 
typedef vector<PII> VPII; 
typedef vector<PLL> VPLL; 
typedef vector<PSS> VPSS; 
typedef vector<PSL> VPSL; 

typedef map<int,int> MII; 
typedef map<ll,ll> MLL;   
typedef map<char,ll> MCL;  
typedef map<char,int> MCI; 
typedef map<char,ll> MCL;   
typedef map<string,string> MSS;  
typedef map<string,int> MSI;  
typedef map<string,ll> MSL; 

typedef unordered_map<int,int> UMII; 
typedef unordered_map<ll,ll> UMLL;   
typedef unordered_map<char,ll> UMCL;  
typedef unordered_map<char,int> UMCI; 
typedef unordered_map<char,ll> UMCL;   
typedef unordered_map<string,string> UMSS;  
typedef unordered_map<string,int> UMSI;  
typedef unordered_map<string,ll> UMSL; 
typedef unsigned long long ull;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll lcm(ll a, ll b) 
{ return (a * (b / __gcd(a, b))); }

string id0(ll a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}
 
ll id1(string a)
{
    char x[100];
    ll res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

string to_binary(ll n)
{
    int bin[100];
     int i = 0;
    while (n > 0) {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    string s="";
    for(int j=i-1;j>=0;j--)
        s+=to_string(bin[j]);
    return s;
}

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errorf.txt" , "w" , stderr) ;
    
    
     tc
     {
        

        ll n;
        cin >> n;
        ll arr[n];
        for(int i=0;i<n;i++)
        
        {
            cin >> arr[i];
        }
        int res = arr[0];
        for(int i=0;i<n;i++)
        {
            res|= arr[i];
        }
        cout << res << "\n";

      }
    return 0;
}

