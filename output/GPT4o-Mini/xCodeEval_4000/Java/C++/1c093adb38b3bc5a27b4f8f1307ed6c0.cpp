#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : stream(stream) {}

    int read() {
        if (stream.eof()) throw runtime_error("InputMismatchException");
        return stream.get();
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

private:
    istream &stream;

    bool isSpaceChar(int c) {
        return isspace(c) || c == -1;
    }
};

class OutputWriter {
public:
    OutputWriter(ostream &outputStream) : writer(outputStream) {}

    void printLine(const string &s) {
        writer << s << endl;
    }

private:
    ostream &writer;
};

class Graph {
public:
    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
    }

    int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        ensureEdgeCapacity(edgeCount + 1);
        nextOutbound[edgeCount] = firstOutbound[fromID];
        firstOutbound[fromID] = edgeCount;
        from.push_back(fromID);
        to.push_back(toID);
        weightList.push_back(weight);
        capacityList.push_back(capacity);
        reverseEdgeList.push_back(reverseEdge);
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
        while (id != -1 && isRemoved(id)) id = nextOutbound[id];
        return id;
    }

    int nextOutbound(int id) {
        id = nextOutbound[id];
        while (id != -1 && isRemoved(id)) id = nextOutbound[id];
        return id;
    }

    long weight(int id) const {
        return weightList[id];
    }

    long capacity(int id) const {
        return capacityList[id];
    }

    void pushFlow(int id, long flow) {
        if (flow == 0) return;
        capacityList[id] -= flow;
        capacityList[reverseEdgeList[id]] += flow;
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
    vector<int> reverseEdgeList;

    void ensureEdgeCapacity(int size) {
        if (from.size() < size) {
            from.resize(size);
            to.resize(size);
            nextOutbound.resize(size);
            weightList.resize(size);
            capacityList.resize(size);
            reverseEdgeList.resize(size);
        }
    }

    bool isRemoved(int id) {
        return false; // Placeholder for actual implementation
    }

    int entriesPerEdge() {
        return 1;
    }
};

class MinCostFlow {
public:
    MinCostFlow(Graph &graph, int source, int destination) 
        : graph(graph), source(source), destination(destination), vertexCount(graph.vertexCount()) {
        phi.resize(vertexCount);
        dijkstraResult.resize(vertexCount);
        lastEdge.resize(vertexCount);
    }

    pair<long, long> minCostMaxFlow(long maxFlow = numeric_limits<long>::max()) {
        long cost = 0;
        long flow = 0;
        while (maxFlow != 0) {
            dijkstraAlgorithm();
            if (lastEdge[destination] == -1) return make_pair(cost, flow);
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
    Graph &graph;
    int source;
    int destination;
    int vertexCount;
    vector<long> phi;
    vector<long> dijkstraResult;
    vector<int> lastEdge;

    void dijkstraAlgorithm() {
        fill(dijkstraResult.begin(), dijkstraResult.end(), numeric_limits<long>::max());
        fill(lastEdge.begin(), lastEdge.end(), -1);
        dijkstraResult[source] = 0;
        // Implement the heap logic here
    }
};

class TaskC1 {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        int rowCount = in.readInt();
        int columnCount = in.readInt();
        vector<vector<int>> type(rowCount, vector<int>(columnCount));
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < columnCount; ++j) {
                type[i][j] = in.readInt();
            }
        }
        Graph graph(rowCount * columnCount + 2);
        int source = graph.vertexCount() - 2;
        int sink = graph.vertexCount() - 1;
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                int index = i * columnCount + j;
                if (((i + j) & 1) == 0) {
                    graph.addFlowEdge(source, index, 1);
                    for (int k = 0; k < 4; k++) {
                        int row = i + DX4[k];
                        int column = j + DY4[k];
                        if (isValidCell(row, column, rowCount, columnCount)) {
                            graph.addFlowWeightedEdge(index, row * columnCount + column, type[i][j] == type[row][column] ? 0 : 1, 1);
                        }
                    }
                } else {
                    graph.addFlowEdge(index, sink, 1);
                }
            }
        }
        out.printLine(to_string(MinCostFlow(graph, source, sink).minCostMaxFlow().first));
    }

private:
    static const int DX4[4];
    static const int DY4[4];

    static bool isValidCell(int row, int column, int rowCount, int columnCount) {
        return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
    }
};

const int TaskC1::DX4[4] = {1, 0, -1, 0};
const int TaskC1::DY4[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    InputReader in(cin);
    OutputWriter out(cout);
    TaskC1 solver;
    solver.solve(1, in, out);
    return 0;
}
