




























































#include <bits/stdc++.h>













	
	

	


	#define ll long long
	#define ld long double
	#define ull unsigned long long
	#define pb push_back
	#define eb emplace_back
	#define cl(C) C.clear()
	#define f first
	#define s second
	#define cint cpp_int
	#define all(C) C.begin(), C.end()
	#define Begin() int N; cin>>N; cin.ignore(); while(N--)
	
	

	
		

		
		#define FOR(i,a,b) for (ll i=a; i<=b; i++)
		#define FOR2(i,a,b) for (ll i=a; i<=b; ++i)
		#define FORD(i,a,b) for (ll i=a; i>=b; i--)
		#define FORA(x,C) for (auto x:C)
		#define WHILE(x,y) while(cin>>x>>y)
		#define WHILEF(x,y,f) while(f>>x>>y)
		#define WHILE2(x) while(cin>>x)
		#define WHILEGL(a) while(getline(cin,a))
		#define WHILEGLF(a,f) while(getline(f,a))
		
		

		
		#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
		#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
		#define ite(y,x,it) y<x>::iterator it
		
		

		
		#define reset(C) memset(C,0,sizeof(C))
		#define clearQueue(C, x) C = queue<x> ()
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
		#define addString(token,a,b){if (a.length() < b.length()) swap(a,b);string token = "";reverse(a.begin(), a.end());reverse(b.begin(), b.end());int carry = 0;FOR(i,0,b.length()-1){carry = carry + (a[i] - '0') + (b[i] - '0');token.push_back(carry % 10 + '0');carry /= 10;}FOR(i,b.length(),a.length()-1){carry = carry + (a[i] - '0');token.pb(carry % 10 + '0');carry /= 10;}if (carry) token.pb(carry + '0');reverse(token.begin(), token.end());}
		#define multiplyString(token,a,b){reverse(A.begin(),A.end());reverse(B.begin(),B.end());string C;C.resize(A.length()+B.length(),'0');FOR(i,0,A.length()-1){int c = 0;FOR(j,0,B.length()-1){c += ((A[i]-'0') * (B[j]-'0') + C[i+j] -'0');C[i+j] = (char)(c%10 + '0');c/=10;}if (c > 0) C[i + B.length()] += c;}reverse(C.begin(),C.end());return C;}
		#define subtractString(token, a, b){string token = "";reverse(a.begin(), a.end());reverse(b.begin(), b.end());int carry = 0;int sum = 0;FOR(i,0,b.length()-1){sum = (a[i] - '0') - (b[i] - '0') - carry;if (sum < 0){carry = 1;sum += 10;}else carry = 0;token.pb(sum + '0');}FOR(i,b.length(),a.length()-1){sum = (a[i] - '0') - carry;if (sum < 0){carry = 1;sum += 10;}else carry = 0;token.pb(sum + '0');}reverse(token.begin(), token.end());while(token[0] == '0') token.erase(0,1);}

		
		

		
		#define get(C,a) for(int i=0; i<a; i++) cin>>C[i]
		#define get2(C,a,b) for(int i=0; i<a; i++) for (int j=0; j<b; j++) cin>>C[i][j]
		#define getVector(C) for(int i=0; i<C.size(); i++) cin>>C[i]
		#define getMatrix(C) for(int i=0; i<C.size(); i++) for (int j=0; j<C[i].size(); j++) cin>>C[i][j]
		#define getDeque(C) for(int i=0; i<C.size(); i++) cin>>C[i]
		#define getSet(C, a, token) for(int i=0; i<a-1; i++) { cin>>token; C.insert(token); } cin>>token; C.insert(token)
		#define print(C,a) for(int i=0; i<a; i++) cout<<C[i]<<' '
		#define printVector(C) for(int _=0; _<C.size(); _++) cout<<C[_]<<' '
		#define printSet(C,x) for (set<x>::iterator it = C.begin(); it!= C.end(); ++it) cout<<*it<<' '
		#define printDeque(C) for(int i=0; i<C.size(); i++) cout<<C[i]<<' '
		
		

		
		#define toSet(C,x) set<x> (C.begin(), C.end())
		#define toVector(C,x) vector<x> (C.begin(), C.end())
		#define toQueue(C,x) queue<x> (C.begin(), C.end())
		#define toDeque(C,x) deque<x> (C.begin(), C.end())
		#define toList(C,x) list<x> (C.begin(), C.end())
		#define toMultiset(C,x) multiset<x> (C.begin(), C.end())
		
		

		
		#define pointer(A,x) A<x>::iterator
		
	

	
	#define um(x,y) unordered_map<x,y> 
	#define m(x,y) map<x,y> 
	#define p(x,y) pair<x,y> 
	#define us(x) unordered_set<x> 
	#define vec(x) vector<x> 
	#define Matrix(x) vector<vec(x)>
	#define Rubik(x) vector<Matrix(x)>
	#define vec2(C,x,y,token) vector<vector<token> > C(x, vector<token> (y, 0))
	#define pq(x) priority_queue<x>
	#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >
	
	

	
	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#define pause() system("pause");




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

bool isprimell(ull n)
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




ll __stoll(string x) 

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




string __to_string(ll a) 

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











#define nl << '\n'

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





