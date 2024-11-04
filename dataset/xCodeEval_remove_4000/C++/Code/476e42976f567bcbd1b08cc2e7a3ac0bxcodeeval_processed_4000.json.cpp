


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

int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; 









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




map<int , int> mapp;



int main(void) {

	int n,x;
	vi a;

	cin>>n>>x;
	int num;
	lp(i,n){
		cin>>num;
		a.pb(num);
	}


	int idx=(n+1)/2;
	sort(a.begin(),a.end());

	int ans=0;

	while(a[idx-1]!=x)
	{
		ans++;
		a.pb(x);
		n=a.size();
		idx=(n+1)/2;
		sort(a.begin(),a.end());
	}

	cout<<ans<<endl;
	return 0;
}












