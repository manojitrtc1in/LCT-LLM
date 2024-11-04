#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

class Graph {
public:
    static const int REMOVED_BIT = 0;

    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
    }

    int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        ensureEdgeCapacity(edgeCount + 1);
        if (firstOutbound[fromID] != -1)
            nextOutbound[edgeCount] = firstOutbound[fromID];
        else
            nextOutbound[edgeCount] = -1;
        firstOutbound[fromID] = edgeCount;
        from[edgeCount] = fromID;
        to[edgeCount] = toID;
        if (capacity != 0) {
            if (this->capacity.empty())
                this->capacity.resize(from.size());
            this->capacity[edgeCount] = capacity;
        }
        if (weight != 0) {
            if (this->weight.empty())
                this->weight.resize(from.size());
            this->weight[edgeCount] = weight;
        }
        if (reverseEdge != -1) {
            if (this->reverseEdge.empty()) {
                this->reverseEdge.resize(from.size(), -1);
            }
            this->reverseEdge[edgeCount] = reverseEdge;
        }
        return edgeCount++;
    }

    int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int lastEdgeCount = edgeCount;
            addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
            return addEdge(from, to, weight, capacity, lastEdgeCount);
        }
    }

    int vertexCount() const {
        return vertexCount;
    }

    int firstOutbound(int vertex) {
        int id = firstOutbound[vertex];
        while (id != -1 && isRemoved(id))
            id = nextOutbound[id];
        return id;
    }

    int nextOutbound(int id) {
        id = nextOutbound[id];
        while (id != -1 && isRemoved(id))
            id = nextOutbound[id];
        return id;
    }

    int source(int id) {
        return from[id];
    }

    int destination(int id) {
        return to[id];
    }

    long weight(int id) {
        if (weight.empty())
            return 0;
        return weight[id];
    }

    long capacity(int id) {
        if (capacity.empty())
            return 0;
        return capacity[id];
    }

    void pushFlow(int id, long flow) {
        if (flow == 0)
            return;
        capacity[id] -= flow;
        capacity[reverseEdge[id]] += flow;
    }

private:
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> nextOutbound;
    vector<int> from;
    vector<int> to;
    vector<long> weight;
    vector<long> capacity;
    vector<int> reverseEdge;

    void ensureEdgeCapacity(int size) {
        if (from.size() < size) {
            int newSize = max(size, 2 * (int)from.size());
            from.resize(newSize);
            to.resize(newSize);
            nextOutbound.resize(newSize);
            weight.resize(newSize);
            capacity.resize(newSize);
            reverseEdge.resize(newSize);
        }
    }

    bool isRemoved(int id) {
        return (flags[id] >> REMOVED_BIT & 1) != 0;
    }

    vector<int> flags;
};

class MinCostFlow {
public:
    MinCostFlow(Graph& graph, int source, int destination, bool hasNegativeEdges)
        : graph(graph), source(source), destination(destination), vertexCount(graph.vertexCount()) {
        phi.resize(vertexCount);
        if (hasNegativeEdges)
            fordBellman();
        dijkstraResult.resize(vertexCount);
        lastEdge.resize(vertexCount);
    }

    pair<long, long> minCostMaxFlow(long maxFlow = numeric_limits<long>::max()) {
        long cost = 0;
        long flow = 0;
        while (maxFlow != 0) {
            dijkstraAlgorithm();
            if (lastEdge[destination] == -1)
                return make_pair(cost, flow);
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
        return make_pair(cost, flow);
    }

private:
    Graph& graph;
    int source;
    int destination;
    int vertexCount;
    vector<long> phi;
    vector<long> dijkstraResult;
    vector<int> lastEdge;

    void fordBellman() {
        fill(phi.begin(), phi.end(), numeric_limits<long>::max());
        phi[source] = 0;
        vector<bool> inQueue(vertexCount);
        queue<int> queue;
        queue.push(source);
        inQueue[source] = true;
        while (!queue.empty()) {
            int vertex = queue.front();
            queue.pop();
            inQueue[vertex] = false;
            int edgeID = graph.firstOutbound(vertex);
            while (edgeID != -1) {
                long total = phi[vertex] + graph.weight(edgeID);
                int dest = graph.destination(edgeID);
                if (graph.capacity(edgeID) != 0 && phi[dest] > total) {
                    phi[dest] = total;
                    if (!inQueue[dest]) {
                        queue.push(dest);
                        inQueue[dest] = true;
                    }
                }
                edgeID = graph.nextOutbound(edgeID);
            }
        }
    }

    void dijkstraAlgorithm() {
        fill(dijkstraResult.begin(), dijkstraResult.end(), numeric_limits<long>::max());
        fill(lastEdge.begin(), lastEdge.end(), -1);
        dijkstraResult[source] = 0;
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> heap;
        heap.push({0, source});
        while (!heap.empty()) {
            int current = heap.top().second;
            heap.pop();
            int edgeID = graph.firstOutbound(current);
            while (edgeID != -1) {
                if (graph.capacity(edgeID) != 0) {
                    int next = graph.destination(edgeID);
                    long total = graph.weight(edgeID) - phi[next] + phi[current] + dijkstraResult[current];
                    if (dijkstraResult[next] > total) {
                        dijkstraResult[next] = total;
                        lastEdge[next] = edgeID;
                        heap.push({dijkstraResult[next], next});
                    }
                }
                edgeID = graph.nextOutbound(edgeID);
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    int shoe = m * n / 2;
    Graph graph(2 * shoe + 2);
    int source = 2 * shoe, sink = 2 * shoe + 1;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int id = i * m + j;
            if ((i + j) % 2 == 0) {
                for (int z = 0; z < 4; ++z) {
                    int i1 = i + dx[z];
                    int j1 = j + dy[z];
                    if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= m) continue;
                    int id1 = i1 * m + j1;
                    int wt = (a[i][j] == a[i1][j1]) ? 0 : 1;
                    graph.addFlowWeightedEdge(id, id1, wt, 1);
                }
                graph.addFlowWeightedEdge(source, id, 0, 1);
            } else {
                graph.addFlowWeightedEdge(id, sink, 0, 1);
            }
        }
    }

    MinCostFlow mcf(graph, source, sink, false);
    pair<long, long> ans = mcf.minCostMaxFlow();
    cout << ans.first << endl;

    return 0;
}
