#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>
#include <climits>
#include <tuple>
#include <cassert>
#include <numeric>

#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>


using namespace std;

#define all(a) a.begin(), a.end()
#define len(a) (int)a.size()
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pldld;

inline int nextInt() {
	int n;
	scanf("%d", &n);
	return n;
}

inline ll nextLong() {
	ll n;
	scanf("%lld", &n);
	return n;
}

inline double nextDouble() {
	double n;
	scanf("%lf", &n);
	return n;
}

inline string nextLine() {
	static char ______________buffer[1000005];
	fgets(______________buffer, 1000000, stdin);
	string res = ______________buffer;
	if (*(res.end() - 1) == '\n')res.erase(res.end() - 1);
	return res;
}

inline char nextChar() {
	char n;
	scanf("%c", &n);
	return n;
}

inline string next() {
	static char ______________buffer[1000005];
	scanf("%s", ______________buffer);
	string res = ______________buffer;
	return res;

}

string nToKss(string num, int n, int k) {
	static unordered_map<char, int> _______________________SSSSSSSSSSSSSSSSSS;
	static unordered_map<int, char> _______________________SSSSSSSSSSSSSSSSS;
	if (len(_______________________SSSSSSSSSSSSSSSSSS) == 0) {
		int c = 0;
		for (char i = '0'; i <= '9'; i++) {
			_______________________SSSSSSSSSSSSSSSSSS[i] = c++;
			_______________________SSSSSSSSSSSSSSSSS[c - 1] = i;
		}
		for (char i = 'A'; i <= 'Z'; i++) {
			_______________________SSSSSSSSSSSSSSSSSS[i] = c++;
			_______________________SSSSSSSSSSSSSSSSS[c - 1] = i;
		}
		for (char i = 'a'; i <= 'z'; i++) {
			_______________________SSSSSSSSSSSSSSSSSS[i] = c++;
			_______________________SSSSSSSSSSSSSSSSS[c - 1] = i;
		}
	}
	ll f = 0;
	reverse(all(num));
	ll powpow = 1;
	for (auto i : num) {
		f += _______________________SSSSSSSSSSSSSSSSSS[i] * powpow;
		powpow *= n;
	}

	string res;

	while (f > 0) {
		res += _______________________SSSSSSSSSSSSSSSSS[f%k];
		f /= k;
	}
	reverse(all(res));
	if (len(res) == 0)res = "0";
	return res;
}

ll mod = 998244353;

double const PI = 3.1415926535897932384626433832795;

double EPS = 1e-8;

struct SegmentTree {

	vector<int> sums;
	vector<int> maxes;
	vector<int> mins;
	vector<int> und;
	vector<int> ur;
	int curN;


	void init(int n) {
		sums.resize(n, 0);
		maxes.resize(n, INT_MIN);
		und.resize(n, 0);
		ur.resize(n, 0);
		mins.resize(n, INT_MAX);
		curN = n >> 1;
	}

	void build() {
		for (int i = curN - 1; i >= 1; i--) {
			sums[i] = sums[i * 2] + sums[i * 2 + 1];
			maxes[i] = max(maxes[i * 2], maxes[i * 2 + 1]);
			mins[i] = min(mins[i * 2], mins[i * 2 + 1]);
			ur[i] = ur[i * 2] | ur[i * 2 + 1];
			und[i] = und[i * 2] & und[i * 2 + 1];
		}
	}

	int getSum(int l, int r) {
		return  _getSum(curN - 1 + l, curN - 1 + r);
	}

	int _getSum(int l, int r) {
		int res = 0;
		if (l == r)return sums[l];
		if (l % 2 == 1) {
			res += sums[l++];
		}
		if (r % 2 == 0) {
			res += sums[r--];
		}
		if (l > r)return res;
		return res + _getSum(l / 2, r / 2);
	}
	int getMin(int l, int r) {
		return _getMin(curN - 1 + l, curN - 1 + r);
	}

	int _getMin(int l, int r) {
		int res = INT_MAX;
		if (l == r)return mins[l];
		if (l % 2 == 1) {
			res = min(res, mins[l++]);
		}
		if (r % 2 == 0) {
			res = min(res, mins[r--]);
		}
		if (l > r)return res;
		return min(res, _getMin(l / 2, r / 2));
	}
	int getMax(int l, int r) {
		return _getMax(curN - 1 + l, curN - 1 + r);
	}

	int _getMax(int l, int r) {
		int res = 0;
		if (l == r)return maxes[l];
		if (l % 2 == 1) {
			res = max(res, maxes[l++]);
		}
		if (r % 2 == 0) {
			res = max(res, maxes[r--]);
		}
		if (l > r)return res;
		return max(res, _getMax(l / 2, r / 2));
	}

	int getAnd(int l, int r) {
		return _getAnd(curN - 1 + l, curN - 1 + r);
	}

	int _getAnd(int l, int r) {
		int res = INT_MAX;
		if (l == r)return ur[l];
		if (l % 2 == 1) {
			res &= ur[l++];
		}
		if (r % 2 == 0) {
			res &= ur[r--];
		}
		if (l > r)return res;
		return res & _getAnd(l / 2, r / 2);
	}

	int getOr(int l, int r) {
		return _getOr(curN - 1 + l, curN - 1 + r);
	}

	int _getOr(int l, int r) {
		int res = 0;
		if (l == r)return ur[l];
		if (l % 2 == 1) {
			res |= ur[l++];
		}
		if (r % 2 == 0) {
			res |= ur[r--];
		}
		if (l > r)return res;
		return res | _getOr(l / 2, r / 2);
	}

	void update(int ind, int newVal) {
		ind += curN - 1;
		initUnit(ind, newVal);

		ind /= 2;
		while (ind > 0) {
			sums[ind] = sums[ind * 2] + sums[ind * 2 + 1];
			maxes[ind] = max(maxes[ind * 2], maxes[ind * 2 + 1]);
			mins[ind] = min(mins[ind * 2], mins[ind * 2 + 1]);
			ur[ind] = ur[ind * 2] | ur[ind * 2 + 1];
			und[ind] = und[ind * 2] & und[ind * 2 + 1];
			ind /= 2;

		}
	}

	void add(int ind, int adding) {
		ind += curN - 1;
		initUnit(ind, sums[ind] + adding);
		ind /= 2;
		while (ind > 0) {
			sums[ind] = sums[ind * 2] + sums[ind * 2 + 1];
			maxes[ind] = max(maxes[ind * 2], maxes[ind * 2 + 1]);
			mins[ind] = min(mins[ind * 2], mins[ind * 2 + 1]);
			ur[ind] = ur[ind * 2] | ur[ind * 2 + 1];
			und[ind] = und[ind * 2] & und[ind * 2 + 1];
			ind /= 2;
		}
	}

	void initUnit(int ind, int wha) {
		sums[ind] = wha;
		maxes[ind] = wha;
		ur[ind] = wha;
		mins[ind] = wha;
		und[ind] = wha;
	}

};

struct DoubleSegmentTree {
	int actM, actN;
	vector<SegmentTree> arr;
	void init(int M, int N) {
		actM = M;
		actN = N;
		arr.resize(2 * actN);
		for (int i = 1; i < 2 * actN; i++)arr[i].init(actM * 2);
	}

	void readData(int n, int m) {
		for (int i = actN; i < actN + n; i++) {
			for (int j = actM; j < actM + m; j++) {
				arr[i].initUnit(j, nextInt());
			}
			arr[i].build();
		}
	}

	void build() {
		for (int i = actN - 1; i >= 2; i--) {
			for (int j = 0; j < 2 * actM; j++) {
				arr[i].sums[j] = arr[i * 2].sums[j] + arr[i * 2 + 1].sums[j];
				arr[i].maxes[j] = max(arr[i * 2].maxes[j], arr[i * 2 + 1].maxes[j]);
				arr[i].mins[j] = min(arr[i * 2].mins[j], arr[i * 2 + 1].mins[j]);
				arr[i].ur[j] = arr[i * 2].ur[j] | arr[i * 2 + 1].ur[j];
				arr[i].und[j] = arr[i * 2].und[j] & arr[i * 2 + 1].und[j];
			}
		}
	}

	int getSum(int x1, int y1, int x2, int y2) {
		int TOP = y1;
		int BOT = y2;

		TOP += actN - 1;
		BOT += actN - 1;
		int res = 0;
		while (TOP < BOT) {
			if (TOP % 2 == 1) {
				res += arr[TOP++].getSum(x1, x2);
			}
			if (BOT % 2 == 0) {
				res += arr[BOT--].getSum(x1, x2);
			}
			if (TOP > BOT)break;
			BOT /= 2;
			TOP /= 2;
		}
		if (BOT == TOP)res += arr[TOP].getSum(x1, x2);
		return res;
	}

	int getAnd(int x1, int y1, int x2, int y2) {
		int TOP = y1;
		int BOT = y2;

		TOP += actN - 1;
		BOT += actN - 1;
		int res = INT_MAX;
		while (TOP < BOT) {
			if (TOP % 2 == 1) {
				res &= arr[TOP++].getAnd(x1, x2);
			}
			if (BOT % 2 == 0) {
				res &= arr[BOT--].getAnd(x1, x2);
			}
			if (TOP > BOT)break;
			BOT /= 2;
			TOP /= 2;
		}
		if (BOT == TOP)res &= arr[TOP].getAnd(x1, x2);
		return res;
	}

	int getOr(int x1, int y1, int x2, int y2) {
		int TOP = y1;
		int BOT = y2;

		TOP += actN - 1;
		BOT += actN - 1;
		int res = 0;
		while (TOP < BOT) {
			if (TOP % 2 == 1) {
				res |= arr[TOP++].getOr(x1, x2);
			}
			if (BOT % 2 == 0) {
				res |= arr[BOT--].getOr(x1, x2);
			}
			if (TOP > BOT)break;
			BOT /= 2;
			TOP /= 2;
		}
		if (BOT == TOP)res |= arr[TOP].getOr(x1, x2);
		return res;
	}

	int getMax(int x1, int y1, int x2, int y2) {
		int TOP = y1;
		int BOT = y2;

		TOP += actN - 1;
		BOT += actN - 1;
		int res = INT_MIN;
		while (TOP < BOT) {
			if (TOP % 2 == 1) {
				res = max(res, arr[TOP++].getMax(x1, x2));
			}
			if (BOT % 2 == 0) {
				res = max(res, arr[BOT--].getMax(x1, x2));
			}
			if (TOP > BOT)break;
			BOT /= 2;
			TOP /= 2;
		}
		if (BOT == TOP)res = max(res, arr[TOP].getMax(x1, x2));
		return res;
	}

	int getMin(int x1, int y1, int x2, int y2) {
		int TOP = y1;
		int BOT = y2;

		TOP += actN - 1;
		BOT += actN - 1;
		int res = INT_MAX;
		while (TOP < BOT) {
			if (TOP % 2 == 1) {
				res = min(res, arr[TOP++].getMin(x1, x2));
			}
			if (BOT % 2 == 0) {
				res = min(res, arr[BOT--].getMin(x1, x2));
			}
			if (TOP > BOT)break;
			BOT /= 2;
			TOP /= 2;
		}
		if (BOT == TOP)res = min(res, arr[TOP].getMin(x1, x2));
		return res;
	}


	void update(int x, int y, int z) {
		y += actN - 1;
		arr[y].update(x, z);
		y /= 2;
		while (y > 0) {
			for (int j = 0; j < 2 * actM; j++) {
				updateVertex(y, j);
			}
			y /= 2;
		}
	}

	void add(int x, int y, int z) {
		y += actN - 1;
		arr[y].add(x, z);
		y /= 2;
		while (y > 0) {
			for (int j = 0; j < 2 * actM; j++) {
				updateVertex(y, j);
			}
			y /= 2;
		}
	}

	void updateVertex(int y, int x) {
		arr[y].sums[x] = arr[y * 2].sums[x] + arr[y * 2 + 1].sums[x];
		arr[y].maxes[x] = max(arr[y * 2].maxes[x], arr[y * 2 + 1].maxes[x]);
		arr[y].mins[x] = min(arr[y * 2].mins[x], arr[y * 2 + 1].mins[x]);
		arr[y].ur[x] = arr[y * 2].ur[x] | arr[y * 2 + 1].ur[x];
		arr[y].und[x] = arr[y * 2].und[x] & arr[y * 2 + 1].und[x];
	}
};

bool guess(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", y1, x1, y2, x2);
	fflush(stdout);
	nextChar();
	return next()[0] == 'Y';
}

int main() {

	int n = nextInt();


	vector<vector<int> > arr(n + 5, vector<int>(n + 5, 0));
	arr[1][1] = 1;
	arr[n][n] = 1;
	int x = n, y = n;

	while (x - 1 + y - 1 >= n - 1) {

		if (x - 1 >= 1 && x - 1 - 1 + y - 1 >= n - 1) {
			arr[y][x - 1] = guess(1, 1, x - 1, y);
			if (arr[y][x - 1] == 1) {
				x--;
				continue;
			}
		}
		if (y - 1 >= 1 && x - 1 + y - 2 >= n - 1) {
			arr[y - 1][x] = guess(1, 1, x, y - 1);
			if (arr[y - 1][x] == 1) {
				y--;
				continue;
			}
		}
		break;
	}
	x = y = 1;

	while (n - x + n - y >= n - 1) {
		if (y + 1 <= n && n - x + n - y - 1 >= n - 1) {
			arr[y + 1][x] = guess(x, y + 1, n, n);
			if (arr[y + 1][x] == 1) {
				y++;
				continue;
			}
		}
		if (x + 1 <= n && n - x - 1 + n - y >= n - 1) {
			arr[y][x + 1] = guess(x + 1, y, n, n);
			if (arr[y][x + 1] == 1) {
				x++;
				continue;
			}
		}
		
		break;
	}

	x = y = 1;

	string res;

	while (!(x == n && y == n)) {
		if (arr[y][x + 1] == 1) {
			x++;
			res += 'R';
		}
		else if (arr[y + 1][x] == 1) {
			y++;
			res += 'D';
		}
	}
	printf("! %s", res.c_str());

	fflush(stdout);

#ifdef _DEBUG
	printf("\nTime elapsed: %.3lf s.\n", 1.0 * clock() / CLOCKS_PER_SEC);
	while (1);
#endif

	return 0;
}