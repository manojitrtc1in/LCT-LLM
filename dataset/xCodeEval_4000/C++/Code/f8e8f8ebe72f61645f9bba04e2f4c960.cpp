

#include<bits/stdc++.h>
using namespace std;

#define P(x) cout<<#x<<" = { "<<x<<" }\n"
#define All(a) (a).begin(), (a).end()
#define _2d(a,row,col,type) type**a=new type*[row]; for (int i=0;i<row;i++) a[i]=new type[col];
#define lp(i,n) for(int i=0;i<int(n);i++)
#define rep(i, j, n) for (int i=j, i<n; i++)
#define lpr(i,n) for(int i=n-1;i>=0;i--)
#define loopi(i,a,n) for(int i=int(a);i<int(n);i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define scn(a,n) rep(i,n) cin>>a[i];
#define scn2(a,row,col) rep(i,row) rep(j,col) cin>>a[i][j];
#define prn(a,n) rep(i,n-1) cout<<a[i]<<" "; cout<<a[n-1]<<endl;
#define prn2(a,row,col) rep(i,row){rep(j,col-1) cout<<a[i][j]<<" "; cout<<a[i][col-1]<<endl;}
#define rdi(x) scanf("%d",&(x))
#define rdk(x,y) scanf("%d%d",&(x),&(y))
#define rdl(x) scanf("%I64d",&(x))
#define rdll(x,y) scanf("%I64d%I64d",&(x),&(y))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define Odd(x) x%2!=0
#define Even(x) x%2==0
#define Pi 3.1415926535897932384626433832795
#define INF 2000000000 

#define OO 0x7fffffff
#define maxL (10000000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))
#define mod 1000000007
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, string> is;
typedef vector<ii> vii;










#define maX 10000001
int se[maX]= {0};

 bool prime[maX];
 void SieveOfEratosthenes(int n)
 {
     

     

     


     memset(prime, true, sizeof(prime));

     for (int p=2; p*p<=n; p++)
     {
         

         if (prime[p] == true)
         {
             

             for (int i=p*2; i<=n; i += p)
                 prime[i] = false;
         }
     }

     

    
 }




bool is_prime(long long x) {
	if (x == 1)
		return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;

}

bool is_palindrome(string s1) {
	int l = s1.length();
	for (int i = 0; i < l / 2; i++)
		if (s1[i] != s1[l - i - 1])
			return false;

	return true;
}

ull C(ll n, ll k) {
	if (k == 0) return 1;

	return (n * C(n - 1, k - 1)) / k;
}

ll modular_pow(ll base, ll exponent, int modulus) {
	ll result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

long long binaryToDec(string number) {
	long long result = 0, pow = 1;
	for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
		result = (result + (number[i] - '0') * pow) % 1000003;

	return result;
}

ull GCD(ull a, ull b) {
	return b == 0 ? a : GCD(b, a % b);
}

int cntMask(int mask) {
	int ret = 0;
	while (mask) {
		if (mask % 2)
			ret++;
		mask /= 2;
	}
	return ret;
}
int getBit(int mask, int i) {
	return ((mask >> i) & 1) == 1;
}
int setBit(int mask, int i, int value = 1) {
	return (value) ? mask | (1 << i) : (mask & ~(1 << i));
}

ull mystoi(string s) {
	ull ans = 0;
	ull po = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += (s[i] - '0') * po;
		po *= 10;
	}

	return ans;

}

string conv(int i) {
	string t = "";
	while (i) {
		t += '0' + (i % 10);
		i /= 10;
	}
	

	return t;
}

bool hasZero(int i) {
	if (i == 0)
		return true;
	while (i) {
		if (i % 10 == 0)
			return true;
		i /= 10;
	}
	return false;
}



bool isSortedAc(int a[], int n) {
	lp(i,n-1)
		if (a[i] > a[i + 1])
			return false;

	return true;
}

bool isSortedDec(int a[], int n) {
	lp(i,n-1)
		if (a[i] < a[i + 1])
			return false;

	return true;
}




bool check(int i,ii p)
{
	return (i>=p.first && i<=p.second);
}



int main(){



int n,q;
scanf("%d%d",&n,&q);

vi a(n);
vll suf(n);
vi b(n);
vii el(n);
vii qu(q);


lp(i,n)scanf("%d",&a[i]);



sort(a.begin(),a.end());


vi f(n);

lp(i,q){scanf("%d%d",&qu[i].first,&qu[i].second);
int l=qu[i].first-1;
int r=qu[i].second-1;

f[l]++;
if(r+1<n)
f[r+1]--;
}

for(int i=1;i<n;i++)
	f[i]+=f[i-1];


lp(i,n)
{
 el[i].second=i;
 el[i].first=f[i];

}


sort(el.begin(),el.end());

for(int i=n-1;i>=0;i--)
{
	int idx=el[i].second;
	b[idx]=a[i];
}



suf[0]=b[0];
for(int i=1;i<n;i++)
	suf[i]=b[i]+suf[i-1];

ll total=0;
lp(i,q)
{
	int l=qu[i].first-1;
	int r=qu[i].second-1;

	total +=suf[r]-suf[l]+b[l];
}


cout<<total<<endl;



return 0;
}





