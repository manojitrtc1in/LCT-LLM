


using namespace std;





























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











int se[maX]= {0};

 bool prime[maX];
 void id0(int n)
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

bool id6(string s1) {
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

ll id1(ll base, ll exponent, int modulus) {
	ll result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

long long id5(string number) {
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

ull id4(string s) {
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



bool id3(int a[], int n) {
	lp(i,n-1)
		if (a[i] > a[i + 1])
			return false;

	return true;
}

bool id2(int a[], int n) {
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





