#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1030, MAXM = 15e4 + 20, MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1e9;
long long a[4][MAXN][MAXN];
long long d[4][MAXN][MAXN];
char c[MAXN][MAXN];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dx1[] = {-1, 1};
int dx2[] = {0, 1, -1};
int dy2[] = {1, 0, 0};
int dx3[] = {0, 0, 1};
int dy3[] = {1, -1, 0};
int dx4[] = {0, 1, -1};
int dy4[] = {-1, 0, 0};
int dx5[] = {0, 0, -1};
int dy5[] = {1, -1, 0};

int n, m;

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void solve() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
			
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				d[k][i][j] = INF;
	}
	int xt, yt;
	cin >> xt >> yt;
	xt--, yt--;
	int x1, y1;
	cin >> x1 >> y1;
	x1--, y1--;
	
	d[0][xt][yt] = 0;
	queue <pair <int, pair <int, int> > > q;
	q.push(make_pair(0, make_pair(xt, yt)));
	
	while (q.size()) {
		int rot = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		bool down = 0, up = 0, r = 0, l = 0;
		if (rot == 0) {
			if ((c[x + 1][y] != 'U' && c[x + 1][y] != '*' && c[x + 1][y] != '>' && c[x + 1][y] != 'v' && c[x + 1][y] != '<' && c[x + 1][y] != '-'))
				down = 1;
			if (x) {
				if ((c[x - 1][y] != 'D' && c[x - 1][y] != '*' && c[x - 1][y] != '^' && c[x - 1][y] != '<' && c[x - 1][y] != '>' && c[x - 1][y] != '-'))
					up = 1;
			}
			if ((c[x][y + 1] != 'L' && c[x][y + 1] != '*' && c[x][y + 1] != 'v' && c[x][y + 1] != '^' && c[x][y + 1] != '>' && c[x][y + 1] != '|'))
				r = 1;
			if (y) {
				if ((c[x][y - 1] != 'R' && c[x][y - 1] != '*' && c[x][y - 1] != '<' && c[x][y - 1] != '^' && c[x][y - 1] != 'v' && c[x][y - 1] != '|'))
					l = 1;
			}
		}
		else if (rot == 1) {
			if ((c[x + 1][y] != 'L' && c[x + 1][y] != '*' && c[x + 1][y] != 'v' && c[x + 1][y] != '>' && c[x + 1][y] != '^'&& c[x + 1][y] != '|'))
				down = 1;
			if (x) {
				if ((c[x - 1][y] != 'R' && c[x - 1][y] != '*' && c[x - 1][y] != 'v' && c[x - 1][y] != '<' && c[x - 1][y] != '^' && c[x - 1][y] != '|'))
					up = 1;
			}
			if ((c[x][y + 1] != 'D' && c[x][y + 1] != '*' && c[x][y + 1] != '<' && c[x][y + 1] != '>' && c[x][y + 1] != '^' && c[x][y + 1] != '-'))
				r = 1;
			if (y) {
				if ((c[x][y - 1] != 'U' && c[x][y - 1] != '*' && c[x][y - 1] != 'v' && c[x][y - 1] != '<' && c[x][y - 1] != '>' && c[x][y - 1] != '-'))
					l = 1;
			}
		}
		else if (rot == 2) {
			if ((c[x + 1][y] != 'D' && c[x + 1][y] != '^' && c[x + 1][y] != '<' && c[x + 1][y] != '>' && c[x + 1][y] != '*' && c[x + 1][y] != '-'))
				down = 1;
			if (x) {
				if ((c[x - 1][y] != 'U' && c[x - 1][y] != '*' && c[x - 1][y] != 'v' && c[x - 1][y] != '>' && c[x - 1][y] != '<' && c[x - 1][y] != '-'))
					up = 1;
			}
			if ((c[x][y + 1] != 'R' && c[x][y + 1] != '*' && c[x][y + 1] != '^' && c[x][y + 1] != 'v' && c[x][y + 1] != '<' && c[x][y + 1] != '|'))
				r = 1;
			if (y) {
				if ((c[x][y - 1] != 'L' && c[x][y - 1] != '*' && c[x][y - 1] != '^' && c[x][y - 1] != 'v' && c[x][y - 1] != '>' && c[x][y - 1] != '|'))
					l = 1;
			}
		}
		else if (rot == 3) {
			if ((c[x + 1][y] != 'R' && c[x + 1][y] != '*' && c[x + 1][y] != '^' && c[x + 1][y] != 'v' && c[x + 1][y] != '<' && c[x + 1][y] != '|'))
				down = 1;
			if (x) {
				if ((c[x - 1][y] != 'L' && c[x - 1][y] != '*' && c[x - 1][y] != '^' && c[x - 1][y] != 'v' && c[x - 1][y] != '>' && c[x - 1][y] != '|'))
					up = 1;
			}
			if ((c[x][y + 1] != 'U' && c[x][y + 1] != '*' && c[x][y + 1] != '<' && c[x][y + 1] != '>' && c[x][y + 1] != 'v' && c[x][y + 1] != '-'))
				r = 1;
			if (y) {
				if ((c[x][y - 1] != 'D' && c[x][y - 1] != '*' && c[x][y - 1] != '^' && c[x][y - 1] != '<' && c[x][y - 1] != '>' && c[x][y - 1] != '-'))
					l = 1;
			}
		}
		
		

		if (d[rot][x][y] + 1 < d[(rot + 1) % 4][x][y]) {
			d[(rot + 1) % 4][x][y] = d[rot][x][y] + 1;
			q.push(make_pair((rot + 1) % 4, make_pair(x, y)));
		}
		
		if (c[x][y] == '*')
			continue;
		
		if (c[x][y] == '+') {
			for (int i = 0; i < 4; i++) {
				int x_ = x + dx[i];
				int y_ = y + dy[i];
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
					if (x_ == (x + 1) && y_ == y) {
						if (down) {
							d[rot][x_][y_] = d[rot][x][y] + 1;
							q.push(make_pair(rot, make_pair(x_, y_)));	
						}
					}	
					else if (x_ == (x - 1) && y_ == y) {
						if (up) {
							d[rot][x_][y_] = d[rot][x][y] + 1;
							q.push(make_pair(rot, make_pair(x_, y_)));
						}
					}
					else if (x_ == x && y_ == (y + 1)) {
						if (r) {
							d[rot][x_][y_] = d[rot][x][y] + 1;
							q.push(make_pair(rot, make_pair(x_, y_)));
						}
					}
					else if (x_ == x && y_ == (y - 1)) {
						if (l) {
							d[rot][x_][y_] = d[rot][x][y] + 1;
							q.push(make_pair(rot, make_pair(x_, y_)));
						}
					}
				}
			}
		}
		else if (c[x][y] == '-') {
			if (rot % 2 == 0) {
				for (int i = 0; i < 2; i++) {
					int x_ = x;
					int y_ = y + dx1[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}	
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					int x_ = x + dx1[i];
					int y_ = y;
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}	
				}
			}
		}
		else if (c[x][y] == '|') {
			if (rot % 2 == 1) {
				for (int i = 0; i < 2; i++) {
					int x_ = x;
					int y_ = y + dx1[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}	
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					int x_ = x + dx1[i];
					int y_ = y;
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}	
				}
			}
		}
		else if (c[x][y] == '^') {
			if (rot == 0) {
				int x_ = x - 1;
				int y_ = y;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				} 
			}
			else if (rot == 1) {
				int x_ = x;
				int y_ = y + 1;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else if (rot == 2) {
				int x_ = x + 1;
				int y_ = y;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else {
				int x_ = x;
				int y_ = y - 1;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
		}
		else if (c[x][y] == '>') {
			if (rot == 0) {
				int x_ = x;
				int y_ = y + 1;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else if (rot == 1) {
				int x_ = x + 1;
				int y_ = y;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else if (rot == 2) {
				int x_ = x;
				int y_ = y - 1;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else {
				int x_ = x - 1;
				int y_ = y;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				} 
			}
		}
		else if (c[x][y] == 'v') {
			if (rot == 0) {
				int x_ = x + 1;
				int y_ = y;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else if (rot == 1) {
				int x_ = x;
				int y_ = y - 1;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else if (rot == 2) {
				int x_ = x - 1;
				int y_ = y;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				} 
			}
			else {
				int x_ = x;
				int y_ = y + 1;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
		}
		else if (c[x][y] == '<') {
			if (rot == 0) {
				int x_ = x;
				int y_ = y - 1;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else if (rot == 1) {
				int x_ = x - 1;
				int y_ = y;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				} 
			}
			else if (rot == 2) {
				int x_ = x;
				int y_ = y + 1;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
			else {
				int x_ = x + 1;
				int y_ = y;
				
				if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
				}
			}
		}
		else if (c[x][y] == 'L') {
			if (rot == 0) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx2[i];
					int y_ = y + dy2[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else if (rot == 1) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx3[i];
					int y_ = y + dy3[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else if (rot == 2) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx4[i];
					int y_ = y + dy4[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx5[i];
					int y_ = y + dy5[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
		}
		else if (c[x][y] == 'U') {
			if (rot == 0) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx3[i];
					int y_ = y + dy3[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else if (rot == 1) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx4[i];
					int y_ = y + dy4[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else if (rot == 2) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx5[i];
					int y_ = y + dy5[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx2[i];
					int y_ = y + dy2[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
		}
		else if (c[x][y] == 'R') {
			if (rot == 0) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx4[i];
					int y_ = y + dy4[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else if (rot == 1) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx5[i];
					int y_ = y + dy5[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else if (rot == 2) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx2[i];
					int y_ = y + dy2[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx3[i];
					int y_ = y + dy3[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
		}
		else if (c[x][y] == 'D') {
			if (rot == 0) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx5[i];
					int y_ = y + dy5[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else if (rot == 1) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx2[i];
					int y_ = y + dy2[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else if (rot == 2) {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx3[i];
					int y_ = y + dy3[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					int x_ = x + dx4[i];
					int y_ = y + dy4[i];
				
					if (ok(x_, y_) && d[rot][x][y] + 1 < d[rot][x_][y_] && c[x_][y_] != '*') {
						if (x_ == (x + 1) && y_ == y) {
							if (down) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));	
							}
						}	
						else if (x_ == (x - 1) && y_ == y) {
							if (up) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y + 1)) {
							if (r) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
						else if (x_ == x && y_ == (y - 1)) {
							if (l) {
								d[rot][x_][y_] = d[rot][x][y] + 1;
								q.push(make_pair(rot, make_pair(x_, y_)));
							}
						}
					}
				}
			}
		}
	}
	long long mn = INF;
	for (int i = 0; i < 4; i++) {
		mn = min(mn, d[i][x1][y1]);
	}
	
















	
	if (mn >= INF)
		cout << -1 << endl;
	else
		cout << mn << endl;
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
