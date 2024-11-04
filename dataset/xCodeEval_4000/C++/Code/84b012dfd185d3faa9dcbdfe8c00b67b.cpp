#include<bits/stdc++.h>

namespace alg {

    

    template<typename _Ty>
    _Ty sqrt(const _Ty& n) {
        _Ty x = 1;
        bool decreased = false;
        while (true) {
            _Ty nx = (x + n / x) / 2;
            if (x == nx || nx > x && decreased) {
                break;
            }
            decreased = nx < x;
            x = nx;
        }
        return x;
    }

    

    template<typename _Ty>
    std::vector<_Ty> eratosthenesSieve(_Ty n) {
        std::vector<bool> prime(n + 1, true);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        std::vector<_Ty> result;
        result.push_back(2);
        for (int i = 3; i <= n; i += 2) {
            if (prime[i]) {
                result.push_back(i);
            }
        }
        return result;
    }

    

    template<typename _Ty>
    bool isPrime(_Ty n) {
        _Ty i;
        for (i = 2; i * i <= n && n % i != 0; i++) {}
        return i * i > n;
    }

    

    

    template<typename _Ty>
    std::vector<std::pair<_Ty, int>> factorize(_Ty N) {
        std::vector<std::pair<_Ty, int>> result;
        for (_Ty i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                result.push_back(std::make_pair(i, 0));
                while (N % i == 0) {
                    result.back().second++;
                    N /= i;
                }
            }
        }
        if (N != 1) {
            result.push_back(std::make_pair(N, 1));
        }
        return result;
    }

    

    template<typename T1, typename T2>
    T1 epow(const T1& a, const T2& n, const T1& mod) {
        if (n == 0) {
            return 1;
        }
        else {
            T1 z = epow(a, n / 2, mod);
            z = (z * z) % mod;

            return (n % 2 == 0) ? z : (z * a) % mod;
        }
    }

    

    template<typename T1, typename T2>
    T1 epow(const T1& a, const T2& n) {
        if (n == 0) {
            return 1;
        }
        else {
            T1 z = epow(a, n / 2);
            z = z * z;

            return (n % 2 == 0 ? z : z * a);
        }
    }

    

    template<typename T>
    T gcd(T a, T b) {
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        }
        return std::max(a, b);
    }

    

    template<typename _Ty>
    _Ty gcd(_Ty a, _Ty b, _Ty& x, _Ty& y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        else {
            _Ty x1, y1;
            _Ty res = gcd(b % a, a, x1, y1);
            x = y1 - (b / a) * x1;
            y = x1;
            return res;
        }
    }

    

    

    

    template<typename _Ty>
    bool solveLDE(_Ty a, _Ty b, _Ty c, _Ty& xg, _Ty& yg, _Ty& g) {
        g = gcd(abs(a), abs(b), xg, yg);
        if (c % g != 0) {
            return false;
        }
        xg *= c / g;
        yg *= c / g;
        xg *= a < 0 ? -1 : 1;
        yg *= b < 0 ? -1 : 1;
        return true;
    }

    

    template<typename T>
    T lcm(const T& a, const T& b) {
        return a * b / gcd(a, b);
    }

    

    

    template<typename _Ty>
    bool squarePres(const _Ty& N, _Ty& a, _Ty& b) {
        for (a = 2; a <= sqrt(N); a++) {
            b = sqrt(N - a * a);
            if (a * a + b * b == N) {
                return true;
            }
        }
        return false;
    }

    

    template<typename _Ty>
    bool reverseElement(_Ty a, _Ty m, _Ty& x) {
        _Ty y;
        _Ty g = gcd(a, m, x, y);
        if (g != 1) {
            return false;
        }
        else {
            x = (x % m + m) % m;
            return true;
        }
    }

    

    template<typename T>
    class fibonacci {

        struct matrix {
            std::vector<std::vector<T>> a;

            matrix() {
                a = { {0, 1}, {1, 1} };
            }
            matrix(const matrix& other) {
                a = other.a;
            }
            matrix mult(const matrix& mult) const {
                matrix res;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        res.a[i][j] = a[i][0] * mult.a[0][j] + a[i][1] * mult.a[1][j];
                    }
                }
                return res;
            }
            matrix mult(const matrix& mult, const T& mod) const {
                matrix res;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        res.a[i][j] = ((a[i][0] * mult.a[0][j]) % mod + (a[i][1] * mult.a[1][j] % mod)) % mod;
                    }
                }
                return res;
            }
        };

        matrix binPow(const matrix& a, const T& n) {
            if (n == 1) {
                return a;
            }
            else {
                matrix z = binPow(a, n / 2);
                z = z.mult(z);

                return n % 2 == 0 ? z : z.mult(a);
            }
        }
        matrix binPow(const matrix& a, const T& n, const T& mod) {
            if (n == 1) {
                return a;
            }
            else {
                matrix z = binPow(a, n / 2, mod);
                z = z.mult(z, mod);

                return n % 2 == 0 ? z : z.mult(a, mod);
            }
        }

    public:

        T get(const T& n) {
            return binPow(matrix(), n).a[0][0];
        }
        T get(const T& n, const T& mod) {
            return binPow(matrix(), n, mod).a[0][0];
        }
    };

    

    template<typename dist_t>
    class dijkstra {

        std::vector<dist_t> Dist;
        std::vector<int> Parent;
        int begin;

    public:

        

        template<typename inf_type>
        dijkstra(const std::vector<std::vector<std::pair<int, dist_t>>>& Graph, size_t newBegin, const inf_type& infinity) {
            begin = newBegin;

            Dist.resize(Graph.size(), static_cast<dist_t>(infinity));
            Dist[begin] = 0;

            Parent.resize(Graph.size());

            std::set<std::pair<dist_t, size_t>> Q;
            Q.insert(std::make_pair(Dist[begin], begin));

            while (!Q.empty()) {
                size_t v = Q.begin()->second;
                Q.erase(Q.begin());

                for (size_t j = 0; j < Graph[v].size(); j++) {
                    size_t to = Graph[v][j].first;
                    dist_t length = Graph[v][j].second, newDist = Dist[v] + length;

                    if (newDist < Dist[to]) {
                        Q.erase(std::make_pair(Dist[to], to));
                        Parent[to] = v;
                        Dist[to] = newDist;
                        Q.insert(std::make_pair(Dist[to], to));
                    }
                }
            }
        }

        

        dist_t getDist(size_t end) const {
            return Dist[end];
        }

        

        std::vector<int> getPath(size_t end) const {
            std::vector<int> res;
            while (end != begin) {
                res.push_back(end);
                end = Parent[end];
            }
            res.push_back(begin);
            std::reverse(res.begin(), res.end());
            return res;
        }
    };

    

    std::vector<int> zFunction(const std::string& str) {
        int n = str.size();
        std::vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r) {
                z[i] = std::min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i, r = i + z[i] - 1;
            }
        }
        return z;
    }

    std::vector<unsigned long long> hashPow;
    

    void updateHashPow(int strLen) {
        if (hashPow.size() < strLen) {
            size_t i = hashPow.size();
            hashPow.resize(strLen);
            if (i == 0) {
                hashPow[0] = 1;
                i++;
            }
            for (; i < strLen; i++) {
                hashPow[i] = hashPow[i - 1] * 53ULL;
            }
        }
    }

    

    char SymbolCode[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 0, 0, 0, 0, 0, 0, 0, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    

    unsigned long long strHash(const std::string& str) {
        updateHashPow(str.size());
        unsigned long long hash = 0;
        for (size_t i = 0; i < str.size(); i++) {
            hash += hashPow[i] * SymbolCode[str[i]];
        }
        return hash;
    }

    

    std::vector<unsigned long long> strHashPref(const std::string& str) {
        updateHashPow(str.size());
        std::vector<unsigned long long> res(str.size());
        for (size_t i = 0; i < str.size(); i++) {
            res[i] = hashPow[i] * SymbolCode[str[i]];
            res[i] += (i ? res[i - 1] : 0);
        }
        return res;
    }

    

    std::vector<int> findSubstr(std::string s, std::string key) {
        auto sHashPref = strHashPref(s);
        auto keyHash = strHash(key);
        std::vector<int> res;
        for (size_t i = 0; i + key.size() - 1 < s.size(); i++) {
            unsigned long long curHash = sHashPref[i + key.size() - 1];
            curHash -= i ? sHashPref[i - 1] : 0;

            

            if (curHash == keyHash * hashPow[i]) {
                res.push_back(i);
            }
        }
        return res;
    }

    

    int cyclicShift(std::string str) {
        str += str;
        int n = str.size(), i = 0, ans = 0;
        while (i < n / 2) {
            ans = i;
            int j = i + 1, k = i;
            while (j < n && str[k] <= str[j]) {
                k = str[k] < str[j] ? i : k + 1;
                j++;
            }
            while (i <= k) {
                i += j - k;
            }
        }
        return ans + 1;
    }

    std::vector<int> preFunction(std::string str) {
        int n = str.size();
        std::vector<int> result(n);
        for (int i = 1; i < n; i++) {
            int j = result[i - 1];
            while (j > 0 && str[i] != str[j]) {
                j = result[j - 1];
            }
            if (str[i] == str[j]) {
                j++;
            }
            result[i] = j;
        }
        return result;
    }
}









template<typename _Ty1, typename _Ty2>
class hashTable {

    

    struct cell {
        _Ty1 key; 

        _Ty2 value; 

        bool free; 


        

        cell() {
            free = true;
        }
        cell(const _Ty1& newKey, const _Ty2& newValue) {
            free = false;
            key = newKey;
            value = newValue;
        }
    };

    cell* A; 

    int length; 

    int count; 


    


    

    int hash(const _Ty1& key) const {
        return key % length;
    }

    

    int sizeInc() const {
        return 1.9 * length + 1.0;
    }

    

    void rebuild() {
        hashTable temp(sizeInc());
        for (int i = 0; i < length; i++) {
            if (!A[i].free) { 

                temp.insert(A[i].key, A[i].value);
            }
        }
        *this = temp;
    }

    

    void copy(const hashTable& source) {
        A = new cell[(length = source.length) + 1];
        count = source.count;
        for (int i = 0; i < length; i++) {
            A[i] = source.A[i];
        }
    }

    

    void zeroing() {
        A = new cell[2];
        length = 1;
        count = 0;
    }

    

    int find(const _Ty1& key) const {
        int index = hash(key);
        

        while (!A[index].free && A[index].key != key) {
            index++;
        }
        return index;
    }

public:

    

    hashTable() {
        zeroing();
    }
    

    hashTable(int newSize) {
        A = new cell[newSize + 1];
        length = newSize;
        count = 0;
    }
    

    hashTable(const hashTable& source) {
        copy(source);
    }
    

    ~hashTable() {
        delete[] A;
    }

    

    void clear() {
        delete[] A;
        zeroing();
    }

    int size() const {
        return count;
    }
    bool empty() const {
        return count == 0;
    }

    hashTable& operator = (const hashTable& source) {
        delete[] A;
        copy(source);
        return *this;
    }

    _Ty2& operator [](const _Ty1& key) {
        int index = find(key);
        if (A[index].free) { 

            if (index == length) { 

                rebuild();
                return this->operator[](key);
            }
            else { 

                A[index] = cell(key, _Ty2());
                count++;
            }
        }
        return A[index].value;
    }

    

    

    void insert(_Ty1 key, _Ty2 value) {
        int index = hash(key);
        while (!A[index].free) {
            if (hash(key) < hash(A[index].key)) { 

                

                std::swap(key, A[index].key);
                std::swap(value, A[index].value);
            }
            index++;
        }
        if (index == length) {
            rebuild();
            insert(key, value);
        }
        else {
            A[index] = cell(key, value);
        }
    }

    

    class iterator {
        int index;
        hashTable* source; 


        

        void findNext() {
            while (index < source->length && source->A[index].free) {
                index++;
            }
        }

    public:

        iterator(int newIndex, hashTable& newSource) {
            index = newIndex;
            source = &newSource;

            findNext();
        }

        void operator ++(int) {
            index++;
            findNext();
        }

        

        _Ty1& getKey() const {
            return source.A[index].key;
        }
        

        _Ty2& getVal() const {
            return source->A[index].value;
        }

        bool operator != (const iterator& Rhs) const {
            return index != Rhs.index;
        }
    };

    iterator begin() {
        return iterator(0, *this);
    }
    iterator end() {
        return iterator(length, *this);
    }
};

using namespace std;
typedef long long ll;
typedef unsigned long ull;

class strHash {
    unsigned long long hash;
public:
    strHash(const string& str) {
        hash = alg::strHash(str);
    }
    strHash() {

    }
    int operator % (int k)const {
        return hash % k;
    }
    bool operator != (const strHash& Rhs) const {
        return hash != Rhs.hash;
    }
};


int main() {
    

    
    int n;
    cin >> n;
    hashTable<strHash, int> M;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (M[str] > 0) {
            cout << str << M[str];
        }
        else {
            cout << "OK";
        }
        cout << "\n";
        M[str]++;
    }

    return 0;
}
