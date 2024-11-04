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
    explicit Graph(int vertexCount) : vertexCount(vertexCount), firstOutbound(vertexCount, -1) {}

    int addEdge(int from, int to, long long weight, long long capacity, int reverseEdge) {
        edges.push_back({from, to, weight, capacity, reverseEdge});
        int id = edges.size() - 1;
        if (firstOutbound[from] != -1) {
            edges[id].nextOutbound = firstOutbound[from];
        }
        firstOutbound[from] = id;
        return id;
    }

    int vertexCount;
    vector<Edge> edges;
    vector<int> firstOutbound;
};

class MinCostFlow {
public:
    MinCostFlow(Graph& graph, int source, int destination, bool hasNegativeEdges)
        : graph(graph), source(source), destination(destination), vertexCount(graph.vertexCount),
          phi(vertexCount), dijkstraResult(vertexCount), lastEdge(vertexCount), visited(vertexCount) {
        if (hasNegativeEdges) {
            fordBellman();
        }
    }

    pair<long long, long long> minCostMaxFlow(long long maxFlow) {
        long long cost = 0, flow = 0;
        while (maxFlow != 0) {
            dijkstraAlgorithm();
            if (lastEdge[destination] == -1) {
                return make_pair(cost, flow);
            }
            for (int i = 0; i < dijkstraResult.size(); ++i) {
                if (dijkstraResult[i] != numeric_limits<long long>::max()) {
                    phi[i] += dijkstraResult[i];
                }
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

private:
    Graph& graph;
    int source, destination;
    int vertexCount;
    vector<long long> phi;
    vector<long long> dijkstraResult;
    vector<int> lastEdge;
    vector<int> visited;

    void fordBellman() {
        fill(phi.begin(), phi.end(), numeric_limits<long long>::max());
        phi[source] = 0;
        vector<bool> inQueue(vertexCount, false);
        vector<int> queue;
        queue.push_back(source);
        inQueue[source] = true;
        int stepCount = 0;
        int head = 0;
        int end = 1;
        int maxSteps = 2 * vertexCount * vertexCount;
        while (head != end) {
            int vertex = queue[head++];
            if (head == queue.size()) {
                head = 0;
            }
            inQueue[vertex] = false;
            int edgeID = graph.firstOutbound[vertex];
            while (edgeID != -1) {
                long long total = phi[vertex] + graph.edges[edgeID].weight;
                int destination = graph.edges[edgeID].to;
                if (graph.edges[edgeID].capacity != 0 && phi[destination] > total) {
                    phi[destination] = total;
                    if (!inQueue[destination]) {
                        queue.push_back(destination);
                        inQueue[destination] = true;
                        if (end == queue.size()) {
                            end = 0;
                        }
                    }
                }
                edgeID = graph.edges[edgeID].nextOutbound;
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
            int current = pq.top().second;
            long long currentResult = pq.top().first;
            pq.pop();
            if (currentResult != dijkstraResult[current]) {
                continue;
            }
            int edgeID = graph.firstOutbound[current];
            while (edgeID != -1) {
                if (graph.edges[edgeID].capacity != 0) {
                    int next = graph.edges[edgeID].to;
                    long long total = graph.edges[edgeID].weight - phi[next] + phi[current] + dijkstraResult[current];
                    if (dijkstraResult[next] > total) {
                        dijkstraResult[next] = total;
                        pq.push(make_pair(total, next));
                        lastEdge[next] = edgeID;
                    }
                }
                edgeID = graph.edges[edgeID].nextOutbound;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ugliness(n);
    for (int i = 0; i < n; ++i) {
        cin >> ugliness[i];
        ugliness[i] = -ugliness[i];
    }

    Graph graph(1 + 26 + n / 2 + 1);
    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 0; i < n / 2; ++i) {
            int cost = 0;
            if (c == s[i]) {
                cost = min(cost, ugliness[i]);
            }
            if (c == s[n - 1 - i]) {
                cost = min(cost, ugliness[n - 1 - i]);
            }
            graph.addEdge(1 + (c - 'a'), 1 + 26 + i, cost, 1, -1);
        }
    }

    vector<int> occurs(128);
    for (int i = 0; i < n; ++i) {
        occurs[s[i]]++;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        graph.addEdge(0, 1 + (c - 'a'), 0, occurs[c], -1);
    }

    for (int i = 0; i < n / 2; ++i) {
        graph.addEdge(1 + 26 + i, 1 + 26 + n / 2, 0, 2, -1);
    }

    pair<long long, long long> flow = MinCostFlow(graph, 0, 1 + 26 + n / 2, true).minCostMaxFlow(n);
    cout << -flow.first << endl;

    return 0;
}
