#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct Edge {
    int from;
    int to;
    long long weight;
    long long capacity;
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

    Graph(int vertexCount) : vertexCount(vertexCount) {
        firstOutbound.resize(vertexCount, -1);
    }

    int addEdge(int fromID, int toID, long long weight, long long capacity, int reverseEdge) {
        ensureEdgeCapacity(edgeCount + 1);
        if (firstOutbound[fromID] != -1) {
            nextOutbound[edgeCount] = firstOutbound[fromID];
        } else {
            nextOutbound[edgeCount] = -1;
        }
        firstOutbound[fromID] = edgeCount;
        if (!firstInbound.empty()) {
            if (firstInbound[toID] != -1) {
                nextInbound[edgeCount] = firstInbound[toID];
            } else {
                nextInbound[edgeCount] = -1;
            }
            firstInbound[toID] = edgeCount;
        }
        this->from[edgeCount] = fromID;
        this->to[edgeCount] = toID;
        if (capacity != 0) {
            if (this->capacity.empty()) {
                this->capacity.resize(from.size());
            }
            this->capacity[edgeCount] = capacity;
        }
        if (weight != 0) {
            if (this->weight.empty()) {
                this->weight.resize(from.size());
            }
            this->weight[edgeCount] = weight;
        }
        if (reverseEdge != -1) {
            if (this->reverseEdge.empty()) {
                this->reverseEdge.resize(from.size(), -1);
            }
            this->reverseEdge[edgeCount] = reverseEdge;
        }
        if (!edges.empty()) {
            edges[edgeCount] = createEdge(edgeCount);
        }
        return edgeCount++;
    }

    void ensureEdgeCapacity(int size) {
        if (from.size() < size) {
            int newSize = max(size, 2 * (int)from.size());
            if (!edges.empty()) {
                edges.resize(newSize);
            }
            from.resize(newSize);
            to.resize(newSize);
            nextOutbound.resize(newSize);
            if (!nextInbound.empty()) {
                nextInbound.resize(newSize);
            }
            if (!weight.empty()) {
                weight.resize(newSize);
            }
            if (!capacity.empty()) {
                capacity.resize(newSize);
            }
            if (!reverseEdge.empty()) {
                reverseEdge.resize(newSize);
            }
            flags.resize(newSize);
        }
    }

    Edge createEdge(int id) {
        return Edge{id};
    }
};

class TaskD {
public:
    Graph graph;
    vector<int> weight;
    vector<int> path;

    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> u(n - 1), v(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> u[i] >> v[i];
        }
        for (int i = 0; i < n - 1; i++) {
            u[i]--;
            v[i]--;
        }
        graph = Graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph.addEdge(u[i], v[i], 0, 0, -1);
            graph.addEdge(v[i], u[i], 0, 0, -1);
        }
        vector<int> order = createOrder(a);
        reverse(order.begin(), order.end());
        int left = k;
        int right = n;
        weight.resize(n);
        vector<int> degree(n);
        for (int i = 0; i < n - 1; i++) {
            degree[u[i]]++;
            degree[v[i]]++;
        }
        vector<int> remaining(n);
        vector<int> queue(n);
        path.resize(n);
        while (left < right) {
            int middle = (left + right) >> 1;
            int threshold = a[order[middle - 1]];
            fill(weight.begin(), weight.end(), 0);
            for (int i = 0; i < n; i++) {
                weight[i] = a[i] >= threshold ? 1 : 0;
            }
            copy(degree.begin(), degree.end(), remaining.begin());
            int size = 0;
            for (int i = 0; i < n; i++) {
                if (degree[i] == 1 && weight[i] > 0) {
                    queue[size++] = i;
                }
            }
            for (int i = 0; i < size; i++) {
                int current = queue[i];
                for (int j = graph.firstOutbound[current]; j != -1; j = graph.nextOutbound[j]) {
                    int next = graph.to[j];
                    if (weight[next] != 0) {
                        weight[next] += weight[current];
                        weight[current] = 0;
                        remaining[next]--;
                        if (remaining[next] == 1) {
                            queue[size++] = next;
                        }
                    }
                }
            }
            int result = dfs(0, -1);
            if (result >= k) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        cout << a[order[left - 1]] << endl;
    }

    int dfs(int current, int last) {
        int result = 0;
        int max = 0;
        int second = 0;
        for (int i = graph.firstOutbound[current]; i != -1; i = graph.nextOutbound[i]) {
            int next = graph.to[i];
            if (next == last) {
                continue;
            }
            result = max(result, dfs(next, current));
            if (path[next] > max) {
                second = max;
                max = path[next];
            } else {
                second = max(second, path[next]);
            }
        }
        if (weight[current] != 0) {
            path[current] = weight[current] + max;
            result = max(result, max + second + weight[current]);
        } else {
            path[current] = 0;
        }
        return result;
    }

    vector<int> createOrder(const vector<int>& array) {
        vector<int> order(array.size());
        for (int i = 0; i < array.size(); i++) {
            order[i] = i;
        }
        sort(order.begin(), order.end(), [&](int a, int b) {
            return array[a] < array[b];
        });
        return order;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    TaskD solver;
    solver.solve();

    return 0;
}
