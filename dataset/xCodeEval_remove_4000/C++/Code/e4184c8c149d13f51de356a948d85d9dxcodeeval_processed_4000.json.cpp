


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














bool is_prime(long long x) {
	if (x == 1)
		return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;

}

bool id3(string s1)
{
    int l=s1.length();
    for(int i=0; i<l/2; i++)
        if(s1[i]!=s1[l-i-1])
        return false;

    return true;
}

ull C(ll n, ll k) {
	if (k == 0)
		return 1;
	return (n * C(n - 1, k - 1)) / k;
}

ll id0(ll base, ll exponent, int modulus) {
	ll result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

long long id2(string number) {
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

ull id1(string s) {
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



int main(void)
{

	int n;
	ii a[1000+5];
	cin>>n;

	set<int> sett;
	int sum=0;
	lp(i,n)
	{
		int x;
		cin>>x;
		a[i]=mp(x,i+1);
		sett.insert(x);
		sum+=x;
	}

	sort(a,a+n);
    int av=sum/n;

	if(a[0].first==a[n-1].first)cout<<"Exemplary pages."<<endl;

	else
	{
		if(sett.size()>3)
			cout<<"Unrecoverable configuration."<<endl;

		else{
			int dif=a[n-1].first-a[0].first;
			

			if((a[n-1].first+a[0].first)/2!=av || Odd(dif) || sum%n || (n>3 && sett.size()!=3))
				cout<<"Unrecoverable configuration."<<endl;
			else
		  cout<<abs(a[0].first-av)<<" ml. from cup 
	}
	}







}










