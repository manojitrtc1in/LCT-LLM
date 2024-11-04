import sys
from collections import defaultdict
import heapq

class Graph:
    REMOVED_BIT = 0

    def __init__(self, vertex_count, edge_capacity=None):
        self.vertex_count = vertex_count
        self.edge_count = 0
        self.first_outbound = [-1] * vertex_count
        self.from_edges = []
        self.to_edges = []
        self.next_outbound = []
        self.flags = []
        if edge_capacity is not None:
            self.from_edges = [0] * edge_capacity
            self.to_edges = [0] * edge_capacity
            self.next_outbound = [-1] * edge_capacity
            self.flags = [0] * edge_capacity

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        self.ensure_edge_capacity(self.edge_count + 1)
        if self.first_outbound[from_id] != -1:
            self.next_outbound[self.edge_count] = self.first_outbound[from_id]
        else:
            self.next_outbound[self.edge_count] = -1
        self.first_outbound[from_id] = self.edge_count

        self.from_edges[self.edge_count] = from_id
        self.to_edges[self.edge_count] = to_id
        if capacity != 0:
            if len(self.capacity) < self.edge_count + 1:
                self.capacity = [0] * (len(self.from_edges) + 1)
            self.capacity[self.edge_count] = capacity
        if weight != 0:
            if len(self.weight) < self.edge_count + 1:
                self.weight = [0] * (len(self.from_edges) + 1)
            self.weight[self.edge_count] = weight
        if reverse_edge != -1:
            if len(self.reverse_edge) < self.edge_count + 1:
                self.reverse_edge = [-1] * (len(self.from_edges) + 1)
            self.reverse_edge[self.edge_count] = reverse_edge

        self.edge_count += 1

    def add_flow_weighted_edge(self, from_id, to_id, weight, capacity):
        if capacity == 0:
            return self.add_edge(from_id, to_id, weight, 0, -1)
        else:
            last_edge_count = self.edge_count
            self.add_edge(to_id, from_id, -weight, 0, last_edge_count + 1)
            return self.add_edge(from_id, to_id, weight, capacity, last_edge_count)

    def ensure_edge_capacity(self, size):
        if len(self.from_edges) < size:
            new_size = max(size, 2 * len(self.from_edges))
            self.from_edges += [0] * (new_size - len(self.from_edges))
            self.to_edges += [0] * (new_size - len(self.to_edges))
            self.next_outbound += [-1] * (new_size - len(self.next_outbound))
            self.flags += [0] * (new_size - len(self.flags))

class MinCostFlow:
    def __init__(self, graph, source, destination, has_negative_edges):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.vertex_count = graph.vertex_count
        self.phi = [0] * self.vertex_count
        if has_negative_edges:
            self.ford_bellman()
        self.dijkstra_result = [0] * self.vertex_count
        self.last_edge = [-1] * self.vertex_count

    def ford_bellman(self):
        self.phi = [float('inf')] * self.vertex_count
        self.phi[self.source] = 0
        in_queue = [False] * self.vertex_count
        queue = [self.source]
        in_queue[self.source] = True
        step_count = 0
        head = 0
        end = 1
        max_steps = 2 * self.vertex_count * self.vertex_count

        while head != end:
            vertex = queue[head]
            head += 1
            if head == len(queue):
                head = 0
            in_queue[vertex] = False
            edge_id = self.graph.first_outbound[vertex]
            while edge_id != -1:
                total = self.phi[vertex] + self.graph.weight[edge_id]
                destination = self.graph.to_edges[edge_id]
                if self.graph.capacity[edge_id] != 0 and self.phi[destination] > total:
                    self.phi[destination] = total
                    if not in_queue[destination]:
                        queue.append(destination)
                        in_queue[destination] = True
                        end += 1
                        if end == len(queue):
                            end = 0
                edge_id = self.graph.next_outbound[edge_id]
                if step_count > max_steps:
                    raise ValueError("Graph contains negative cycle")

    def min_cost_max_flow(self, max_flow=float('inf')):
        cost = 0
        flow = 0
        while max_flow != 0:
            self.dijkstra_algorithm()
            if self.last_edge[self.destination] == -1:
                return cost, flow
            for i in range(len(self.dijkstra_result)):
                if self.dijkstra_result[i] != float('inf'):
                    self.phi[i] += self.dijkstra_result[i]
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
                self.graph.push_flow(edge_id, current_flow)
                vertex = self.graph.from_edges[edge_id]
        return cost, flow

    def dijkstra_algorithm(self):
        self.dijkstra_result = [float('inf')] * self.vertex_count
        self.last_edge = [-1] * self.vertex_count
        self.dijkstra_result[self.source] = 0
        heap = [(0, self.source)]
        while heap:
            current_cost, current = heapq.heappop(heap)
            edge_id = self.graph.first_outbound[current]
            while edge_id != -1:
                if self.graph.capacity[edge_id] != 0:
                    next_vertex = self.graph.to_edges[edge_id]
                    total = self.graph.weight[edge_id] - self.phi[next_vertex] + self.phi[current] + current_cost
                    if self.dijkstra_result[next_vertex] > total:
                        self.dijkstra_result[next_vertex] = total
                        heapq.heappush(heap, (total, next_vertex))
                        self.last_edge[next_vertex] = edge_id
                edge_id = self.graph.next_outbound[edge_id]

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
                    if i1 < 0 or i1 >= n or j1 < 0 or j1 >= m:
                        continue
                    id1 = i1 * m + j1
                    wt = 0 if a[i][j] == a[i1][j1] else 1
                    graph.add_flow_weighted_edge(id, id1, wt, 1)
                graph.add_flow_weighted_edge(source, id, 0, 1)
            else:
                graph.add_flow_weighted_edge(id, sink, 0, 1)

    mcf = MinCostFlow(graph, source, sink, False)
    ans = mcf.min_cost_max_flow()
    print(ans[0])

if __name__ == "__main__":
    main()