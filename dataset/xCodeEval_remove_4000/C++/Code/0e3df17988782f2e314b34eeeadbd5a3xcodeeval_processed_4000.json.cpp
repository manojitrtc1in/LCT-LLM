










using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef set<pii> :: iterator itr;
const int inf = ~0U >> 1;
const ll INF = ~0ULL >> 1;



const int maxn = 120000;

int x2[maxn], y2[maxn], nxtid[maxn];
int Dir[maxn];
int M, N;
int f[maxn][52];
ll g[maxn][52];
set<pii> S[4][maxn];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

inline int inside(int x, int y)
{
	return x > 0 && y > 0 && x <= N && y <= N;
}

struct Segment_Tree
{

	struct node
	{
		int l, r;
		set<pii> s;
	} t[maxn * 5];
	
	void build(int p, int l, int r)
	{
		t[p].l = l; t[p].r = r;
		if (l != r)
		{
			build(p << 1, l, l + r >> 1);
			build(p << 1 | 1, (l + r >> 1) + 1, r);
		}
	}
	
	pii query(int p, int target, int now, int Dir)
	{
		pii ret;
		if (Dir == 0 || Dir == 2)
		{
			ret = mp(inf, -1);
			itr it = t[p].s.lower_bound(mp(now, 0));
			if (it != t[p].s.end()) ret = min(ret, *it);
		}
		else 
		{
			ret = mp(-inf, -1);
			itr it = t[p].s.upper_bound(mp(now, inf)); 
			if (it != t[p].s.begin())
			{
				--it;
				ret = max(ret, *it);
			}
		}
		if (t[p].l == t[p].r) return ret;
		int m = t[p].l + t[p].r >> 1;
		if (target <= m)
		{
			pii tmp = query(p << 1, target, now, Dir);
			if (Dir == 0 || Dir == 2) return min(tmp, ret);
			else return max(tmp, ret);
		}
		else
		{
			pii tmp = query(p << 1 | 1, target, now, Dir);
			if (Dir == 0 || Dir == 2) return min(tmp, ret);
			else return max(tmp, ret);
		}
	}
	
	void modify(int p, int l, int r, int x, int y)
	{
		if (t[p].l == l && t[p].r == r)
		{
			t[p].s.insert(mp(x, y));
			return;
		}
		int m = t[p].l + t[p].r >> 1;
		if (r <= m) modify(p << 1, l, r, x, y);
		else if (l > m) modify(p << 1 | 1, l, r, x, y);
		else modify(p << 1, l, m, x, y), modify(p << 1 | 1, m + 1, r, x, y);
	}

} T[2];

pii walk(int cur, ll maxt)
{
	drep(i, 50, 0)
		if (f[cur][i] && maxt >= g[cur][i]) 
		{
			maxt -= g[cur][i];
			cur = f[cur][i];
		}
	int curx = x2[cur], cury = y2[cur];
	if (Dir[cur] == 0)
	{
		pii tmp = T[1].query(1, x2[cur], y2[cur], Dir[cur]);
		itr it = S[1][curx].lower_bound(mp(cury, 0));
		if (it != S[1][curx].end() && max(y2[it->yy], cury) < tmp.xx)
		{
			ll step = max(y2[it->yy], cury) - cury;
			if (step >= maxt)
				return mp(int(curx + dx[Dir[cur]] * maxt), int(cury + dy[Dir[cur]] * maxt));
			cury += step;
			maxt -= step;
			step = cury - y2[it->yy];
			if (step >= maxt)
				return mp(int(curx + dx[Dir[it->yy]] * maxt), int(cury + dy[Dir[it->yy]] * maxt));											
		}
		if (tmp.yy == -1) 
		{
			if (maxt <= N - y2[cur]) return mp(x2[cur], y2[cur] + maxt);
			else return mp(x2[cur], N);
		}
		else
		{
			if (maxt <= tmp.xx - y2[cur]) return mp(x2[cur], y2[cur] + maxt);
			maxt -= (tmp.xx - y2[cur]);
			return mp(x2[cur] + dx[Dir[tmp.yy]] * maxt, tmp.xx + dy[Dir[tmp.yy]] * maxt);
		}
	}
	else if (Dir[cur] == 1)
	{
		pii tmp = T[1].query(1, x2[cur], y2[cur], Dir[cur]);
			itr it = S[0][curx].upper_bound(mp(cury, inf));
			if (it != S[0][curx].begin() && min(y2[(--it)->yy], cury) > tmp.xx)
			{
				

				ll step = cury - min(y2[it->yy], cury);
				if (step >= maxt)
					return mp(int(curx + dx[Dir[cur]] * maxt), int(cury + dy[Dir[cur]] * maxt));
				cury -= step;
				maxt -= step;
				step = y2[it->yy] - cury;
				if (step >= maxt)
					return mp(int(curx + dx[Dir[it->yy]] * maxt), int(cury + dy[Dir[it->yy]] * maxt));											
			}				
		if (tmp.yy == -1) 
		{
			if (maxt <= y2[cur]) return mp(x2[cur], y2[cur] - maxt);
			else return mp(x2[cur], 0);
		}
		else
		{
			if (maxt <= y2[cur] - tmp.xx) return mp(x2[cur], y2[cur] - maxt);
			maxt -= (y2[cur] - tmp.xx);
			return mp(x2[cur] + dx[Dir[tmp.yy]] * maxt, tmp.xx + dy[Dir[tmp.yy]] * maxt);
		}			
	}
	else if (Dir[cur] == 2)
	{
		pii tmp = T[0].query(1, y2[cur], x2[cur], Dir[cur]);
			itr it = S[3][cury].lower_bound(mp(curx, 0));	
			if (it != S[3][cury].end() && max(x2[it->yy], curx) < tmp.xx)
			{
				ll step = abs(curx - max(curx, x2[it->yy]));
				if (step >= maxt) 
					return mp(int(curx + dx[Dir[cur]] * maxt), int(cury + dy[Dir[cur]] * maxt));
				curx += step;
				maxt -= step;
				step = abs(x2[it->yy] - curx);
				if (step >= maxt)
					return mp(int(curx + dx[Dir[it->yy]] * maxt), int(cury + dy[Dir[it->yy]] * maxt));												
			}				
		if (tmp.yy == -1) 
		{
			if (maxt <= N - x2[cur]) return mp(x2[cur] + maxt, y2[cur]);
			else return mp(N, y2[cur]);
		}
		else
		{
			if (maxt <= tmp.xx - x2[cur]) return mp(x2[cur] + maxt, y2[cur]);
			maxt -= (tmp.xx - x2[cur]);
			return mp(tmp.xx + dx[Dir[tmp.yy]] * maxt, y2[cur] + dy[Dir[tmp.yy]] * maxt);
		}
	}
	else
	{
		pii tmp = T[0].query(1, y2[cur], x2[cur], Dir[cur]);
			itr it = S[2][cury].upper_bound(mp(curx, inf));
			if (it != S[2][cury].begin() && min(x2[(--it)->yy], curx) > tmp.xx)
			{
				

				ll step = abs(curx - min(x2[it->yy], curx));
				if (step >= maxt)
					return mp(int(curx + dx[Dir[cur]] * maxt), int(cury + dy[Dir[cur]] * maxt));
				curx -= step;
				maxt -= step;
				step = abs(x2[it->yy] - curx);
				if (step >= maxt)
					return mp(int(curx + dx[Dir[it->yy]] * maxt), int(cury + dy[Dir[it->yy]] * maxt));
			}
		if (tmp.yy == -1) 
		{
			if (maxt <= x2[cur]) return mp(x2[cur] - maxt, y2[cur]);
			else return mp(0, y2[cur]);
		}
		else
		{
			if (maxt <= x2[cur] - tmp.xx) return mp(x2[cur] - maxt, y2[cur]);
			maxt -= (x2[cur] - tmp.xx);
			return mp(tmp.xx + dx[Dir[tmp.yy]] * maxt, y2[cur] + dy[Dir[tmp.yy]] * maxt);
		}
	}
}

int main()
{

	freopen("in", "r", stdin);

	
	scanf("%d%d", &M, &N);
	T[0].build(1, 0, N);
	T[1].build(1, 0, N);
	rep(i, 1, M)
	{
		int x1, y1;
		scanf("%d%d%d%d", &x1, &y1, &x2[i], &y2[i]);
		if (x1 == x2[i])
		{
			if (y1 < y2[i]) 

			{
				T[0].modify(1, y1, y2[i], x1, i);
				Dir[i] = 0;
				S[0][x1].insert(mp(y1, i));
			}
			else 

			{
				T[0].modify(1, y2[i], y1, x2[i], i);
				Dir[i] = 1;
				S[1][x1].insert(mp(y1, i));
			}
		}
		else if (x1 < x2[i]) 

		{
			T[1].modify(1, x1, x2[i], y1, i);
			Dir[i] = 2;
			S[2][y1].insert(mp(x1, i));
		}
		else 

		{
			T[1].modify(1, x2[i], x1, y1, i);
			Dir[i] = 3;
			S[3][y1].insert(mp(x1, i));
		}
	}
	rep(i, 1, M) 
	{
		int curx = x2[i], cury = y2[i];
		if (Dir[i] == 0)
		{
			pii tmp = T[1].query(1, x2[i], y2[i], Dir[i]);
			itr it = S[1][curx].lower_bound(mp(cury, 0));
			if (it != S[1][curx].end() && max(y2[it->yy], cury) < tmp.xx)
			{
				ll step = max(y2[it->yy], cury) - cury;
				g[i][0] += step;
				cury += step;
				step = cury - y2[it->yy];
				curx += dx[Dir[it->yy]] * step; 
				cury += dy[Dir[it->yy]] * step;
				g[i][0] += step;
				f[i][0] = it->yy;
				continue;												
			}
			if (tmp.yy == -1) f[i][0] = 0, g[i][0] = N - y2[i];
			else
			{
				f[i][0] = tmp.yy;
				g[i][0] = tmp.xx - y2[i] + abs(x2[tmp.yy] - x2[i]);
			}
		}
		else if (Dir[i] == 1)
		{
			pii tmp = T[1].query(1, x2[i], y2[i], Dir[i]);
			itr it = S[0][curx].upper_bound(mp(cury, inf));
			if (it != S[0][curx].begin() && min(y2[(--it)->yy], cury) > tmp.xx)
			{
				

				ll step = cury - min(y2[it->yy], cury);
				g[i][0] += step;
				cury -= step;
				step = y2[it->yy] - cury;
				g[i][0] += step;
				curx += dx[Dir[it->yy]] * step; 
				cury += dy[Dir[it->yy]] * step;
				f[i][0] = it->yy;
				continue;												
			}						
			if (tmp.yy == -1) f[i][0] = 0, g[i][0] = y2[i];
			else
			{
				f[i][0] = tmp.yy;
				g[i][0] = y2[i] - tmp.xx + abs(x2[tmp.yy] - x2[i]);
			}			
		}
		else if (Dir[i] == 2)
		{
			pii tmp = T[0].query(1, y2[i], x2[i], Dir[i]);
			itr it = S[3][cury].lower_bound(mp(curx, 0));
			if (it != S[3][cury].end() && max(x2[it->yy], curx) < tmp.xx)
			{
				ll step = abs(curx - max(curx, x2[it->yy]));
				g[i][0] += step;
				curx += step;
				step = abs(x2[it->yy] - curx);
				g[i][0] += step;
				curx += dx[Dir[it->yy]] * step; 
				cury += dy[Dir[it->yy]] * step;
				f[i][0] = it->yy;
				continue;												
			}									
			if (tmp.yy == -1) f[i][0] = 0, g[i][0] = N - x2[i];
			else
			{
				f[i][0] = tmp.yy;
				g[i][0] = tmp.xx - x2[i] + abs(y2[tmp.yy] - y2[i]);
			}
		}
		else
		{
			pii tmp = T[0].query(1, y2[i], x2[i], Dir[i]);
			itr it = S[2][cury].upper_bound(mp(curx, inf));
			if (it != S[2][cury].begin() && min(x2[(--it)->yy], curx) > tmp.xx)
			{
				

				ll step = abs(curx - min(x2[it->yy], curx));
				g[i][0] += step;
				curx -= step;
				step = abs(x2[it->yy] - curx);
				g[i][0] += step;
				curx += dx[Dir[it->yy]] * step; 
				cury += dy[Dir[it->yy]] * step;
				f[i][0] = it->yy;					
				continue;							
			}									
			if (tmp.yy == -1) f[i][0] = 0, g[i][0] = x2[i];
			else
			{
				f[i][0] = tmp.yy;
				g[i][0] = x2[i] - tmp.xx + abs(y2[tmp.yy] - y2[i]);
			}
		}
	}
	rep(j, 1, 50) rep(i, 1, M) 
	{
		if (g[i][j - 1] < INF && g[f[i][j - 1]][j - 1] < INF) 
			g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
		else g[i][j] = INF;
		if (g[i][j] > (ll)1e16) g[i][j] = INF;
		f[i][j] = f[f[i][j - 1]][j - 1];
	}
	int Q;
	scanf("%d", &Q);
	rep(_, 1, Q)
	{
		char is[5];
		int curx, cury, dir;
		ll maxt;
		scanf("%d%d%s%lld", &curx, &cury, is, &maxt);
		
		
		
		if (is[0] == 'U') dir = 0;
		else if (is[0] == 'D') dir = 1;
		else if (is[0] == 'R') dir = 2;
		else dir = 3;
		if (dir == 0)
		{
			pii tmp = T[1].query(1, curx, cury, dir);
			itr it = S[1][curx].lower_bound(mp(cury, 0));
			if (it != S[1][curx].end() && max(y2[it->yy], cury) < tmp.xx)
			{
				ll step = max(y2[it->yy], cury) - cury;
				if (step >= maxt)
				{
					printf("%d %d\n", int(curx + dx[dir] * maxt), int(cury + dy[dir] * maxt));
					continue;
				}
				cury += step;
				maxt -= step;
				step = cury - y2[it->yy];
				if (step >= maxt)
				{
					printf("%d %d\n", int(curx + dx[Dir[it->yy]] * maxt), int(cury + dy[Dir[it->yy]] * maxt));
					continue;
				}
				curx += dx[Dir[it->yy]] * step; 
				cury += dy[Dir[it->yy]] * step;
				maxt -= step;
				pii ans = walk(it->yy, maxt);
				printf("%d %d\n", int(ans.xx), int(ans.yy));
				continue;												
			}
			if (tmp.yy == -1)
			{
				ll step = min((ll)N - cury, maxt);
				printf("%d %d\n", int(curx + dx[dir] * step), int(cury + dy[dir] * step));				
				continue;
			}
			ll step = tmp.xx - cury;
			if (step >= maxt)
			{
				printf("%d %d\n", int(curx + dx[dir] * maxt), int(cury + dy[dir] * maxt));
				continue;
			}
			curx += dx[dir] * step; 
			cury += dy[dir] * step;
			maxt -= step;
			step = abs(x2[tmp.yy] - curx) + abs(y2[tmp.yy] - cury);
			if (step >= maxt)
			{
				printf("%d %d\n", int(curx + dx[Dir[tmp.yy]] * maxt), int(cury + dy[Dir[tmp.yy]] * maxt));
				continue;
			}
			curx += dx[Dir[tmp.yy]] * step; 
			cury += dy[Dir[tmp.yy]] * step;
			maxt -= step;
			pii ans = walk(tmp.yy, maxt);
			printf("%d %d\n", int(ans.xx), int(ans.yy));
		}
		else if (dir == 1)
		{
			pii tmp = T[1].query(1, curx, cury, dir);
			itr it = S[0][curx].upper_bound(mp(cury, inf));
			if (it != S[0][curx].begin() && min(y2[(--it)->yy], cury) > tmp.xx)
			{
				

				ll step = cury - min(y2[it->yy], cury);
				if (step >= maxt)
				{
					printf("%d %d\n", int(curx + dx[dir] * maxt), int(cury + dy[dir] * maxt));
					continue;
				}
				cury -= step;
				maxt -= step;
				step = y2[it->yy] - cury;
				if (step >= maxt)
				{
					printf("%d %d\n", int(curx + dx[Dir[it->yy]] * maxt), int(cury + dy[Dir[it->yy]] * maxt));
					continue;
				}
				curx += dx[Dir[it->yy]] * step; 
				cury += dy[Dir[it->yy]] * step;
				maxt -= step;
				pii ans = walk(it->yy, maxt);
				printf("%d %d\n", int(ans.xx), int(ans.yy));
				continue;												
			}			
			if (tmp.yy == -1)
			{
				ll step = min((ll)cury, maxt);
				printf("%d %d\n", int(curx + dx[dir] * step), int(cury + dy[dir] * step));				
				continue;
			}				
			ll step = cury - tmp.xx;
			if (step >= maxt)
			{
				printf("%d %d\n", int(curx + dx[dir] * maxt), int(cury + dy[dir] * maxt));
				continue;
			}
			curx += dx[dir] * step; 
			cury += dy[dir] * step;
			maxt -= step;
			step = abs(x2[tmp.yy] - curx) + abs(y2[tmp.yy] - cury);
			if (step >= maxt)
			{
				printf("%d %d\n", int(curx + dx[Dir[tmp.yy]] * maxt), int(cury + dy[Dir[tmp.yy]] * maxt));
				continue;
			}
			curx += dx[Dir[tmp.yy]] * step; 
			cury += dy[Dir[tmp.yy]] * step;
			maxt -= step;
			pii ans = walk(tmp.yy, maxt);
			printf("%d %d\n", int(ans.xx), int(ans.yy));
		}
		else if (dir == 2)
		{
			pii tmp = T[0].query(1, cury, curx, dir);
			itr it = S[3][cury].lower_bound(mp(curx, 0));
			if (it != S[3][cury].end() && max(x2[it->yy], curx) < tmp.xx)
			{
				ll step = abs(curx - max(curx, x2[it->yy]));
				if (step >= maxt)
				{
					printf("%d %d\n", int(curx + dx[dir] * maxt), int(cury + dy[dir] * maxt));
					continue;
				}
				curx += step;
				maxt -= step;
				step = abs(x2[it->yy] - curx);
				if (step >= maxt)
				{
					printf("%d %d\n", int(curx + dx[Dir[it->yy]] * maxt), int(cury + dy[Dir[it->yy]] * maxt));
					continue;
				}
				curx += dx[Dir[it->yy]] * step; 
				cury += dy[Dir[it->yy]] * step;
				maxt -= step;
				pii ans = walk(it->yy, maxt);
				printf("%d %d\n", int(ans.xx), int(ans.yy));
				continue;												
			}						
			if (tmp.yy == -1)
			{
				ll step = min((ll)N - curx, maxt);
				printf("%d %d\n", int(curx + dx[dir] * step), int(cury + dy[dir] * step));				
				continue;
			}		
			ll step = tmp.xx - curx;
			if (step >= maxt)
			{
				printf("%d %d\n", int(curx + dx[dir] * maxt), int(cury + dy[dir] * maxt));
				continue;
			}
			curx += dx[dir] * step; 
			cury += dy[dir] * step;
			maxt -= step;
			step = abs(x2[tmp.yy] - curx) + abs(y2[tmp.yy] - cury);
			if (step >= maxt)
			{
				printf("%d %d\n", int(curx + dx[Dir[tmp.yy]] * maxt), int(cury + dy[Dir[tmp.yy]] * maxt));
				continue;
			}
			curx += dx[Dir[tmp.yy]] * step; 
			cury += dy[Dir[tmp.yy]] * step;
			maxt -= step;
			pii ans = walk(tmp.yy, maxt);
			printf("%d %d\n", int(ans.xx), int(ans.yy));
		}
		else
		{
			pii tmp = T[0].query(1, cury, curx, dir);
			itr it = S[2][cury].upper_bound(mp(curx, inf));
			if (it != S[2][cury].begin() && min(x2[(--it)->yy], curx) > tmp.xx)
			{
				

				ll step = abs(curx - min(x2[it->yy], curx));
				if (step >= maxt)
				{
					printf("%d %d\n", int(curx + dx[dir] * maxt), int(cury + dy[dir] * maxt));
					continue;
				}
				curx -= step;
				maxt -= step;
				step = abs(x2[it->yy] - curx);
				if (step >= maxt)
				{
					printf("%d %d\n", int(curx + dx[Dir[it->yy]] * maxt), int(cury + dy[Dir[it->yy]] * maxt));
					continue;
				}
				curx += dx[Dir[it->yy]] * step; 
				cury += dy[Dir[it->yy]] * step;
				maxt -= step;
				pii ans = walk(it->yy, maxt);
				printf("%d %d\n", int(ans.xx), int(ans.yy));
				continue;												
			}						
			
			if (tmp.yy == -1)
			{
				ll step = min((ll)curx, maxt);
				printf("%d %d\n", int(curx + dx[dir] * step), int(cury + dy[dir] * step));				
				continue;
			}			
			ll step = curx - tmp.xx;
			if (step >= maxt)
			{
				printf("%d %d\n", int(curx + dx[dir] * maxt), int(cury + dy[dir] * maxt));
				continue;
			}
			curx += dx[dir] * step; 
			cury += dy[dir] * step;
			maxt -= step;
			step = abs(x2[tmp.yy] - curx) + abs(y2[tmp.yy] - cury);
			if (step >= maxt)
			{
				printf("%d %d\n", int(curx + dx[Dir[tmp.yy]] * maxt), int(cury + dy[Dir[tmp.yy]] * maxt));
				continue;
			}
			curx += dx[Dir[tmp.yy]] * step; 
			cury += dy[Dir[tmp.yy]] * step;
			maxt -= step;
			pii ans = walk(tmp.yy, maxt);
			printf("%d %d\n", int(ans.xx), int(ans.yy));
		}
	}
    return 0;
}
