#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

class FastWriter {
    private:
        ostringstream out;
    public:
        void p(const string& str) {
            out << str;
        }
        void pp(long long n) {
            out << n << " ";
        }
        void pp(long long n1, long long n2) {
            out << n1 << " " << n2 << "\n";
        }
        void close() {
            cout << out.str();
        }
};

class FastScanner {
    private:
        istream& sin;
    public:
        FastScanner(istream& input) : sin(input) {}
        
        long long longNext() {
            long long n;
            sin >> n;
            return n;
        }
        
        long long* nextLongArray(int n) {
            long long* a = new long long[n];
            for (int i = 0; i < n; i++) {
                a[i] = longNext();
            }
            return a;
        }
        
        int intNext() {
            int n;
            sin >> n;
            return n;
        }
};

class E {
    public:
        void solver(FastScanner& in, FastWriter& out) {
            long long n = in.intNext();
            long long* ar = in.nextLongArray(3);
            long long* br = in.nextLongArray(3);
            long long mxWins = 0;
            long long mxLosesOrDraw = 0;
            long long draws = 0;
            for (int i = 0; i < 3; i++) {
                mxWins += min(ar[i], br[(i + 1) % 3]);
                long long mxLose = min(br[i], ar[(i + 1) % 3]);
                long long mxDraw = min(br[i], ar[i]);
                mxLosesOrDraw += min(br[i], mxLose + mxDraw);
            }
            out.pp(n - mxLosesOrDraw, mxWins);
            delete[] ar;
            delete[] br;
        }
};

int main() {
    FastScanner in(cin);
    FastWriter out;
    E e;
    e.solver(in, out);
    out.close();
    return 0;
}
