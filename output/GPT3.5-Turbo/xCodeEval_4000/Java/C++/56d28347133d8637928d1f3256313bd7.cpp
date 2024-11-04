#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int from, to;
    long long weight, capacity;
    int reverseEdge;
};

class Graph {
public:
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> firstInbound;
    vector<Edge> edges;
    vector<int> nextInbound;
    vector<int> nextOutbound;
    vector<int> from;
    vector<int> to;
    vector<long long> weight;
    vector<long long> capacity;
    vector<int> reverseEdge;
    vector<int> flags;

    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
    }

    int addEdge(int from, int to, long long weight, long long capacity, int reverseEdge) {
        int id = edges.size();
        edges.push_back({from, to, weight, capacity, reverseEdge});
        if (firstOutbound[from] != -1) {
            nextOutbound[id] = firstOutbound[from];
        } else {
            nextOutbound[id] = -1;
        }
        firstOutbound[from] = id;
        if (firstInbound.size() > 0) {
            if (firstInbound[to] != -1) {
                nextInbound[id] = firstInbound[to];
            } else {
                nextInbound[id] = -1;
            }
            firstInbound[to] = id;
        }
        this->from.push_back(from);
        this->to.push_back(to);
        this->weight.push_back(weight);
        this->capacity.push_back(capacity);
        this->reverseEdge.push_back(reverseEdge);
        flags.push_back(0);
        return id;
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
            int newSize = max(size, 2 * static_cast<int>(from.size()));
            from.resize(newSize);
            to.resize(newSize);
            nextOutbound.resize(newSize);
            if (nextInbound.size() > 0) {
                nextInbound.resize(newSize);
            }
            weight.resize(newSize);
            capacity.resize(newSize);
            reverseEdge.resize(newSize);
            flags.resize(newSize);
        }
    }

    int entriesPerEdge() {
        return 1;
    }
};

class MinCostFlow {
public:
    Graph graph;
    int source;
    int destination;
    vector<long long> phi;
    vector<long long> dijkstraResult;
    vector<int> lastEdge;
    vector<int> visited;
    int visitIndex;

    MinCostFlow(Graph graph, int source, int destination, bool hasNegativeEdges) : graph(graph), source(source), destination(destination) {
        int vertexCount = graph.vertexCount;
        phi.resize(vertexCount);
        if (hasNegativeEdges) {
            fordBellman();
        }
        dijkstraResult.resize(vertexCount);
        lastEdge.resize(vertexCount);
        if (graph.firstInbound.size() > 0) {
            visited.resize(vertexCount);
        }
    }

    pair<long long, long long> minCostMaxFlow() {
        return minCostMaxFlow(numeric_limits<long long>::max());
    }

    pair<long long, long long> minCostMaxFlow(long long maxFlow) {
        long long cost = 0;
        long long flow = 0;
        while (maxFlow != 0) {
            if (graph.firstInbound.size() > 0) {
                dijkstraAlgorithmFull();
            } else {
                dijkstraAlgorithm();
            }
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
                graph.capacity[edgeID] -= currentFlow;
                graph.capacity[graph.reverseEdge[edgeID]] += currentFlow;
                vertex = graph.from[edgeID];
            }
        }
        return make_pair(cost, flow);
    }

    void fordBellman() {
        fill(phi.begin(), phi.end(), numeric_limits<long long>::max());
        phi[source] = 0;
        vector<bool> inQueue(graph.vertexCount);
        vector<int> queue(graph.vertexCount + 1);
        int head = 0;
        int tail = 1;
        queue[0] = source;
        inQueue[source] = true;
        int stepCount = 0;
        int maxSteps = 2 * graph.vertexCount * graph.vertexCount;
        while (head != tail) {
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
                        queue[tail++] = destination;
                        if (tail == queue.size()) {
                            tail = 0;
                        }
                        inQueue[destination] = true;
                    }
                }
                edgeID = graph.nextOutbound[edgeID];
            }
            if (++stepCount > maxSteps) {
                throw invalid_argument("Graph contains negative cycle");
            }
        }
    }

    void dijkstraAlgorithm() {
        fill(dijkstraResult.begin(), dijkstraResult.end(), numeric_limits<long long>::max());
        fill(lastEdge.begin(), lastEdge.end(), -1);
        dijkstraResult[source] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            pair<long long, int> top = pq.top();
            pq.pop();
            int current = top.second;
            if (top.first != dijkstraResult[current]) {
                continue;
            }
            int edgeID = graph.firstOutbound[current];
            while (edgeID != -1) {
                if (graph.capacity[edgeID] != 0) {
                    int next = graph.to[edgeID];
                    long long total = graph.weight[edgeID] - phi[next] + phi[current] + dijkstraResult[current];
                    if (dijkstraResult[next] > total) {
                        dijkstraResult[next] = total;
                        pq.push(make_pair(total, next));
                        lastEdge[next] = edgeID;
                    }
                }
                edgeID = graph.nextOutbound[edgeID];
            }
        }
    }

    void dijkstraAlgorithmFull() {
        visitIndex++;
        fill(dijkstraResult.begin(), dijkstraResult.end(), numeric_limits<long long>::max());
        lastEdge[destination] = -1;
        dijkstraResult[source] = 0;
        for (int i = 0; i < graph.vertexCount; i++) {
            int index = -1;
            long long length = numeric_limits<long long>::max();
            for (int j = 0; j < graph.vertexCount; j++) {
                if (visited[j] != visitIndex && dijkstraResult[j] < length) {
                    length = dijkstraResult[j];
                    index = j;
                }
            }
            if (index == -1) {
                return;
            }
            visited[index] = visitIndex;
            int edgeID = graph.firstOutbound[index];
            while (edgeID != -1) {
                if (graph.capacity[edgeID] != 0) {
                    int next = graph.to[edgeID];
                    if (visited[next] != visitIndex) {
                        long long total = graph.weight[edgeID] - phi[next] + phi[index] + length;
                        if (dijkstraResult[next] > total) {
                            dijkstraResult[next] = total;
                            lastEdge[next] = edgeID;
                        }
                    }
                }
                edgeID = graph.nextOutbound[edgeID];
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

    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

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
                    graph.addEdge(id, id1, wt, 1, 1);
                }
                graph.addEdge(source, id, 0, 1, 1);
            } else {
                graph.addEdge(id, sink, 0, 1, 1);
            }
        }
    }

    MinCostFlow mcf(graph, source, sink, false);
    pair<long long, long long> ans = mcf.minCostMaxFlow();
    cout << ans.first << endl;

    return 0;
}
