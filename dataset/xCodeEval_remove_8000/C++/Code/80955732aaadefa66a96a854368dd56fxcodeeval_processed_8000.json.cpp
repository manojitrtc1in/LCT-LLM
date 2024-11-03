















































































































using namespace std;




static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();





typedef std::vector<int> vi;
typedef std::vector<pair<int,int>> vii;
typedef std::vector<char> vc;
typedef std::vector<string> vs;



typedef std::vector<vector<int>> vvi;
typedef std::vector<vector<char>> vvc;
typedef std::vector<vector<string>> vvs;



typedef std::set<int> si;
typedef std::set<char> sc;
typedef std::set<string> ss;



typedef std::map<int,int> mii;
typedef std::map<char,int> mci;
typedef std::map<string,int> msi;
typedef std::map<pair<int,int>,int> miii;







bool prime_seive[1000010];
void id3()
{
	bool flag;

	for(int i=0;i<=1000002;i++)
		prime_seive[i] = true;
	
	
	for(int i=2;i<=1000002;i++)
	{
		for(int j=i*i;j<=1000002;j+=i)
		{
			prime_seive[j-1] = false;
		}
	}

	prime_seive[0]=0;



}



int mod_power(int a,int b,int mod){
	if(b == 0){
		return 1;
	}
	int ans = mod_power(a,b/2,mod);
	ans *= ans;
	ans %= mod;
	if(b % 2)
	{
		ans *= a;
	}
	return ans % mod;
}





struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
        

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t id1 = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + id1);
	}
};








int id2(string s)
{
	int res=0,power=(s.length())-1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-48!=0)
			res+=pow(2,power);
		power--;
	}
	return res;

}
























template<class T> void in(T &x) { cin >> x; }
void in(float &d) { string t; in(t); d = stof(t); }
void in(double &d) { string t; in(t); d = stod(t); }
void in(long double &d) { string t; in(t); d = stold(t); }
template<class A, class B> void in(pair<A, B> &a) {
in(a.fr); in(a.sc);
}
template<class A> void in(vector<A> &a) { each(i, a) in(i); }
template<class H, class... T> void in(H &h, T&... t) {
in(h); in(t...);
}




string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char * s) { return string(s); }
string to_string(string s) { return s; }
template<class A, class B>
string to_string(pair<A, B> &a) { 
	return to_string(a.fr) + " " + to_string(a.sc); 
}
template<class T> void prr(T x) { cout << to_string(x); }
template<class H, class... T> void prr(const H &h, const T&... t) {
prr(h); prr(t...); 
}

void prn() { prr("\n"); }
template<class T> void prn(vector<T> x) { 
each(i, x) { prr(i); prr(" "); }
prn();
}
template<class H, class... T> void prn(const H &h, const T&... t) {
prr(h); if (sizeof...(t)) prr(' '); prn(t...);
}















void solve()
{
	int n;in(n);
	string s;in(s);

	bool zero_present=false;
	for(auto i: s){
		if(i=='0')
		{
			zero_present=true;break;
		}
	}
	if(zero_present)
	{
		bool id0=false;
		int pos_zero;
		for(int i=0;i<n/2;i++)
		{
			if(s[i]=='0')
			{
				id0=true;
				pos_zero=i;break;
			}
		}
		if(id0)
		{
			cout<<pos_zero+1<<" "<<n<<" "<<pos_zero+2<<" "<<n<<endl;
		}
		else
		{
			for(int i=n/2;i<n;i++)
			{
				if(s[i]=='0')
				{
					pos_zero=i;break;
				}

			}
			cout<<1<<" "<<pos_zero+1<<" "<<1<<" "<<pos_zero<<" "<<endl;

		}

	}
	else
	{
		cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<endl;
	}

}


main()
{
	sync

	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
    


	int test;in(test);
	while(test--)
		solve();
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}