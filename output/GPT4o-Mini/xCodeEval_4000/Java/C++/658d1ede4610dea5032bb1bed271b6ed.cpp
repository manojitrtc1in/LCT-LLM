#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <utility>
#include <queue>

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : stream(stream) {}

    int read() {
        if (curChar >= numChars) {
            curChar = 0;
            stream.read(reinterpret_cast<char*>(buf), sizeof(buf));
            numChars = stream.gcount();
            if (numChars <= 0) return -1;
        }
        return buf[curChar++];
    }

    int readInt() {
        int c = read();
        while (isSpaceChar(c)) c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') throw runtime_error("InputMismatchException");
            res = res * 10 + (c - '0');
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    string readString() {
        int c = read();
        while (isSpaceChar(c)) c = read();
        string res;
        do {
            res += static_cast<char>(c);
            c = read();
        } while (!isSpaceChar(c));
        return res;
    }

private:
    istream &stream;
    char buf[1024];
    int curChar = 0;
    int numChars = 0;

    bool isSpaceChar(int c) {
        return isspace(c) || c == -1;
    }
};

class Graph {
public:
    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
    }

    int addEdge(int fromID, int toID, long weight, long capacity) {
        ensureEdgeCapacity(edgeCount + 1);
        nextOutbound[edgeCount] = firstOutbound[fromID];
        firstOutbound[fromID] = edgeCount;
        from.push_back(fromID);
        to.push_back(toID);
        weightList.push_back(weight);
        capacityList.push_back(capacity);
        return edgeCount++;
    }

    int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0);
        } else {
            int lastEdgeCount = edgeCount;
            addEdge(to, from, -weight, 0);
            return addEdge(from, to, weight, capacity);
        }
    }

    int firstOutboundEdge(int vertex) {
        return firstOutbound[vertex];
    }

    int nextOutboundEdge(int id) {
        return nextOutbound[id];
    }

    int source(int id) {
        return from[id];
    }

    int destination(int id) {
        return to[id];
    }

    long weight(int id) {
        return weightList[id];
    }

    long capacity(int id) {
        return capacityList[id];
    }

    void pushFlow(int id, long flow) {
        capacityList[id] -= flow;
        capacityList[reverseEdge[id]] += flow;
    }

private:
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> nextOutbound;
    vector<int> from;
    vector<int> to;
    vector<long> weightList;
    vector<long> capacityList;
    vector<int> reverseEdge;

    void ensureEdgeCapacity(int size) {
        if (from.size() < size) {
            from.resize(size);
            to.resize(size);
            nextOutbound.resize(size);
            weightList.resize(size);
            capacityList.resize(size);
            reverseEdge.resize(size);
        }
    }
};

class MinCostFlow {
public:
    MinCostFlow(Graph &graph, int source, int destination) : graph(graph), source(source), destination(destination) {
        dijkstraResult.resize(graph.vertexCount());
        lastEdge.resize(graph.vertexCount());
    }

    pair<long, long> minCostMaxFlow(long maxFlow) {
        long cost = 0;
        long flow = 0;
        while (maxFlow != 0) {
            dijkstraAlgorithm();
            if (lastEdge[destination] == -1) return {cost, flow};

            long currentFlow = maxFlow;
            long currentCost = 0;
            int vertex = destination;
            while (vertex != source) {
                int edgeID = lastEdge[vertex];
                currentFlow = min(currentFlow, graph.capacity(edgeID));
                currentCost += graph.weight(edgeID);
                vertex = graph.source(edgeID);
            }
            maxFlow -= currentFlow;
            cost += currentCost * currentFlow;
            flow += currentFlow;
            vertex = destination;
            while (vertex != source) {
                int edgeID = lastEdge[vertex];
                graph.pushFlow(edgeID, currentFlow);
                vertex = graph.source(edgeID);
            }
        }
        return {cost, flow};
    }

private:
    Graph &graph;
    int source;
    int destination;
    vector<long> dijkstraResult;
    vector<int> lastEdge;

    void dijkstraAlgorithm() {
        fill(dijkstraResult.begin(), dijkstraResult.end(), numeric_limits<long>::max());
        fill(lastEdge.begin(), lastEdge.end(), -1);
        dijkstraResult[source] = 0;

        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        pq.push({0, source});
        while (!pq.empty()) {
            int current = pq.top().second;
            pq.pop();
            int edgeID = graph.firstOutboundEdge(current);
            while (edgeID != -1) {
                if (graph.capacity(edgeID) != 0) {
                    int next = graph.destination(edgeID);
                    long total = graph.weight(edgeID) + dijkstraResult[current];
                    if (dijkstraResult[next] > total) {
                        dijkstraResult[next] = total;
                        lastEdge[next] = edgeID;
                        pq.push({total, next});
                    }
                }
                edgeID = graph.nextOutboundEdge(edgeID);
            }
        }
    }
};

class TaskF {
public:
    void solve(int testNumber, InputReader &in, ostream &out) {
        int n = in.readInt();
        string s = in.readString();
        vector<int> ugliness(n);
        for (int i = 0; i < n; ++i) {
            ugliness[i] = -in.readInt();
        }

        Graph graph(1 + 26 + n / 2 + 1);
        for (char c = 'a'; c <= 'z'; ++c) {
            for (int i = 0; i < n / 2; ++i) {
                int cost = numeric_limits<int>::max();
                if (c == s[i]) {
                    cost = min(cost, ugliness[i]);
                }
                if (c == s[n - 1 - i]) {
                    cost = min(cost, ugliness[n - 1 - i]);
                }
                graph.addFlowWeightedEdge(1 + (c - 'a'), 1 + 26 + i, cost, 1);
            }
        }

        vector<int> occurs(128, 0);
        for (char c : s) occurs[c]++;
        for (char c = 'a'; c <= 'z'; ++c) {
            graph.addFlowWeightedEdge(0, 1 + (c - 'a'), 0, occurs[c]);
        }

        for (int i = 0; i < n / 2; ++i) {
            graph.addFlowWeightedEdge(1 + 26 + i, 1 + 26 + n / 2, 0, 2);
        }

        auto flow = MinCostFlow(graph, 0, 1 + 26 + n / 2).minCostMaxFlow(n);
        out << -flow.first << endl;
    }
};

int main() {
    InputReader in(cin);
    ostream &out = cout;
    TaskF solver;
    solver.solve(1, in, out);
    return 0;
}
