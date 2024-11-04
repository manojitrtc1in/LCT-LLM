








































































#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>



	
	

	
	#define ll long long
	#define ld long double
	#define ull unsigned long long
	#define pb push_back
	#define eb emplace_back
	#define f first
	#define s second
	#define p pair
	#define all(C) C.begin(), C.end()
	#define Begin() int N; cin>>N; cin.ignore(); while(N--)
	
	

	
		

		
		#define FOR(i,a,b) for (ll i=(ll)a; i<=(ll)b; i++)
		#define FOR2(i,a,b) for (ll i=(ll)a; i<=(ll)b; ++i)
		#define FORD(i,a,b) for (ll i=(ll)a; i>=(ll)b; i--)
		
		

		
		#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
		#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
		
		

		
		#define reset(C) memset(C,0,sizeof(C))
		#define Fill(C,a) fill(C.begin(), C.end(), a)
		
		

		
		#define SORT(C) sort(C.begin(), C.end())
		#define SORTD(C,x) sort(C.begin(), C.end(), greater<x>())
		#define SORTC(C,check) sort(C.begin(), C.end(), check)
		#define tlw(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = tolower(C[i])
		#define tup(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = toupper(C[i])
		#define Merge(C,F,K) merge(C.begin(), C.end(), F.begin(), F.end(), K.begin());
		#define Unique(C) C.erase(unique(C.begin(), C.end()), C.end())
		#define CutInHalf(C,F,x,y) y<x> F(C.begin() + C.size()/2 + 1, C.end()); C.resize(C.size()/2)
		#define revrs(C) reverse(C.begin(), C.end())
		
		


		#define getVector(C) for(ll _=0; _<C.size(); _++) cin>>C[_]
		#define printVector(C) for(int _=0; _<C.size(); _++) cout<<C[_]<<' '
		
	

	
	#define vec(x) vector<x> 
	#define Matrix(x) vector<vector<x> >
	#define Rubik(x) vector<vector<vector<x> > >
	#define pq(x) priority_queue<x>
	#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >
	#define ordered_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
	#define ordered_multiset(T) tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>
	
	

	
	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);




using namespace std;
using namespace __gnu_pbds;














multiset<ll> LIS(vector<ll> A)
{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.upper_bound(A[i]);
		if (it != S.end()) S.erase(it);
	}
	return S;
}

multiset<ll> LSIS(vector<ll> A) 

{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.lower_bound(A[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}

ll gcd(ll a, ll b)	
{
	if (a == 0) return(b);
	return(gcd(b % a, a));
}

ll extGcd(ll a, ll b, ll& x, ll& y) 

{
	if(a==0)
	{
		x=0;y=1;
		return(b);
	}
	ll a1, b1, c, x1, y1, rst;
	a1 = b % a; b1 = a; c = b / a;
	rst = extGcd(a1, b1, x1, y1);
	x = y1 - c * x1; y = x1;
	return(rst);
}

ll powermod(ll a, ll b, ll m)
{
	if (b == 0) return 1;
	ull k = powermod(a, b / 2, m);
	k = k * k;
	k %= m;
	if (b & 1) k = (k * a) % m;
	return k;
}




bool isPrime(ull n, int iter = 5) 
{
    if (n < 4) return n == 2 || n == 3;
	if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 0; i < iter; i++) 
	{
        ull a = 2 + rand() % (n - 3);
        if (powermod(a, n - 1, n) != 1) return false;
    }
    return true;
}







class STRO
{
	public:
		bool bigger(string a, string b)
		{
			if (a.length() > b.length()) return true;
			if (a.length() < b.length()) return false;
			FOR(i, 0, a.length() - 1)
			{
				if (a[i] > b[i]) return true;
				else if (a[i] < b[i]) return false;
			}
			return false;
		}
		
		string add(string str1, string str2) 

		{
		    if (str1.length() > str2.length())
		        swap(str1, str2);
		    string str = "";
		    int n1 = str1.length(), n2 = str2.length();
		    int diff = n2 - n1;
		    int carry = 0;
		    for (int i=n1-1; i>=0; i--)
		    {
		        int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);
		        str.push_back(sum%10 + '0');
		        carry = sum/10;
		    }
		    for (int i=n2-n1-1; i>=0; i--)
		    {
		        int sum = ((str2[i]-'0')+carry);
		        str.push_back(sum%10 + '0');
		        carry = sum/10;
		    }
		    if (carry) str.push_back(carry+'0');
		    reverse(str.begin(), str.end());
		    while(str.size() > 1 && str[0] == '0') str.erase(0, 1);
		    return str;
		}
		
		string sub(string str1, string str2) 

		{
		    if (bigger(str2, str1)) swap(str1, str2);
		    string str = "";
		    int n1 = str1.length(), n2 = str2.length();
		    reverse(str1.begin(), str1.end());
		    reverse(str2.begin(), str2.end());
		    int carry = 0;
		    for (int i = 0; i < n2; i++) 
			{
		        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
		        if (sub < 0) {
		            sub = sub + 10;
		            carry = 1;
		        }
		        else
		            carry = 0;
		 
		        str.push_back(sub + '0');
		    }
		    for (int i = n2; i < n1; i++) 
			{
		        int sub = ((str1[i] - '0') - carry);
		        if (sub < 0) {
		            sub = sub + 10;
		            carry = 1;
		        }
		        else
		            carry = 0;
		 
		        str.push_back(sub + '0');
		    }
		    reverse(str.begin(), str.end());
		    while (str.size() > 1 && str[0] == '0') str.erase(0, 1);
		    return str;
		}
		
		string mul(string A, string B) 

		{
			reverse(A.begin(),A.end());
			reverse(B.begin(),B.end());
			string C;
			C.resize(A.length() + B.length(),'0');
			FOR(i, 0, A.length()-1)
			{
				int c = 0;
				FOR(j, 0, B.length()-1)
				{
					c += ((A[i] - '0') * (B[j] - '0') + C[i + j] - '0');
					C[i + j] = (char)(c%10 + '0');
					c/=10;
				}
				if (c > 0) C[i + B.length()] += c;
			}
			reverse(C.begin(),C.end());
			while (C.size() > 1 && C[0] == '0') C.erase(0, 1);
			return C;
		}
		string div(string number, ll divisor) 

		{
		    string ans = "";
		    ll idx = 0;
		    ll temp = number[idx] - '0';
		    while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');
		    while (number.size() > idx) 
			{
		        ans += (temp / divisor) + '0';
		        temp = (temp % divisor) * 10 + number[++idx] - '0';
		    }
		    while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
		    if (ans.length() == 0) return "0";
		    return ans;
		}
		bool bigger2(string a, string b)
		{
			if (a.length() > b.length()) return true;
			if (a.length() < b.length()) return false;
			FOR(i, 0, a.length() - 1)
			{
				if (a[i] > b[i]) return true;
				else if (a[i] < b[i]) return false;
			}
			return true;
		}
		string dv(string a, string b)
		{
			if (bigger(b, a)) return "0";
			if (a == "0") return "0";
			string l = "0";
			string r = a;
			string mid, mid2;
			while (bigger2(r, l))
			{
				mid = add(r, l);
				if ((mid[mid.length() - 1] - '0') % 2 == 1) mid[mid.length() - 1]--;
				mid = div(mid, 2);
				if (mid == "0") break;
				mid2 = mul(mid, b);
				if (bigger(mid2, a)) r = sub(mid, "1");
				else l = add(mid, "1");
			}
			return r;
		}
		string md(string a, string b)
		{
			if (bigger(b, a)) return a;
			if (a == "0") return "0";
			if (b == "1") return "0";
			string l = "0";
			string r = a;
			string mid, mid2;
			while (bigger2(r, l))
			{
				if (mid == "0") break;
				mid = add(r, l);
				if ((mid[mid.length() - 1] - '0') % 2 == 1) mid[mid.length() - 1]--;
				mid = div(mid, 2);
				mid2 = mul(mid, b);
				if (bigger(mid2, a)) r = sub(mid, "1");
				else l = add(mid, "1");
			}
			mid = mul(r, b);
			mid = sub(a, mid);
			while (mid.size() > 1 && mid[0] == '0') mid.erase(0, 1);
			if (mid == b) return "0";
			return mid;
		}
		string strgcd(string a, string b)
		{
			if (a == "0") return b;
			return strgcd(md(b, a), a);
		}
};

STRO STR;












ld PI = 3.14159265358979323846;

ld eps = 1e-6;

ll M = 1e9 + 7;















bool __isprime(ll x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	if (x == 3) return true;
	if (x % 3 == 0) return false;
	ll t = 1;
	for (ll i = 5; i * i <= x; i += 2 * (1 + t))
	{
		if (x % i == 0) return false;
		t = 1 - t;
	}
	return true;
}

ll ST[800050];

ll a, b;

void build()
{
	ll x = (1LL << 34) - 1;
	memset(ST, x, sizeof(ST));








}

void modify(ll l, ll r, ll value)
{
	for (l += a, r += a; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) ST[l++] &= value;
		if (r & 1) ST[--r] &= value;
	}
}

ll query(ll idx)
{
	ll res = (1LL << 34) - 1;
	for (idx += a; idx > 0; idx >>= 1) res &= ST[idx];
	return res;
}

void Process()
{
	reset(ST);
	cin >> a >> b;
	build();
	FOR(i, 0, b - 1)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		modify(x, y + 1, z);
	}
	vec(ll) ttl;
	FOR(i, 1, a) ttl.pb(query(i));




	SORT(ttl);
	ll zero = 0;
	ll TMXM = (1LL << 34) - 1;
	FOR(i, 0, ttl.size() - 1)
	{
		if (ttl[i] == TMXM)
		{
			ttl[i] = 0;
		}


	}
	vec(ll) final = ttl;
	SORT(final);
	Unique(final);
	zero = ttl.size() - final.size() + (final[0] == 0);
	ll DP[35];
	reset(DP);
	for (auto x : final)
	{
		FOR(i, 0, 33)
		{
			if (x & (1LL << i)) DP[i] = 1;
		}
	}
	ll ANS = 0;
	FOR(i, 0, 29)
	{
		if (DP[i])
		{
			ANS += (1LL << i);


			ANS %= M;
		}
	}
	ANS *= powermod(2, zero, M);
	ANS %= M;
	ll t = (ll)final.size() - (final[0] == 0);
	ANS *= powermod(2, t - 1, M);
	ANS %= M;
	cout << ANS << '\n';
}

signed main() 
{
	faster();
	Begin()
	{
		Process();
	}
}














