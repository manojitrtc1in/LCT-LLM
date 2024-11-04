










































































	
	

	


	
	
	
	
	
	
	
	
	
	
	
	
	

	
		

		
		
		
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		

		
		
		
		
		
		

		
		
		
		
		
		
		
		
		
		
		
		
		

		
		

		
		
		
		
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		
		
		
		

		
		
		
	

	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	




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
	string k = "";
	while(a)
	{
		k = (char)((a % 10) + '0') + k;
		a /= 10;
	}
	return k;
}



















































ld PI = 3.14159265358979323846;













vec(ll) C;

bool found = false;

ll a;

map<ll, ll> M;

void Try(ll curr, ll sum, ll get)
{


	if (get == 1) M[sum]++;
	if (sum != 0 && M[sum] > 1) found = true;
	if (C[curr] == 0) found = true;
	if (found) return;
	if (curr == a - 1) return;
	Try(curr + 1, sum, 0);
	Try(curr + 1, sum + C[curr + 1], 1);
}

void Process()
{
	cin >> a;
	C.resize(a);
	getVector(C);
	FOR(i, 0, a - 1) if (C[i] < 0) C[i] = -1 * C[i];
	if (a == 1)
	{
		if (C[0] == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		return;
	}
	found = false;
	M.clear();
	Try(0, 0, 0);
	Try(0, C[0], 1);
	if (found) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() 
{
	faster();
	Begin()
	{
		Process();
	}
}





