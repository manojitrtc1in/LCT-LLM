#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <tuple>
#include <set>
#include <iterator>
#include <string>
#include <sstream>
#include <array>

using namespace std;

#undef min
#undef max

void Solve1285E() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	size_t t;
	cin >> t;
	vector<tuple<int, size_t, size_t>> v;
	vector<int> costRemove;
	for (size_t iTest = 0; iTest < t; ++iTest) {
		size_t n;
		cin >> n;
		v.clear();
		costRemove.assign(n, 0);
		for (size_t i = 0; i < n; ++i) {
			size_t l, r;
			cin >> l >> r;
			v.emplace_back(l, 0, i);
			v.emplace_back(r, 1, i);
		}

		make_heap(v.begin(), v.end());
		sort_heap(v.begin(), v.end());

		size_t cnt = 0;
		size_t n0 = 0;
		set<size_t> s;
		size_t lastStarted = n;
		vector<size_t> f(v.size());
		for (size_t i = 0; i < v.size();) {
			size_t cnt0 = cnt;
			size_t curSegment = n;
			if (cnt == 1) {
				curSegment = *s.begin();
			}
			size_t j = i;
			for (; j < v.size() && get<0>(v[j]) == get<0>(v[i]) && get<1>(v[j]) == 0; ++j) {
				s.insert(get<2>(v[j]));
				++cnt;
				f[j] = cnt;
			}
			size_t cnt1 = cnt;
			if (cnt0 == 1 && cnt1 > 1 && lastStarted == curSegment) {
				++costRemove[curSegment];
			}
			for (; j < v.size() && get<0>(v[j]) == get<0>(v[i]) && get<1>(v[j]) == 1; ++j) {
				s.erase(get<2>(v[j]));
				--cnt;
				f[j] = cnt;
			}

			i = j;
			size_t cnt2 = cnt;
			if (cnt2 == 0) {
				++n0;
			}
			if (cnt1 > 1 && cnt2 == 1) {
				lastStarted = *s.begin();
			}
		}

		for (size_t i = 0; i + 1 < v.size(); ++i) {
			if ((i == 0 || f[i - 1] == 0) && f[i] == 1 && f[i + 1] == 0) {
				costRemove[get<2>(v[i])] = -1;
			}
		}

		int maxCost = -1;
		for (const auto c : costRemove) {
			maxCost = max(maxCost, c);
		}
		cout << n0 + maxCost << "\n";
	}
}

struct TBestResult {
	TBestResult(long long bestDiff = 0, size_t winCount = 0)
		: BestDiff(bestDiff)
		, WinCount(winCount)
	{}

	long long BestDiff;
	size_t WinCount;
};

bool operator<(const TBestResult& r1, const TBestResult& r2) {
	return r1.WinCount < r2.WinCount || (r1.WinCount == r2.WinCount && r1.BestDiff < r2.BestDiff);
}

TBestResult operator+(const TBestResult& r1, const TBestResult& r2) {
	return TBestResult{r1.BestDiff + r2.BestDiff, r1.WinCount + r2.WinCount};
}

TBestResult EndHere(const TBestResult& r) {
	return {0, r.WinCount + (r.BestDiff > 0 ? 1 : 0)};
}

void TryImprove(const TBestResult& res, vector<TBestResult>& results, size_t pos) {
	if (results.size() == pos) {
		results.push_back(res);
	}
	else {
		results[pos] = max(results[pos], res);
	}
}

vector<TBestResult> SolveMissPuniverse(
	size_t iVertex,
	size_t iParent,
	const vector<vector<size_t>>& neib,
	const vector<long long>& b,
	const vector<long long>& w)
{
	vector<TBestResult> curRes;
	curRes.emplace_back(w[iVertex] - b[iVertex], 0);
	for (const auto iNeib : neib[iVertex]) {
		if (iNeib == iParent) {
			continue;
		}

		vector<TBestResult> newRes;
		const auto childRes = SolveMissPuniverse(iNeib, iVertex, neib, b, w);
		for (size_t villageCount = 0; villageCount < curRes.size(); ++villageCount) {
			for (size_t childVillageCount = 0; childVillageCount < childRes.size(); ++childVillageCount) {
				TryImprove(curRes[villageCount] + childRes[childVillageCount], newRes, childVillageCount + villageCount);
				TryImprove(curRes[villageCount] + EndHere(childRes[childVillageCount]), newRes, childVillageCount + villageCount + 1);
			}
		}
		newRes.swap(curRes);
	}
	return curRes;
}

void Solve1280D() {
	cin.sync_with_stdio(false);
	vector<vector<size_t>> neib(3000);
	vector<long long> w, b;
	size_t t;
	cin >> t;
	for (size_t iTest = 0; iTest < t; ++iTest) {
		size_t n, m;
		cin >> n >> m;
		w.clear();
		b.clear();
		copy_n(istream_iterator<long long>(cin), n, back_inserter(b));
		copy_n(istream_iterator<long long>(cin), n, back_inserter(w));

		for (auto& v : neib) {
			v.clear();
		}

		for (size_t i = 0; i + 1 < n; ++i) {
			size_t i1, i2;
			cin >> i1 >> i2;
			--i1;
			--i2;
			neib[i1].push_back(i2);
			neib[i2].push_back(i1);
		}

		auto res = SolveMissPuniverse(0, 0, neib, b, w);
		cout << EndHere(res[m - 1]).WinCount << "\n";
	}
}

void SolveUva10918() {
	long long F[31][8] = { 0 };
	F[0][7] = 1;
	for (size_t i = 1; i <= 30; ++i) {
		F[i][0] = F[i - 1][7];
		F[i][1] = F[i - 1][6];
		F[i][2] = F[i - 1][5];
		F[i][3] = F[i - 1][7] + F[i - 1][4];
		F[i][4] = F[i - 1][3];
		F[i][5] = F[i - 1][2];
		F[i][6] = F[i - 1][7] + F[i - 1][1];
		F[i][7] = F[i - 1][0] + F[i - 1][3] + F[i - 1][6];
	}

	while (true) {
		int i;
		cin >> i;
		if (i == -1) {
			break;
		}

		cout << F[i][7] << "\n";
	}
}

void SolveRobbery101(size_t iNode, size_t k, const vector<vector<size_t>>& neib, const vector<size_t>& s, vector<vector<size_t>>& f) {
	f[iNode].push_back(0);
	
	vector<size_t> fNew;
	for (auto iChild : neib[iNode]) {
		SolveRobbery101(iChild, k, neib, s, f);

		fNew.clear();
		for (size_t nRobbed = 0; nRobbed < f[iChild].size(); ++nRobbed) {
			for (size_t i = 0; i + nRobbed <= k && i < f[iNode].size(); ++i) {
				if (fNew.size() == i + nRobbed) {
					fNew.push_back(f[iNode][i] + f[iChild][nRobbed]);
				} else {
					fNew[i + nRobbed] = max(fNew[i + nRobbed], f[iNode][i] + f[iChild][nRobbed]);
				}
			}
		}

		f[iNode].swap(fNew);
	}

	if (f[iNode].size() == 1) {
		f[iNode].push_back(s[iNode]);
	} else {
		f[iNode][1] = max(f[iNode][1], s[iNode]);
	}
}

void SolveCodeChefINF16B() {  

	cin.sync_with_stdio(false);
	size_t t;
	cin >> t;
	for (size_t iTest = 0; iTest < t; ++iTest) {
		size_t n, k;
		cin >> n >> k;
		vector<vector<size_t>> neib(n);
		vector<size_t> s(n);
		size_t iRoot;
		for (size_t i = 0; i < n; ++i) {
			size_t iParent;
			cin >> iParent >> s[i];
			if (iParent == 0) {
				iRoot = i;
			} else {
				--iParent;
				

				neib[iParent].push_back(i);
			}
		}

		vector<vector<size_t>> f(n);
		SolveRobbery101(iRoot, k, neib, s, f);

		if (f[iRoot].size() <= k) {
			cout << "-1\n";
		} else {
			cout << f[iRoot][k] << "\n";
		}
	}
}

string GetLineFromCin() {
	string s;
	getline(cin, s);
	return s;
}

struct TMoveCounts {
	int u, d, l, r;
};

void Resize(vector<vector<vector<int>>>& v, size_t s1, size_t s2, size_t s3) {
	v.resize(s1);
	for (auto& v1 : v) {
		v1.resize(s2);
		for (auto& v2 : v1) {
			v2.assign(s3, 0);
		}
	}
}

TMoveCounts CountMoves(int r1, int c1, int r2, int c2, int rowReturns, int nMoves) {
	TMoveCounts res = { rowReturns, rowReturns, 0, 0 };
	if (r2 > r1) {
		res.d += r2 - r1;
	}
	else {
		res.u += r1 - r2;
	}

	if (c2 > c1) {
		res.r += c2 - c1;
	}
	else {
		res.l += c1 - c2;
	}

	int colReturns = (nMoves - res.u - res.d - res.l - res.r) / 2;
	res.l += colReturns;
	res.r += colReturns;
	return res;
}



void SolveHackerrankTheRoom() {
	int N, M;
	stringstream firstLine(GetLineFromCin());
	firstLine >> N >> M;
	vector<string> a(N);
	int sr = -1, sc = -1;
	for (int i = 0; i < N; ++i) {
		getline(cin, a[i]);
		for (int j = 0; j < M; ++j) {
			if (a[i][j] == 'J') {
				sr = i;
				sc = j;
			}
		}
	}

	int p;
	cin >> p;
	TMoveCounts initialDogs;
	cin >> initialDogs.u >> initialDogs.d >> initialDogs.l >> initialDogs.r;
	const int MOD = 1000000007;

	const int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	vector<vector<vector<int>>> prev, next;
	Resize(prev, N, M, 1 + p / 2);
	Resize(next, N, M, 1 + p / 2);
	prev[sr][sc][0] = 1;
	for (int nMoves = 1; nMoves <= p; ++nMoves) {
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				for (int rowReturns = 0; rowReturns <= p / 2; ++rowReturns) {
					if (prev[r][c][rowReturns] == 0) {
						continue;
					}

					for (int iDir = 0; iDir < 4; ++iDir) {
						int nr = r + dir[iDir][0];
						int nc = c + dir[iDir][1];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
							continue;
						}

						if (a[nr][nc] == 'L') {
							continue;
						}

						int newReturns = rowReturns;
						if ((r > sr && nr < r) || (r < sr && nr > r)) {
							++newReturns;
						}

						auto mv = CountMoves(sr, sc, nr, nc, newReturns, nMoves);
						if (initialDogs.u >= mv.u && initialDogs.d >= mv.d && initialDogs.l >= mv.l && initialDogs.r >= mv.r) {
							next[nr][nc][newReturns] = (next[nr][nc][newReturns] + prev[r][c][rowReturns]) % MOD;
						}
					}
				}
			}
		}


		next.swap(prev);
		for (auto& v1 : next) {
			for (auto& v2 : v1) {
				v2.assign(1 + p / 2, 0);
			}
		}
	}

	int res = 0;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			for (int rowReturns = 0; rowReturns <= p / 2; ++rowReturns) {
				res = (res + prev[r][c][rowReturns]) % MOD;
			}
		}
	}
	cout << res;
}



void SolveHackerrankGuardiansOfTheLunatics2() {
	cin.sync_with_stdio(false);
	size_t T;
	cin >> T;
	vector<long long> p;
	p.reserve(100000);

	vector<long long> f;
	f.reserve(100000);

	vector<pair<long long, size_t>> h;
	h.resize(100000);
	for (size_t iTest = 0; iTest < T; ++iTest) {
		size_t P, Q;
		cin >> P >> Q;
		p.resize(P);
		for (size_t i = 0; i < P; ++i) {
			cin >> p[i];
		}
		f.resize(P);

		for (size_t iQuery = 0; iQuery < Q; ++iQuery) {
			size_t k;
			cin >> k;			
			long long runningSum = 0;
			for (size_t i = 0; i < k; ++i) {
				runningSum += p[i];
			}

			for (size_t i = 0; i < k; ++i) {
				f[i] = runningSum;
				h[i] = { runningSum, i };
			}

			size_t heapSize = k;
			for (size_t i = k; i < P; ++i) {
				runningSum += p[i];
				runningSum -= p[i - k];

				while (h[0].second + k < i) {
					pop_heap(h.begin(), h.begin() + heapSize, greater<pair<long long, size_t>>());
					--heapSize;
				}

				f[i] = h[0].first + runningSum;
				h[heapSize] = { f[i], i };
				++heapSize;
				push_heap(h.begin(), h.begin() + heapSize, greater<pair<long long, size_t>>());
			}

			cout << f.back() << "\n";
		}
	}
}

void InitDpData(vector<array<int, 9>>& data, size_t nStates) {
	array<int, 9> a;
	for (auto& x : a) {
		x = numeric_limits<int>::max();
	}

	data.assign(nStates, a);
}

int IntAbs(int x) {
	return (x > 0) ? x : -x;
}

void SolveCF983C() { 

	size_t n;
	cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		--a[i];
		--b[i];
	}

	using TPassengers = array<int, 4>;

	vector<TPassengers> liftStates;
	for (int i = 0; i <= 9; ++i) {
		for (int j = i; j <= 9; ++j) {
			for (int k = j; k <= 9; ++k) {
				for (int l = k; l <= 9; ++l) {
					liftStates.push_back({ i, j, k, l });
				}
			}
		}
	}

	size_t nStates = liftStates.size();
	vector<size_t> passengerCount;
	for (const auto& state : liftStates) {
		passengerCount.push_back(count_if(state.begin(), state.end(), [](const auto& dst) {return dst < 9; }));
	}
	vector<array<size_t, 9>> addDestStateIndex(nStates);
	for (size_t i = 0; i < nStates; ++i) {
		for (size_t j = 0; j < 9; ++j) {
			if (passengerCount[i] == 4) {
				addDestStateIndex[i][j] = numeric_limits<size_t>::max();
			} else {
				auto tmpState = liftStates[i];
				tmpState[3] = j;
				sort(tmpState.begin(), tmpState.end());
				addDestStateIndex[i][j] = distance(liftStates.begin(), find(liftStates.begin(), liftStates.end(), tmpState));
			}
		}
	}

	vector<array<size_t, 4>> unloadStateIndex(nStates);
	for (size_t i = 0; i < nStates; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			if (j < passengerCount[i]) {
				auto tmpState = liftStates[i];
				tmpState[j] = 9;
				sort(tmpState.begin(), tmpState.end());
				unloadStateIndex[i][j] = distance(liftStates.begin(), find(liftStates.begin(), liftStates.end(), tmpState));
			} else {
				unloadStateIndex[i][j] = numeric_limits<size_t>::max();
			}
		}
	}

	vector<array<int, 9>> oldState, newState;
	InitDpData(oldState, nStates);
	oldState[nStates - 1][0] = 0;
	for (size_t iPassenger = 0; iPassenger < n; ++iPassenger) {
		InitDpData(newState, nStates);
		

		for (size_t i = 0; i < nStates; ++i) {
			if (passengerCount[i] == 4) {
				continue;
			}
			for (int j = 0; j < 9; ++j) {
				if (oldState[i][j] == numeric_limits<int>::max()) {
					continue;
				}

				auto s2 = addDestStateIndex[i][b[iPassenger]];
				newState[s2][a[iPassenger]] = min(newState[s2][a[iPassenger]], oldState[i][j] + 1 + IntAbs(a[iPassenger] - j));
			}
		}

		

		for (size_t nUnloads = 0; nUnloads < 4; ++nUnloads) {
			for (size_t i = 0; i < nStates; ++i) {
				for (int j = 0; j < 9; ++j) {
					if (newState[i][j] == numeric_limits<int>::max()) {
						continue;
					}

					for (size_t k = 0; k < passengerCount[i]; ++k) {
						auto s2 = unloadStateIndex[i][k];
						auto dstFloor = liftStates[i][k];
						newState[s2][dstFloor] = min(newState[s2][dstFloor], newState[i][j] + 1 + IntAbs(j - dstFloor));
					}
				}
			}
		}

		oldState.swap(newState);
	}

	int res = numeric_limits<int>::max();
	for (size_t i = 0; i < 9; ++i) {
		res = min(res, oldState[nStates - 1][i]);
	}

	cout << res;
}

int main() {
	SolveCF983C();
	return 0;
}
