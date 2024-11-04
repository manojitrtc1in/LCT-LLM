#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

class PairInt {
public:
    int X, Y;

    PairInt(int X, int Y) : X(X), Y(Y) {}

    PairInt add(PairInt b) {
        return PairInt(X + b.X, Y + b.Y);
    }

    PairInt sub(PairInt b) {
        return PairInt(X - b.X, Y - b.Y);
    }

    bool operator<(const PairInt& o) const {
        if (X != o.X)
            return X < o.X;
        return Y < o.Y;
    }
};

class MyMath {
public:
    static vector<int> sieve(int n) {
        vector<int> pr(n + 1, 1);
        vector<int> prime;
        pr[0] = pr[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (pr[i] == 1) {
                prime.push_back(i);
                for (long long j = (long long)i * i; j <= n; j += i)
                    pr[j] = 0;
            }
        }
        return prime;
    }

    static int GCD(int a, int b) {
        return b != 0 ? GCD(b, a % b) : a;
    }

    static int add(int a, int b, int MOD) {
        return ((a + b) % MOD + MOD) % MOD;
    }

    static int mul(int a, int b, int MOD) {
        return ((long long)a * b % MOD + MOD) % MOD;
    }
};

class MyInput {
    istream& in;

public:
    MyInput(istream& inputStream) : in(inputStream) {}

    string next() {
        string s;
        in >> s;
        return s;
    }

    int nextInt() {
        int x;
        in >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        in >> x;
        return x;
    }
};

class Solver {
    static int zone;
    static int x1, y1, x2, y2, m;

public:
    void solve(MyInput& in, ostream& out, int testCase) {
        m = in.nextInt();
        int h1 = in.nextInt();
        int a1 = in.nextInt();
        x1 = in.nextInt();
        y1 = in.nextInt();

        int h2 = in.nextInt();
        int a2 = in.nextInt();
        x2 = in.nextInt();
        y2 = in.nextInt();

        zone = 1;
        int r1 = cycleFinding(h1).Y;
        int mu1 = cycleFinding(h1).X;

        zone = 2;
        int r2 = cycleFinding(h2).Y;
        int mu2 = cycleFinding(h2).X;

        bool can = true;

        zone = 1;
        int len1 = 0;
        while (h1 != a1) {
            h1 = f(h1);
            len1++;
            if (len1 > m) {
                can = false;
                break;
            }
        }

        zone = 2;
        int len2 = 0;
        while (h2 != a2) {
            h2 = f(h2);
            len2++;
            if (len2 > m) {
                can = false;
                break;
            }
        }

        int ans = -2;
        if (mu1 > len1) {
            if (mu2 > len2) {
                if (len1 == len2) {
                    ans = len1;
                } else {
                    can = false;
                }
            } else {
                int temp = len1 - len2;
                if (temp % r2 == 0 && temp >= 0) {
                    ans = len1;
                } else {
                    can = false;
                }
            }
        } else {
            if (mu2 > len2) {
                int temp = len2 - len1;
                if (temp % r1 == 0 && temp >= 0) {
                    ans = len2;
                } else {
                    can = false;
                }
            }
        }

        if (ans != -2) {
            out << ans << endl;
            return;
        }

        int M = len2 - len1;
        int gcd = MyMath::GCD(r1, r2);
        if (M % gcd != 0) {
            can = false;
        }

        if (can) {
            for (int k = 0; ; k++) {
                long long kPrim = ((long long)r1 * k - M) / r2;
                if (kPrim < 0) {
                    continue;
                }
                if ((long long)r1 * k - (long long)r2 * kPrim == M) {
                    out << ((long long)r1 * k + len1) << endl;
                    return;
                }
            }
        }

        out << -1 << endl;
    }

    PairInt cycleFinding(int a) {
        int mu, lambda;
        int turtle = f(a);
        int hare = f(turtle);
        while (turtle != hare) {
            turtle = f(turtle);
            hare = f(f(hare));
        }
        mu = 0;
        turtle = a;
        while (turtle != hare) {
            turtle = f(turtle);
            hare = f(hare);
            mu++;
        }
        lambda = 1;

        hare = f(turtle);
        while (turtle != hare) {
            hare = f(hare);
            lambda++;
        }
        return PairInt(mu, lambda);
    }

    int f(int h) {
        if (zone == 1) {
            return MyMath::add(MyMath::mul(x1, h, m), y1, m);
        } else {
            return MyMath::add(MyMath::mul(x2, h, m), y2, m);
        }
    }
};

int Solver::zone;
int Solver::x1, Solver::y1, Solver::x2, Solver::y2, Solver::m;

int main() {
    MyInput in(cin);
    ostream& out = cout;
    Solver solver;

    int test = 1;
    while (true) {
        try {
            solver.solve(in, out, test++);
            out.flush();
        } catch (...) {
            out.flush();
            break;
        }
    }

    out.flush();
    return 0;
}
