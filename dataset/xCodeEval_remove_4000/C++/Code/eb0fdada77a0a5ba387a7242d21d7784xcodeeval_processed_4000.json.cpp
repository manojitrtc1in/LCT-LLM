




















using namespace std;

typedef long long ll;

static const double EPS = 1e-6;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(fabs(x),fabs(y)); }









int H;
int W;
const int DIR = 4;
const int dy[] = { 0,+1, 0,-1};
const int dx[] = {+1, 0,-1, 0};
vector < vector <int> > movable[4];

inline bool InArea(int y, int x)
{
	return INRANGE(x,0,W-1)&&INRANGE(y,0,H-1);
}

void EdgeMove(int& y, int&x ,int dir)
{

	y += movable[dir][y][x]*dy[dir];
	x += movable[dir][y][x]*dx[dir];

	while(1)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if( InArea(ny,nx)&&vs[y][x]==vs[ny][nx])
		{
			x = nx;
			y = ny;
		}
		else
		{
			break;
		}
	}

}



int main()
{
	int M,N;
	cin >> M >> N;
	vector <string> vs;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		vs.push_back(s);
	}

	H = M;
	W = SZ(vs[0]);


	for(int d = 0; d < 4; d++)
	{
		movable[d].clear();
		movable[d].resize(H);
		for (int y = 0; y < H; y++)
		{
			movable[d][y].resize(W);
		}
	}

	{
		const int d = 0;
		for (int y = 0; y < H; y++)
		{
			for (int x = W-1; x >= 0; x--)
			{
				if(x!=W-1 && vs[y][x]==vs[y][x+1])
				{
					movable[d][y][x] = movable[d][y][x+1]+1;
				}
				else
				{
					movable[d][y][x] = 0;
				}
			}
		}
	}

	{
		const int d = 1;
		for (int x = W-1; x >= 0; x--)
		{
			for (int y = H-1; y >= 0; y--)
			{
				if(y!=H-1 && vs[y][x]==vs[y+1][x])
				{
					movable[d][y][x] = movable[d][y+1][x]+1;
				}
				else
				{
					movable[d][y][x] = 0;
				}
			}
		}
	}

	{
		const int d = 2;
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x <= W-1; x++)
			{
				if(x!=0 && vs[y][x]==vs[y][x-1])
				{
					movable[d][y][x] = movable[d][y][x-1]+1;
				}
				else
				{
					movable[d][y][x] = 0;
				}
			}
		}
	}

	{
		const int d = 3;
		for (int x = W-1; x >= 0; x--)
		{
			for (int y = 0; y <= H-1; y++)
			{
				if(y!=0 && vs[y][x]==vs[y-1][x])
				{
					movable[d][y][x] = movable[d][y-1][x]+1;
				}
				else
				{
					movable[d][y][x] = 0;
				}
			}
		}
	}


	int x = 0;
	int y = 0;
	int dp =  0;
	int dcp = -1; 


	for (int n = 0; n < N; n++)
	{
		

		

		

		const int cp = (dp+dcp+DIR)%DIR;
		y += movable[dp][y][x]*dy[dp];
		x += movable[dp][y][x]*dx[dp];
		y += movable[cp][y][x]*dy[cp];
		x += movable[cp][y][x]*dx[cp];


		


		

		int ny = y + dy[dp];
		int nx = x + dx[dp];
		if(InArea(ny,nx)&&vs[ny][nx]!='0')
		{
			

			y = ny;
			x = nx;
		}
		else
		{
		

			if(dcp==-1)
			{
				

				dcp = +1;
			}
			else
			{
				

				dcp = -1;
				dp = (dp+1)%DIR;
			}
		}
		



		


	}

	printf("%d\n",vs[y][x]-'0');
}



int main()
{
	string s;
	int id4;
	cin >> s;
	cin >> id4;

	int dp[2][2][200][200]={}; 


	for (int i = 0; i < 2; i++)
	{
		for (int c = 0; c < 200; c++)
		{
			for (int x = 0; x < 200; x++)
			{
				dp[0][i][c][x]= -100000;
				dp[1][i][c][x]=  100000;
			}
		}
	}
	
	const int N = SZ(s);
	dp[0][1][id4][0]=0;
	dp[1][1][id4][0]=0;
	for (int m = 0; m < 2; m++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int forward = 0; forward < 2; forward++)
			{
				for (int now_commands = 0; now_commands <= id4; now_commands++)
				{
					for (int use_commands = 0; use_commands <= now_commands; use_commands++)
					{
						char now = s[x];

						if( use_commands%2==1 )
						{
							if(now=='F')
							{
								now='T';
							}
							else
							{
								now='F';
							}
						}

						const int id0 = now_commands-use_commands;
						if(now=='F')
						{
							int move = 1;
							if(forward==0)
							{
								move = -1;
							}
							dp[0][forward][id0][x+1] = max(dp[0][forward][id0][x+1],dp[0][forward][now_commands][x]+move);
							dp[1][forward][id0][x+1] = min(dp[1][forward][id0][x+1],dp[1][forward][now_commands][x]+move);
						}
						else
						{
							dp[0][1-forward][id0][x+1] = max(dp[0][1-forward][id0][x+1],dp[0][forward][now_commands][x]);
							dp[1][1-forward][id0][x+1] = min(dp[1][1-forward][id0][x+1],dp[1][forward][now_commands][x]);
						}
					}
				}
			}
		}
	}

	int resultmax = max(dp[0][0][0][N],dp[0][1][0][N]);
	int resultmin = max(-dp[1][0][0][N],-dp[1][1][0][N]);
	int result = max(resultmax,resultmin);
	cout << result << endl;
}



int reverse(int a)
{
	int rev = 0;
	for (int k = 0; k < 8; k++)
	{
		if(a & (1<<k))
		{
			rev |= (1<<(7-k));
		}
	}
	return rev;
}

int main()
{
	char str[256];
	gets(str);
	string s(str);
	cin >> s;

	int value = 0;
	for (int i = 0; i < SZ(s); i++)
	{
		int value = 0;
		if(i!=0) value = s[i-1];
		int ret = ( reverse(value) - reverse(s[i]) + 256) % 256;
		printf("%d\n",ret);
		value = ret;
	}

}


int main()
{
	string s;
	cin >> s;

	ll result = 0;
	const ll MOD = 1000003;
	for (int i = 0; i < SZ(s); i++)
	{
		result *= 16;
		result %= MOD;

		ll value = 0;
		switch(s[i])
		{
		case '>': value=8; break;
		case '<': value=9; break;
		case '+': value=10; break;
		case '-': value=11; break;
		case '.': value=12; break;
		case ',': value=13; break;
		case '[': value=14; break;
		case ']': value=15; break;
		}
		result = result + value;
		result %= MOD;
	}


	cout << result << endl;


}


int main()
{
	char str[256];
	gets(str);
	string s(str);
	bool ok = false;
	for (int i = 0; i < SZ(s); i++)
	{
		if(s[i]=='H' || s[i]=='Q' ||s[i]=='9')
		{
			ok = true;
		}
	}
	if(ok)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}


int main()
{
	int N,M;
	scanf("%d %d ",&N,&M);

	map < int, vector < pair<int, int> > > vr[4];
	vector <int> dirnum(M);

	for (int i = 0; i < M; i++)
	{
		int r,c;
		scanf("%d %d ",&r,&c);
		r--;
		c--;

		vr[0][r].push_back(make_pair(c,i));
		vr[1][c].push_back(make_pair(r,i));
		vr[2][r+c].push_back(make_pair(r-c,i));
		vr[3][r-c].push_back(make_pair(r+c,i));
	}

	for(int d = 0; d < 4; d++)
	{
		for(map < int, vector < pair<int, int> > >::iterator it=vr[d].begin();it!=vr[d].end();it++)
		{
			vector < pair<int, int> >& vp = it->second;
			sort(vp.begin(),vp.end());


			if(SZ(vp)>=2)
			{
				for (int i = 0; i < SZ(vp); i++)
				{
					if(i==0 || i==SZ(vp)-1)
					{
						dirnum[vp[i].second] += 1;
					}
					else
					{
						dirnum[vp[i].second] += 2;
					}
				}
			}
		}
	}

	vector <int> sum(9);
	for (int i = 0; i < M; i++)
	{
		sum[dirnum[i]]++;
	}

	for (int i = 0; i < SZ(sum); i++)
	{
		printf("%d ",sum[i]);
	}
	printf("\n");
}


vector < vector < int > > mAdj;
vector < bool > mVisited;
vector < bool > id5;
vector < bool > id3;
bool mFound;

void id2(int now, int prev)
{
	if(id5[now]==true)
	{
		return;
	}

	if(mFound)
	{
		return;
	}

	if(mVisited[now]==true)
	{
		mFound = true;
		id3 = mVisited;
		return;
	}

	mVisited[now]=true;

	for (int k = 0; k < SZ(mAdj[now]); k++)
	{
		if(mFound)
		{
			break;
		}
		if(mAdj[now][k]!=prev)
		{
			id2(mAdj[now][k],now);
		}
	}

	mVisited[now]=false;
	id5[now]=true;
}

int main()
{
	int N;
	scanf("%d",&N);
	
	mAdj.clear();
	mAdj.resize(N);

	for (int i = 0; i < N; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		mAdj[a].push_back(b);
		mAdj[b].push_back(a);

	}


	vector < bool > id1;
	int best = BIG;

	for (int i = 0; i < N; i++)
	{
		mVisited.clear();
		mVisited.resize(N);
		id5.clear();
		id5.resize(N);
		mFound = false;

		id2(i,-1);

		int count = 0;
		for (int k = 0; k < SZ(id3); k++)
		{
			if(id3[k]==true) count++;
		}
		if(best>count)
		{
			count = best;
			id1 = id3;
		}


	}

	queue < pair <int, int> > q;
	vector <int> dist(N,BIG);
	{
		for (int k = 0; k < SZ(id1); k++)
		{
			if(id1[k])
			{
				q.push(make_pair(k,0));
				dist[k]=0;
			}
		}
	}

	while (!q.empty())
	{
		const pair <int, int> now = q.front();
		q.pop();

		dist[now.first]=min(dist[now.first],now.second);

		for (int k = 0; k < SZ(mAdj[now.first]); k++)
		{
			int next = mAdj[now.first][k];
			if(dist[next]==BIG)
			{
				q.push(make_pair(next,now.second+1));
			}
		}
	}

	for (int k = 0; k < N; k++)
	{
		printf("%d ",dist[k]);
	}
	printf("\n");

	return 0;









}





int main()
{
	int N;
	scanf("%d",&N);
	ll a[21]={};
	for (int i = 0; i < N; i++)
	{
		int z;
		scanf("%d",&z);
		a[z+10]++;
	}

	ll ret = 0;
	for (int i = 0; i <= 10; i++)
	{
		if(i==10)
		{
			ret += a[i]*(a[i]-1LL)/2LL;
		}
		else
		{
			ret += a[i]*a[20-i];
		}

	}

	cout << ret << endl;
}





ll comb(ll n, ll r)
{
	if(r>n)
	{
		return 0;
	}

	ll ret=1LL;
	if(r>n/2)
	{
		r = n-r;
	}

	for(ll i=0;i<r;i++)
	{
		ret *= (n-i);
		ret /= (i+1);
	}
	return ret;
}

int main()
{
	int N,M,T;
	cin >> N >> M >> T;

	ll ret = 0;
	for (int n = 4; n <= N; n++)
	{
		if(M>=T-n && T-n>=1)
		{
			ret += comb(N,n)*comb(M,T-n);
		}
	}

	cout << ret << endl;
}



int main()
{
	char str[256];
	scanf("%s ",str);
	string s(str);

	bool change = true;

	for (int n = 1; n < SZ(s); n++)
	{
		if(INRANGE(s[n],'a','z'))
		{
			change = false;
		}
	}

	if(SZ(s)==1) change = true;


	if(change)
	{
		for (int n = 0; n < SZ(s); n++)
		{
			if( INRANGE(s[n],'a','z') )
			{
				s[n] = s[n]-'a'+'A';
			}
			else if (INRANGE(s[n],'A','Z'))
			{
				s[n] = s[n]-'A'+'a';
			}
		}
	}
	printf("%s\n",s.c_str());
}


