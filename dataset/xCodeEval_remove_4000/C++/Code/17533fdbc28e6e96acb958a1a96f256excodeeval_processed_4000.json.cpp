











using namespace std;
const int siz = 100000;
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
	ll n; cin >> n;
	ll arr[siz];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[n - 1] + arr[n - 2] - arr[0] - arr[1] << "\n";


	

}
}

