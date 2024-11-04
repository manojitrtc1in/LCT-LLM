#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <functional>
#include <numeric>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define trav(a, x) for(auto& a : x)
#define debug(x) cerr << #x << " = " << x << endl;
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

template<typename T>
void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T>
void ckmax(T& a, const T& b) { a = max(a, b); }
template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T>
T mod(T a, T b) { return (a % b + b) % b; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

const int MAX_STACK_SIZE = 128;

class C {
private:
    bool FIRST_INPUT_STRING = false;
    bool MULTIPLE_TESTS = true;
    bool ONLINE_JUDGE = !ifstream("input.txt").good();
    int MODULO = 1000 * 1000 * 1000 + 7;

    int n, k;
    vector<int> a;

    struct Point {
        int x, y;
        Point(int x, int y) : x(x), y(y) {}
    };

    Point getAnswer(int n, vector<int>& a, int limit) {
        const int MULTIPLIER = 50;
        limit /= MULTIPLIER;

        for (int i = 0; i < n; ++i) a[i] /= MULTIPLIER;

        int onesCount = 0, twosCount = 0;
        for (int v : a) {
            if (v == 1) ++onesCount;
            else ++twosCount;
        }

        vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
        for (int i = 0; i <= n; ++i) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MODULO;
            }
        }

        const int FROM_SIDE = 0, TO_SIDE = 1;
        const int INF = INF / 3;

        vector<vector<vector<int>>> distances(2, vector<vector<int>>(onesCount + 1, vector<int>(twosCount + 1, INF)));
        vector<vector<vector<long long>>> ways(2, vector<vector<long long>>(onesCount + 1, vector<long long>(twosCount + 1)));

        distances[FROM_SIDE][onesCount][twosCount] = 0;
        ways[FROM_SIDE][onesCount][twosCount] = 1;

        queue<tuple<int, int, int>> q;
        q.push(make_tuple(FROM_SIDE, onesCount, twosCount));

        while (!q.empty()) {
            int fromSide, fromOnes, fromTwos;
            tie(fromSide, fromOnes, fromTwos) = q.front();
            q.pop();

            int fromDistance = distances[fromSide][fromOnes][fromTwos];
            long long fromWays = ways[fromSide][fromOnes][fromTwos];
            int fromNextDistance = fromDistance + 1;

            int nextSide = FROM_SIDE + TO_SIDE - fromSide;

            if (fromSide == FROM_SIDE) {
                for (int deltaOnes = 0; deltaOnes <= fromOnes; ++deltaOnes) {
                    for (int deltaTwos = 0; deltaTwos <= fromTwos; ++deltaTwos) {
                        if (deltaOnes + deltaTwos == 0) continue;
                        if (deltaOnes + 2 * deltaTwos > limit) continue;

                        int nextOnes = fromOnes - deltaOnes;
                        int nextTwos = fromTwos - deltaTwos;

                        int nextDistance = distances[nextSide][nextOnes][nextTwos];

                        if (nextDistance < fromNextDistance) continue;

                        long long fromNextWays = (fromWays * c[fromOnes][deltaOnes] % MODULO * c[fromTwos][deltaTwos] % MODULO) % MODULO;

                        if (nextDistance > fromNextDistance) {
                            nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance;
                            q.push(make_tuple(nextSide, nextOnes, nextTwos));
                        }

                        if (nextDistance == fromNextDistance) {
                            ways[nextSide][nextOnes][nextTwos] = (ways[nextSide][nextOnes][nextTwos] + fromNextWays) % MODULO;
                        }
                    }
                }
            }
            else {
                int toOnes = onesCount - fromOnes;
                int toTwos = twosCount - fromTwos;

                for (int deltaOnes = 0; deltaOnes <= toOnes; ++deltaOnes) {
                    for (int deltaTwos = 0; deltaTwos <= toTwos; ++deltaTwos) {
                        if (deltaOnes + deltaTwos == 0) continue;
                        if (deltaOnes + 2 * deltaTwos > limit) continue;

                        int nextOnes = fromOnes + deltaOnes;
                        int nextTwos = fromTwos + deltaTwos;

                        int nextDistance = distances[nextSide][nextOnes][nextTwos];

                        if (nextDistance < fromNextDistance) continue;

                        long long fromNextWays = (fromWays * c[toOnes][deltaOnes] % MODULO * c[toTwos][deltaTwos] % MODULO) % MODULO;

                        if (nextDistance > fromNextDistance) {
                            nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance;
                            q.push(make_tuple(nextSide, nextOnes, nextTwos));
                        }

                        if (nextDistance == fromNextDistance) {
                            ways[nextSide][nextOnes][nextTwos] = (ways[nextSide][nextOnes][nextTwos] + fromNextWays) % MODULO;
                        }
                    }
                }
            }
        }

        int distance = distances[TO_SIDE][0][0];
        if (INF == distance) {
            return Point(-1, 0);
        }
        else {
            return Point(distance, ways[TO_SIDE][0][0]);
        }
    }

public:
    void solve() {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        Point answer = getAnswer(n, a, k);

        cout << answer.x << endl;
        cout << answer.y << endl;
    }

    void run() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (ONLINE_JUDGE) {
            solve();
        }
        else {
            do {
                try {
                    solve();
                }
                catch (const EOFException& e) {
                    break;
                }
                catch (const exception& e) {
                    if (FIRST_INPUT_STRING) break;
                    else throw e;
                }
            } while (MULTIPLE_TESTS);
        }
    }
};

int main() {
    C solver;
    solver.run();
    return 0;
}
