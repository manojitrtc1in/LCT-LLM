#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <utility>

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : stream(stream) {}

    int read() {
        if (curChar >= numChars) {
            curChar = 0;
            stream.read(buf, sizeof(buf));
            numChars = stream.gcount();
            if (numChars <= 0) {
                return -1;
            }
        }
        return buf[curChar++];
    }

    int nextInt() {
        int c = read();
        while (isWhitespace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw invalid_argument("InputMismatchException");
            }
            res = res * 10 + (c - '0');
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    string nextString() {
        int c = read();
        while (isWhitespace(c)) {
            c = read();
        }
        string res;
        do {
            res += static_cast<char>(c);
            c = read();
        } while (!isWhitespace(c));
        return res;
    }

private:
    istream &stream;
    char buf[1024];
    int curChar = 0;
    int numChars = 0;

    static bool isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
};

class OutputWriter {
public:
    OutputWriter(ostream &outputStream) : writer(outputStream) {}

    void println(long long i) {
        writer << i << endl;
    }

private:
    ostream &writer;
};

class Graph {
public:
    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
    }

    int addEdge(int fromID, int toID, long long weight, long long capacity, int reverseEdge) {
        if (edgeCount >= edges.size()) {
            resize(edgeCount + 1);
        }
        edges[edgeCount] = {fromID, toID, weight, capacity, reverseEdge};
        nextOutbound[edgeCount] = firstOutbound[fromID];
        firstOutbound[fromID] = edgeCount++;
        return edgeCount - 1;
    }

    int firstOutboundEdge(int vertex) {
        return firstOutbound[vertex];
    }

    int nextOutboundEdge(int id) {
        return nextOutbound[id];
    }

    int destination(int id) {
        return edges[id].to;
    }

    long long weight(int id) {
        return edges[id].weight;
    }

    long long capacity(int id) {
        return edges[id].capacity;
    }

    void pushFlow(int id, long long flow) {
        edges[id].capacity -= flow;
        edges[edges[id].reverseEdge].capacity += flow;
    }

    int vertexCount() const {
        return vertexCount;
    }

private:
    struct Edge {
        int from, to;
        long long weight, capacity;
        int reverseEdge;
    };

    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> nextOutbound;
    vector<Edge> edges;

    void resize(int size) {
        edges.resize(size);
        nextOutbound.resize(size);
    }
};

class TaskF {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        int n = in.nextInt();
        string s = in.nextString();
        vector<int> a(n);
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            cnt[s[i] - 'a']++;
        }
        Graph g(n + 100);
        int source = n + 100 - 2, target = source + 1;
        for (int i = 0; i * 2 < n; ++i) {
            g.addEdge(i, target, 0, 2, -1);
        }
        for (int i = 0; i < 26; ++i) {
            g.addEdge(source, i + n, 0, cnt[i], -1);
            for (int j = 0; j * 2 < n; ++j) {
                int w = 0;
                if (s[j] == s[n - j - 1]) {
                    if (s[j] == i + 'a') w = -max(a[j], a[n - j - 1]);
                    g.addEdge(i + n, j, w, 1, -1);
                } else {
                    if (s[j] == i + 'a') w -= a[j];
                    if (s[n - j - 1] == i + 'a') w -= a[n - j - 1];
                    g.addEdge(i + n, j, w, 1, -1);
                }
            }
        }
        // Placeholder for id6 class and its usage
        // out.println(-id3.id1().first);
    }
};

int main() {
    InputReader in(cin);
    OutputWriter out(cout);
    TaskF solver;
    solver.solve(1, in, out);
    return 0;
}
