




















































































	
	

	


	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
		

		
		
		
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		

		
		
		
		
		
		

		
		
		
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		
		
		
		

		
		
		
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	




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

ull gcd(ll a, ll b)	
{
	if (a == 0) return(b);
	return(gcd(b % a, a));
}

ll id1(ll a, ll b, ll& x, ll& y) 

{
	if(a==0)
	{
		x=0;y=1;
		return(b);
	}
	ll a1, b1, c, x1, y1, rst;
	a1 = b % a; b1 = a; c = b / a;
	rst = id1(a1, b1, x1, y1);
	x = y1 - c * x1; y = x1;
	return(rst);
}




bool suspect(ll b, ll t, ll u, ll n)
{
	ll prod = 1;
	while(u)
	{
		if(u & 1) prod=((prod * b) % n);
		b=((b * b) % n);
		u /= 2;
	}
	if(prod == 1) return true;
	FOR(i, 1, t)
	{
		if(prod == n - 1) return true;
		prod = (prod * prod) % n;
	}
	return false;
}

bool isprime(ll n)
{
	ll k = n - 1;
	ll t = 0;
	while(!(k % 2)) 
	{
		t++; 
		k /= 2; 
	}
	if(n > 2 && n % 2 == 0) return 0;
	if(n > 3 && n % 3 == 0) return 0;
	if(n > 5 && n % 5 == 0) return 0;
	if(n > 7 && n % 7 == 0) return 0;
	if(suspect(61, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n)) return true;
	return false;
}

bool id0(ull n)
{
	ll k = n - 1;
	ll t = 0;
	while(!(k % 2)) 
	{
		t++; 
		k /= 2; 
	}
	if(n > 2 && n % 2 == 0) return 0;
	if(n > 3 && n % 3 == 0) return 0;
	if(n > 5 && n % 5 == 0) return 0;
	if(n > 7 && n % 7 == 0) return 0;
	if(suspect(3, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n) && suspect(5, t, k, n) && suspect(11, t, k, n) && suspect(13, t, k, n) && suspect(17, t, k, n) && suspect(19, t, k, n) && suspect(19, t, k, n) && suspect(23, t, k, n) && suspect(29, t, k, n) && suspect(31, t, k, n) && suspect(37, t, k, n)) return true;
	return false;
}




ll id4(string x) 

{
	ll k = 0;
	FOR(i, 0, x.size() - 1)
	{
		k = k * 10 + (x[i] - '0');
	}
	return k;
}




struct Treap 

{
    ll len = 0;
    const ll ADD = 1000010;
    const ll MAXVAL = 1000000010;
    map<ll, ll> mp; 

    tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;
    tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>::iterator it;

    Treap() { len = 0; T.clear(), mp.clear(); }

    inline void insert(ll x)
	{
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c); 
	}
    
    inline void erase(ll x)
	{
        x += MAXVAL;
        ll c = mp[x];
        if(c) 
		{
            c--, mp[x]--, len--;
            T.erase((x*ADD) + c); 
		} 
	}
    inline ll kth(ll k) 

	{       
        if(k<1 || k>len) return -1;     

        it = T.find_by_order(--k); 

        return ((*it)/ADD) - MAXVAL;
	} 
    
    inline ll lower_bound(ll x) 

	{     
        x += MAXVAL;
        ll c = mp[x];
        return (T.order_of_key((x*ADD)+c)); 
	}

    inline ll upper_bound(ll x) 

	{     
        x += MAXVAL;
        ll c = mp[x];
        return (T.order_of_key((x*ADD)+c)); 
	}
 
    inline ll size() { return len; }   

};







class SegTree2
{
	ll size;
	vec(ll) base;
	public:
		void build()
		{
			for (int i = size - 1; i > 0; --i) base[i] = base[i << 1] + base[i << 1 | 1];
		}
		void getbase(ll x)
		{
			size = x;
			base.resize(x * 2);
			build();
		}
		ll sumrange(ll l, ll r) 

		{
			ll res = 0;
			for (l += size, r += size; l < r; l >>= 1, r >>= 1) 
			{
			    if (l & 1) res += base[l++];
			    if (r & 1) res += base[--r];
			}
			return res;
		}
		void updatenum(ll idx, ll value) 
		{
			for (base[idx += size] = value; idx > 1; idx >>= 1) base[idx >> 1] = base[idx] + base[idx ^ 1];
		}
		void updaterange(ll l, ll r, ll value) 
		{
			for (l += size, r += size; l < r; l >>= 1, r >>= 1) 
			{
			    if (l & 1) base[l++] += value;
			    if (r & 1) base[--r] += value;
			}
		}
		ll at(ll idx) 
		{
			int res = 0;
			for (idx += size; idx > 0; idx >>= 1) res += base[idx];
			return res;
		}
};




string id2(ll a) 

{
	if (a == 0) return "0";
	string k = "";
	ll p = 0;
	if (a < 0)
	{
		p = 1;
		a = -a;
	}
	while(a)
	{
		k = (char)((a % 10) + '0') + k;
		a /= 10;
	}
	if (p) k = '-' + k;
	return k;
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

ld eps = 1e-9;

























bool id3(ll x)
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

struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n);
        if (n > 0) FOR(i, 0, par.size() - 1) par[i] = i;
    }

    int getPar(int u) {
        if (par[u] != u)
            par[u] = getPar(par[u]);
        return par[u];
    }

    void join(int u, int v) {
        u = getPar(u), v = getPar(v);
        par[max(u, v)] = min(u, v);
    }

    int operator[](int x) {
        return getPar(x);
    }
};

void Process()
{
	int n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU a(n), b(n);
    FOR(i, 1, m1)
    {
    	ll x, y;
    	cin >> x >> y;
    	a.join(x - 1, y - 1);
	}
	FOR(i, 1, m2)
	{
		ll x, y;
		cin >> x >> y;
		b.join(x - 1, y - 1);
	}
    vector<pair<int, int> > ans;
    FOR(i, 0, n - 1) FOR(j, 0, n - 1)
        if (a[i] != a[j] && b[i] != b[j]) {
            ans.pb({i + 1, j + 1}),
            a.join(i, j), b.join(i, j);
        }

    cout << ans.size() << '\n';
    if (ans.empty()) return;
    for (int i = 0; i < ans.size(); i++)
    {
    	cout << ans[i].f << ' ' << ans[i].s << endl;
	}
}

signed main() 
{
	faster();




		Process();


}














