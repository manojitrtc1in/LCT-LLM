
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}
 
template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}
 
mt19937 rnd(2);
 
const int INF = int(2e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
 
const int N = 300 * 1000 + 13;
 
int n;
pt a[N];
 
bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}
 
struct node{
	node *l, *r;
	int x, y, siz, mx, add;
	node(){}
	node(int x) : l(NULL), r(NULL), x(x), y(rnd()), siz(1), mx(0), add(0) {}
};
 
typedef node* treap;
typedef pair<treap, treap> ptt;
 
int getSize(treap t){
	return t ? t->siz : 0;
}
 
int getMax(treap t){
	return t ? t->mx + t->add : 0;
}
 
treap fix(treap t){
	if (!t) return t;
	t->siz = getSize(t->l) + 1 + getSize(t->r);
	t->mx = max({getMax(t->l), t->x, getMax(t->r)});
	t->x += t->add;
	t->mx += t->add;
	if (t->l) t->l->add += t->add;
	if (t->r) t->r->add += t->add;
	t->add = 0;
	return t;
}
 
void print(treap t){
	if (!t) return;
	

	if (t->l) print(t->l);
	cerr << t->x << " ";
	if (t->r) print(t->r);
}
    
treap merge(treap a, treap b) {
	if (!a || !b) return a ? fix(a) : fix(b);
	
	a = fix(a);
	b = fix(b);
 
	if (a->y < b->y) {
		b->l = merge(a, b->l);
		return fix(b);
	} else {
		a->r = merge(a->r, b);
		return fix(a); 
	}
} 
 
ptt split(treap t, int siz) {
	if (!t) return ptt(NULL, NULL);
	         
	t = fix(t);
	int curs = getSize(t->l);
 
	if (siz <= curs) {
		ptt p = split(t->l, siz);
		t->l = p.y;
		return ptt(p.x, fix(t));
	} else {
		ptt p = split(t->r, siz - curs - 1);
		t->r = p.x;
		return ptt(fix(t), p.y);
	}
}
 
int l_b(treap t, int val){
	if (!t) return 0;
	
	t = fix(t);
	if (t->l && getMax(t->l) >= val)
		return l_b(t->l, val);
	else if (t->x >= val)
		return getSize(t->l);
	else
		return getSize(t->l) + 1 + l_b(t->r, val);
}
 
void solve() {
	treap t = new node(INF);
	forn(i, n){
		ptt l = split(t, l_b(t, a[i].x));
		ptt r = split(l.y, l_b(l.y, a[i].y));
		r = mp(r.x, split(r.y, 1).y);
		if (r.x) ++r.x->add;
		t = merge(merge(l.x, new node(a[i].x)), merge(r.x, r.y));
		

		

	}
	printf("%d\n", getSize(t));
}
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;
 
	if(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif
 
	}
}