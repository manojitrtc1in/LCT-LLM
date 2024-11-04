
















using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;





  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {

~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}

sim dor(const c&) { ris; }

};




using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=607;
const ll mod=1000*1000*1000+7;
const ll modk=mod*mod*5;

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

int n, k;

ll tab[nax];

ll kom[nax][nax];
ll p2[nax];

ll wyn;

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void id4(ll &a, ll b)
{
	if ((a+=b)>=modk)
		a-=modk;
}

bool id3(int a, int b)
{
	return abs(a)<abs(b);
}

ll dpn[nax][nax][2][2];
ll dps[nax][nax][2][2];

ll harde[nax][nax];

void id1(int a, int b, int h, ll w)
{
	

	
	int d=a;
	int uje=b;
	int lew=a;
	if (!h)
		swap(d, uje);
	dod(harde[d][uje], w);
}

ll poms[nax][nax];
ll pomn[nax][nax];

vector<pll> wek[nax];

int nd, nu;
ll dosd[nax];
ll dosu[nax];

int kt[nax];

ll slaba_gor[nax][nax];
ll slaba_dol[nax][nax];

void go(int v, vector<pair<pll,ll>> &dwa)
{
	if (dwa.empty())
		return;
	for (auto &i : dwa)
		i.first.second=abs(i.first.second);
	for (int i=0; i<=nd+1; i++)
	{
		for (int j=0; j<=nu+1; j++)
		{
			slaba_gor[i][j]=slaba_dol[i][j]=0;
		}
	}
	

	

	for (int j=1; j<=v; j++)
	{
		for (int l=1; l<=v; l++)
		{
			if (tab[j]>0 && tab[l]<0)
			{
				dod(slaba_gor[kt[j]][kt[l]], pomn[j][l]*abs(tab[l]));
				dod(slaba_dol[kt[j]][kt[l]], pomn[j][l]*abs(tab[j]));
			}
		}
	}
	

	

		

		

			

			

			

				

				

			

		

		

		

	

	for (int i=1; i<=nd; i++)
	{
		for (int j=2; j<=nu; j++)
			dod(slaba_dol[i][j], slaba_dol[i][j-1]);
		for (int j=nu-1; j; j--)
			dod(slaba_gor[i][j], slaba_gor[i][j+1]);
	}
	for (auto j : dwa)
	{
		ll zgor=j.second*inv(j.first.first)%mod;
		ll zdol=j.second*inv(j.first.second)%mod;
		int wsk=0;
		for (int i=1; i<=nd; i++)
		{
			while(wsk<nu && j.first.second*dosu[wsk+1]<j.first.first*dosd[i])
				wsk++;
			dod(wyn, zgor*slaba_gor[i][wsk+1]);
			dod(wyn, zdol*slaba_dol[i][wsk]);
		}
	}
	

	

		

		

			

			

			

				

				

			

			

			

				

				

			

		

	

}

ll gowno1[nax][nax][2];
ll gowno2[nax][nax];

void id2()
{
	gowno1[0][0][0]=1;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=k; j++)
		{
			for (int p=0; p<2; p++)
			{
				dod(gowno1[i][j][p], gowno1[i-1][j][p]);
				dod(gowno1[i][j+1][p^(tab[i]<0)], gowno1[i-1][j][p]*tab[i]);
			}
		}
	}
	dod(wyn, gowno1[n][k][1]);
	
	if (k&1)
	{
		gowno2[0][0]=1;
		for (int i=1; i<=n; i++)
		{
			for (int j=0; j<i && j<=k+1; j++)
			{
				dod(gowno2[i][j], gowno2[i-1][j]);
				if (tab[i]<0)
				{
					if (j<k)
						dod(gowno2[i][min(j+1, k+1)], gowno2[i-1][j]*tab[i]);
					else
						dod(gowno2[i][min(j+1, k+1)], gowno2[i-1][j]);
				}
			}
		}
		for (int i=k+1; i<=n; i++)
			dod(wyn, gowno2[n][i]);
	}
}




int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
		

	ll id0=1;
	sort(tab+1, tab+1+n, id3);
	reverse(tab+1, tab+1+n);
	while(n && !tab[n])
	{
		n--;
		id0=(id0*2)%mod;
	}
	reverse(tab+1, tab+1+n);
	tab[n+1]=0;
	for (int i=0; i<=n; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j]+kom[i-1][j-1])%mod;
	}
	p2[0]=1;
	for (int i=1; i<=n; i++)
		p2[i]=p2[i-1]*2%mod;
	dpn[0][n+1][0][0]=1;
	dpn[0][n+1][0][1]=1;
	

	
	
	
	for (int i=n; i; i--)
	{
		for (int j=0; j<k; j++)
		{
			for (int l=i+1; l<=n+1; l++)
			{
				for (int p=0; p<2; p++)
				{
					for (int h=0; h<2; h++)
					{
						dps[j][l][p][h]=dpn[j][l][p][h];
						dpn[j][l][p][h]=0;
					}
				}
			}
		}
		int w=(tab[i]<0);
		for (int j=0; j<k; j++)
		{
			if (j+i<k-5)
				continue;
			for (int l=i+1; l<=n+1; l++)
			{
				for (int p=0; p<2; p++)
				{
					for (int h=0; h<2; h++)
					{
						if (!dps[j][l][p][h])
							continue;
						dod(dpn[j][l][p][h], dps[j][l][p][h]);
						if (j+1<k)
						{
							if (w!=h)
								dod(dpn[j+1][l][p^w][h], dps[j][l][p][h]*abs(tab[i]));
							else
								dod(dpn[j+1][i][p^w][h], dps[j][l][p][h]*abs(tab[i]));
						}
						else
						{
							if (w!=h)
							{
								if (!(p^w))
								{
									dod(wyn, dps[j][l][p][h]*abs(tab[i])%mod*p2[i-1]);
								}
								else
								{
									id1(i, l, h, dps[j][l][p][h]*abs(tab[i])%mod);
								}
							}
						}
					}
				}
			}
		}
	}
	

	{
		set<ll> d, u;
		for (int i=1; i<=n; i++)
		{
			if (tab[i]>0)
				d.insert(tab[i]);
			if (tab[i]<0)
				u.insert(-tab[i]);
		}
		d.insert(1);
		u.insert(1);
		for (ll i : d)
		{
			nd++;
			dosd[nd]=i;
		}
		for (ll i : u)
		{
			nu++;
			dosu[nu]=i;
		}
		for (int i=1; i<=n; i++)
		{
			if (tab[i]>0)
			{
				for (int j=1; j<=nd; j++)
				{
					if (tab[i]==dosd[j])
						kt[i]=j;
				}
			}
			if (tab[i]<0)
			{
				for (int j=1; j<=nu; j++)
				{
					if (-tab[i]==dosu[j])
						kt[i]=j;
				}
			}
		}
	}
	pomn[0][0]=1;
	

	

		

		

			

			

				

				

					

				

					

			

		

	

	vector<pair<pii,int>> raz, dwa;
	vector<pair<pii,int>> razs[2];
	vector<pair<pll,ll>> dwas[2];
	for (int i=0; i<n; i++)
	{
		

			

		if (i+k>n)
			break;
		if (i)
		{
			for (int j=0; j<i; j++)
			{
				for (int l=0; l<i; l++)
				{
					poms[j][l]=pomn[j][l];
					pomn[j][l]=0;
				}
			}
			for (int j=0; j<i; j++)
			{
				for (int l=0; l<i; l++)
				{
					if (!poms[j][l])
						continue;
					dod(pomn[j][l], poms[j][l]);
					if (tab[i]>0)
						dod(pomn[i][l], poms[j][l]);
					else
						dod(pomn[j][i], poms[j][l]);
				}
			}
		}
		raz.clear();
		dwa.clear();
		for (int a=0; a<2; a++)
		{
			razs[a].clear();
			dwas[a].clear();
		}
		for (int j=0; j<=i; j++)
		{
			for (int l=0; l<=i; l++)
			{
				if (!pomn[j][l])
					continue;
				

				if (!tab[j] || !tab[l])
					razs[1].push_back({{tab[j], tab[l]}, (pomn[j][l]+mod)%mod});
			}
		}
		for (int j=i+1; j<=n+1; j++)
		{
			for (int l=i+1; l<=n+1; l++)
			{
				if (j>i+1 && l>i+1)
					continue;
				if (!harde[j][l])
					continue;
				dwa.push_back({{tab[j], tab[l]}, (harde[j][l]+mod)%mod});
			}
		}
		
		if (dwa.empty())
			continue;
		
		

		
		
		

			

				

		for (auto j : dwa)
			dwas[!j.first.first || !j.first.second].push_back(j);
		for (int a=0; a<2; a++)
		{
			if (a)
				break;
			const vector<pair<pii,int>> &praz=(!a ? razs[1] : raz);
			const vector<pair<pll,ll>> &pdwa=(!a ? dwas[0] : dwas[1]);
			

			for (const auto &l : pdwa)
			{
				ll o1=inv(l.first.first);
				ll o2=inv(abs(l.first.second));
				if (!o1 && !o2)
					continue;
				for (const auto &j : praz)
				{
					if ((!j.first.first || !l.first.second) && (!j.first.second || !l.first.first))
					{
						

						continue;
					}
					if (!j.first.first || !l.first.second)
					{
						id4(wyn, j.second*l.second%mod*o1%mod*abs(j.first.second));
						continue;
					}
					if (!j.first.second || !l.first.first)
					{
						id4(wyn, j.second*l.second%mod*o2%mod*j.first.first);
						continue;
					}
					

				}
			}
		}
		

		for (const auto &l : dwas[1])
		{
			ll o1=inv(l.first.first);
			ll o2=inv(abs(l.first.second));
			if (!o1 && !o2)
				continue;
			for (int h1=0; h1<=i; h1++)
			{
				for (int h2=0; h2<=i; h2++)
				{
					if (!pomn[h1][h2])
						continue;
					pair<pll,ll> j={{tab[h1], tab[h2]}, (pomn[h1][h2]+mod)%mod};
					

					if ((!j.first.first || !l.first.second) && (!j.first.second || !l.first.first))
					{
						

						continue;
					}
					if (!j.first.first || !l.first.second)
					{
						id4(wyn, j.second*l.second%mod*o1%mod*abs(j.first.second));
						continue;
					}
					if (!j.first.second || !l.first.first)
					{
						id4(wyn, j.second*l.second%mod*o2%mod*j.first.first);
						continue;
					}
				}
				

			}
		}
		

		go(i, dwas[0]);
	}
	
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	wyn*=id0;
	wyn%=mod;
	
	
	

	

	

	
	

	
	

	
	id2();
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	
	printf("%lld\n", wyn);
	return 0;
}
