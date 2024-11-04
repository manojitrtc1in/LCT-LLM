











using namespace std;

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;

const ld pi=2*acos(0);
const ll inf  = id0;
const ll ninf = id1;
const int oo = INT_MAX;
const int noo = INT_MIN;
const int limit = 1e5+5;

int n;
string s;
int k;

void init(){
	cin>>n;
	cin>>s;
}

void process(){
	int dem = 0;
	k = s.length()-10;
	for (int i = 0; i < k ; i++){
		if (s[i] == '8') dem++;
	}
	if (dem >= k - dem) cout << "YES";
	else cout << "NO";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	init();
	process();	
	return 0;
}

























































































































































































