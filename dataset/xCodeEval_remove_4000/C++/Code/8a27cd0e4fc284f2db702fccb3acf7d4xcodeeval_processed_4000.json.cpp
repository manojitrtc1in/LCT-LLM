







const size_t ioSize = 1 << 21;
char iBuf[ioSize], *iS, *iE;
inline char getc()
{
	return iS == iE ? iE = iBuf + fread(iS = iBuf, 1, ioSize, stdin), iS == iE ? EOF : *iS++ : *iS++;
}
template <typename T>
void readi(T &x)
{
	char c;
	for (c = getc(); !isdigit(c); c = getc())
		;
	x = c ^ '0';
	for (c = getc(); isdigit(c); c = getc())
		(x *= 10) += c ^ '0';
}
void readc(char &c)
{
	while (c = getc(), !isupper(c))
		;
}

typedef long long ll;
const size_t maxN = 100005;

std::map<int, int> X1[maxN], X2[maxN], Y1[maxN], Y2[maxN];
int N, M, Q;
int X[maxN], Y[maxN], X_1[maxN], Y_1[maxN];
char Dir[maxN];
int to0[maxN];
std::vector<std::tuple<int, int, int>> rowLine[maxN], colLine[maxN];
int To[51][maxN], toX[51][maxN], toY[51][maxN];
ll Step[51][maxN];

int qX[maxN], qY[maxN];
char qDir[maxN];
ll qT[maxN];
int qto0[maxN];
std::vector<std::pair<int, int *>> points[4][maxN];

namespace segTree
{


int Cover[1 << 18 | 1];
inline void clear()
{
	Cover[1] = 0;
}
inline void cover(int i, int v)
{
	Cover[i] = v;
}
inline void pushdown(int i)
{
	if (~Cover[i])
	{
		cover(lc, Cover[i]);
		cover(rc, Cover[i]);
		Cover[i] = -1;
	}
}
void modify(int i, int l, int r, int tl, int tr, int v)
{
	if (l >= tl && r <= tr)
	{
		cover(i, v);
		return;
	}
	pushdown(i);
	int m = l + r >> 1;
	if (tl <= m)
		modify(lc, l, m, tl, tr, v);
	if (tr > m)
		modify(rc, m + 1, r, tl, tr, v);
}
int query(int i, int l, int r, int pos)
{
	if (l == r)
		return Cover[i];
	pushdown(i);
	int m = l + r >> 1;
	return pos <= m ? query(lc, l, m, pos) : query(rc, m + 1, r, pos);
}


} 


int main()
{
	readi(N), readi(M);
	for (int i = 1, x1, y1, x2, y2; i <= N; ++i)
	{
		readi(x1), readi(y1), readi(x2), readi(y2);
		X[i] = x1, Y[i] = y1;
		X_1[i] = std::min(x1, x2), Y_1[i] = std::min(y1, y2);
		if (y1 == y2)
		{
			Dir[i] = x1 < x2 ? 'R' : 'L';
			X1[y1].emplace(std::min(x1, x2), i);
			X2[y1].emplace(std::max(x1, x2), i);
			rowLine[y1].emplace_back(std::min(x1, x2), std::max(x1, x2), i);
			if (Dir[i] == 'L')
				points[0][x1].emplace_back(y1, to0 + i);
			else
				points[1][x1].emplace_back(y1, to0 + i);
		}
		else
		{
			Dir[i] = y1 < y2 ? 'U' : 'D';
			Y1[x1].emplace(std::min(y1, y2), i);
			Y2[x2].emplace(std::max(y1, y2), i);
			colLine[x1].emplace_back(std::min(y1, y2), std::max(y1, y2), i);
			if (Dir[i] == 'U')
				points[2][y1].emplace_back(x1, to0 + i);
			else
				points[3][y1].emplace_back(x1, to0 + i);
		}
	}

	readi(Q);
	for (int i = 1; i <= Q; ++i)
	{
		readi(qX[i]), readi(qY[i]), readc(qDir[i]), readi(qT[i]);
		auto it = X2[qY[i]].lower_bound(qX[i]);
		if (it != X2[qY[i]].end())
		{
			if (X_1[it->second] <= qX[i])
				qDir[i] = Dir[it->second];
		}
		it = Y2[qX[i]].lower_bound(qY[i]);
		if (it != Y2[qX[i]].end())
		{
			if (Y_1[it->second] <= qY[i])
				qDir[i] = Dir[it->second];
		}
		if (qDir[i] == 'L')
			points[0][qX[i]].emplace_back(qY[i], qto0 + i);
		else if (qDir[i] == 'R')
			points[1][qX[i]].emplace_back(qY[i], qto0 + i);
		else if (qDir[i] == 'U')
			points[2][qY[i]].emplace_back(qX[i], qto0 + i);
		else
			points[3][qY[i]].emplace_back(qX[i], qto0 + i);
	}

	for (int i = 0; i <= M; ++i)
	{
		for (auto x : points[0][i])
			*(x.second) = segTree::query(1, 0, M, x.first);
		for (auto x : colLine[i])
			segTree::modify(1, 0, M, std::get<0>(x), std::get<1>(x), std::get<2>(x));
	}

	segTree::clear();
	for (int i = M; ~i; --i)
	{
		for (auto x : points[1][i])
			*(x.second) = segTree::query(1, 0, M, x.first);
		for (auto x : colLine[i])
			segTree::modify(1, 0, M, std::get<0>(x), std::get<1>(x), std::get<2>(x));
	}

	segTree::clear();
	for (int i = 0; i <= M; ++i)
	{
		for (auto x : points[3][i])
			*(x.second) = segTree::query(1, 0, M, x.first);
		for (auto x : rowLine[i])
			segTree::modify(1, 0, M, std::get<0>(x), std::get<1>(x), std::get<2>(x));
	}

	segTree::clear();
	for (int i = M; ~i; --i)
	{
		for (auto x : points[2][i])
			*(x.second) = segTree::query(1, 0, M, x.first);
		for (auto x : rowLine[i])
			segTree::modify(1, 0, M, std::get<0>(x), std::get<1>(x), std::get<2>(x));
	}

	for (int i = 1; i <= N; ++i)
	{
		if (Dir[i] == 'L')
		{
			auto it = X2[Y[i]].lower_bound(X[i]);
			if (it != X2[Y[i]].begin())
			{
				--it;
				if (!to0[i] || it->first > X[to0[i]])
				{
					to0[i] = it->second;
					To[0][i] = it->second;
					toX[0][i] = it->first;
					toY[0][i] = Y[i];
					Step[0][i] = X[i] - toX[0][i];
				}
				else
				{
					To[0][i] = to0[i];
					toX[0][i] = X[to0[i]];
					toY[0][i] = Y[i];
					Step[0][i] = X[i] - toX[0][i];
				}
			}
			else
			{
				To[0][i] = to0[i];
				toX[0][i] = X[to0[i]];
				toY[0][i] = Y[i];
				Step[0][i] = X[i] - toX[0][i];
			}
		}
		else if (Dir[i] == 'R')
		{
			auto it = X1[Y[i]].upper_bound(X[i]);
			if (it != X1[Y[i]].end())
			{
				if (!to0[i] || it->first < X[to0[i]])
				{
					to0[i] = it->second;
					To[0][i] = it->second;
					toX[0][i] = it->first;
					toY[0][i] = Y[i];
					Step[0][i] = -X[i] + toX[0][i];
				}
				else
				{
					To[0][i] = to0[i];
					toX[0][i] = X[to0[i]];
					toY[0][i] = Y[i];
					Step[0][i] = -X[i] + toX[0][i];
				}
			}
			else
			{
				To[0][i] = to0[i];
				toX[0][i] = X[to0[i]];
				toY[0][i] = Y[i];
				Step[0][i] = -X[i] + toX[0][i];
			}
		}
		else if (Dir[i] == 'U')
		{
			auto it = Y1[X[i]].upper_bound(Y[i]);
			if (it != Y1[X[i]].end())
			{
				if (!to0[i] || it->first < Y[to0[i]])
				{
					to0[i] = it->second;
					To[0][i] = it->second;
					toX[0][i] = X[i];
					toY[0][i] = it->first;
					Step[0][i] = -Y[i] + toY[0][i];
				}
				else
				{
					To[0][i] = to0[i];
					toX[0][i] = X[i];
					toY[0][i] = Y[to0[i]];
					Step[0][i] = -Y[i] + toY[0][i];
				}
			}
			else
			{
				To[0][i] = to0[i];
				toX[0][i] = X[i];
				toY[0][i] = Y[to0[i]];
				Step[0][i] = -Y[i] + toY[0][i];
			}
		}
		else
		{
			auto it = Y2[X[i]].lower_bound(Y[i]);
			if (it != Y2[X[i]].begin())
			{
				--it;
				if (!to0[i] || it->first > Y[to0[i]])
				{
					to0[i] = it->second;
					To[0][i] = it->second;
					toX[0][i] = X[i];
					toY[0][i] = it->first;
					Step[0][i] = Y[i] - toY[0][i];
				}
				else
				{
					To[0][i] = to0[i];
					toX[0][i] = X[i];
					toY[0][i] = Y[to0[i]];
					Step[0][i] = Y[i] - toY[0][i];
				}
			}
			else
			{
				To[0][i] = to0[i];
				toX[0][i] = X[i];
				toY[0][i] = Y[to0[i]];
				Step[0][i] = Y[i] - toY[0][i];
			}
		}
	}

	for (int i = 1; i != 50; ++i)
		for (int j = 1; j <= N; ++j)
		{
			if (Step[i - 1][j] > (1LL << 50))
				continue;
			To[i][j] = To[i - 1][To[i - 1][j]];
			Step[i][j] = Step[i - 1][j] + Step[i - 1][To[i - 1][j]] - std::abs(toX[i - 1][j] - X[To[i - 1][j]] + toY[i - 1][j] - Y[To[i - 1][j]]);
			toX[i][j] = toX[i - 1][To[i - 1][j]];
			toY[i][j] = toY[i - 1][To[i - 1][j]];
		}

	for (int i = 1; i <= Q; ++i)
	{
		int curi, curx = qX[i], cury = qY[i];
		ll curT = qT[i];
		char curdir = qDir[i];
		int tox, toy, toi = qto0[i];
		if (curdir == 'L')
		{
			auto it = X2[cury].lower_bound(curx);
			if (it != X2[cury].begin())
			{
				--it;
				if (!toi || it->first > X[toi])
				{
					toi = it->second;
					tox = it->first;
					toy = cury;
				}
				else
				{
					tox = X[toi];
					toy = cury;
				}
			}
			else
			{
				if (!toi)
				{
					printf("%lld %d\n", std::max(0LL, curx - curT), cury);
					continue;
				}
				tox = X[toi];
				toy = cury;
			}
			if (curx - tox > curT)
			{
				printf("%lld %d\n", curx - curT, cury);
				continue;
			}
			curT -= curx - tox;
		}
		else if (curdir == 'R')
		{
			auto it = X1[cury].upper_bound(curx);
			if (it != X1[cury].end())
			{
				if (!toi || it->first < X[toi])
				{
					toi = it->second;
					tox = it->first;
					toy = cury;
				}
				else
				{
					tox = X[toi];
					toy = cury;
				}
			}
			else
			{
				if (!toi)
				{
					printf("%lld %d\n", std::min(static_cast<ll>(M), curx + curT), cury);
					continue;
				}
				tox = X[toi];
				toy = cury;
			}
			if (tox - curx > curT)
			{
				printf("%lld %d\n", curx + curT, cury);
				continue;
			}
			curT -= tox - curx;
		}
		else if (curdir == 'U')
		{
			auto it = Y1[curx].upper_bound(cury);
			if (it != Y1[curx].end())
			{
				if (!toi || it->first < Y[toi])
				{
					toi = it->second;
					tox = curx;
					toy = it->first;
				}
				else
				{
					tox = curx;
					toy = Y[toi];
				}
			}
			else
			{
				if (!toi)
				{
					printf("%d %lld\n", curx, std::min(static_cast<ll>(M), cury + curT));
					continue;
				}
				tox = curx;
				toy = Y[toi];
			}
			if (toy - cury > curT)
			{
				printf("%d %lld\n", curx, cury + curT);
				continue;
			}
			curT -= toy - cury;
		}
		else
		{
			auto it = Y2[curx].lower_bound(cury);
			if (it != Y2[curx].begin())
			{
				--it;
				if (!toi || it->first > Y[toi])
				{
					toi = it->second;
					tox = curx;
					toy = it->first;
				}
				else
				{
					tox = curx;
					toy = Y[toi];
				}
			}
			else
			{
				if (!toi)
				{
					printf("%d %lld\n", curx, std::max(0LL, cury - curT));
					continue;
				}
				tox = curx;
				toy = Y[toi];
			}
			if (cury - toy > curT)
			{
				printf("%d %lld\n", curx, cury - curT);
				continue;
			}
			curT -= cury - toy;
		}
		curi = toi, curx = tox, cury = toy;
		for (int d = 49; ~d; --d)
			if (To[d][curi] && Step[d][curi] - std::abs(curx - X[curi] + cury - Y[curi]) <= curT)
			{
				curT -= Step[d][curi] - std::abs(curx - X[curi] + cury - Y[curi]);
				curx = toX[d][curi], cury = toY[d][curi];
				curi = To[d][curi];
			}
		curdir = Dir[curi];
		if (curdir == 'L')
			printf("%lld %d\n", std::max(0LL, curx - curT), cury);
		else if (curdir == 'R')
			printf("%lld %d\n", std::min(static_cast<ll>(M), curx + curT), cury);
		else if (curdir == 'U')
			printf("%d %lld\n", curx, std::min(static_cast<ll>(M), cury + curT));
		else
			printf("%d %lld\n", curx, std::max(0LL, cury - curT));
	}

	return 0;
}