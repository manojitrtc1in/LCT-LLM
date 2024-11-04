#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <functional>
#include <ctype.h>
#include <map>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <deque>

using namespace std;

#define Cout cout
#define Endl '\n'

template<class T>
using TMatrix = vector<vector<T>>;
template<class T>
using TVector = vector<T>;
using TString = string;

void read(int& x) {
    scanf("%i", &x);
}
void write(const int x) {
    printf("%i", x);
}
void read(long long& x) {
    scanf("%lli", &x);
}
void write(const long long& x) {
    printf("%lli", x);
}
void read(double& x) {
    scanf("%lf", &x);
}
void write(const double& x) {
    printf("%lf", x);
}
void read(char& c, bool whiteSpaces = false) {
    while (1) {
        c = getchar();
        if (whiteSpaces || !isspace(c)) {
            break;
        }
    }
}
void write(const char c) {
    printf("%c", c);
}
void read(TString& result, bool untilEol = false) {
    result.clear();
    char c;
    if (!untilEol) {
        while (1) {
            c = getchar();
            if (!isspace(c)) break;
        }
        result.push_back(c);
    }
    while (1) {
        c = getchar();
        if (c == '\n' || (!untilEol && isspace(c))) break;
        result.push_back(c);
    }
}
void write(const TString& s) {
    printf("%s", s.c_str());
}
void writeYES(const bool condition) {
    printf("%s\n", condition ? "YES" : "NO");
}
void writeYes(const bool condition) {
    printf("%s\n", condition ? "Yes" : "No");
}
template<class T>
void writeIf(const bool condition, const T& forTrue, const T& forFalse) {
    cout << (condition ? forTrue : forFalse) << endl;
}
template<class T1, class T2>
void read(pair<T1, T2>& x) {
    read(x.first);
    read(x.second);
}
template<class T1, class T2>
void write(pair<T1, T2>& x) {
    write(x.first);
    write(' ');
    write(x.second);
}
template<class T>
void writeln(const T& x) {
    write(x);
    write('\n');
}
template<class T1, class T2>
void read(T1& x1, T2& x2) {
    read(x1); read(x2);
}
template<class T1, class T2, class T3>
void read(T1& x1, T2& x2, T3& x3) {
    read(x1); read(x2); read(x3);
}
template<class T1, class T2, class T3, class T4>
void read(T1& x1, T2& x2, T3& x3, T4& x4) {
    read(x1); read(x2); read(x3); read(x4);
}
template<class T1, class T2, class T3, class T4, class T5>
void read(T1& x1, T2& x2, T3& x3, T4& x4, T5& x5) {
    read(x1); read(x2); read(x3); read(x4); read(x5);
}
template<class T1, class T2, class T3, class T4, class T5, class T6>
void read(T1& x1, T2& x2, T3& x3, T4& x4, T5& x5, T6& x6) {
    read(x1); read(x2); read(x3); read(x4); read(x5); read(x6);
}
template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
void read(T1& x1, T2& x2, T3& x3, T4& x4, T5& x5, T6& x6, T7& x7) {
    read(x1); read(x2); read(x3); read(x4); read(x5); read(x6); read(x7);
}

namespace NMatrix {
    template<class T>
    void Read(TMatrix <T>& matrix, int n = -1, int m = -1) {
        if (n == -1) {
            read(n, m);
        } else if (m == -1) {
            m = n;
        }
        matrix.clear();
        matrix.resize(n, TVector<T>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                read(matrix[i][j]);
            }
        }
    }

    template<class T>
    void Write(const TMatrix<T>& v, const TString del = " ") {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j];
                if (j < v[i].size() - 1) {
                    cout << del;
                }
            }
            cout << endl;
        }
    }

    template<class T>
    T Sum(const TMatrix<T>& matrix) {
        T result = 0;
        for (const auto& row: matrix) {
            for (const auto& elem: row) {
                result += elem;
            }
        }

        return result;
    }

    template<class T>
    TMatrix<T> Sum(const TMatrix<T>& matrix1, const TMatrix<T>& matrix2) {
        TMatrix<T> result(matrix1.size(), TVector<T>(matrix1[0].size()));
        for (size_t i = 0; i < matrix1.size(); ++i) {
            for (size_t j = 0; j < matrix1[i].size(); ++j) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return move(result);
    }

    template<class T>
    TMatrix<T> Transpose(const TMatrix<T>& matrix) {
        TMatrix<T> result(matrix[0].size(), TVector<T>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return move(result);
    }
}

namespace NVector {
    template <class T>
    void Read(TVector<T>& v, int length = -1) {
        if (length == -1) {
            read(length);
        }
        v.resize(length);
        for (auto& elem: v) {
            read(elem);
        }
    }

    template <class T>
    void Write(const TVector<T>& v, TString del = " ", bool needEndl = true) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) {
                cout << del;
            }
        }
        if (needEndl) {
            cout << endl;
        }
    }

    template<class T>
    TVector<T> Filter(const TVector<T>& v, std::function<bool(T)> filter) {
        TVector<T> result;
        for (const auto& elem: v) {
            if (filter(elem)) {
                result.push_back(elem);
            }
        }
        return move(result);
    }

    template<class T>
    T Max(const TVector<T>& v) {
        return *max_element(v.begin(), v.end());
    }

    template<class T>
    void Sort(TVector<T>& v) {
        sort(v.begin(), v.end());
    }

    template<class T>
    void SortR(TVector<T>& v) {
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
    }

    template<class T>
    void Reverse(TVector<T>& v) {
        reverse(v.begin(), v.end());
    }

    template<class T>
    T Min(const TVector<T>& v) {
        return *min_element(v.begin(), v.end());
    }

    template<class T>
    T Sum(const TVector<T>& v) {
        T result = 0;
        for (const auto& elem: v) {
            result += elem;
        }
        return result;
    }

    template<class T>
    T Mult(const TVector<T>& v) {
        T result = 1;
        for (const auto& elem: v) {
            result *= elem;
        }
        return result;
    }

    template<class T>
    TVector<int> FromInt(T number) {
        TVector<int> v;
        while (number) {
            v.push_back(number % 10);
            number /= 10;
        }
        reverse(v.begin(), v.end());
        return move(v);
    }

    template<class T>
    T ToInt(const TVector<int>& v) {
        T ans = 0;
        for (const auto e: v) {
            ans = ans * 10 + e;
        }
        return ans;
    }

    template<class T>
    T Mex(const TVector<T>& v) {
        unordered_set<T> s(v.begin(), v.end());
        T value;
        for (value = 1; s.find(value) != s.end(); value += 1) {}
        return value;
    }

    template<class T>
    bool Contains(const TVector<T>& v, const T& searchedElem) {
        for (const auto& elem: v) {
            if (elem == searchedElem) {
                return true;
            }
        }
        return false;
    }
}

namespace NMath {
    template<class T>
    T Gcd(T x, T y) {
        while (x) {
            y %= x;
            swap(x, y);
        }
        return y;
    }

    template<class T>
    T Lcm(T x, T y) {
        return (x / Gcd(x, y)) * y;
    }

    template<class T>
    T Gcd(const vector<T>& v) {
        T ans = v.front();
        for (const auto& elem: v) {
            ans = Gcd(ans, elem);
        }
        return ans;
    }

    template<class T>
    T Lcm(const vector<T>& v) {
        T ans = v.front();
        for (const auto& elem: v) {
            ans = Lcm(ans, elem);
        }
        return ans;
    }

    int GcdEx(const int a, const int b, int& x, int& y) {
        if (!a) {
            x = 0;
            y = 1;
            return b;
        }
        int x1, y1;
        int d = GcdEx(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }

    int CalcInverseNumber(const int number, const int mod) {
        int x, y;
        int g = GcdEx(number, mod, x, y);
        if (g != 1) {
            return -1;
        }
        return x = (x % mod + mod) % mod;
    }

    template<class T>
    T Factorial(T n) {
        T result = 1;
        while (n > 0) {
            result *= n--;
        }
    }

    template<class T>
    T FactorialWithMod(T n, T mod) {
        if (n >= mod) {
            return 0;
        }
        T result = 1;
        while (n > 0) {
            result = (result * n) % mod;
            --n;
        }

        return result;
    }

    template<class T1, class T2>
    T1 BinPow(T1 value, T2 extent) {
        T1 res = 1;
        while (extent > 0) {
            if (extent & 1) {
                res *= value;
            }

            extent >>= 1;
            value *= value;
        }

        return res;
    }

    template<class T1, class T2>
    T1 BinPowWithMod(T1 value, T2 extent, T1 mod) {
        T1 res = 1;
        value %= mod;
        while (extent > 0) {
            if (extent & 1) {
                res = (value * res) % mod;
            }

            extent >>= 1;
            value = (value*value) % mod;
        }

        return res;
    }

    template<class T>
    bool IsPrime(T value) {
        for (T i = 2; i * i <= value; ++i) {
            if (value % i == 0) {
                return false;
            }
        }

        return true;
    }

    template<class T>
    T Min(const T& a, const T& b) {
        return a < b ? a : b;
    }

    template<class T>
    T Max(const T& a, const T& b) {
        return a > b ? a : b;
    }

    template<class T>
    T Abs(const T& value) {
        return value >= 0 ? value : -value;
    }

    TVector<int> Factorize(int value) {
        TVector<int> res;
        for (int i = 2; i * i <= value; i++) {
            while (value % i == 0) {
                res.push_back(i);
                value /= i;
            }
        }
        if (value > 1) {
            res.push_back(value);
        }

        return res;
    }

    template<class T>
    TVector<int> ToKSystem(T value, const int numberOfSystem) {
        TVector<int> result;
        while (value > 0) {
            result.push_back(value % numberOfSystem);
            value /= numberOfSystem;
        }
        if (result.empty()) result.push_back(0);
        reverse(result.begin(), result.end());
        return result;
    }

    template<class T>
    T FromKSystem(const TVector<int> value, const int numberOfSystem) {
        T result = 0;
        T mult = 1;
        for (int i = value.size() - 1; i >= 0; --i) {
            result += mult * value[i];
            mult *= numberOfSystem;
        }

        return result;
    }

    double Log(const double a, const double b) {
        return log(b) / log(a);
    }
}

namespace NString {
    TVector<TString> Split(const TString& value, const char delimiter = ' ', bool skipEmpty = false) {
        TString current = "";
        TVector<TString> result;
        for (size_t i = 0; i <= value.size(); i++) {
            if (i == value.size() || value[i] == delimiter) {
                if (!skipEmpty || !current.empty()) {
                    result.push_back(current);
                    current.clear();
                }
            } else {
                current.push_back(value[i]);
            }
        }

        return move(result);
    }
    TString ToString(long long value) {
        TString result;
        bool isNegative = false;
        if (value < 0) {
            isNegative = true;
            value = -value;
        }
        if (!value) {
            result.push_back('0');
        }
        while (value > 0) {
            result.push_back((value % 10) + '0');
            value /= 10;
        }
        if (isNegative) {
            result.push_back('-');
        }
        reverse(result.begin(), result.end());
        return result;
    }

    TString ToString(const int value) {
        return ToString(1ll * value);
    }

    long long ToLong(const TString& value) {
        long long result = 0;
        bool isNegative = false;
        auto it = value.begin();
        if (*it == '-') {
            isNegative = true;
            it++;
        }
        for (; it != value.end(); it++) {
            result = result * 10 + (*it) - '0';
        }
        if (isNegative) {
            result = -result;
        }

        return result;
    }

    int ToInt(const TString& value) {
        return static_cast<int>(ToLong(value));
    }

    TString ToUpper(const TString& value) {
        TString result = value;
        for (auto& c: result) {
            c = toupper(c);
        }

        return result;
    }

    TString ToLower(const TString& value) {
        TString result = value;
        for (auto& c: result) {
            c = tolower(c);
        }

        return result;
    }

    bool StartsWith(const TString& first, const TString& second) {
        if (second.size() > first.size()) return false;
        return first.substr(0, second.size()) == second;
    }

    bool EndsWith(const TString& first, const TString& second) {
        if (second.size() > first.size()) return false;
        return first.substr(first.size() - second.size()) == second;
    }
}

int solve();

int main(int argc, char* argv[]) {
    

    

    

    #ifdef LOCALT
        if (argc == 1) {
            return solve();
        }
        TString problemNumber = argv[1];
    
        int _testNumber = 1;
        while (1) {
            TString current_filename_in = "problems_tests/in" + problemNumber + "_" + NString::ToString(_testNumber) + ".txt";
            TString current_filename_out = "problems_tests/out" + problemNumber + "_" + NString::ToString(_testNumber) + ".txt";
            ifstream current_file_in(current_filename_in.c_str());
            if (!current_file_in.good()) break;
            freopen(current_filename_in.c_str(), "r", stdin);
            

            
            _testNumber++;

            solve();
            continue;

            fclose(stdout);
            freopen("CON", "w", stdout);
            cout << "ok" << endl;
            ifstream fOut("output.txt");
            ifstream fTest(current_filename_out.c_str());
            char c1, c2;
            bool isOk = true;
            while (fTest >> c2) {
                if (!(fOut >> c1) || c1 != c2) {
                    isOk = false;
                    break;
                }
            }


            if (isOk) {
                cout << "Test is OK" << endl;
            } else {
                cout << "ERROR!" << endl;
            }
        }
    #else
        return solve();
    #endif

    return 0;
}

int solve() {
    int r, n;
    read(r, n);
    TVector<pair<int, pair<int, int>>> v(n);
    TVector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        read(v[i].first, v[i].second.first, v[i].second.second);
    }
 
    for (int i = 0; i < n; i++) {
        ans[i] = v[i].second.first - 1 + v[i].second.second - 1 <= v[i].first ? 1 : -1000000000;
        for (int j = i - 1; j >= max(0, i - 2010); j--) {
            if (abs(v[i].second.first - v[j].second.first) + abs(v[i].second.second - v[j].second.second) <= v[i].first - v[j].first) {
                ans[i] = max(ans[i], ans[j] + 1);
            }
        }
    }
    

    int res = max(NVector::Max(ans), 0);
    cout << res << endl;
    return 0;
}
