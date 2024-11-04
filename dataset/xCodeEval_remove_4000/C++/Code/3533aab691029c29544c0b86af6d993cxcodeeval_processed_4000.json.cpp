




using namespace sexually_transferred_diseases;			











































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

int64_t id0(int64_t a, int64_t b)
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
int64_t id1(int64_t a, int64_t b)
{
	int64_t res = 1;
	a %= MODULO;
	if (a == 0) return 0;
	while(b > 0)
	{
		if (b & 1)
			res = id0(res, a);
		b /= 2;
		a = id0(a, a);
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








driver main(int32_t argc, char *argv[]){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin.exceptions(cin.failbit);
	if (argc == 1 || strcmp("stdinp", argv[1]) != 0)
	{
		
			
				if (!fopen(task input_extension,"r"))
					return -1;
				(void)!freopen (task input_extension, "r", stdin);
				(void)!freopen (task output_extension, "w", stdout);
			
				if (!fopen("input.inp","r")) 
				{
					cerr << "U STUPID" << endline;
					return -1;
				}
				(void)!freopen ("input.inp","r",stdin);
				(void)!freopen ("output.out","w",stdout);
			
		
	}
	int64_t T = 1; 	test_cases(T);
	fr1(i, T)		solve(i);
	if (argc == 1 || strcmp("stdinp", argv[1]) != 0)
	{
		
			
				finish();
			
		
	}
	return 0;
}
void test_cases(int64_t &T){
	cin >> T;
}
