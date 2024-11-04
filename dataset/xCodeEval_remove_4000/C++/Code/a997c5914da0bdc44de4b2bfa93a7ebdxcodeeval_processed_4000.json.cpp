


























































































































































































































using namespace std;
const int MAXINT = 100010;
const int MAXNODE = 100010;
const int MAXEDGE = 2 * MAXNODE;
char BUF, *buf;
int read() {
	char c = getchar(); int f = 1, x = 0;
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return f * x;
}
char get_ch() {
	char c = getchar();
	while (!isalpha(c)) c = getchar();
	return c;
}


int x_s, x_l, y_s, y_l, n;
long double lb = -1e50, rb = 1e50;
struct mouse {
	int vx, vy, sx, sy;
	mouse(int _sx, int _sy, int _vx, int _vy) {
		sx = _sx; sy = _sy; vx = _vx; vy = _vy;
	}
	mouse() {}
	long double intersect(int p, int tp) {
		long double t;
		if (tp == 1) { 

			t = ((long double)(p)-sx) / vx;
			long double py1 = sy + vy * (t + eps);
			long double py2 = sy + vy * (t - eps);
			if (((t + eps > 0) && (py1<y_l && py1>y_s)) || ((t - eps > 0) && (py2<y_l && py2>y_s))) return t;
			return -1;
		}
		if (tp == 2) { 

			t = ((long double)(p)-sy) / vy;
			long double px1 = sx + vx * (t + eps);
			long double px2 = sx + vx * (t - eps);
			if (((t + eps > 0) && (px1<x_l && px1>x_s)) || ((t - eps > 0) && (px2<x_l && px2>x_s))) return t;
			return -1;
		}
	}
	int in() {
		return (sx < x_l && sx > x_s) && (sy < y_l && sy > y_s);
	}
} mice[MAXINT];
int intersect(long double l, long double r) {
	lb = max(l, lb);
	rb = min(r, rb);
	if (rb - lb < eps) return 0;
	return 1;
}
void get_input();
void work();
int main() {
	get_input();
	work();
	return 0;
}
void work() {
	rep0(i, n) {
		long double t, l = 1e50, r = -1e50;
		if (mice[i].in()) {
			l = 0;
			if (mice[i].vx == 0 && mice[i].vy == 0) r = 1e50;
		}
		if ((t = mice[i].intersect(x_s, 1)) > -eps) l = min(l, t), r = max(r, t);
		if ((t = mice[i].intersect(x_l, 1)) > -eps) l = min(l, t), r = max(r, t);
		if ((t = mice[i].intersect(y_s, 2)) > -eps) l = min(l, t), r = max(r, t);
		if ((t = mice[i].intersect(y_l, 2)) > -eps) l = min(l, t), r = max(r, t);
		if (r - l < eps) {
			printf("-1\n");
			return;
		}
		if (!intersect(l, r)) {
			printf("-1\n");
			return;
		}
	}
	printf("%.10Lf\n", lb);
}
void get_input() {
	n = read();
	int x1 = read(), y1 = read(), x2 = read(), y2 = read();
	x_s = min(x1, x2);
	x_l = max(x1, x2);
	y_s = min(y1, y2);
	y_l = max(y1, y2);
	rep0(i, n) {
		mice[i].sx = read();
		mice[i].sy = read();
		mice[i].vx = read();
		mice[i].vy = read();
	}
}