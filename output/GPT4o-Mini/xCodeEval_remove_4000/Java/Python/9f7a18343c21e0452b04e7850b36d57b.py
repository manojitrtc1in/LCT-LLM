import sys
from collections import deque

class Graph:
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count
        self.first_outbound = [-1] * vertex_count
        self.from_edges = []
        self.to_edges = []
        self.next_outbound = []
        self.weight = []
        self.capacity = []
        self.reverse_edge = []
        self.edge_count = 0

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        if len(self.from_edges) <= self.edge_count:
            self.resize(self.edge_count + 1)
        if self.first_outbound[from_id] != -1:
            self.next_outbound[self.edge_count] = self.first_outbound[from_id]
        else:
            self.next_outbound.append(-1)
        self.first_outbound[from_id] = self.edge_count
        self.from_edges.append(from_id)
        self.to_edges.append(to_id)
        self.weight.append(weight)
        self.capacity.append(capacity)
        self.reverse_edge.append(reverse_edge)
        self.edge_count += 1

    def resize(self, size):
        self.from_edges.extend([0] * (size - len(self.from_edges)))
        self.to_edges.extend([0] * (size - len(self.to_edges)))
        self.next_outbound.extend([-1] * (size - len(self.next_outbound)))
        self.weight.extend([0] * (size - len(self.weight)))
        self.capacity.extend([0] * (size - len(self.capacity)))
        self.reverse_edge.extend([-1] * (size - len(self.reverse_edge)))

    def first_outbound_edge(self, vertex):
        return self.first_outbound[vertex]

    def next_outbound_edge(self, id):
        return self.next_outbound[id]

    def destination(self, id):
        return self.to_edges[id]

    def weight_of_edge(self, id):
        return self.weight[id]

    def capacity_of_edge(self, id):
        return self.capacity[id]

    def push_flow(self, id, flow):
        self.capacity[id] -= flow
        self.capacity[self.reverse_edge[id]] += flow


class MinCostFlow:
    def __init__(self, graph, source, destination):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.phi = [float('inf')] * graph.vertex_count
        self.phi[source] = 0
        self.last_edge = [-1] * graph.vertex_count
        self.id13 = [float('inf')] * graph.vertex_count

    def find_flow(self, max_flow):
        cost = 0
        flow = 0
        while max_flow != 0:
            self.id12()
            if self.last_edge[self.destination] == -1:
                return cost, flow
            current_flow = max_flow
            current_cost = 0
            vertex = self.destination
            while vertex != self.source:
                edge_id = self.last_edge[vertex]
                current_flow = min(current_flow, self.graph.capacity_of_edge(edge_id))
                current_cost += self.graph.weight_of_edge(edge_id)
                vertex = self.graph.from_edges[edge_id]
            max_flow -= current_flow
            cost += current_cost * current_flow
            flow += current_flow
            vertex = self.destination
            while vertex != self.source:
                edge_id = self.last_edge[vertex]
                self.graph.push_flow(edge_id, current_flow)
                vertex = self.graph.from_edges[edge_id]
        return cost, flow

    def id12(self):
        self.id13 = [float('inf')] * self.graph.vertex_count
        self.last_edge = [-1] * self.graph.vertex_count
        self.id13[self.source] = 0
        queue = deque([self.source])
        while queue:
            current = queue.popleft()
            edge_id = self.graph.first_outbound_edge(current)
            while edge_id != -1:
                if self.graph.capacity_of_edge(edge_id) > 0:
                    next_vertex = self.graph.destination(edge_id)
                    total = self.graph.weight_of_edge(edge_id) - self.phi[next_vertex] + self.phi[current] + self.id13[current]
                    if self.id13[next_vertex] > total:
                        self.id13[next_vertex] = total
                        self.last_edge[next_vertex] = edge_id
                        queue.append(next_vertex)
                edge_id = self.graph.next_outbound_edge(edge_id)

def main():
    n, m = map(int, sys.stdin.readline().split())
    a = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    shoe = m * n // 2
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]
    graph = Graph(2 * shoe + 2)
    source = 2 * shoe
    sink = 2 * shoe + 1

    for i in range(n):
        for j in range(m):
            id = i * m + j
            if (i + j) % 2 == 0:
                for z in range(4):
                    i1 = i + dx[z]
                    j1 = j + dy[z]
                    if 0 <= i1 < n and 0 <= j1 < m:
                        id1 = i1 * m + j1
                        wt = 0 if a[i][j] == a[i1][j1] else 1
                        graph.add_edge(id, id1, wt, 1, -1)
                graph.add_edge(source, id, 0, 1, -1)
            else:
                graph.add_edge(id, sink, 0, 1, -1)

    mcf = MinCostFlow(graph, source, sink)
    ans = mcf.find_flow(float('inf'))
    print(ans[0])

if __name__ == "__main__":
    main()
