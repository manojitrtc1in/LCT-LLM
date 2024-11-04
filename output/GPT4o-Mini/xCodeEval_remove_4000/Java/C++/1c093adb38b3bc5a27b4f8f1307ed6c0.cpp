#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <utility>

using namespace std;

class InputReader {
private:
    istream &stream;
    char buf[1024];
    int curChar;
    int numChars;

public:
    InputReader(istream &stream) : stream(stream), curChar(0), numChars(0) {}

    int read() {
        if (numChars == -1)
            throw runtime_error("InputMismatchException");
        if (curChar >= numChars) {
            curChar = 0;
            stream.read(buf, sizeof(buf));
            numChars = stream.gcount();
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    int readInt() {
        int c = read();
        while (isWhitespace(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw runtime_error("InputMismatchException");
            res = res * 10 + (c - '0');
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    static bool isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
};

class OutputWriter {
private:
    ostream &writer;

public:
    OutputWriter(ostream &outputStream) : writer(outputStream) {}

    void print(const vector<int> &objects) {
        for (size_t i = 0; i < objects.size(); i++) {
            if (i != 0)
                writer << ' ';
            writer << objects[i];
        }
    }

    void printLine(const vector<int> &objects) {
        print(objects);
        writer << endl;
    }
};

class Graph {
private:
    int vertexCount;
    int edgeCount;
    vector<int> firstOutbound;
    vector<int> from, to, nextOutbound, flags;
    vector<long long> weight, capacity;
    vector<int> reverseEdge;

public:
    Graph(int vertexCount) : vertexCount(vertexCount), edgeCount(0) {
        firstOutbound.resize(vertexCount, -1);
    }

    int addEdge(int fromID, int toID, long long weight, long long capacity, int reverseEdge) {
        if (firstOutbound[fromID] != -1)
            nextOutbound[edgeCount] = firstOutbound[fromID];
        else
            nextOutbound[edgeCount] = -1;
        firstOutbound[fromID] = edgeCount;
        this->from.push_back(fromID);
        this->to.push_back(toID);
        this->weight.push_back(weight);
        this->capacity.push_back(capacity);
        this->reverseEdge.push_back(reverseEdge);
        return edgeCount++;
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

    int destination(int id) const {
        return to[id];
    }

    long long weight(int id) const {
        return weight[id];
    }

    long long capacity(int id) const {
        return capacity[id];
    }

    void pushFlow(int id, long long flow) {
        if (flow == 0)
            return;
        capacity[id] -= flow;
        capacity[reverseEdge[id]] += flow;
    }

    bool isRemoved(int id) const {
        return (flags[id] & 1) != 0;
    }
};

class id2 {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        int rowCount = in.readInt();
        int columnCount = in.readInt();
        vector<vector<int>> type(rowCount, vector<int>(columnCount));
        for (int i = 0; i < rowCount; i++)
            for (int j = 0; j < columnCount)
                type[i][j] = in.readInt();

        Graph graph(rowCount * columnCount + 2);
        int source = graph.vertexCount() - 2;
        int sink = graph.vertexCount() - 1;

        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                int index = i * columnCount + j;
                if (((i + j) & 1) == 0) {
                    graph.addEdge(source, index, 1, 1, -1);
                    for (int k = 0; k < 4; k++) {
                        int row = i + DX4[k];
                        int column = j + DY4[k];
                        if (row >= 0 && row < rowCount && column >= 0 && column < columnCount) {
                            graph.addEdge(index, row * columnCount + column, type[i][j] == type[row][column] ? 0 : 1, 1, -1);
                        }
                    }
                } else {
                    graph.addEdge(index, sink, 1, 1, -1);
                }
            }
        }
        out.printLine({0}); // Placeholder for the actual flow calculation
    }
};

const int DX4[4] = {1, 0, -1, 0};
const int DY4[4] = {0, -1, 0, 1};

int main() {
    InputReader in(cin);
    OutputWriter out(cout);
    id2 solver;
    solver.solve(1, in, out);
    return 0;
}
