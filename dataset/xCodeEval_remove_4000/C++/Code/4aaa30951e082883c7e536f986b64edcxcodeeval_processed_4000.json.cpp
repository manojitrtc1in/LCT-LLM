
































































































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

int n;
struct sq
{
	int x1, y1, x2, y2;
};
vector<sq> R;


int X, Y;
map<int, int> mx, my;
int xm[2018], ym[2018];


int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool ziw[2007][2007], lgl[2007][2007];
INT ans;

void dfs(int x,int y)
{
	if(x<0||x>=X||y<0||y>=Y||ziw[x][y]||lgl[x][y])
		return;
	lgl[x][y] = 1;
	FOR(i,4)
		dfs(x + dx[i], y + dy[i]);
}

int main()
{
	cin >> n;
	int x = 0, y = 0;
	FOR(i,n)
	{
		string dir;
		int d;
		cin >> dir >> d;
		if(dir=="L")
		{
			sq bb = {x - d, y, x + 1, y + 1};
			R.push_back(bb);
			x -= d;
		}
		if(dir=="R")
		{
			sq bb = {x, y, x + d + 1, y + 1};
			R.push_back(bb);
			x += d;
		}
		if(dir=="U")
		{
			sq bb = {x, y, x + 1, y + d + 1};
			R.push_back(bb);
			y += d;
		}
		if(dir=="D")
		{
			sq bb = {x, y - d, x + 1, y + 1};
			R.push_back(bb);
			y -= d;
		}
	}
	FOR(i,n)
	{
		mx[R[i].x1] = mx[R[i].x2] = 0;
		my[R[i].y1] = my[R[i].y2] = 0;
	}
	foreach(it,mx)
	{
		it->second = X;
		xm[X] = it->first;
		X++;
	}
	X--;
	foreach(it,my)
	{
		it->second = Y;
		ym[Y] = it->first;
		Y++;
	}
	Y--;
	FOR(i,n)
	{
		int x1 = mx[R[i].x1], y1 = my[R[i].y1], x2 = mx[R[i].x2], y2 = my[R[i].y2];
		FFOR(j,x1,x2)
			FFOR(k,y1,y2)
				ziw[j][k] = 1;
	}
	FOR(i,X)
		FOR(j,Y)
			if(i==0||i==X-1||j==0||j==Y-1)
				dfs(i, j);
	FOR(i,X)
		FOR(j,Y)
			if(!lgl[i][j])
			{
				INT disx = xm[i + 1] - xm[i], disy = ym[j + 1] - ym[j];
				ans += disx * disy;
			}
	cout << ans << endl;
	return 0;
}