





































































































































































	

	

	

	

	












using namespace std;

typedef pair<int, int> ii;
const int N = 215261;
const ll mod = 1e9 + 7;
const ll base = 31;



template <typename T> inline void read(T &x)
{
	x = 0;
	int neg = 1;
	char c = getchar();
	
	if(c == '-'){
		neg = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		x = x * 10 + c - '0';
		c = getchar();	
	}
	
	x = x * neg;
}



template <typename T>bool maxi(T &x, T y) 
{ 
	if (x < y) x = y; else return 0; return 1; 
}

template <typename T>
bool mini(T &x, T y) 
{ 
	if (x > y) x = y; else return 0; return 1; 
}



string s;
vector<int> dp(1 << 20);











int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	

						
	
	

	

			  
	

	cin >> s;
	for (int i = 0; i < int(s.size()); ++i) {
		vector<bool> used(20);
		int mask = 0;
		for (int j = 0; i + j < int(s.size()); ++j) {
			if (used[s[i + j] - 'a']) break;
			used[s[i + j] - 'a'] = true;
			mask |= 1 << (s[i + j] - 'a');
			dp[mask] = __builtin_popcount(mask);
		}
	}
	
	for (int mask = 0; mask < (1 << 20); ++mask) {
		for (int pos = 0; pos < 20; ++pos) {
			if ((mask >> pos) & 1) {
				dp[mask] = max(dp[mask], dp[mask ^ (1 << pos)]);
			}
		}
	}
	
	int ans = 0;
	for (int mask = 0; mask < (1 << 20); ++mask) {
		if (dp[mask] == __builtin_popcount(mask)) {
			int comp = ~mask & ((1 << 20) - 1);
			ans = max(ans, dp[mask] + dp[comp]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}


