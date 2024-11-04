#include<bits/stdc++.h>


using namespace std;



#define ll long long
#define PI 3.14159265

ll mod = 1000000007;
ll z   = 1000000000;
const ll N   = 1e9 + 1;
const ll INF = 1e18;
ll mod2 = 998244353;






#define mp                make_pair
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (ll)((x).size())
#define fr                first
#define sc                second
#define pii               pair<ll,ll>
#define vi                vector<ll>
#define vvi               vector<vector<ll>>
#define vp                vector<pair<ll,ll>>
#define rep(i,a,b)        for(ll i=a;i<b;i++)
#define repr(i,a,b)       for(ll i=b-1;i>=a;i--)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)








































































































































































































































































































































































































































































































































































































































ll t, n, m;

void solve()
{
	string s;
	cin >> s;
	n = s.size();
	vi cnt(26, 0);
	rep(i, 0, n)
	{
		cnt[s[i] - 'a']++;
	}
	ll zero_ans = -1;
	rep(i, 0, 26)
	{
		if (cnt[i] == 1)
		{
			zero_ans = i;
			cnt[i] = 0;
			break;
		}
	}
	string ans = "";
	vp counts;
	rep(i, 0, 26)
	{
		if (cnt[i] > 0)
			counts.pb(mp(cnt[i], i));
	}
	if (zero_ans != -1)
	{
		ans += zero_ans + 'a';
		rep(i, 0, 26)
		{
			while (cnt[i] > 0)
			{
				cnt[i]--;
				ans += (i + 'a');
			}
		}
		cout << ans << endl;
		return;
	}


	

	

	

	

	if (counts.size() == 1)
	{
		

		rep(i, 0, counts[0].fr)
		{
			ans += counts[0].sc + 'a';
		}
		cout << ans << endl;
		return;
	}
	else
	{
		


		if ((counts[0].fr) <= 2 + n - (counts[0].fr))
		{
			

			ans += counts[0].sc + 'a';
			counts[0].fr--;
			vi others;
			ll min_poss = counts[0].sc;
			rep(i, 1, sz(counts))
			{
				while (counts[i].fr > 0)
				{
					counts[i].fr--;
					others.pb(counts[i].sc);
				}
			}
			ans += counts[0].sc + 'a';
			counts[0].fr -= 1;
			ll size = min((ll)others.size(), counts[0].fr);
			rep(i, 0, size)
			{
				ans += others[i] + 'a';
				ans += min_poss + 'a';
			}
			counts[0].fr -= size;
			rep(i, size, others.size())
			{
				ans += others[i] + 'a';
			}
			while (counts[0].fr > 0)
			{
				ans += min_poss + 'a';
				counts[0].fr--;
			}
			cout << ans << endl;
			return;
		}
		

		else if (counts.size() == 2)
		{
			ans += counts[0].sc + 'a';
			counts[0].fr--;
			rep(i, 0, counts[1].fr)
			{
				ans += counts[1].sc + 'a';
			}
			rep(i, 0, counts[0].fr)
			{
				ans += counts[0].sc + 'a';
			}
			cout << ans << endl;
			return;
		}
		

		else
		{
			

			

			

			

			

			

			

			

			

			

			

			ans += counts[0].sc + 'a';
			counts[0].fr--;
			ans += counts[1].sc + 'a';
			counts[1].fr--;
			rep(i, 0, counts[0].fr)
			{
				ans += counts[0].sc + 'a';
			}
			ans += counts[2].sc + 'a';
			counts[2].fr--;
			rep(i, 0, counts[1].fr)
			{
				ans += counts[1].sc + 'a';
			}
			rep(i, 2, counts.size())
			{
				rep(j, 0, counts[i].fr)
				{
					ans += counts[i].sc + 'a';
				}
			}
			cout << ans << endl;
			return;
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;
	cin >> t;
	

	while (t--)
	{
		solve();
	}
}
