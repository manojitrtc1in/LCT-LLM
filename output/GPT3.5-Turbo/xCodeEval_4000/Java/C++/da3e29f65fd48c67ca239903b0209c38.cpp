#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class IO {
public:
    static int readInt() {
        int num;
        cin >> num;
        return num;
    }

    static long long readLong() {
        long long num;
        cin >> num;
        return num;
    }

    static string readString() {
        string str;
        cin >> str;
        return str;
    }

    static vector<int> readArrayInt(string split) {
        vector<int> arr;
        string str;
        cin >> str;
        int start = 0;
        int end = str.find(split);
        while (end != string::npos) {
            arr.push_back(stoi(str.substr(start, end - start)));
            start = end + split.length();
            end = str.find(split, start);
        }
        arr.push_back(stoi(str.substr(start, end - start)));
        return arr;
    }

    static vector<long long> readArrayLong(string split) {
        vector<long long> arr;
        string str;
        cin >> str;
        int start = 0;
        int end = str.find(split);
        while (end != string::npos) {
            arr.push_back(stoll(str.substr(start, end - start)));
            start = end + split.length();
            end = str.find(split, start);
        }
        arr.push_back(stoll(str.substr(start, end - start)));
        return arr;
    }

    static vector<string> readArrayString(string split) {
        vector<string> arr;
        string str;
        cin >> str;
        int start = 0;
        int end = str.find(split);
        while (end != string::npos) {
            arr.push_back(str.substr(start, end - start));
            start = end + split.length();
            end = str.find(split, start);
        }
        arr.push_back(str.substr(start, end - start));
        return arr;
    }

    static void writeArray(const vector<int>& arr, string split, bool enter) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeArray(const vector<long long>& arr, string split, bool enter) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeArray(const vector<string>& arr, string split, bool enter) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeInt(int num, string end) {
        cout << num << end;
    }

    static void writeLong(long long num, string end) {
        cout << num << end;
    }

    static void writeString(const string& str, string end) {
        cout << str << end;
    }

    static void writeEnter() {
        cout << endl;
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

    Int(int value) {
        this->value = value;
    }

    bool operator<(const Int& other) const {
        return value < other.value;
    }

    bool operator==(const Int& other) const {
        return value == other.value;
    }

    bool operator>(const Int& other) const {
        return value > other.value;
    }

    bool operator<=(const Int& other) const {
        return value <= other.value;
    }

    bool operator>=(const Int& other) const {
        return value >= other.value;
    }

    bool operator!=(const Int& other) const {
        return value != other.value;
    }
};

template<typename T, typename T1>
class Pair {
public:
    T first;
    T1 second;

    Pair(T first, T1 second) {
        this->first = first;
        this->second = second;
    }

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }

    bool operator!=(const Pair& other) const {
        return first != other.first || second != other.second;
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
            vector<int> input = readConsole ? IO::readArrayInt(" ") : value[i];
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
            vector<int> input = readConsole ? IO::readArrayInt(" ") : value[i];
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
        vector<bool> used(size, false);
        vector<int> parent(size, start);

        dist[start] = 0;
        for (int i = 0; i < size; i++) {
            int v = -1;
            for (int j = 0; j < size; j++) {
                if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                    v = j;
                }
            }
            if (dist[v] == INT_MAX) {
                break;
            }
            used[v] = true;

            for (int j = 0; j < base[v].size(); j++) {
                int to = base[v][j];
                int len = 1; // assuming all edges have weight 1
                if (dist[v] + len < dist[to]) {
                    dist[to] = dist[v] + len;
                    parent[to] = v;
                }
            }
        }

        if (dist[stop] == INT_MAX) {
            return -1;
        }

        return dist[stop];
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
                int oldColor = dsu[v], newColor = dsu[u];
                for (int i = 0; i < countVertex; i++) {
                    if (dsu[i] == oldColor) {
                        dsu[i] = newColor;
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

    SegmentTree(const vector<int>& startBase, int neutral, const function<int(int, int)>& function) {
        this->function = function;
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

class SystemOfDisjointSets {
private:
    vector<int> rank;
    vector<int> ancestor;

public:
    SystemOfDisjointSets(int size) {
        rank = vector<int>(size, 0);
        ancestor = vector<int>(size);
    }

    void makeSet(int value) {
        ancestor[value] = value;
        rank[value] = 0;
    }

    int findSet(int value) {
        if (value == ancestor[value]) {
            return value;
        }
        return ancestor[value] = findSet(ancestor[value]);
    }

    bool mergeSets(int first, int second) {
        first = findSet(first);
        second = findSet(second);
        if (first != second) {
            if (rank[first] < rank[second]) {
                swap(first, second);
            }
            ancestor[second] = first;
            if (rank[first] == rank[second]) {
                rank[first]++;
            }
            return true;
        }
        return false;
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
        answer = min(min(sh, j), p);
        p -= answer;
        answer *= priceSecond;
        answer += (min(p, g) * priceFirst);
    } else {
        answer = min(g, p);
        p -= answer;
        answer *= priceFirst;
        answer += (min(min(sh, j), p) * priceSecond);
    }
    IO::writeLong(answer, "\n");
    return 0;
}
