#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to;
    long long weight, capacity;
    int reverseEdge;
};

class Graph {
public:
    int vertexCount;
    vector<vector<int>> outbound;
    vector<vector<int>> inbound;
    vector<Edge> edges;

    Graph(int vertexCount) : vertexCount(vertexCount) {
        outbound.resize(vertexCount);
        inbound.resize(vertexCount);
    }

    void addEdge(int from, int to, long long weight, long long capacity, int reverseEdge) {
        outbound[from].push_back(edges.size());
        inbound[to].push_back(edges.size());
        edges.push_back({from, to, weight, capacity, reverseEdge});
    }
};

class MinCostFlow {
public:
    Graph graph;
    int source, destination;
    vector<long long> phi;
    vector<long long> dijkstraResult;
    vector<int> lastEdge;
    vector<int> visited;
    int visitIndex;

    MinCostFlow(Graph graph, int source, int destination, bool hasNegativeEdges) : graph(graph), source(source), destination(destination) {
        phi.resize(graph.vertexCount, 0);
        if (hasNegativeEdges)
            fordBellman();
        dijkstraResult.resize(graph.vertexCount, numeric_limits<long long>::max());
        lastEdge.resize(graph.vertexCount, -1);
        visited.resize(graph.vertexCount, 0);
    }

    void fordBellman() {
        phi[source] = 0;
        vector<bool> inQueue(graph.vertexCount, false);
        queue<int> q;
        q.push(source);
        inQueue[source] = true;
        int stepCount = 0;
        int maxSteps = 2 * graph.vertexCount * graph.vertexCount;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            inQueue[vertex] = false;
            for (int edgeID : graph.outbound[vertex]) {
                Edge& edge = graph.edges[edgeID];
                long long total = phi[vertex] + edge.weight;
                if (edge.capacity != 0 && phi[edge.to] > total) {
                    phi[edge.to] = total;
                    if (!inQueue[edge.to]) {
                        q.push(edge.to);
                        inQueue[edge.to] = true;
                    }
                }
            }
            if (++stepCount > maxSteps)
                throw invalid_argument("Graph contains negative cycle");
        }
    }

    pair<long long, long long> minCostMaxFlow() {
        return minCostMaxFlow(numeric_limits<long long>::max());
    }

    pair<long long, long long> minCostMaxFlow(long long maxFlow) {
        long long cost = 0;
        long long flow = 0;
        while (maxFlow != 0) {
            dijkstraAlgorithm();
            if (lastEdge[destination] == -1)
                return make_pair(cost, flow);
            for (int i = 0; i < dijkstraResult.size(); i++) {
                if (dijkstraResult[i] != numeric_limits<long long>::max())
                    phi[i] += dijkstraResult[i];
            }
            int vertex = destination;
            long long currentFlow = maxFlow;
            long long currentCost = 0;
            while (vertex != source) {
                int edgeID = lastEdge[vertex];
                currentFlow = min(currentFlow, graph.edges[edgeID].capacity);
                currentCost += graph.edges[edgeID].weight;
                vertex = graph.edges[edgeID].from;
            }
            maxFlow -= currentFlow;
            cost += currentCost * currentFlow;
            flow += currentFlow;
            vertex = destination;
            while (vertex != source) {
                int edgeID = lastEdge[vertex];
                graph.edges[edgeID].capacity -= currentFlow;
                graph.edges[graph.edges[edgeID].reverseEdge].capacity += currentFlow;
                vertex = graph.edges[edgeID].from;
            }
        }
        return make_pair(cost, flow);
    }

    void dijkstraAlgorithm() {
        dijkstraResult.assign(graph.vertexCount, numeric_limits<long long>::max());
        lastEdge.assign(graph.vertexCount, -1);
        dijkstraResult[source] = 0;
        if (graph.outbound.size() < graph.vertexCount) {
            heapDijkstraAlgorithm();
        } else {
            fullDijkstraAlgorithm();
        }
    }

    void heapDijkstraAlgorithm() {
        visitIndex++;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            int current = pq.top().second;
            long long length = pq.top().first;
            pq.pop();
            if (dijkstraResult[current] != length)
                continue;
            for (int edgeID : graph.outbound[current]) {
                Edge& edge = graph.edges[edgeID];
                long long total = edge.weight - phi[edge.to] + phi[edge.from] + length;
                if (edge.capacity != 0 && dijkstraResult[edge.to] > total) {
                    dijkstraResult[edge.to] = total;
                    lastEdge[edge.to] = edgeID;
                    pq.push(make_pair(total, edge.to));
                }
            }
        }
    }

    void fullDijkstraAlgorithm() {
        visitIndex++;
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
            for (int edgeID : graph.outbound[index]) {
                Edge& edge = graph.edges[edgeID];
                if (visited[edge.to] != visitIndex && edge.capacity != 0) {
                    long long total = edge.weight - phi[edge.to] + phi[edge.from] + length;
                    if (dijkstraResult[edge.to] > total) {
                        dijkstraResult[edge.to] = total;
                        lastEdge[edge.to] = edgeID;
                    }
                }
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
                    if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= m)
                        continue;
                    int id1 = i1 * m + j1;
                    int wt = (a[i][j] == a[i1][j1]) ? 0 : 1;
                    graph.addEdge(id, id1, wt, 1, -1);
                }
                graph.addEdge(source, id, 0, 1, -1);
            } else {
                graph.addEdge(id, sink, 0, 1, -1);
            }
        }
    }

    MinCostFlow mcf(graph, source, sink, false);
    pair<long long, long long> ans = mcf.minCostMaxFlow();
    cout << ans.first << endl;

    return 0;
}
