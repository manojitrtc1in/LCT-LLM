#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

class id7 {
private:
    ifstream r;
    string line;
    size_t pos;

public:
    id7() : r(cin.rdbuf()) {}

    id7(const string& problemName) : r(problemName + ".in") {}

    string nextLine() {
        getline(r, line);
        return line;
    }

    string next() {
        if (pos >= line.size()) {
            nextLine();
            pos = 0;
        }
        size_t start = pos;
        while (pos < line.size() && line[pos] != ' ') pos++;
        string token = line.substr(start, pos - start);
        pos++;
        return token;
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }
};

id7 input;
ofstream log("output.txt");
vector<vector<long long>> powerSet;
long long mod = static_cast<long long>(pow(10, 9) + 7);
vector<vector<int>> dp;

int bfs(long long w, int n) {
    queue<long long> q;
    q.push(w);
    unordered_map<long long, int> h;
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
            long long v = static_cast<long long>(x) * s;
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

int log2(long long n) {
    int cnt = 0;
    while (n > 1) {
        n /= 2;
        cnt++;
    }
    return cnt;
}

vector<int> bfs(int node, const vector<vector<int>>& a) {
    queue<int> q;
    q.push(node);
    vector<int> distances(a.size(), -1);
    distances[node] = 0;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        const vector<int>& nodes = a[parent];

        int cost = distances[parent];
        for (int node1 : nodes) {
            if (distances[node1] == -1) {
                q.push(node1);
                distances[node1] = cost + 1;
            }
        }
    }
    return distances;
}

int get(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long primeFactors(int n) {
    long long sum = 1;
    while (n % 2 == 0) {
        sum *= 2;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            sum *= static_cast<long long>(i);
            n /= i;
        }
        if (n < i) {
            break;
        }
    }
    if (n > 2) {
        sum *= n;
    }
    return sum;
}

vector<int> id9(int n) {
    vector<int> a;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (isPrime(i)) {
                a.push_back(i);
                n /= i;
                i = 0;
            } else if (isPrime(n / i)) {
                a.push_back(n / i);
                n = i;
                i = 0;
            }
        }
    }
    return a;
}

void generate(int ind, long long* a, vector<long long>& sub) {
    if (ind == sizeof(a) / sizeof(a[0])) {
        powerSet.push_back(sub);
        return;
    }
    vector<long long> have = sub;
    vector<long long> less = sub;
    have.push_back(a[ind]);
    generate(ind + 1, a, have);
    generate(ind + 1, a, less);
}

long long factorial(long long n) {
    if (n <= 1) {
        return 1;
    }
    long long t = n - 1;
    while (t > 1) {
        n *= t;
        t--;
    }
    return n;
}

bool isPalindrome(int n) {
    int t = n;
    int ans = 0;
    while (t > 0) {
        ans = ans * 10 + t % 10;
        t /= 10;
    }
    return ans == n;
}

class tri {
public:
    int x, y, z;

    tri(int x, int y, int z) : x(x), y(y), z(z) {}
};

bool isPrime(long long num) {
    if (num == 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    if (num == 3) return true;
    for (int i = 3; i <= sqrt(num) + 1; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void prefixSum(int* a, int size) {
    for (int i = 1; i < size; i++) {
        a[i] += a[i - 1];
    }
}

void suffixSum(long long* a, int size) {
    for (int i = size - 2; i > -1; i--) {
        a[i] += a[i + 1];
    }
}

long long mod(long long a, long long b) {
    long long r = a % b;
    return r < 0 ? r + b : r;
}

long long id13(const string& w) {
    long long r = 0;
    long long l = 0;
    for (int i = w.length() - 1; i > -1; i--) {
        long long x = (w[i] - '0') * static_cast<long long>(pow(2, l));
        r += x;
        l++;
    }
    return r;
}

string id3(long long n) {
    string w = "";
    while (n > 0) {
        w = to_string(n % 2) + w;
        n /= 2;
    }
    return w;
}

bool isSorted(int* a, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

void print(int* a, int size) {
    for (int i = 0; i < size; i++) {
        log << a[i] << " ";
    }
    log << "\n";
}

void read(int* a, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = input.nextInt();
    }
}

class pair {
public:
    long long x;
    long long y;

    pair(long long x, long long y) : x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const pair& p) {
        return os << p.x << " " << p.y;
    }
};

long long LCM(long long x, long long y) {
    return x / GCD(x, y) * y;
}

long long GCD(long long x, long long y) {
    if (y == 0) {
        return x;
    }
    return GCD(y, x % y);
}

void id10(long long a, long long b) {
    long long GCD = GCD(a, b);
    cout << a / GCD << " " << b / GCD << "\n";
}

template <typename T>
class id0 {
public:
    static const int BLACK = 0;
    static const int RED = 1;

    T key;
    id0* parent;
    id0* left;
    id0* right;
    int numLeft;
    int numRight;
    int color;

    id0() : color(BLACK), numLeft(0), numRight(0), parent(nullptr), left(nullptr), right(nullptr) {}

    id0(T key) : id0() {
        this->key = key;
    }
};

template <typename T>
class id5 {
private:
    id0<T>* nil = new id0<T>();
    id0<T>* root = nil;

    void leftRotate(id0<T>* x) {
        id17(x);
        id0<T>* y = x->right;
        x->right = y->left;

        if (!isNil(y->left)) {
            y->left->parent = x;
        }
        y->parent = x->parent;

        if (isNil(x->parent)) {
            root = y;
        } else if (x->parent->left == x) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void id17(id0<T>* x) {
        if (isNil(x->left) && isNil(x->right->left)) {
            x->numLeft = 0;
            x->numRight = 0;
            x->right->numLeft = 1;
        } else if (isNil(x->left) && !isNil(x->right->left)) {
            x->numLeft = 0;
            x->numRight = 1 + x->right->left->numLeft + x->right->left->numRight;
            x->right->numLeft = 2 + x->right->left->numLeft + x->right->left->numRight;
        } else if (!isNil(x->left) && isNil(x->right->left)) {
            x->numRight = 0;
            x->right->numLeft = 2 + x->left->numLeft + x->left->numRight;
        } else {
            x->numRight = 1 + x->right->left->numLeft + x->right->left->numRight;
            x->right->numLeft = 3 + x->left->numLeft + x->left->numRight + x->right->left->numLeft + x->right->left->numRight;
        }
    }

    void rightRotate(id0<T>* y) {
        id12(y);
        id0<T>* x = y->left;
        y->left = x->right;

        if (!isNil(x->right)) {
            x->right->parent = y;
        }
        x->parent = y->parent;

        if (isNil(y->parent)) {
            root = x;
        } else if (y->parent->right == y) {
            y->parent->right = x;
        } else {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    void id12(id0<T>* y) {
        if (isNil(y->right) && isNil(y->left->right)) {
            y->numRight = 0;
            y->numLeft = 0;
            y->left->numRight = 1;
        } else if (isNil(y->right) && !isNil(y->left->right)) {
            y->numRight = 0;
            y->numLeft = 1 + y->left->right->numRight + y->left->right->numLeft;
            y->left->numRight = 2 + y->left->right->numRight + y->left->right->numLeft;
        } else if (!isNil(y->right) && isNil(y->left->right)) {
            y->numLeft = 0;
            y->left->numRight = 2 + y->right->numRight + y->right->numLeft;
        } else {
            y->numLeft = 1 + y->left->right->numRight + y->left->right->numLeft;
            y->left->numRight = 3 + y->right->numRight + y->right->numLeft + y->left->right->numRight + y->left->right->numLeft;
        }
    }

public:
    id5() {
        root->left = nil;
        root->right = nil;
        root->parent = nil;
    }

    void insert(T key) {
        insert(new id0<T>(key));
    }

    void insert(id0<T>* z) {
        id0<T>* y = nil;
        id0<T>* x = root;

        while (!isNil(x)) {
            y = x;

            if (z->key < x->key) {
                x->numLeft++;
                x = x->left;
            } else {
                x->numRight++;
                x = x->right;
            }
        }

        z->parent = y;

        if (isNil(y)) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }

        z->left = nil;
        z->right = nil;
        z->color = id0<T>::RED;

        id8(z);
    }

    void id8(id0<T>* z) {
        id0<T>* y = nil;

        while (z->parent->color == id0<T>::RED) {
            if (z->parent == z->parent->left) {
                y = z->parent->parent->right;

                if (y->color == id0<T>::RED) {
                    z->parent->color = id0<T>::BLACK;
                    y->color = id0<T>::BLACK;
                    z->parent->parent->color = id0<T>::RED;
                    z = z->parent->parent;
                } else if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                } else {
                    z->parent->color = id0<T>::BLACK;
                    z->parent->parent->color = id0<T>::RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                y = z->parent->parent->left;

                if (y->color == id0<T>::RED) {
                    z->parent->color = id0<T>::BLACK;
                    y->color = id0<T>::BLACK;
                    z->parent->parent->color = id0<T>::RED;
                    z = z->parent->parent;
                } else if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                } else {
                    z->parent->color = id0<T>::BLACK;
                    z->parent->parent->color = id0<T>::RED;
                    leftRotate(z->parent->parent);
                }
            }
        }

        root->color = id0<T>::BLACK;
    }

    id0<T>* search(T key) {
        id0<T>* current = root;

        while (!isNil(current)) {
            if (current->key == key) {
                return current;
            } else if (current->key < key) {
                current = current->right;
            } else {
                current = current->left;
            }
        }

        return nullptr;
    }

    bool isNil(id0<T>* node) {
        return node == nil;
    }

    int size() {
        return root->numLeft + root->numRight + 1;
    }
};

int main() {
    int n = input.nextInt();
    long long w = input.nextLong();
    log << bfs(w, n) << "\n";
    log.close();
    return 0;
}
