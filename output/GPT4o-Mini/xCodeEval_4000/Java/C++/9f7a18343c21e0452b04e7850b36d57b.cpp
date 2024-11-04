#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>

using namespace std;

class Graph {
public:
    static const int REMOVED_BIT = 0;

    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
        from.reserve(vertexCount);
        to.reserve(vertexCount);
        nextOutbound.reserve(vertexCount);
        flags.reserve(vertexCount);
    }

    int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        ensureEdgeCapacity(edgeCount + 1);
        if (firstOutbound[fromID] != -1)
            nextOutbound[edgeCount] = firstOutbound[fromID];
        else
            nextOutbound[edgeCount] = -1;
        firstOutbound[fromID] = edgeCount;
        if (firstInbound.size() > 0) {
            if (firstInbound[toID] != -1)
                nextInbound[edgeCount] = firstInbound[toID];
            else
                nextInbound[edgeCount] = -1;
            firstInbound[toID] = edgeCount;
        }
        from.push_back(fromID);
        to.push_back(toID);
        if (capacity != 0) {
            if (this->capacity.size() == 0)
                this->capacity.resize(from.size());
            this->capacity[edgeCount] = capacity;
        }
        if (weight != 0) {
            if (this->weight.size() == 0)
                this->weight.resize(from.size());
            this->weight[edgeCount] = weight;
        }
        if (reverseEdge != -1) {
            if (this->reverseEdge.size() == 0) {
                this->reverseEdge.resize(from.size());
                fill(this->reverseEdge.begin(), this->reverseEdge.end(), -1);
            }
            this->reverseEdge[edgeCount] = reverseEdge;
        }
        if (edges.size() > 0)
            edges[edgeCount] = createEdge(edgeCount);
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

    long weight(int id) {
        if (weight.size() == 0)
            return 0;
        return weight[id];
    }

    long capacity(int id) {
        if (capacity.size() == 0)
            return 0;
        return capacity[id];
    }

    void pushFlow(int id, long flow) {
        if (flow == 0)
            return;
        if (flow > 0) {
            if (capacity(id) < flow)
                throw invalid_argument("Not enough capacity");
        } else {
            if (flow(id) < -flow)
                throw invalid_argument("Not enough capacity");
        }
        capacity[id] -= flow;
        capacity[reverseEdge[id]] += flow;
    }

    bool isRemoved(int id) {
        return flag(id, REMOVED_BIT);
    }

private:
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> firstInbound;
    vector<int> from;
    vector<int> to;
    vector<long> weight;
    vector<long> capacity;
    vector<int> reverseEdge;
    vector<int> flags;
    vector<int> nextOutbound;
    vector<int> nextInbound;

    void ensureEdgeCapacity(int size) {
        if (from.size() < size) {
            int newSize = max(size, 2 * (int)from.size());
            if (edges.size() > 0)
                edges.resize(newSize);
            from.resize(newSize);
            to.resize(newSize);
            nextOutbound.resize(newSize);
            if (nextInbound.size() > 0)
                nextInbound.resize(newSize);
            if (weight.size() > 0)
                weight.resize(newSize);
            if (capacity.size() > 0)
                capacity.resize(newSize);
            if (reverseEdge.size() > 0)
                reverseEdge.resize(newSize);
            flags.resize(newSize);
        }
    }

    bool flag(int id, int bit) {
        return (flags[id] >> bit & 1) != 0;
    }

    int entriesPerEdge() {
        return 1;
    }

    GraphEdge createEdge(int id) {
        return GraphEdge(id);
    }

    class GraphEdge {
    public:
        GraphEdge(int id) : id(id) {}
    private:
        int id;
    };
};

class MinCostFlow {
public:
    MinCostFlow(Graph &graph, int source, int destination, bool hasNegativeEdges)
        : graph(graph), source(source), destination(destination), vertexCount(graph.vertexCount()) {
        phi.resize(vertexCount);
        if (hasNegativeEdges)
            fordBellman();
        dijkstraResult.resize(vertexCount);
        lastEdge.resize(vertexCount);
        visited.resize(vertexCount);
    }

    pair<long, long> minCostMaxFlow(long maxFlow = numeric_limits<long>::max()) {
        long cost = 0;
        long flow = 0;
        while (maxFlow != 0) {
            dijkstraAlgorithm();
            if (lastEdge[destination] == -1)
                return make_pair(cost, flow);
            for (int i = 0; i < dijkstraResult.size(); i++) {
                if (dijkstraResult[i] != numeric_limits<long>::max())
                    phi[i] += dijkstraResult[i];
            }
            int vertex = destination;
            long currentFlow = maxFlow;
            long currentCost = 0;
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
    Graph &graph;
    int source;
    int destination;
    vector<long> phi;
    vector<long> dijkstraResult;
    vector<int> lastEdge;
    vector<int> visited;
    int vertexCount;

    void fordBellman() {
        fill(phi.begin(), phi.end(), numeric_limits<long>::max());
        phi[source] = 0;
        vector<bool> inQueue(vertexCount);
        vector<int> queue(vertexCount + 1);
        queue[0] = source;
        inQueue[source] = true;
        int stepCount = 0;
        int head = 0;
        int end = 1;
        int maxSteps = 2 * vertexCount * vertexCount;
        while (head != end) {
            int vertex = queue[head++];
            if (head == queue.size())
                head = 0;
            inQueue[vertex] = false;
            int edgeID = graph.firstOutbound(vertex);
            while (edgeID != -1) {
                long total = phi[vertex] + graph.weight(edgeID);
                int destination = graph.destination(edgeID);
                if (graph.capacity(edgeID) != 0 && phi[destination] > total) {
                    phi[destination] = total;
                    if (!inQueue[destination]) {
                        queue[end++] = destination;
                        inQueue[destination] = true;
                        if (end == queue.size())
                            end = 0;
                    }
                }
                edgeID = graph.nextOutbound(edgeID);
            }
            if (++stepCount > maxSteps)
                throw invalid_argument("Graph contains negative cycle");
        }
    }

    void dijkstraAlgorithm() {
        fill(dijkstraResult.begin(), dijkstraResult.end(), numeric_limits<long>::max());
        fill(lastEdge.begin(), lastEdge.end(), -1);
        dijkstraResult[source] = 0;
        // Implement a priority queue or similar structure for efficiency
        // For simplicity, using a basic approach here
        vector<bool> visited(vertexCount, false);
        while (true) {
            int current = -1;
            long minDist = numeric_limits<long>::max();
            for (int i = 0; i < vertexCount; i++) {
                if (!visited[i] && dijkstraResult[i] < minDist) {
                    minDist = dijkstraResult[i];
                    current = i;
                }
            }
            if (current == -1) break;
            visited[current] = true;
            int edgeID = graph.firstOutbound(current);
            while (edgeID != -1) {
                if (graph.capacity(edgeID) != 0) {
                    int next = graph.destination(edgeID);
                    long total = graph.weight(edgeID) - phi[next] + phi[current] + dijkstraResult[current];
                    if (dijkstraResult[next] > total) {
                        dijkstraResult[next] = total;
                        lastEdge[next] = edgeID;
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
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    Graph graph(2 * shoe + 2);
    int source = 2 * shoe, sink = 2 * shoe + 1;

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
