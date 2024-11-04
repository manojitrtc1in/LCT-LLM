






using namespace std;






















 

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;








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











































     


void id0()
{
   
 {
    ll n,m;cin>>n>>m;
    
     ll maxval=((n-1)*m)+(m);
     ll nn=m-1;
     ll aa=(maxval)/(nn+1);
     cout<<nn*(nn+1)/2+((nn+1)*(aa*(aa+1)/2))<<endl;
     
    
 }
}




 
int main() 
{
     
    
    freopen("input.txt", "r", stdin);
    freopen("debug.txt", "w", stderr);
    
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    NFS;
   
    

    int tx=1;
    cin>>tx;
    while(tx--) 
   id0();
   
  
} 