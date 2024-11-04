import sys
from collections import deque

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    @staticmethod
    def make_pair(first, second):
        return Pair(first, second)

class Graph:
    id14 = 0

    def __init__(self, vertex_count, edge_capacity=None):
        self.vertex_count = vertex_count
        self.edge_count = 0
        self.first_outbound = [-1] * vertex_count
        self.from_edges = []
        self.to_edges = []
        self.next_outbound = []
        self.weight = []
        self.capacity = []
        self.reverse_edge = []
        self.flags = []

        if edge_capacity is None:
            edge_capacity = vertex_count
        self.resize(edge_capacity)

    def resize(self, size):
        self.from_edges += [0] * (size - len(self.from_edges))
        self.to_edges += [0] * (size - len(self.to_edges))
        self.next_outbound += [-1] * (size - len(self.next_outbound))
        self.weight += [0] * (size - len(self.weight))
        self.capacity += [0] * (size - len(self.capacity))
        self.reverse_edge += [-1] * (size - len(self.reverse_edge))
        self.flags += [0] * (size - len(self.flags))

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        self.id8(self.edge_count + 1)
        if self.first_outbound[from_id] != -1:
            self.next_outbound[self.edge_count] = self.first_outbound[from_id]
        else:
            self.next_outbound[self.edge_count] = -1
        self.first_outbound[from_id] = self.edge_count
        self.from_edges.append(from_id)
        self.to_edges.append(to_id)
        self.weight.append(weight)
        self.capacity.append(capacity)
        self.reverse_edge.append(reverse_edge)
        self.edge_count += 1
        return self.edge_count - 1

    def id3(self, from_id, to_id, weight, capacity):
        if capacity == 0:
            return self.add_edge(from_id, to_id, weight, 0, -1)
        else:
            id4 = self.edge_count
            self.add_edge(to_id, from_id, -weight, 0, id4 + 1)
            return self.add_edge(from_id, to_id, weight, capacity, id4)

    def first_outbound_edge(self, vertex):
        id = self.first_outbound[vertex]
        while id != -1 and self.is_removed(id):
            id = self.next_outbound[id]
        return id

    def next_outbound_edge(self, id):
        id = self.next_outbound[id]
        while id != -1 and self.is_removed(id):
            id = self.next_outbound[id]
        return id

    def is_removed(self, id):
        return (self.flags[id] >> self.id14 & 1) != 0

class Id5:
    def __init__(self, graph, source, destination, id11):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.vertex_count = graph.vertex_count
        self.phi = [float('inf')] * self.vertex_count
        self.id13 = [0] * self.vertex_count
        self.last_edge = [-1] * self.vertex_count
        self.visited = [0] * self.vertex_count
        self.visit_index = 0

        if id11:
            self.id6()

    def id6(self):
        self.phi[self.source] = 0
        queue = deque([self.source])
        in_queue = [False] * self.vertex_count
        in_queue[self.source] = True
        step_count = 0
        max_steps = 2 * self.vertex_count * self.vertex_count

        while queue:
            vertex = queue.popleft()
            in_queue[vertex] = False
            edge_id = self.graph.first_outbound_edge(vertex)

            while edge_id != -1:
                total = self.phi[vertex] + self.graph.weight[edge_id]
                destination = self.graph.to_edges[edge_id]
                if self.graph.capacity[edge_id] != 0 and self.phi[destination] > total:
                    self.phi[destination] = total
                    if not in_queue[destination]:
                        queue.append(destination)
                        in_queue[destination] = True
                edge_id = self.graph.next_outbound_edge(edge_id)

            step_count += 1
            if step_count > max_steps:
                raise ValueError("Graph contains negative cycle")

    def id2(self, max_flow=float('inf')):
        cost = 0
        flow = 0
        while max_flow != 0:
            self.id12()
            if self.last_edge[self.destination] == -1:
                return Pair.make_pair(cost, flow)

            for i in range(len(self.id13)):
                if self.id13[i] != float('inf'):
                    self.phi[i] += self.id13[i]

            vertex = self.destination
            current_flow = max_flow
            current_cost = 0

            while vertex != self.source:
                edge_id = self.last_edge[vertex]
                current_flow = min(current_flow, self.graph.capacity[edge_id])
                current_cost += self.graph.weight[edge_id]
                vertex = self.graph.from_edges[edge_id]

            max_flow -= current_flow
            cost += current_cost * current_flow
            flow += current_flow
            vertex = self.destination

            while vertex != self.source:
                edge_id = self.last_edge[vertex]
                self.graph.capacity[edge_id] -= current_flow
                vertex = self.graph.from_edges[edge_id]

        return Pair.make_pair(cost, flow)

    def id12(self):
        self.id13 = [float('inf')] * self.vertex_count
        self.last_edge = [-1] * self.vertex_count
        self.id13[self.source] = 0
        queue = deque([self.source])

        while queue:
            current = queue.popleft()
            edge_id = self.graph.first_outbound_edge(current)

            while edge_id != -1:
                if self.graph.capacity[edge_id] != 0:
                    next_vertex = self.graph.to_edges[edge_id]
                    total = self.graph.weight[edge_id] - self.phi[next_vertex] + self.phi[current] + self.id13[current]
                    if self.id13[next_vertex] > total:
                        self.id13[next_vertex] = total
                        queue.append(next_vertex)
                        self.last_edge[next_vertex] = edge_id
                edge_id = self.graph.next_outbound_edge(edge_id)

def main():
    n, m = map(int, sys.stdin.readline().split())
    a = [list(map(lambda x: int(x) - 1, sys.stdin.readline().split())) for _ in range(n)]

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
                    if i1 < 0 or i1 >= n or j1 < 0 or j1 >= m:
                        continue
                    id1 = i1 * m + j1
                    wt = 0 if a[i][j] == a[i1][j1] else 1
                    graph.id3(id, id1, wt, 1)
                graph.id3(source, id, 0, 1)
            else:
                graph.id3(id, sink, 0, 1)

    mcf = Id5(graph, source, sink, False)
    ans = mcf.id2()
    print(ans.first)

if __name__ == "__main__":
    main()
