#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <functional>

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
        firstOutbound.assign(vertexCount, -1);
    }

    int addEdge(int from, int to, long long weight, long long capacity, int reverseEdge) {
        this->from.push_back(from);
        this->to.push_back(to);
        this->weight.push_back(weight);
        this->capacity.push_back(capacity);
        this->reverseEdge.push_back(reverseEdge);
        this->flags.push_back(0);

        if (firstOutbound[from] != -1) {
            nextOutbound.push_back(firstOutbound[from]);
        } else {
            nextOutbound.push_back(-1);
        }
        firstOutbound[from] = edgeCount;

        if (firstInbound.size() > 0) {
            if (firstInbound[to] != -1) {
                nextInbound.push_back(firstInbound[to]);
            } else {
                nextInbound.push_back(-1);
            }
            firstInbound[to] = edgeCount;
        }

        edges.push_back(Edge{from, to, weight, capacity, reverseEdge});
        return edgeCount++;
    }
};

class MinCostFlow {
private:
    Graph graph;
    int source;
    int destination;
    vector<long long> phi;
    vector<long long> dijkstraResult;
    vector<int> lastEdge;
    vector<int> visited;
    int visitIndex;

public:
    MinCostFlow(Graph graph, int source, int destination, bool hasNegativeEdges) :
        graph(graph), source(source), destination(destination), visitIndex(0) {
        phi.assign(graph.vertexCount, 0);
        if (hasNegativeEdges) {
            fordBellman();
        }
        dijkstraResult.assign(graph.vertexCount, numeric_limits<long long>::max());
        lastEdge.assign(graph.vertexCount, -1);
        visited.assign(graph.vertexCount, 0);
    }

    pair<long long, long long> minCostMaxFlow() {
        return minCostMaxFlow(numeric_limits<long long>::max());
    }

    pair<long long, long long> minCostMaxFlow(long long maxFlow) {
        long long cost = 0;
        long long flow = 0;
        while (maxFlow != 0) {
            if (graph.firstOutbound.size() > 0) {
                dijkstraAlgorithm();
            } else {
                dijkstraAlgorithmFull();
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

private:
    void fordBellman() {
        phi[source] = 0;
        vector<bool> inQueue(graph.vertexCount, false);
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
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> heap;
        heap.push(make_pair(0, source));
        while (!heap.empty()) {
            int current = heap.top().second;
            long long currentResult = heap.top().first;
            heap.pop();
            if (currentResult != dijkstraResult[current]) {
                continue;
            }
            int edgeID = graph.firstOutbound[current];
            while (edgeID != -1) {
                if (graph.capacity[edgeID] != 0) {
                    int next = graph.to[edgeID];
                    long long total = graph.weight[edgeID] - phi[next] + phi[current] + dijkstraResult[current];
                    if (dijkstraResult[next] > total) {
                        dijkstraResult[next] = total;
                        heap.push(make_pair(total, next));
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
    int rowCount, columnCount;
    cin >> rowCount >> columnCount;
    vector<vector<int>> type(rowCount, vector<int>(columnCount));
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            cin >> type[i][j];
        }
    }

    Graph graph(rowCount * columnCount + 2);
    int source = graph.vertexCount - 2;
    int sink = graph.vertexCount - 1;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            int index = i * columnCount + j;
            if (((i + j) & 1) == 0) {
                graph.addEdge(source, index, 1, 0, -1);
                for (int k = 0; k < 4; k++) {
                    int row = i + DX4[k];
                    int column = j + DY4[k];
                    if (isValidCell(row, column, rowCount, columnCount)) {
                        graph.addEdge(index, row * columnCount + column, type[i][j] == type[row][column] ? 0 : 1, 1, -1);
                    }
                }
            } else {
                graph.addEdge(index, sink, 1, 0, -1);
            }
        }
    }

    pair<long long, long long> result = MinCostFlow(graph, source, sink, false).minCostMaxFlow();
    cout << result.first << endl;

    return 0;
}
