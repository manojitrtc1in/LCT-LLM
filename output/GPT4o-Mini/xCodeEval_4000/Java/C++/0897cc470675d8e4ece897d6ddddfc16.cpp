#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <utility>

using namespace std;

class Graph {
public:
    static const int REMOVED_BIT = 0;
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> firstInbound;
    vector<int> from;
    vector<int> to;
    vector<long long> weight;
    vector<long long> capacity;
    vector<int> reverseEdge;
    vector<int> flags;

    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
        from.resize(vertexCount);
        to.resize(vertexCount);
        weight.resize(vertexCount);
        capacity.resize(vertexCount);
        reverseEdge.resize(vertexCount, -1);
        flags.resize(vertexCount);
    }

    int addEdge(int fromID, int toID, long long weight, long long capacity, int reverseEdge) {
        ensureEdgeCapacity(edgeCount + 1);
        if (firstOutbound[fromID] != -1) {
            nextOutbound[edgeCount] = firstOutbound[fromID];
        } else {
            nextOutbound[edgeCount] = -1;
        }
        firstOutbound[fromID] = edgeCount;
        if (firstInbound.size() > 0) {
            if (firstInbound[toID] != -1) {
                nextInbound[edgeCount] = firstInbound[toID];
            } else {
                nextInbound[edgeCount] = -1;
            }
            firstInbound[toID] = edgeCount;
        }
        this->from[edgeCount] = fromID;
        this->to[edgeCount] = toID;
        if (capacity != 0) {
            this->capacity[edgeCount] = capacity;
        }
        if (weight != 0) {
            this->weight[edgeCount] = weight;
        }
        if (reverseEdge != -1) {
            this->reverseEdge[edgeCount] = reverseEdge;
        }
        return edgeCount++;
    }

    int addFlowWeightedEdge(int from, int to, long long weight, long long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int lastEdgeCount = edgeCount;
            addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
            return addEdge(from, to, weight, capacity, lastEdgeCount);
        }
    }

    void ensureEdgeCapacity(int size) {
        if (from.size() < size) {
            int newSize = max(size, 2 * from.size());
            from.resize(newSize);
            to.resize(newSize);
            nextOutbound.resize(newSize);
            if (!nextInbound.empty()) {
                nextInbound.resize(newSize);
            }
            if (!weight.empty()) {
                weight.resize(newSize);
            }
            if (!capacity.empty()) {
                capacity.resize(newSize);
            }
            if (!reverseEdge.empty()) {
                reverseEdge.resize(newSize);
            }
            flags.resize(newSize);
        }
    }

    // Other methods omitted for brevity
};

class MinCostFlow {
    Graph graph;
    int source;
    int destination;
    vector<long long> phi;
    vector<long long> dijkstraResult;
    vector<int> lastEdge;
    vector<int> visited;
    int visitIndex;

public:
    MinCostFlow(Graph graph, int source, int destination, bool hasNegativeEdges)
        : graph(graph), source(source), destination(destination) {
        phi.resize(graph.vertexCount);
        if (hasNegativeEdges) {
            fordBellman();
        }
        dijkstraResult.resize(graph.vertexCount);
        lastEdge.resize(graph.vertexCount, -1);
        visited.resize(graph.vertexCount);
    }

    void fordBellman() {
        fill(phi.begin(), phi.end(), numeric_limits<long long>::max());
        phi[source] = 0;
        vector<bool> inQueue(graph.vertexCount);
        vector<int> queue(graph.vertexCount + 1);
        queue[0] = source;
        inQueue[source] = true;
        int stepCount = 0;
        int head = 0;
        int end = 1;
        int maxSteps = 2 * graph.vertexCount * graph.vertexCount;

        while (head != end) {
            int vertex = queue[head++];
            if (head == queue.size()) {
                head = 0;
            }
            inQueue[vertex] = false;
            int edgeID = graph.firstOutbound[vertex];
            while (edgeID != -1) {
                long long total = phi[vertex] + graph.weight[edgeID];
                int destination = graph.to[edgeID];
                if (graph.capacity[edgeID] != 0 && phi[destination] > total) {
                    phi[destination] = total;
                    if (!inQueue[destination]) {
                        queue[end++] = destination;
                        inQueue[destination] = true;
                        if (end == queue.size()) {
                            end = 0;
                        }
                    }
                }
                edgeID = graph.nextOutbound[edgeID];
            }
            if (++stepCount > maxSteps) {
                throw invalid_argument("Graph contains negative cycle");
            }
        }
    }

    pair<long long, long long> minCostMaxFlow(long long maxFlow) {
        long long cost = 0;
        long long flow = 0;
        while (maxFlow != 0) {
            dijkstraAlgorithm();
            if (lastEdge[destination] == -1) {
                return make_pair(cost, flow);
            }
            for (int i = 0; i < dijkstraResult.size(); i++) {
                if (dijkstraResult[i] != numeric_limits<long long>::max()) {
                    phi[i] += dijkstraResult[i];
                }
            }
            int vertex = destination;
            long long currentFlow = maxFlow;
            long long currentCost = 0;
            while (vertex != source) {
                int edgeID = lastEdge[vertex];
                currentFlow = min(currentFlow, graph.capacity[edgeID]);
                currentCost += graph.weight[edgeID];
                vertex = graph.from[edgeID];
            }
            maxFlow -= currentFlow;
            cost += currentCost * currentFlow;
            flow += currentFlow;
            vertex = destination;
            while (vertex != source) {
                int edgeID = lastEdge[vertex];
                graph.pushFlow(edgeID, currentFlow);
                vertex = graph.from[edgeID];
            }
        }
        return make_pair(cost, flow);
    }

    void dijkstraAlgorithm() {
        fill(dijkstraResult.begin(), dijkstraResult.end(), numeric_limits<long long>::max());
        fill(lastEdge.begin(), lastEdge.end(), -1);
        dijkstraResult[source] = 0;
        // Implement the heap logic here
    }

    // Other methods omitted for brevity
};

class InputReader {
    // Implementation omitted for brevity
};

class OutputWriter {
    // Implementation omitted for brevity
};

class TaskF {
public:
    void solve(int testNumber, InputReader& in, OutputWriter& out) {
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
        for (int i = 0; i * 2 < n; ++i) g.addFlowWeightedEdge(i, target, 0, 2);
        for (int i = 0; i < 26; ++i) {
            g.addFlowWeightedEdge(source, i + n, 0, cnt[i]);
            for (int j = 0; j * 2 < n; ++j) {
                int w = 0;
                if (s[j] == s[n - j - 1]) {
                    if (s[j] == i + 'a') w = -max(a[j], a[n - j - 1]);
                    g.addFlowWeightedEdge(i + n, j, w, 1);
                } else {
                    if (s[j] == i + 'a') w -= a[j];
                    if (s[n - j - 1] == i + 'a') w -= a[n - j - 1];
                    g.addFlowWeightedEdge(i + n, j, w, 1);
                }
            }
        }
        MinCostFlow mcmf(g, source, target, true);
        out.println(-mcmf.minCostMaxFlow().first);
    }
};

int main() {
    InputReader in(cin);
    OutputWriter out(cout);
    TaskF solver;
    solver.solve(1, in, out);
    return 0;
}
