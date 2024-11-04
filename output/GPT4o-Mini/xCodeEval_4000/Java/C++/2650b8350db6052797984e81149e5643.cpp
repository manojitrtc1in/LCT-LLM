#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <fstream>

using namespace std;

class FastWriter {
    stringstream out;
public:
    void p(const string &s) { out << s; }
    void p(const char *format, ...) {
        va_list args;
        va_start(args, format);
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), format, args);
        out << buffer;
        va_end(args);
    }
    void pp(const vector<int> &args) {
        for (int ob : args) {
            out << ob << " ";
        }
        out << "\n";
    }
    void println(long long x) { out << x << "\n"; }
    void close() { cout << out.str(); }
};

class FastScanner {
    ifstream sin;
public:
    FastScanner() : sin(cin.rdbuf()) {}
    FastScanner(const string &filename) : sin(filename) {}
    
    bool hasNext() {
        return !sin.eof();
    }
    
    string next() {
        string s;
        sin >> s;
        return s;
    }
    
    long long longNext() {
        long long n;
        sin >> n;
        return n;
    }
    
    int intNext() {
        int n;
        sin >> n;
        return n;
    }
    
    vector<int> nextIntArray(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = intNext();
        }
        return a;
    }
};

int main() {
    FastScanner in;
    FastWriter out;

    string lng = in.next();
    string sht = in.next();
    int n = lng.length();
    int m = sht.length();
    vector<int> leftmost(m + 1);
    vector<int> rightmost(m + 1);
    rightmost[m] = n;

    int idx = 0;
    for (int i = 0; i < m; i++) {
        while (sht[i] != lng[idx]) idx++;
        leftmost[i] = idx;
        idx++;
    }
    idx = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (sht[i] != lng[idx]) idx--;
        rightmost[i] = idx;
        idx--;
    }

    int ans = rightmost[0];
    for (int i = 0; i < m; i++)
        ans = max(ans, rightmost[i + 1] - leftmost[i] - 1);
    out.println(ans);

    out.close();
    return 0;
}