








#include <bits/stdc++.h>
#define ceil(n,m) (n / m + (n%m != 0))
#define ll	 long long
using namespace std;
const int siz = 10000;
typedef int Back;
typedef long l;
typedef float f;
typedef double d;
typedef long double ld;
typedef double d;
#define nooo cout << "NO\n";
#define yeee cout << "YES\n";
#define fine cout <<"OK\n";
#define c(x)  cout <<x
#define container(x) vector<int> container(x)
#define pqmx priority_queue
#define pqmni priority_queue <int, vector<int>, greater<int> >
#define pqmnll priority_queue <ll, vector<ll>, greater<ll> > 
#define pb push_back
#define mp make_pair
#define V2Di(c,r) vector<vector <int>> VECT(c,vector<int>(r));
#define KHOD_HAT(FILE,FILE2) freopen(FILE,"r",stdin); freopen(FILE2,"w",stdout); auto start = high_daysolution_clock::now();
#define KHOD(FILE) freopen(FILE,"r",stdin);
#define untie ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mem(x,n) memset(x,n,sizeof x);
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define read(x) for (auto &it:(x))cin >> it;
#define print(x) for (auto &it:(x))cout << it << " ";
#define print2D(x) for (vector<int> vect1D : x) {for (auto &it:vect1D)cout << it << " "; cout << endl;}
#define f0(n) for (int i = 0; i < n; i++)
#define f1(n) for (int i = 1; i <= n; i++)
#define isVOWEL(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define setP(n) cout << fixed<<setprecision(n);
#define en endl
#define all(a) (a).begin(),(a).end()
#define fr(n) for(int i=0;i<n;i++)
#define countTime auto stop = high_daysolution_clock::now(); auto duration = duration_cast<milliseconds>(stop - start); cout << "\n$time in ms: "<<duration.count();
const double pi = 3.14159265359; 

const double e = 2.71828182846;
const int mod = 1e9 + 7;
struct TEST_CASE {

};

void fast() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void file()
{
	

	

}
int main() {
fast();
file();
int tt;
tt = 1;
cin >> tt;
while (tt--)
{
	
	vector <ll> v;
	ll n; cin >> n;
	v.resize(n);
	for (auto& t : v) { cin >> t; }
	sort(v.begin(), v.end());
	cout << v[n - 1] + v[n - 2] - v[0] - v[1] << "\n"; 

}
}

