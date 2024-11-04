


#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>
#include <set>
#include <deque>
#include <unordered_map>
#include <queue>
#include <unordered_map>

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
void build_fack()
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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
		ll pe = 0;
        vector<vector<ll>> vec(26, vector<ll>(3, -2));
        for (int i = 0; i < 26; i++)
            vec[i][1] = i;

        vector<bool> used(26, false);
        for (int i = 0; i < n; i++)
        {
            ll q = s[i] - 'a';
            if (vec[q][2] != -2)
			{
                ans += (char)vec[vec[q][2]][1] + 'a';
            }
            else 
			{
                for (int j = 0; j < 26; j++)
                {
                    if (q != j && !used[j])
                    {
                       
                        ll y = 0;
						ll x = q;
						ll el = 0;
                        while (vec[x][0] != -2) 
                        {
                            y++;
							x = vec[x][0];
                            if (y < 25 && x == j)
                            {
                                el = 1;
                                break;
                            }
                        }
                        if (el == 0)
                        {
                           
                            vec[j][0] = q;
							used[j] = true;
							

							pe++;
							

                            ans += (char)'a' + j;
							vec[q][2] = j;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}