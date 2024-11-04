#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <sstream>

using namespace std;

class Graph {
public:
    static const int id20 = 0;
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> from, to, nextOutbound, flags;
    vector<long> weight, capacity;
    vector<int> reverseEdge;

    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
    }

    int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        if (edgeCount >= from.size()) {
            resize(edgeCount + 1);
        }
        if (firstOutbound[fromID] != -1) {
            nextOutbound[edgeCount] = firstOutbound[fromID];
        } else {
            nextOutbound[edgeCount] = -1;
        }
        firstOutbound[fromID] = edgeCount;
        this->from[edgeCount] = fromID;
        this->to[edgeCount] = toID;
        if (capacity != 0) {
            if (this->capacity.empty()) {
                this->capacity.resize(from.size());
            }
            this->capacity[edgeCount] = capacity;
        }
        if (weight != 0) {
            if (this->weight.empty()) {
                this->weight.resize(from.size());
            }
            this->weight[edgeCount] = weight;
        }
        if (reverseEdge != -1) {
            if (this->reverseEdge.empty()) {
                this->reverseEdge.resize(from.size());
                fill(this->reverseEdge.begin(), this->reverseEdge.end(), -1);
            }
            this->reverseEdge[edgeCount] = reverseEdge;
        }
        return edgeCount++;
    }

    int firstOutboundVertex(int vertex) {
        int id = firstOutbound[vertex];
        while (id != -1 && isRemoved(id)) {
            id = nextOutbound[id];
        }
        return id;
    }

    int nextOutboundVertex(int id) {
        id = nextOutbound[id];
        while (id != -1 && isRemoved(id)) {
            id = nextOutbound[id];
        }
        return id;
    }

    int destination(int id) {
        return to[id];
    }

    bool isRemoved(int id) {
        return (flags[id] >> id20 & 1) != 0;
    }

private:
    void resize(int size) {
        from.resize(size);
        to.resize(size);
        nextOutbound.resize(size);
        weight.resize(size);
        capacity.resize(size);
        reverseEdge.resize(size);
        flags.resize(size);
    }
};

class InputReader {
public:
    InputReader(istream &stream) : stream(stream) {}

    int readInt() {
        int res;
        stream >> res;
        return res;
    }

private:
    istream &stream;
};

class OutputWriter {
public:
    OutputWriter(ostream &stream) : stream(stream) {}

    void printLine(int i) {
        stream << i << endl;
    }

private:
    ostream &stream;
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
        for (int &x : u) x--;
        for (int &x : v) x--;
        graph = createGraph(n, u, v);
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&a](int i, int j) { return a[i] < a[j]; });
        reverse(order.begin(), order.end());
        int left = k, right = n;
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
                for (int j = graph.firstOutboundVertex(current); j != -1; j = graph.nextOutboundVertex(j)) {
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
    vector<int> weight, path;

    int dfs(int current, int last) {
        int result = 0;
        int max = 0, second = 0;
        for (int i = graph.firstOutboundVertex(current); i != -1; i = graph.nextOutboundVertex(i)) {
            int next = graph.destination(i);
            if (next == last) continue;
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

    Graph createGraph(int vertexCount, const vector<int> &from, const vector<int> &to) {
        Graph graph(vertexCount);
        for (size_t i = 0; i < from.size(); i++) {
            graph.addEdge(from[i], to[i], 0, 0, -1);
        }
        return graph;
    }
};

int main() {
    InputReader in(cin);
    OutputWriter out(cout);
    TaskD solver;
    solver.solve(1, in, out);
    return 0;
}
