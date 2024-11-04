















using namespace std;
typedef long long  ll;
typedef long double ld;

ll mod = 998244353;
ld pi = 3.1415926535;


struct Triple
{
	ll a;
	ll b;
	ll c;
};

void print2(vector<vector<ll>>& vec)
{
	for (int i = 0; i < vec[0].size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			cout << vec[j][i] << " ";
		}
		cout << endl;
	}
}

ll pow2(ll n, ll p)
{
	if (p == 0)
		return 1;

	if (p % 2 == 0)
	{
		ll x = pow2(n, p / 2);
		return (x * x) % mod;
	}
	else
	{
		return n * pow2(n, p - 1) % mod;
	}
}


vector<ll> fack(1000000, 1);
void id0()
{
	for (int i = 1; i < fack.size(); i++)
	{
		fack[i] = fack[i - 1] * (i) % mod;
	}
	return;
}

ll c(ll n, ll k)
{
	if (n < k)
		return 0;
	return ((fack[n] * pow2(fack[n - k], mod - 2) % mod) * pow2(fack[k], mod - 2)) % mod;
}



int main()
{
	ll q;
	cin >> q;
	while (q--)
	{
		ll n;
		cin >> n;
		cout << (n - 3) / 3 - 1 << endl;
	}
}

