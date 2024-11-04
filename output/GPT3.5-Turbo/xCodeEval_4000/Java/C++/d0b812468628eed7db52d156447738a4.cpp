#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

class IceCave {
    static class Kattio : public ostream {
        private:
            istream& r;
            string line;
            int pos;
            vector<string> tokens;

            void readLine() {
                getline(r, line);
                pos = 0;
                tokens.clear();
                string token;
                for (char c : line) {
                    if (c == ' ') {
                        if (!token.empty()) {
                            tokens.push_back(token);
                            token.clear();
                        }
                    } else {
                        token += c;
                    }
                }
                if (!token.empty()) {
                    tokens.push_back(token);
                }
            }

        public:
            Kattio() : ostream(nullptr), r(cin), line(), pos(0), tokens() {}
            Kattio(istream& i) : ostream(nullptr), r(i), line(), pos(0), tokens() {}

            string nextLine() {
                readLine();
                return line;
            }

            string next() {
                if (pos == tokens.size()) {
                    readLine();
                }
                return tokens[pos++];
            }

            int nextInt() {
                return stoi(next());
            }

            double nextDouble() {
                return stod(next());
            }

            long long nextLong() {
                return stoll(next());
            }
    };

    static Kattio input;
    static ostream& log;
    static vector<vector<long long>> powerSet;
    static long long mod;
    static int dp[][];

    public:
        static void main() {
            int n = input.nextInt();
            long long w = input.nextLong();
            log << bfs(w, n) << "\n";
            log.flush();
        }

        static int bfs(long long w, int n) {
            queue<long long> q;
            q.push(w);
            map<long long, int> h;
            h[w] = 0;
            int min = INT_MAX;
            while (!q.empty()) {
                long long s = q.front();
                q.pop();
                if (n == to_string(s).length()) {
                    return h[s];
                }
                set<int> t;
                string e = to_string(s);
                for (char c : e) {
                    t.insert(c - '0');
                }
                for (int x : t) {
                    long long v = (long long) x * s;
                    if (to_string(v).length() > n) {
                        continue;
                    }
                    if (h.find(v) == h.end()) {
                        h[v] = h[s] + 1;
                        q.push(v);
                    }
                }
            }
            return min == INT_MAX ? -1 : min;
        }
};

Kattio IceCave::input = Kattio();
ostream& IceCave::log = cout;
vector<vector<long long>> IceCave::powerSet = vector<vector<long long>>();
long long IceCave::mod = (long long) (pow(10, 9) + 7);
int IceCave::dp[][];

int main() {
    IceCave::main();
    return 0;
}
