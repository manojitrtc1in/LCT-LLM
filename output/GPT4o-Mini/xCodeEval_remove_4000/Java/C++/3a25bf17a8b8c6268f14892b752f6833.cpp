#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <random>
#include <cassert>
#include <string>
#include <stack>

using namespace std;

const int id33 = 1000000007;
const double epsilon = 0.00000001;
bool isPrime[1000001];
int id25[1000001];

class FastReader {
public:
    FastReader() {}

    string next() {
        string s;
        cin >> s;
        return s;
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }

    double nextDouble() {
        double x;
        cin >> x;
        return x;
    }

    char nextChar() {
        char c;
        cin >> c;
        return c;
    }

    vector<int> id15(int n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }

    vector<double> id38(int n) {
        vector<double> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = nextDouble();
        return arr;
    }

    vector<long long> id42(int n) {
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = nextLong();
        return arr;
    }

    vector<vector<int>> id19(int n, int m) {
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                grid[i][j] = nextInt();
        }
        return grid;
    }
};

class Point {
public:
    long long x, y, z, id;

    Point() : x(0), y(0), z(0), id(0) {}

    Point(long long x, long long y, long long z, long long id) : x(x), y(y), z(z), id(id) {}

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

class UGraph {
private:
    vector<unordered_set<int>> adj;
    int E;

public:
    UGraph(int V) : E(0) {
        adj.resize(V);
    }

    void addEdge(int from, int to) {
        if (adj[from].count(to)) return;
        E++;
        adj[from].insert(to);
        adj[to].insert(from);
    }

    const unordered_set<int>& adjList(int from) const {
        return adj[from];
    }

    int degree(int v) const {
        return adj[v].size();
    }

    int V() const {
        return adj.size();
    }

    int E() const {
        return E;
    }

    static void dfsMark(int current, vector<bool>& marked, const UGraph& g) {
        if (marked[current]) return;

        marked[current] = true;
        for (int adjc : g.adjList(current))
            dfsMark(adjc, marked, g);
    }

    static void dfsMark(int current, int from, vector<long long>& distTo, vector<bool>& marked, const UGraph& g, vector<int>& endPoints) {
        if (marked[current]) return;

        marked[current] = true;
        if (from != -1)
            distTo[current] = distTo[from] + 1;
        const auto& adj = g.adjList(current);
        int id36 = 0;
        for (int adjc : adj) {
            if (marked[adjc]) id36++;
            dfsMark(adjc, current, distTo, marked, g, endPoints);
        }

        if (id36 == adj.size())
            endPoints.push_back(current);
    }

    static vector<int> connectedComponents(const UGraph& g) {
        int n = g.V();
        vector<int> componentId(n, -1);
        int colorCtr = 0;
        for (int i = 0; i < n; i++) {
            if (componentId[i] != -1) continue;
            dfsMark(i, componentId, colorCtr, g);
            colorCtr++;
        }

        return componentId;
    }
};

int check(char* tgt, char* src) {
    int n = strlen(tgt);
    if (strlen(src) != n) return 0;

    char xDig = 0;
    for (int i = 0; i < n; i++) {
        if (src[i] == 'X') {
            if (xDig == 0) {
                xDig = tgt[i];
            } else {
                if (tgt[i] != xDig) return 0;
            }
        }
    }

    if (tgt[0] == '0') return 0;

    for (int i = 0; i < n; i++) {
        if (src[i] != '_' && src[i] != 'X' && tgt[i] != src[i]) return 0;
    }
    return 1;
}

int main() {
    FastReader fr;
    int t = 1;

    for (int tc = 0; tc < t; tc++) {
        string sOG = fr.next();
        int n = sOG.length();
        char s[n + 1];
        strcpy(s, sOG.c_str());

        if (n == 1) {
            if (s[0] == '0' || s[0] == '_' || s[0] == 'X')
                cout << 1 << endl;
            else
                cout << 0 << endl;
            continue;
        }

        int answer = 0;

        {
            char s1[n + 1];
            strcpy(s1, s);
            bool shit = (s1[n - 1] != '_' && s1[n - 1] != 'X' && s1[n - 1] != '0');
            shit |= (s1[n - 2] != '_' && s1[n - 2] != 'X' && s1[n - 2] != '0');

            if (!shit) {
                if (s1[n - 1] == 'X' || s1[n - 2] == 'X')
                    for (int i = 0; i < n; i++)
                        if (s1[i] == 'X')
                            s1[i] = '0';
                s1[n - 1] = '0';
                s1[n - 2] = '0';

                answer += check("00", s1);

                for (int num = 0; num < 1e6; num++) {
                    char tgt[10];
                    sprintf(tgt, "%d00", num);
                    answer += check(tgt, s1);
                }
            }
        }

        {
            char s1[n + 1];
            strcpy(s1, s);
            bool shit = (s1[n - 1] != '_' && s1[n - 1] != 'X' && s1[n - 1] != '5');
            shit |= (s1[n - 2] != '_' && s1[n - 2] != 'X' && s1[n - 2] != '2');
            shit |= (s1[n - 1] == 'X' && s1[n - 2] == 'X');

            if (!shit) {
                if (s1[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s1[i] == 'X')
                            s1[i] = '5';
                } else if (s1[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s1[i] == 'X')
                            s1[i] = '2';
                }

                s1[n - 1] = '5';
                s1[n - 2] = '2';

                answer += check("25", s1);

                for (int num = 0; num < 1e6; num++) {
                    char tgt[10];
                    sprintf(tgt, "%d25", num);
                    answer += check(tgt, s1);
                }
            }
        }

        {
            char s1[n + 1];
            strcpy(s1, s);
            bool shit = (s1[n - 1] != '_' && s1[n - 1] != 'X' && s1[n - 1] != '0');
            shit |= (s1[n - 2] != '_' && s1[n - 2] != 'X' && s1[n - 2] != '5');
            shit |= (s1[n - 1] == 'X' && s1[n - 2] == 'X');

            if (!shit) {
                if (s1[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s1[i] == 'X')
                            s1[i] = '0';
                } else if (s1[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s1[i] == 'X')
                            s1[i] = '5';
                }

                s1[n - 1] = '0';
                s1[n - 2] = '5';

                answer += check("50", s1);

                for (int num = 0; num < 1e6; num++) {
                    char tgt[10];
                    sprintf(tgt, "%d50", num);
                    answer += check(tgt, s1);
                }
            }
        }

        {
            char s1[n + 1];
            strcpy(s1, s);
            bool shit = (s1[n - 1] != '_' && s1[n - 1] != 'X' && s1[n - 1] != '5');
            shit |= (s1[n - 2] != '_' && s1[n - 2] != 'X' && s1[n - 2] != '7');
            shit |= (s1[n - 1] == 'X' && s1[n - 2] == 'X');

            if (!shit) {
                if (s1[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s1[i] == 'X')
                            s1[i] = '5';
                } else if (s1[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s1[i] == 'X')
                            s1[i] = '7';
                }

                s1[n - 1] = '5';
                s1[n - 2] = '7';

                answer += check("75", s1);

                for (int num = 0; num < 1e6; num++) {
                    char tgt[10];
                    sprintf(tgt, "%d75", num);
                    answer += check(tgt, s1);
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}
