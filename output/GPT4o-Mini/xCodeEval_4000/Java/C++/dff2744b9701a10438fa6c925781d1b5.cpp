#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <limits>

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : stream(stream) {}

    int readInt() {
        int c = read();
        while (isSpaceChar(c)) {
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
                throw invalid_argument("Input mismatch");
            }
            res = res * 10 + (c - '0');
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

private:
    istream &stream;
    char buf[1024];
    int curChar = 0;
    int numChars = 0;

    int read() {
        if (numChars == -1) {
            throw invalid_argument("Input mismatch");
        }
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

    bool isSpaceChar(int c) {
        return isspace(c) || c == -1;
    }
};

class OutputWriter {
public:
    OutputWriter(ostream &outputStream) : writer(outputStream) {}

    void printLine(int i) {
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

    int addEdge(int fromID, int toID) {
        ensureEdgeCapacity(edgeCount + 1);
        nextOutbound.push_back(firstOutbound[fromID]);
        firstOutbound[fromID] = edgeCount;
        from.push_back(fromID);
        to.push_back(toID);
        return edgeCount++;
    }

    int firstOutboundEdge(int vertex) {
        int id = firstOutbound[vertex];
        while (id != -1 && isRemoved(id)) {
            id = nextOutbound[id];
        }
        return id;
    }

    int nextOutboundEdge(int id) {
        id = nextOutbound[id];
        while (id != -1 && isRemoved(id)) {
            id = nextOutbound[id];
        }
        return id;
    }

    int destination(int id) {
        return to[id];
    }

private:
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> nextOutbound;
    vector<int> from;
    vector<int> to;

    bool isRemoved(int id) {
        return false; // Placeholder for actual implementation
    }

    void ensureEdgeCapacity(int size) {
        if (from.size() < size) {
            from.resize(size);
            to.resize(size);
            nextOutbound.resize(size);
        }
    }
};

class TaskD {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        int n = in.readInt();
        int k = in.readInt();
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = in.readInt();
        }
        vector<int> u(n - 1), v(n - 1);
        for (int i = 0; i < n - 1; i++) {
            u[i] = in.readInt();
            v[i] = in.readInt();
        }
        decreaseByOne(u, v);
        graph = createGraph(n, u, v);
        vector<int> order = createOrder(a);
        reverse(order.begin(), order.end());
        int left = k;
        int right = n;
        weight.resize(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < n - 1; i++) {
            degree[u[i]]++;
            degree[v[i]]++;
        }
        vector<int> remaining(n);
        vector<int> queue(n);
        path.resize(n);
        while (left < right) {
            int middle = (left + right) >> 1;
            int threshold = a[order[middle - 1]];
            fill(weight.begin(), weight.end(), 0);
            for (int i = 0; i < n; i++) {
                weight[i] = a[i] >= threshold ? 1 : 0;
            }
            copy(degree.begin(), degree.end(), remaining.begin());
            int size = 0;
            for (int i = 0; i < n; i++) {
                if (degree[i] == 1 && weight[i] > 0) {
                    queue[size++] = i;
                }
            }
            for (int i = 0; i < size; i++) {
                int current = queue[i];
                for (int j = graph.firstOutboundEdge(current); j != -1; j = graph.nextOutboundEdge(j)) {
                    int next = graph.destination(j);
                    if (weight[next] != 0) {
                        weight[next] += weight[current];
                        weight[current] = 0;
                        remaining[next]--;
                        if (remaining[next] == 1) {
                            queue[size++] = next;
                        }
                    }
                }
            }
            int result = dfs(0, -1);
            if (result >= k) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        out.printLine(a[order[left - 1]]);
    }

private:
    Graph graph;
    vector<int> weight;
    vector<int> path;

    int dfs(int current, int last) {
        int result = 0;
        int max = 0;
        int second = 0;
        for (int i = graph.firstOutboundEdge(current); i != -1; i = graph.nextOutboundEdge(i)) {
            int next = graph.destination(i);
            if (next == last) {
                continue;
            }
            result = max(result, dfs(next, current));
            if (path[next] > max) {
                second = max;
                max = path[next];
            } else {
                second = max(second, path[next]);
            }
        }
        if (weight[current] != 0) {
            path[current] = weight[current] + max;
            result = max(result, max + second + weight[current]);
        } else {
            path[current] = 0;
        }
        return result;
    }

    void decreaseByOne(vector<int> &u, vector<int> &v) {
        for (auto &x : u) x--;
        for (auto &x : v) x--;
    }

    Graph createGraph(int vertexCount, vector<int> &from, vector<int> &to) {
        Graph graph(vertexCount);
        for (size_t i = 0; i < from.size(); i++) {
            graph.addEdge(from[i], to[i]);
        }
        return graph;
    }

    vector<int> createOrder(const vector<int> &array) {
        vector<int> order(array.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&array](int a, int b) {
            return array[a] < array[b];
        });
        return order;
    }
};

int main() {
    InputReader in(cin);
    OutputWriter out(cout);
    TaskD solver;
    solver.solve(1, in, out);
    return 0;
}
