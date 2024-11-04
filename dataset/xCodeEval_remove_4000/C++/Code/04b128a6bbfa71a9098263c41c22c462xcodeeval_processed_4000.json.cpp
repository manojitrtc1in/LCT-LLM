










































































	
	

	


	
	
	
	
	
	
	
	
	
	
	
	
	

	
		

		
		
		
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		

		
		
		
		
		
		

		
		
		
		
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		
		
		
		

		
		
		
	

	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	




using namespace std;
























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




ll id3(string x) 

{
	ll k = 0;
	FOR(i, 0, x.size() - 1)
	{
		k = k * 10 + (x[i] - '0');
	}
	return k;
}




vec(ll) __baseForSeg[2000]; 


class SegTree
{
	SegTree *L = NULL, *R = NULL;
	ll idxl, idxr;
	ll ans;
	ll x;
	public:
		void getbase(vec(ll) &a, ll k)
		{
			__baseForSeg[k] = a;
			x = k;
			idxl = 0;
			idxr = a.size() - 1;
		}
		void update()
		{
			if (idxl == idxr)
			{
				ans = __baseForSeg[x][idxl];
				return;
			}
			if (idxl > idxr) 
			{
				ans = 0; return;
			}
			else 
			{
				ll mid = (idxl + idxr) / 2;
				if (L == NULL)
				{
					L = new SegTree;
					L->idxl = idxl;
					L->idxr = mid;
					L->x = x;
				}
				L->update();
				if (R == NULL)
				{
					R = new SegTree;
					R->idxl = mid + 1;
					R->idxr = idxr;
					R->x = x;
				}
				R->update();
				ans = L->ans + R->ans;
			}
		}
		void out()
		{
			cout << this->ans << endl;
			printVector(__baseForSeg[x]);
			cout << endl;
		}
		ll searchn(SegTree *a, ll l, ll r)
		{
			if (a->idxl >= l && a->idxr <= r) return a->ans;
			if (a->idxl > r || a->idxr < l) return 0;
			return searchn(a->L, l, r) + searchn(a->R, l, r);
		}
		ll search(ll l, ll r)
		{
			if (idxl >= l && idxr <= r) return ans;
			if (idxl > r || idxr < l) return 0;
			return searchn(this->L, l, r) + searchn(this->R, l, r);
		}
		void updatenum(ll a, ll idx)
		{
			if (idx > idxr || idx < idxl) return;
			if (idxr == idxl) return;
			ans += (a - __baseForSeg[x][idx]);
			L->updatenum(a, idx);
			R->updatenum(a, idx);
		}
		void afterupdate(ll a, ll idx)
		{
			__baseForSeg[x][idx] = a;
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
	return C;
}

string div(string number, ll divisor) 

{
    string ans;
    ll idx = 0;
    ll temp = number[idx] - '0';
    while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) 
	{
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if (ans.length() == 0) return "0";
    return ans;
}



















































ld PI = 3.14159265358979323846;













void Process()
{
	ll a;
	cin >> a;
	set<ll> S;
	ll x;
	cin >> x;
	S.insert(x);
	ll y;
	set<ll>::iterator it;
	bool f = 1;
	FOR(i, 1, a - 1)
	{
		cin >> y;
		S.insert(y);
		if (y > x)
		{
			ll k = *(S.upper_bound(x));
			if (k != y)
			{
				f = 0;


			}
		}
		else if (y == x)
		{
			it = (S.lower_bound(x));
			ll k = *it;
			if (k != y)
			{
				f = 0;


			}
		}
		else
		{
			it = (S.lower_bound(x));
			it--;
			ll k = *it;
			if (k != y)
			{
				f = 0;




			}
		}
		x = y;
	}
	if (f) cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}

signed main() 
{
	faster();
	Begin()
	{
		Process();
	}
}





