#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char maz[4][1010][1010];
bool maze[4][1001][1001];
int n, m;
struct Point{
	int x, y, maz, t;
};
void Init()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", maz[0][i] + 1);
	for(int i = 1; i < 4; i++){
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= m; k++){
				if(maz[i - 1][j][k] == '*'){
					maz[i][j][k] = '*';
					maze[0][j][k] = maze[1][j][k] = maze[2][j][k] = maze[3][j][k] = 1;
				}
				if(maz[i - 1][j][k] == '+')
					maz[i][j][k] = '+';
					
				if(maz[i - 1][j][k] == '-')
					maz[i][j][k] = '|';
				if(maz[i - 1][j][k] == '|')
					maz[i][j][k] = '-';
					
				if(maz[i - 1][j][k] == 'L')
					maz[i][j][k] = 'U';
				if(maz[i - 1][j][k] == 'U')
					maz[i][j][k] = 'R';
				if(maz[i - 1][j][k] == 'R')
					maz[i][j][k] = 'D';
				if(maz[i - 1][j][k] == 'D')
					maz[i][j][k] = 'L';
					
				if(maz[i - 1][j][k] == '^')
					maz[i][j][k] = '>';
				if(maz[i - 1][j][k] == '>')
					maz[i][j][k] = 'v';
				if(maz[i - 1][j][k] == 'v')
					maz[i][j][k] = '<';
				if(maz[i - 1][j][k] == '<')
					maz[i][j][k] = '^';
			}
	}

}
void Work()
{
	queue<Point> q;
	int x, y, xx, yy;
	scanf("%d%d", &x, &y);
	scanf("%d%d", &xx, &yy);
	q.push((Point){x, y, 0, 0});
	maze[0][x][y] = 1;
	ll ans = -1;
	while(!q.empty()){
		Point now = q.front();
		q.pop();
		if(now.x == xx && now.y == yy){
			ans = now.t;
			break;
		}
		if(now.t > 2000000)
			break;
		int ok = 0;
		for(int i = 0; i < 4; i++){
			int tx = now.x + dx[i];
			int ty = now.y + dy[i];
			if(tx <= 0 || ty <= 0 || tx > n || ty > m || maze[now.maz][tx][ty])
				ok++;
		}
		if(ok == 4)
			continue;
		if(!maze[(now.maz + 1) % 4][now.x][now.y]){
			q.push((Point){now.x, now.y, (now.maz + 1) % 4, now.t + 1});
			maze[(now.maz + 1) % 4][now.x][now.y] = 1;
		}
		if(maz[now.maz][now.x][now.y] == '+'){
			int tx = now.x;
			int ty = now.y;
			tx--;
			if(tx > 0 && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == 'v' || maz[now.maz][tx][ty] == '+'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			tx++;
			tx++;
			if(tx <= n && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '^'|| maz[now.maz][tx][ty] == '+'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			tx--;
			ty++;
			if(ty <= m && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '<' || maz[now.maz][tx][ty] == '+'
			|| maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			ty--;
			ty--;
			if(tx > 0 && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '>' || maz[now.maz][tx][ty] == '+'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
		}
		if(maz[now.maz][now.x][now.y] == '-'){
			int tx = now.x, ty = now.y;
			ty++;
			if(ty <= m && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '<'
			|| maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			ty -= 2;
			if(ty > 0 && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '>'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'D')&& !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
		}
		if(maz[now.maz][now.x][now.y] == '|'){
			int tx = now.x, ty = now.y;
			tx++;
			if(tx <= n && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '^'
			|| maz[now.maz][tx][ty] == 'L'|| maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			tx -= 2;
			if(tx > 0 &&(maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == 'v'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R')&& !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
		}
		
		if(maz[now.maz][now.x][now.y] == '^'){
			int tx = now.x, ty = now.y;
			tx--;
			if(tx > 0 &&(maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == 'v'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R')&& !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
			    maze[now.maz][tx][ty] = 1;
			}
		}
		if(maz[now.maz][now.x][now.y] == '>'){
			int tx = now.x, ty = now.y;
			ty++;
			if(tx <= n &&(maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '<'
			|| maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D')&& !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
			    maze[now.maz][tx][ty] = 1;
			}
		}
		if(maz[now.maz][now.x][now.y] == 'v'){
			int tx = now.x, ty = now.y;
			tx++;
			if(tx <= n &&(maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '^'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D')&& !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
			    maze[now.maz][tx][ty] = 1;
			}
		}
		if(maz[now.maz][now.x][now.y] == '<'){
			int tx = now.x, ty = now.y;
			ty--;
			if(ty > 0 &&(maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '>'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'D')&& !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
			    maze[now.maz][tx][ty] = 1;
			}
		}
		
		if(maz[now.maz][now.x][now.y] == 'L'){
			int tx = now.x, ty = now.y;
			tx++;
			if(tx <= n && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '^'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			tx -= 2;
			if(tx > 0 && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == 'v'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			tx++;
			ty++;
			if(ty <= m && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '<'
			|| maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
		}
		if(maz[now.maz][now.x][now.y] == 'R'){
			int tx = now.x, ty = now.y;
			tx++;
			if(tx <= n && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '^'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			tx -= 2;
			if(tx > 0 && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == 'v'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			tx++;
			ty--;
			if(ty > 0 && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '>'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
		}
		if(maz[now.maz][now.x][now.y] == 'U'){
			int tx = now.x, ty = now.y;
			ty--;
			if(ty > 0 &&  (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '>'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			ty += 2;
			if(ty <= m && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '<'
			|| maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			ty--;
			tx++;
			if(tx <= n && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '^'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
		}
		if(maz[now.maz][now.x][now.y] == 'D'){
			int tx = now.x, ty = now.y;
			ty--;
			if(ty > 0 && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '>'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			ty += 2;
			if(ty <= m && (maz[now.maz][tx][ty] == '-' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == '<'
			|| maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R'|| maz[now.maz][tx][ty] == 'D') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
			ty--;
			tx--;
			if(tx > 0 && (maz[now.maz][tx][ty] == '|' || maz[now.maz][tx][ty] == '+' || maz[now.maz][tx][ty] == 'v'
			|| maz[now.maz][tx][ty] == 'L' || maz[now.maz][tx][ty] == 'U' || maz[now.maz][tx][ty] == 'R') && !maze[now.maz][tx][ty]){
				q.push((Point){tx, ty, now.maz, now.t + 1});
				maze[now.maz][tx][ty] = 1;
			}
		}
	}
	printf("%I64d\n", ans);
}
int main()
{




	Init();
	Work();
	return 0;
}
