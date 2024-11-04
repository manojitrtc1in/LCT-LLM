






























































































using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;





INT dt[800007][5], cou[800007], rnd[800007];
INT n;
INT do1[100007], do2[100007];
map<INT, INT> mii;
vector<INT> jl;

void Add(INT cur, INT tocur, INT num, INT mod, INT l, INT r)
{
	if(l>tocur)
	{
		rnd[cur] = (rnd[cur] + 1) % 5;
		rnd[2 * cur + 1] = (rnd[2 * cur + 1] + rnd[cur]) % 5;
		rnd[2 * cur + 2] = (rnd[2 * cur + 2] + rnd[cur]) % 5;
		INT dt2[5];
		for (INT i = 0; i < 5; i++)
			dt2[(i + rnd[cur]) % 5] = dt[cur][i];
		for (INT i = 0; i < 5; i++)
			dt[cur][i] = dt2[i];
		rnd[cur] = 0;
		return;
	}
	if(r<=tocur)
	{
		rnd[2 * cur + 1] = (rnd[2 * cur + 1] + rnd[cur]) % 5;
		rnd[2 * cur + 2] = (rnd[2 * cur + 2] + rnd[cur]) % 5;
		INT dt2[5];
		for (INT i = 0; i < 5; i++)
			dt2[(i + rnd[cur]) % 5] = dt[cur][i];
		for (INT i = 0; i < 5; i++)
			dt[cur][i] = dt2[i];
		rnd[cur] = 0;
		return;
	}
	if(l==tocur&&r==tocur+1)
	{
		INT dt2[5];
		for (INT i = 0; i < 5; i++)
			dt2[(i + rnd[cur]) % 5] = dt[cur][i];
		for (INT i = 0; i < 5; i++)
			dt[cur][i] = dt2[i];
		dt[cur][mod] += num;
		cou[cur]++;
		rnd[cur] = 0;
		return;
	}
	rnd[2 * cur + 1] = (rnd[2 * cur + 1] + rnd[cur]) % 5;
	rnd[2 * cur + 2] = (rnd[2 * cur + 2] + rnd[cur]) % 5;
	rnd[cur] = 0;
	if(r!=l+1)
	{
		Add(2 * cur + 1, tocur, num, mod, l, (l + r) / 2);
		Add(2 * cur + 2, tocur, num, mod, (l + r) / 2, r);
		for (INT i = 0; i < 5; i++)
			dt[cur][i] = dt[2 * cur + 1][i] + dt[2 * cur + 2][i];
		for (INT i = 0; i < 5; i++)
			cou[cur] = cou[2 * cur + 1] + cou[2 * cur + 2];
	}
}

void Del(INT cur, INT tocur, INT num, INT mod, INT l, INT r)
{
	if(l>tocur)
	{
		rnd[cur] = (rnd[cur] + 4) % 5;
		rnd[2 * cur + 1] = (rnd[2 * cur + 1] + rnd[cur]) % 5;
		rnd[2 * cur + 2] = (rnd[2 * cur + 2] + rnd[cur]) % 5;
		INT dt2[5];
		for (INT i = 0; i < 5; i++)
			dt2[(i + rnd[cur]) % 5] = dt[cur][i];
		for (INT i = 0; i < 5; i++)
			dt[cur][i] = dt2[i];
		rnd[cur] = 0;
		return;
	}
	if(r<=tocur)
	{
		rnd[2 * cur + 1] = (rnd[2 * cur + 1] + rnd[cur]) % 5;
		rnd[2 * cur + 2] = (rnd[2 * cur + 2] + rnd[cur]) % 5;
		INT dt2[5];
		for (INT i = 0; i < 5; i++)
			dt2[(i + rnd[cur]) % 5] = dt[cur][i];
		for (INT i = 0; i < 5; i++)
			dt[cur][i] = dt2[i];
		rnd[cur] = 0;
		return;
	}
	if(l==tocur&&r==tocur+1)
	{
		INT dt2[5];
		for (INT i = 0; i < 5; i++)
			dt2[(i + rnd[cur]) % 5] = dt[cur][i];
		for (INT i = 0; i < 5; i++)
			dt[cur][i] = dt2[i];
		dt[cur][mod] -= num;
		cou[cur]--;
		rnd[cur] = 0;
		return;
	}
	rnd[2 * cur + 1] = (rnd[2 * cur + 1] + rnd[cur]) % 5;
	rnd[2 * cur + 2] = (rnd[2 * cur + 2] + rnd[cur]) % 5;
	rnd[cur] = 0;
	if(r!=l+1)
	{
		Del(2 * cur + 1, tocur, num, mod, l, (l + r) / 2);
		Del(2 * cur + 2, tocur, num, mod, (l + r) / 2, r);
		for (INT i = 0; i < 5; i++)
			dt[cur][i] = dt[2 * cur + 1][i] + dt[2 * cur + 2][i];
		for (INT i = 0; i < 5; i++)
			cou[cur] = cou[2 * cur + 1] + cou[2 * cur + 2];
	}
}

INT Djg(INT cur, INT tol, INT tor, INT l, INT r)
{
	if(l>=tor)
		return 0;
	if(r<=tol)
		return 0;
	if(tol<=l&&r<=tor)
		return cou[cur];
	return Djg(2 * cur + 1, tol, tor, l, (l + r) / 2) + Djg(2 * cur + 2, tol, tor, (l + r) / 2, r);
}

void add(INT what)
{
	INT pos = mii[what];
	INT djg = Djg(0, 0, pos, 0, 100007);
	Add(0, pos, what, djg % 5, 0, 100007);
}

void del(INT what)
{
	INT pos = mii[what];
	INT djg = Djg(0, 0, pos, 0, 100007);
	Del(0, pos, what, djg % 5, 0, 100007);
}

int main()
{
	cin >> n;
	for (INT i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if(s=="add")
		{
			INT a;
			cin>>a;
			jl.pb(a);
			do1[i] = 1;
			do2[i] = a;
		}
		if(s=="del")
		{
			INT a;
			cin >> a;
			do1[i] = 2;
			do2[i] = a;
		}
		if(s=="sum")
			do1[i] = 3;
	}
	sort(jl.begin(), jl.end());
	for (INT i = 0; i < SZ(jl); i++)
		mii[jl[i]] = i;
	for (INT i = 0; i < n; i++)
	{
		if(do1[i]==1)
			add(do2[i]);
		if(do1[i]==2)
			del(do2[i]);
		if(do1[i]==3)
			cout << dt[0][2] << endl;
	}
	return 0;
}