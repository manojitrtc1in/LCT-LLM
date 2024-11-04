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
    vector<vector<int>> outEdges;
    vector<Edge> edges;

    Graph(int vertexCount) : vertexCount(vertexCount), outEdges(vertexCount) {}

    void addEdge(int from, int to, long long weight, long long capacity, int reverseEdge) {
        Edge e1 = {from, to, weight, capacity, reverseEdge};
        outEdges[from].push_back(edges.size());
        edges.push_back(e1);
        Edge e2 = {to, from, -weight, 0, edges.size() - 1};
        outEdges[to].push_back(edges.size());
        edges.push_back(e2);
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

    MinCostFlow(Graph graph, int source, int destination, bool hasNegativeEdges) : graph(graph), source(source), destination(destination), phi(graph.vertexCount), dijkstraResult(graph.vertexCount), lastEdge(graph.vertexCount), visited(graph.vertexCount) {
        if (hasNegativeEdges) {
            fordBellman();
        }
    }

    pair<long long, long long> minCostMaxFlow() {
        long long cost = 0;
        long long flow = 0;
        while (true) {
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
            long long currentFlow = numeric_limits<long long>::max();
            long long currentCost = 0;
            while (vertex != source) {
                int edgeID = lastEdge[vertex];
                currentFlow = min(currentFlow, graph.edges[edgeID].capacity);
                currentCost += graph.edges[edgeID].weight;
                vertex = graph.edges[edgeID].from;
            }
            flow += currentFlow;
            cost += currentCost * currentFlow;
            vertex = destination;
            while (vertex != source) {
                int edgeID = lastEdge[vertex];
                graph.edges[edgeID].capacity -= currentFlow;
                graph.edges[graph.edges[edgeID].reverseEdge].capacity += currentFlow;
                vertex = graph.edges[edgeID].from;
            }
        }
    }

private:
    void fordBellman() {
        phi.assign(graph.vertexCount, numeric_limits<long long>::max());
        phi[source] = 0;
        vector<bool> inQueue(graph.vertexCount);
        queue<int> q;
        q.push(source);
        inQueue[source] = true;
        int stepCount = 0;
        int maxSteps = 2 * graph.vertexCount * graph.vertexCount;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            inQueue[vertex] = false;
            for (int edgeID : graph.outEdges[vertex]) {
                long long total = phi[vertex] + graph.edges[edgeID].weight;
                if (graph.edges[edgeID].capacity != 0 && phi[graph.edges[edgeID].to] > total) {
                    phi[graph.edges[edgeID].to] = total;
                    if (!inQueue[graph.edges[edgeID].to]) {
                        q.push(graph.edges[edgeID].to);
                        inQueue[graph.edges[edgeID].to] = true;
                    }
                }
            }
            if (++stepCount > maxSteps) {
                throw invalid_argument("Graph contains negative cycle");
            }
        }
    }

    void dijkstraAlgorithm() {
        dijkstraResult.assign(graph.vertexCount, numeric_limits<long long>::max());
        lastEdge.assign(graph.vertexCount, -1);
        dijkstraResult[source] = 0;
        if (graph.vertexCount <= 1) {
            return;
        }
        if (graph.vertexCount <= 2) {
            throw invalid_argument("Graph contains a negative cycle");
        }
        visited.assign(graph.vertexCount, visitIndex);
        vector<int> heap;
        heap.push_back(source);
        vector<int> position(graph.vertexCount);
        position[source] = 0;
        auto cmp = [&](int a, int b) {
            return dijkstraResult[a] < dijkstraResult[b];
        };
        while (!heap.empty()) {
            int current = heap[0];
            if (current == destination) {
                return;
            }
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
            for (int edgeID : graph.outEdges[current]) {
                if (graph.edges[edgeID].capacity != 0) {
                    int next = graph.edges[edgeID].to;
                    long long total = graph.edges[edgeID].weight - phi[next] + phi[current] + dijkstraResult[current];
                    if (visited[next] != visitIndex || dijkstraResult[next] > total) {
                        dijkstraResult[next] = total;
                        lastEdge[next] = edgeID;
                        if (visited[next] != visitIndex) {
                            visited[next] = visitIndex;
                            heap.push_back(next);
                            position[next] = heap.size() - 1;
                        } else {
                            int i = position[next];
                            while (i > 0 && cmp(heap[(i - 1) / 2], next)) {
                                heap[i] = heap[(i - 1) / 2];
                                position[heap[i]] = i;
                                i = (i - 1) / 2;
                            }
                            heap[i] = next;
                            position[next] = i;
                        }
                    }
                }
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    vector<int> cnt(26);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
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
            if (s[j] == s[n - j - 1]) {
                int w = 0;
                if (s[j] == i + 'a') {
                    w = -max(a[j], a[n - j - 1]);
                }
                g.addEdge(i + n, j, w, 1, -1);
            } else {
                int w = 0;
                if (s[j] == i + 'a') {
                    w -= a[j];
                }
                if (s[n - j - 1] == i + 'a') {
                    w -= a[n - j - 1];
                }
                g.addEdge(i + n, j, w, 1, -1);
            }
        }
    }
    MinCostFlow mcmf(g, source, target, true);
    auto result = mcmf.minCostMaxFlow();
    cout << -result.first << endl;
    return 0;
}
