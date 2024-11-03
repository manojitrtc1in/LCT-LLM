#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;

class IO {
public:
    static int readInt() {
        int x;
        cin >> x;
        return x;
    }

    static long long readLong() {
        long long x;
        cin >> x;
        return x;
    }

    static string readString() {
        string s;
        cin >> s;
        return s;
    }

    static vector<int> readArrayInt(int n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        return arr;
    }

    static vector<long long> readArrayLong(int n) {
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        return arr;
    }

    static vector<string> readArrayString(int n) {
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        return arr;
    }

    static void writeArray(const vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static void writeArray(const vector<long long>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static void writeArray(const vector<string>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static void writeInt(int x) {
        cout << x << endl;
    }

    static void writeLong(long long x) {
        cout << x << endl;
    }

    static void writeString(const string& s) {
        cout << s << endl;
    }
};

class math {
public:
    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static float gcd(float a, float b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, fmod(a, b));
    }

    static double gcd(double a, double b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, fmod(a, b));
    }

    static double lcm(double a, double b) {
        return a / gcd(a, b) * b;
    }

    static float lcm(float a, float b) {
        return a / gcd(a, b) * b;
    }

    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    static long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    static double log(double value, int base) {
        return log(value) / log(base);
    }

    static long long factorial(int number) {
        if (number < 0) {
            return 0;
        }
        return solveFactorial(number);
    }

private:
    static long long solveFactorial(int number) {
        if (number > 0) {
            return solveFactorial(number - 1) * number;
        }
        return 1;
    }
};

class Int {
public:
    int value;

    Int(int value) : value(value) {}

    bool operator<(const Int& other) const {
        return value < other.value;
    }

    bool operator==(const Int& other) const {
        return value == other.value;
    }
};

template<typename T, typename T1>
class Pair {
public:
    T first;
    T1 second;

    Pair(T first, T1 second) : first(first), second(second) {}

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }
};

template<typename T>
class Fraction : public Pair<T, T> {
public:
    Fraction(T dividend, T divider) : Pair<T, T>(dividend, divider) {
        reduce();
    }

    void reduce() {
        T dividend = this->first;
        T divider = this->second;
        T gcd = math::gcd(dividend, divider);
        this->first = dividend / gcd;
        this->second = divider / gcd;
    }

    void addWithoutReturn(const Fraction& number) {
        add(number, 0);
    }

    Fraction addWithReturn(const Fraction& number) {
        return add(number, 1);
    }

    void multiplyWithoutReturn(const Fraction& number) {
        multiply(number, 0);
    }

    Fraction multiplyWithReturn(const Fraction& number) {
        return multiply(number, 1);
    }

private:
    Fraction add(const Fraction& number, int function) {
        T dividend = this->first;
        T divider = this->second;
        T dividend1 = number.first;
        T divider1 = number.second;
        T lcm = math::lcm(divider, divider1);
        if (function == 0) {
            this->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            this->second = lcm;
            reduce();
            return Fraction(0, 0);
        }
        Fraction result((lcm / divider) * dividend + (lcm / divider1) * dividend1, lcm);
        result.reduce();
        return result;
    }

    Fraction multiply(const Fraction& number, int function) {
        T first = this->first * number.first;
        T second = this->second * number.second;
        if (function == 0) {
            this->first = first;
            this->second = second;
            reduce();
            return Fraction(0, 0);
        }
        Fraction answer(first, second);
        answer.reduce();
        return answer;
    }
};

class Graph {
private:
    vector<vector<int>> base;
    vector<bool> used;
    int quantity;
    vector<int> ancestor;

public:
    vector<vector<int>> getBase() {
        return base;
    }

    vector<bool> getUsed() {
        return used;
    }

    int getQuantity() {
        return quantity;
    }

    vector<int> getAncestor() {
        return ancestor;
    }

    void setBase(const vector<vector<int>>& base) {
        this->base = base;
    }

    void start(int length) {
        used = vector<bool>(length, false);
        ancestor = vector<int>(length, -1);
        quantity = 0;
    }

    void edgesMatrixToDefault(int length, int quantity, bool readConsole, const vector<vector<int>>& value) {
        base = vector<vector<int>>(length);
        vector<vector<int>> inputBase(length);
        for (int i = 0; i < quantity; i++) {
            vector<int> input = readConsole ? IO::readArrayInt(2) : value[i];
            inputBase[input[0] - 1].push_back(input[1] - 1);
            inputBase[input[1] - 1].push_back(input[0] - 1);
        }
        for (int i = 0; i < length; i++) {
            base[i] = inputBase[i];
        }
        start(length);
    }

    void adjacencyMatrixToDefault(int length, int not, bool readConsole, const vector<vector<int>>& value) {
        base = vector<vector<int>>(length);
        for (int i = 0; i < length; i++) {
            vector<int> input = readConsole ? IO::readArrayInt(length) : value[i];
            for (int index = 0; index < length; index++) {
                if (i != index && input[index] != not) {
                    base[i].push_back(index);
                }
            }
        }
        start(length);
    }

    void dfs(int position) {
        used[position] = true;
        quantity++;
        int next;
        for (int index = 0; index < base[position].size(); index++) {
            next = base[position][index];
            if (!used[next]) {
                ancestor[next] = position;
                dfs(next);
            }
        }
    }

    int dijkstra(int start, int stop, int size) {
        start--;
        stop--;
        vector<int> dist(size, INT_MAX);
        for (int i = 0; i < size; i++) {
            if (i != start) {
                dist[i] = INT_MAX;
            }
            ancestor[i] = start;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, start));
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (u == stop) {
                break;
            }
            if (dist[u] == INT_MAX) {
                continue;
            }
            for (int i = 0; i < base[u].size(); i++) {
                int v = base[u][i];
                int weight = 1; // Assuming all edges have weight 1
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    ancestor[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist[stop] == INT_MAX ? -1 : dist[stop];
    }

    static bool solveFloydWarshall(vector<vector<int>>& base, int length, int not) {
        for (int k = 0; k < length; k++) {
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    if (base[i][k] == not || base[k][j] == not) {
                        continue;
                    }
                    int total = base[i][k] + base[k][j];
                    if (base[i][j] != not) {
                        base[i][j] = min(base[i][j], total);
                    } else {
                        base[i][j] = total;
                    }
                }
            }
        }
        for (int index = 0; index < length; index++) {
            if (base[index][index] != 0) {
                return false;
            }
        }
        return true;
    }

    static pair<long long, vector<vector<int>>> solveKruskal(vector<vector<int>>& edgesMatrix, int countVertex, int indexSort) {
        vector<vector<int>> answer(countVertex - 1, vector<int>(2));
        long long sum = 0;
        sort(edgesMatrix.begin(), edgesMatrix.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[indexSort] < b[indexSort];
        });
        vector<int> dsu(countVertex);
        for (int i = 0; i < countVertex; i++) {
            dsu[i] = i;
        }
        int index = 0;
        for (const vector<int>& value : edgesMatrix) {
            int u = value[0];
            int v = value[1];
            if (dsu[u] != dsu[v]) {
                sum += value[indexSort];
                answer[index][0] = u;
                answer[index][1] = v;
                index++;
                int oldDsu = dsu[v];
                int newDsu = dsu[u];
                for (int j = 0; j < countVertex; j++) {
                    if (dsu[j] == oldDsu) {
                        dsu[j] = newDsu;
                    }
                }
            }
        }
        if (index < countVertex - 1) {
            return make_pair(-1, vector<vector<int>>());
        }
        return make_pair(sum, answer);
    }
};

class SegmentTree {
private:
    vector<int> segmentArray;
    function<int(int, int)> function;

public:
    SegmentTree() {}

    SegmentTree(const vector<int>& startBase, int neutral, const function<int(int, int)>& function) : function(function) {
        int length = startBase.size();
        vector<int> base;
        if ((length & (length - 1)) != 0) {
            int pow = 0;
            while (length > 0) {
                length >>= 1;
                pow++;
            }
            pow--;
            base = vector<int>(2 << pow);
            copy(startBase.begin(), startBase.end(), base.begin());
            fill(base.begin() + startBase.size(), base.end(), neutral);
        } else {
            base = startBase;
        }
        segmentArray = vector<int>(base.size() << 1, neutral);
        fill(segmentArray.begin(), segmentArray.end(), neutral);
        inDepth(base, 1, 0, base.size() - 1);
    }

    int getValue(int left, int right, int neutral) {
        return findValue(1, 0, (segmentArray.size() >> 1) - 1, left, right, neutral);
    }

    void replaceValue(int index, int value) {
        update(1, 0, (segmentArray.size() >> 1) - 1, index, value);
    }

private:
    void inDepth(const vector<int>& base, int position, int low, int high) {
        if (low == high) {
            segmentArray[position] = base[low];
        } else {
            int mid = (low + high) >> 1;
            inDepth(base, position << 1, low, mid);
            inDepth(base, (position << 1) + 1, mid + 1, high);
            segmentArray[position] = function(segmentArray[position << 1], segmentArray[(position << 1) + 1]);
        }
    }

    int findValue(int position, int low, int high, int left, int right, int neutral) {
        if (left > right) {
            return neutral;
        }
        if (left == low && right == high) {
            return segmentArray[position];
        }
        int mid = (low + high) >> 1;
        return function(findValue(position << 1, low, mid, left, min(right, mid), neutral),
                        findValue((position << 1) + 1, mid + 1, high, max(left, mid + 1), right, neutral));
    }

    void update(int position, int low, int high, int index, int value) {
        if (low == high) {
            segmentArray[position] = value;
        } else {
            int mid = (low + high) >> 1;
            if (index <= mid) {
                update(position << 1, low, mid, index, value);
            } else {
                update((position << 1) + 1, mid + 1, high, index, value);
            }
            segmentArray[position] = function(segmentArray[position << 1], segmentArray[(position << 1) + 1]);
        }
    }
};

int main() {
    int g = IO::readInt();
    int sh = IO::readInt();
    int j = IO::readInt();
    int p = IO::readInt();
    int priceFirst = IO::readInt();
    int priceSecond = IO::readInt();
    long long answer = 0;
    if (priceFirst <= priceSecond) {
        answer = min({sh, j, p});
        p -= answer;
        answer *= priceSecond;
        answer += (min(p, g) * priceFirst);
    } else {
        answer = min({g, p});
        p -= answer;
        answer *= priceFirst;
        answer += (min({sh, j, p}) * priceSecond);
    }
    IO::writeLong(answer);
    return 0;
}
