







using std::vector;
using std::cin;
using std::endl;
using std::cout;
using std::pair;
using std::swap_ranges;
using std::iter_swap;

template<class C>
C Min(C a, C b) {
	return a < b ? a : b;
}

template <class Iter, class Compare>
bool Less(Iter first, Iter second, Compare cmp) {
	return cmp(*first, *second);
}

template <class Iter, class Compare>
bool Equal(Iter first, Iter second, Compare cmp) {
	return !Less(first, second, cmp) && !Less(second, first, cmp);
}

template <class Iter, class Compare>
bool lessEqual(Iter first, Iter second, Compare cmp) {
	return Less(first, second, cmp) || Equal(first, second, cmp);
}

template <class Iter, class Compare>
bool greater(Iter first, Iter second, Compare cmp) {
	return !lessEqual(first, second, cmp);
}

template <class Iter, class Compare>
bool greaterEqual(Iter first, Iter second, Compare cmp) {
	return greater(first, second, cmp) || Equal(first, second, cmp);
}

int id6(int n) {
	int flag = 0;
	while (n >= 64) {
		flag |= n & 1;
		n >>= 1;
	}
	return n + flag;
}

enum MonotonyType {
	undefined,
	decreasing,
	id0
};

template <class Iter, class Compare>
void slowSort(Iter begin, Iter end, Compare cmp) {
	for (Iter i = begin; i < end; ++i) {
		for (Iter j = i + 1; j < end; ++j) {
			if (!Less(i, j, cmp)) {
				iter_swap(i, j);
			}
		}
	}
}

template <class Iter>
void Reverse(Iter begin, Iter end) {
	int n2 = int(end - begin) / 2;
	Iter i = begin, j = end - 1;
	for (int cnt = 0; cnt < n2; ++cnt) {
		iter_swap(i, j);
		++i;
		--j;
	}
}

template <class Iter, class Iter2, class Compare>
int id5(Iter first, Iter last, Iter2 to_cmp, Compare cmp) {
	

	int len = last - first + 1;
	int pw = 1;
	while (pw <= int(last - first)) {
		if (cmp(*to_cmp, *(first + pw))) {
			break;
		}
		pw <<= 1;
	}
	int left, right;
	if (pw <= int(last - first)) {
		left = pw >> 1;
		right = pw;
	} else {
		left = pw >> 1;
		right = len;
	}
	while (right - left > 1) {
		int mid = (right + left) >> 1;
		if (cmp(*to_cmp, *(first + mid))) {
			right = mid;
		} else {
			left = mid;
		}
	}
	assert((first + left) <= last);
	assert(!cmp(*to_cmp, *(first + left)));
	return left;
}

template <class Iter, class Iter2>
void Copy(Iter fir, Iter sec, Iter2 res) {
	

	int len = sec - fir + 1;
	for (int i = 0; i < len; ++i) {
		*(res + i) = *(fir + i);
	}
}

template <class iter, class Compare>
void mergeBlocks(iter fir, iter mid, iter last, int len, Compare cmp) {
	assert(mid != last);
	assert(fir != last);
	for (int i = 0; i < len; i++) {
		iter_swap(fir + i, last + i);
	}
	int posf, posm, posl;
	posf = posm = posl = 0;
	int cntm, cntl;
	cntm = cntl = 0;
	while (posm < len && posl < len) {
		if (cntm == 7 && lessEqual(mid + posm, last + posl, cmp)) {
			int id2 = posm + id5(mid + posm, mid + len - 1, last + posl, cmp);
			swap_ranges(mid + posm, mid + id2 + 1, fir + posf);
			posf += id2 - posm + 1;
			posm = id2 + 1;
			cntm = 0;
			cntl = 0;
			continue;
		} else if (cntl == 7 && lessEqual(last + posl, mid + posm, cmp)){
			int id7 = posl + id5(last + posl, last + len - 1, mid + posm, cmp);
			swap_ranges(last + posl, last + id7 + 1, fir + posf);
			posf += id7 - posl + 1;
			posl = id7 + 1;
			cntm = 0;
			cntl = 0;
			continue;
		}
		if (Less(mid + posm, last + posl, cmp)) {
			cntm++;
			cntl = 0;
			iter_swap(fir + posf++, mid + posm++);
		} else {
			cntl++;
			cntm = 0;
			iter_swap(fir + posf++, last + posl++);
		}
	}
	while (posm < len) {
		iter_swap(fir + posf++, mid + posm++);
	}
	while (posl < len) {
		iter_swap(fir + posf++, last + posl++);
	}
}

template <class iter, class Compare>
void id9(iter begin, iter first, iter mid, iter last, int s, Compare cmp) {
	int len = int(first - begin) + 1;
	for (int i = 0; i < s; ++i) {
		iter_swap(mid - i, last - i);
	}
	int posf, posm, posl;
	posf = posm = posl = 0;
	while (posf < len && posl < s) {
		if (Less(first - posf, last - posl, cmp)) {
			iter_swap(mid - posm++, last - posl++);
		} else {
			iter_swap(mid - posm++, first - posf++);
		}
	}
	while (posl < s) {
		iter_swap(mid - posm++, last - posl++);
	}
	while (posf < len) {
		iter_swap(mid - posm++, first - posf++);
	}
}

template <class Iter, class Compare>
void id1(Iter l1, Iter r1, Iter l2, Iter r2, Compare cmp) {
	int lenl = r1 - l1 + 1;
	int lenr = r2 - l2 + 1;
	int len = lenl + lenr;
	if (len < 9) {
		slowSort(l1, r2 + 1, cmp);
		return;
	}
	int k = int(sqrt(len));
	int posMid = (lenl - 1) / k;
	int cnt_blocks = len / k;
	if (posMid < cnt_blocks) {
		swap_ranges(l1 + posMid * k, l1 + (posMid + 1) * k, l1 + (cnt_blocks - 1) * k);
	}
	for (int i = 0; i < cnt_blocks - 1; ++i) {
		int min_pos = i;
		for (int j = i + 1; j < cnt_blocks - 1; ++j) {
			if (Less(l1 + j * k, l1 + min_pos * k, cmp) || Equal(l1 + j * k, l1 + min_pos * k, cmp) && Less(l1 + (j * k + k - 1), l1 + (min_pos * k + k - 1), cmp)) {
				min_pos = j;
			}
		}
		swap_ranges(l1 + i * k, l1 + i * k + k, l1 + min_pos * k);
	}
	for (int i = 0; i < cnt_blocks - 2; ++i) {
		mergeBlocks(l1 + i * k, l1 + i * k + k, l1 + (cnt_blocks - 1) * k, k, cmp);
	}
	int s = k + len % k;
	assert(2 * s <= len);
	slowSort(r2 - (2 * s - 1), r2 + 1, cmp);
	id9(l1, r2 - 2 * s, r2 - s, r2, s, cmp);
	slowSort(r2 - (2 * s - 1), r2 + 1, cmp);
}



template <class Iter, class Compare>
void mergeAt(vector<pair<Iter, int> > &runs, int pos, Compare cmp) {
	Iter l1 = runs[pos].first, r1 = runs[pos].first + runs[pos].second - 1, l2 = runs[pos + 1].first, r2 = runs[pos + 1].first + runs[pos + 1].second - 1;
	int sz = runs.size();
	runs[pos].second += runs[pos + 1].second;
	if (pos == sz - 3) {
		runs[pos + 1] = runs[pos + 2];
	}
	runs.pop_back();
	id1(l1, r1, l2, r2, cmp);
}

template <class Iter, class Compare>
void mergeRuns(vector<pair<Iter, int> > &runs, Compare cmp) {
	while (runs.size() > 1) {
		int n = runs.size() - 2;
		if ((n > 0 && runs[n - 1].second <= runs[n].second + runs[n + 1].second) ||
			(n > 1 && runs[n - 2].second <= runs[n - 1].second + runs[n].second)) {
			if (runs[n - 1].second < runs[n + 1].second) {
				--n;
			}
			mergeAt(runs, n, cmp);
		} else if (runs[n].second <= runs[n + 1].second) {
			mergeAt(runs, n, cmp);
		} else {
			break;
		}
	}
}

template <class Iter, class Compare>
void id3(vector<pair<Iter, int> > &runs, Compare cmp) {
	while (runs.size() > 1) {
		int n = runs.size() - 2;
		if (n > 0 && runs[n - 1].second < runs[n + 1].second) {
			--n;
		}
		mergeAt(runs, n, cmp);
	}
}

template <class Iter, class Compare>
void timSort(Iter begin, Iter end, Compare cmp) {
	int n = end - begin;
	if (n == 1) {
		return;
	}
	int length = id6(n);
	vector<pair<Iter, int> > runs;
	int curLen = 1;
	int pos = 0;
	MonotonyType id8 = undefined;
	while (pos < n) {
		if (pos + 1 == n) {
			if (id8 == decreasing) {
				Reverse(begin + (pos + 1 - curLen), begin + pos + 1);
			}
			runs.push_back({begin + (pos + 1 - curLen), curLen});
			mergeRuns(runs, cmp);
			break;
		}
		if (id8 == undefined) {
			if (greaterEqual(begin + pos + 1, begin + pos, cmp)) {
				id8 = id0;
			} else {
				id8 = decreasing;
			}
			++curLen;
		} else if (id8 == decreasing) {
			if (lessEqual(begin + pos + 1, begin + pos, cmp)) {
				++curLen;
			} else {
				if (curLen < length) {
					int id4 = curLen;
					curLen = Min(length, curLen + (n - pos) - 1);
					pos = Min(pos + (length - id4), n - 1);
					slowSort(begin + (pos + 1 - curLen), begin + (pos + 1), cmp);
				} else {
					Reverse(begin + (pos + 1 - curLen), begin + pos + 1);
				}
				runs.push_back({begin + (pos + 1 - curLen), curLen});
				mergeRuns(runs, cmp);
				id8 = undefined;
				curLen = 1;
			}
		} else if (id8 == id0) {
			if (greaterEqual(begin + pos + 1, begin + pos, cmp)) {
				++curLen;
			} else {
				if (curLen < length) {
					int id4 = curLen;
					curLen = Min(length, curLen + (n - pos) - 1);
					pos = Min(pos + (length - id4), n - 1);
					slowSort(begin + (pos + 1 - curLen), begin + (pos + 1), cmp);
				}
				runs.push_back({begin + (pos + 1 - curLen), curLen});
				mergeRuns(runs, cmp);
				id8 = undefined;
				curLen = 1;
			}
		}
		++pos;
	}
	id3(runs, cmp);
	assert(runs.size() == 1);
}

template <class Iter>
void timSort(Iter begin, Iter end) {
	typedef typename std::iterator_traits<Iter>::value_type value_type;
	std::less<value_type> cmp = std::less<value_type>();
	timSort(begin, end, cmp);
}






















using namespace std;





typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

vector<pair<int, int> > ans;
vector<int> used;

void solve(vector<int> &want, vector<vector<int> > &g, int v, int h){
	if (!used[want[v]]){
		used[want[v]] = 1;
		ans.push_back({h, want[v]});
	}
	for (int i = 0; i < g[v].size(); i++){
		solve(want, g, g[v][i], h + 1);
	}
}

void solve1(int x, int v, vector<vector<int> > &g, vector<int> &chosen){
	if (chosen[v] != -1) return;
	chosen[v] = x;
	for (int i = 0; i < g[v].size(); i++){
		solve1(x, g[v][i], g, chosen);
	}
}

int main(){
	

	

	int n, m;
	cin >> n >> m;
	vector<vector<int>>g(n, vector<int>());
	vector<int> ins(n);
	for (int i = 0; i < m; i++){
		int q, w;
		cin >> q >> w;
		q--, w--;
		g[q].push_back(w);
		ins[w]++;
	}
	used.resize(n);
	vector<int> want(n);
	for (int i = 0; i < n; i++){
		cin >> want[i];
		want[i]--;
	}
	for (int i = 0; i < n; i++){
		if (ins[i] == 0){
			solve(want, g, i, 0);
		}
	}
	

	timSort(ans.rbegin(), ans.rend());
	vector<int> chosen(n, -1);
	for (int i = 0; i < ans.size(); i++){
		solve1(ans[i].second, ans[i].second, g, chosen);
	}
	for (int i = 0; i < n; i++){
		if (chosen[i] != want[i]) return cout << -1, 0;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i].second+1 << " ";
	}
}