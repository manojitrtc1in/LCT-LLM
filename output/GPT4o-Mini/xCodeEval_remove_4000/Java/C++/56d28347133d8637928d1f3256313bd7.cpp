#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>
#include <utility>
#include <algorithm>

using namespace std;

class Graph {
public:
    static const int id14 = 0;

    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
        from.resize(vertexCount);
        to.resize(vertexCount);
        nextOutbound.resize(vertexCount);
        flags.resize(vertexCount);
    }

    int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        id8(edgeCount + 1);
        if (firstOutbound[fromID] != -1)
            nextOutbound[edgeCount] = firstOutbound[fromID];
        else
            nextOutbound[edgeCount] = -1;
        firstOutbound[fromID] = edgeCount;
        this->from[edgeCount] = fromID;
        this->to[edgeCount] = toID;
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

    int id3(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id4 = edgeCount;
            addEdge(to, from, -weight, 0, id4 + id7());
            return addEdge(from, to, weight, capacity, id4);
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

    long flow(int id) {
        if (reverseEdge.empty())
            return 0;
        return capacity[reverseEdge[id]];
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
        return flag(id, id14);
    }

private:
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> from;
    vector<int> to;
    vector<int> nextOutbound;
    vector<long> weight;
    vector<long> capacity;
    vector<int> reverseEdge;
    vector<int> flags;

    void id8(int size) {
        if (from.size() < size) {
            int newSize = max(size, 2 * from.size());
            from.resize(newSize);
            to.resize(newSize);
            nextOutbound.resize(newSize);
            if (!nextInbound.empty())
                nextInbound.resize(newSize);
            if (!weight.empty())
                weight.resize(newSize);
            if (!capacity.empty())
                capacity.resize(newSize);
            if (!reverseEdge.empty())
                reverseEdge.resize(newSize);
            flags.resize(newSize);
        }
    }

    bool flag(int id, int bit) {
        return (flags[id] >> bit & 1) != 0;
    }
};

class id5 {
public:
    id5(Graph& graph, int source, int destination, bool id11) 
        : graph(graph), source(source), destination(destination), vertexCount(graph.vertexCount()) {
        phi.resize(vertexCount);
        if (id11)
            id6();
        id13.resize(vertexCount);
        lastEdge.resize(vertexCount);
    }

    pair<long, long> id2(long maxFlow = numeric_limits<long>::max()) {
        long cost = 0;
        long flow = 0;
        while (maxFlow != 0) {
            id12();
            if (lastEdge[destination] == -1)
                return make_pair(cost, flow);
            for (int i = 0; i < id13.size(); i++) {
                if (id13[i] != numeric_limits<long>::max())
                    phi[i] += id13[i];
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
    Graph& graph;
    int source;
    int destination;
    vector<long> phi;
    vector<long> id13;
    vector<int> lastEdge;
    int vertexCount;

    void id6() {
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
                int dest = graph.destination(edgeID);
                if (graph.capacity(edgeID) != 0 && phi[dest] > total) {
                    phi[dest] = total;
                    if (!inQueue[dest]) {
                        queue[end++] = dest;
                        inQueue[dest] = true;
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

    void id12() {
        fill(id13.begin(), id13.end(), numeric_limits<long>::max());
        fill(lastEdge.begin(), lastEdge.end(), -1);
        id13[source] = 0;
        // Implement the heap logic here if needed
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
                    graph.id3(id, id1, wt, 1);
                }
                graph.id3(source, id, 0, 1);
            } else {
                graph.id3(id, sink, 0, 1);
            }
        }
    }

    id5 mcf(graph, source, sink, false);
    pair<long, long> ans = mcf.id2();
    cout << ans.first << endl;

    return 0;
}
