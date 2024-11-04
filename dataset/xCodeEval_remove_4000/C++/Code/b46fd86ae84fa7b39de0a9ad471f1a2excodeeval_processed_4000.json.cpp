

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long llu;
typedef pair<ll, ll> llp;


llp a, b, c;
vector<llp> pts;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	if (b.x > c.x)swap(b, c);
	if (a.x > b.x)swap(a, b);
	if (b.x > c.x)swap(b, c);

	ll mny = min(a.y, min(b.y, c.y));
	ll mxy = max(a.y, max(b.y, c.y));
	for (int y = mny; y <= mxy; y++) {
		pts.push_back(llp{ b.x, y });
	}
	for (int x = a.x; x < b.x; x++) {
		pts.push_back(llp{ x, a.y });
	}

	for (int x = c.x; x > b.x; x--) {
		pts.push_back(llp{ x,c.y });
	}

	cout << pts.size() << endl;
	for (auto p : pts) {
		cout << p.x << " " << p.y << endl;
	}

	return 0;
}


