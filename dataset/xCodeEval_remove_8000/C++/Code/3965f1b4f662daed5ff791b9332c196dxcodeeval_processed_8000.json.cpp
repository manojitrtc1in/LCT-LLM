











using namespace std;
const int siz = 10000;
typedef int Back;
typedef long l;
typedef float f;
typedef double d;
typedef long double ld;
typedef double d;































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

