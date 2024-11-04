#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define sexually_transferred_diseases std				

using namespace sexually_transferred_diseases;			














#define FOR(i,a,b)      		for(int64_t i=a;i<=b;i++)
#define fr(i,n)         		for(int64_t i=0;i<n;i++)
#define fr1(i,n)        		for(int64_t i=1;i<=n;i++)
#define FORI(i,a,b)      		for(int32_t i=a;i<=b;i++)
#define fri(i,n)         		for(int32_t i=0;i<n;i++)
#define fr1i(i,n)        		for(int32_t i=1;i<=n;i++)
#define FORD(i, a, b)  			for(int64_t i=a;i>=b;i--)
#define FORDI(i, a, b)			for(int32_t i=a;i>=b;i--)
#define forv(a, b)				for(auto &a : b)
#define sortall(arr)   	 		sort(arr.begin(), arr.end())
#define sortallmax(arr)	 		sort(arr.begin(), arr.end(), greater<int64_t>())
#define sortallarr(arr, n)		sort(arr, arr + n)
#define sortallarr1(arr, n) 	sort(arr + 1, arr + n + 1)
#define sortallarrmax(arr, n)	sort(arr, arr + n, greater<int64_t>())
#define sortallarrmax1(arr, n)	sort(arr + 1, arr + n + 1, greater<int64_t>())
#define elif					else if
#define pb						push_back
#define pf						push_front
#define mp						make_pair
#define str						string
#define int						long long 
#define endline					"\n"
#define spaceuk					" "
#define driver					int32_t
#define vi						vector<int32_t>
#define qi						queue<int32_t>
#define reset(a,b)				memset(a,b,sizeof(a))
#define uid(a, b)				uniform_int_distribution<int>(a, b)(rng)
#define TOINFINITYANDBEYOND		0x3f3f3f3f
const long long MODULO =		1e9+7;


const double pi =				acos(-1.0);
auto start =					chrono::steady_clock::now();
void finish(){
	auto end = chrono::steady_clock::now();
	

	cout << chrono::duration<double, std::milli>(end - start).count() << "ms" << endl;
	fclose(stdin);
	fclose(stdout);
	return;
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B, typename C>	struct threesome{
	A fi;
	B se;
	C th;
};
int64_t getbit(int64_t x, int32_t i) {return ((x >> i) & 1);} 

int64_t Modular_multiplication(int64_t a, int64_t b)
{
	int64_t res = 0;
	a %= MODULO;
	while (b > 0)
	{
		if (b % 2 == 1)
			res = (res + a) % MODULO;
		a = (a * 2) % MODULO;
		b /= 2;
	}
	return res % MODULO;
}
int64_t Modular_exponentiation(int64_t a, int64_t b)
{
	int64_t res = 1;
	a %= MODULO;
	if (a == 0) return 0;
	while(b > 0)
	{
		if (b & 1)
			res = Modular_multiplication(res, a);
		b /= 2;
		a = Modular_multiplication(a, a);
	}
	return res;
}
void test_cases(int64_t &T);







vector<int32_t> a = {1, 2, 1, 2, -1, -2, -2, -1},
				b = {2, 1, -2, -1, 2, 1, -1, -2};

void solve(int64_t test_cases)
{
	

	int32_t x, y;
	cin >> x >> y;
	if (x == 1 || y == 1)
	{
		cout << x << spaceuk << y << endline;
		return;
	}
	if (x == 2 && y < 4)
	{
		cout << 2 << spaceuk << y / 2 + 1 << endline;
		return;
	}	
	if (x < 4 && y == 2)
	{
		cout << x / 2 + 1 << spaceuk << 2 << endline;
		return;
	}
	if (x == 3 && y == 3)
	{
		cout << 2 << spaceuk << 2 << endline;
	}
	else 
	{
		cout << x << spaceuk << y << endline;
	}
}





#define standard_input 
#define input_extension ".inp"
#define output_extension ".out"
driver main(int32_t argc, char *argv[]){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin.exceptions(cin.failbit);
	if (argc == 1 || strcmp("stdinp", argv[1]) != 0)
	{
		#ifndef standard_input
			#ifdef task
				if (!fopen(task input_extension,"r"))
					return -1;
				(void)!freopen (task input_extension, "r", stdin);
				(void)!freopen (task output_extension, "w", stdout);
			#else
				if (!fopen("input.inp","r")) 
				{
					cerr << "U STUPID" << endline;
					return -1;
				}
				(void)!freopen ("input.inp","r",stdin);
				(void)!freopen ("output.out","w",stdout);
			#endif
		#endif
	}
	int64_t T = 1; 	test_cases(T);
	fr1(i, T)		solve(i);
	if (argc == 1 || strcmp("stdinp", argv[1]) != 0)
	{
		#ifndef standard_input
			#ifndef task
				finish();
			#endif
		#endif
	}
	return 0;
}
void test_cases(int64_t &T){
	cin >> T;
}
