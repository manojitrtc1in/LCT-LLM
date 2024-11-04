import sys
from collections import defaultdict
import heapq

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = bytearray(1024)
        self.cur_char = 0
        self.num_chars = 0

    def read(self):
        if self.num_chars == -1:
            raise ValueError("InputMismatchException")
        if self.cur_char >= self.num_chars:
            self.cur_char = 0
            self.num_chars = self.stream.readinto(self.buffer)
            if self.num_chars <= 0:
                return -1
        return self.buffer[self.cur_char]

    def read_int(self):
        c = self.read()
        while self.is_space_char(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.is_space_char(c):
            if c < ord('0') or c > ord('9'):
                raise ValueError("InputMismatchException")
            res = res * 10 + (c - ord('0'))
            c = self.read()
        return res * sgn

    def read_string(self):
        c = self.read()
        while self.is_space_char(c):
            c = self.read()
        res = []
        while not self.is_space_char(c):
            res.append(chr(c))
            c = self.read()
        return ''.join(res)

    def is_space_char(self, c):
        return c in (ord(' '), ord('\n'), ord('\r'), ord('\t'), -1)

class Graph:
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count
        self.first_outbound = [-1] * vertex_count
        self.edges = []
        self.next_outbound = []
        self.from_vertices = []
        self.to_vertices = []
        self.weights = []
        self.capacities = []
        self.reverse_edges = []

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        edge_id = len(self.edges)
        self.edges.append((from_id, to_id, weight, capacity, reverse_edge))
        self.from_vertices.append(from_id)
        self.to_vertices.append(to_id)
        self.weights.append(weight)
        self.capacities.append(capacity)
        self.reverse_edges.append(reverse_edge)
        self.next_outbound.append(self.first_outbound[from_id])
        self.first_outbound[from_id] = edge_id

    def add_flow_weighted_edge(self, from_id, to_id, weight, capacity):
        if capacity == 0:
            return self.add_edge(from_id, to_id, weight, 0, -1)
        else:
            last_edge_count = len(self.edges)
            self.add_edge(to_id, from_id, -weight, 0, last_edge_count + 1)
            return self.add_edge(from_id, to_id, weight, capacity, last_edge_count)

class MinCostFlow:
    def __init__(self, graph, source, destination, has_negative_edges):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.phi = [0] * graph.vertex_count
        self.dijkstra_result = [float('inf')] * graph.vertex_count
        self.last_edge = [-1] * graph.vertex_count
        if has_negative_edges:
            self.ford_bellman()

    def ford_bellman(self):
        self.phi[self.source] = 0
        in_queue = [False] * self.graph.vertex_count
        queue = [self.source]
        in_queue[self.source] = True
        while queue:
            vertex = queue.pop(0)
            in_queue[vertex] = False
            edge_id = self.graph.first_outbound[vertex]
            while edge_id != -1:
                total = self.phi[vertex] + self.graph.weights[edge_id]
                destination = self.graph.to_vertices[edge_id]
                if self.graph.capacities[edge_id] != 0 and self.phi[destination] > total:
                    self.phi[destination] = total
                    if not in_queue[destination]:
                        queue.append(destination)
                        in_queue[destination] = True
                edge_id = self.graph.next_outbound[edge_id]

    def min_cost_max_flow(self, max_flow):
        cost = 0
        flow = 0
        while max_flow != 0:
            self.dijkstra_algorithm()
            if self.last_edge[self.destination] == -1:
                return cost, flow
            current_flow = max_flow
            current_cost = 0
            vertex = self.destination
            while vertex != self.source:
                edge_id = self.last_edge[vertex]
                current_flow = min(current_flow, self.graph.capacities[edge_id])
                current_cost += self.graph.weights[edge_id]
                vertex = self.graph.from_vertices[edge_id]
            max_flow -= current_flow
            cost += current_cost * current_flow
            flow += current_flow
            vertex = self.destination
            while vertex != self.source:
                edge_id = self.last_edge[vertex]
                self.graph.capacities[edge_id] -= current_flow
                self.graph.capacities[self.graph.reverse_edges[edge_id]] += current_flow
                vertex = self.graph.from_vertices[edge_id]
        return cost, flow

    def dijkstra_algorithm(self):
        self.dijkstra_result = [float('inf')] * self.graph.vertex_count
        self.last_edge = [-1] * self.graph.vertex_count
        self.dijkstra_result[self.source] = 0
        heap = [(0, self.source)]
        while heap:
            current_cost, current = heapq.heappop(heap)
            edge_id = self.graph.first_outbound[current]
            while edge_id != -1:
                if self.graph.capacities[edge_id] != 0:
                    next_vertex = self.graph.to_vertices[edge_id]
                    total = self.graph.weights[edge_id] - self.phi[next_vertex] + self.phi[current] + current_cost
                    if self.dijkstra_result[next_vertex] > total:
                        self.dijkstra_result[next_vertex] = total
                        heapq.heappush(heap, (total, next_vertex))
                        self.last_edge[next_vertex] = edge_id
                edge_id = self.graph.next_outbound[edge_id]

class TaskF:
    def solve(self, test_number, in_reader, out_writer):
        n = in_reader.read_int()
        s = in_reader.read_string()
        ugliness = [-in_reader.read_int() for _ in range(n)]
        graph = Graph(1 + 26 + n // 2 + 1)

        for c in range(ord('a'), ord('z') + 1):
            for i in range(n // 2):
                cost = float('inf')
                if c == ord(s[i]):
                    cost = min(cost, ugliness[i])
                if c == ord(s[n - 1 - i]):
                    cost = min(cost, ugliness[n - 1 - i])
                graph.add_flow_weighted_edge(1 + (c - ord('a')), 1 + 26 + i, cost, 1)

        occurs = [0] * 128
        for char in s:
            occurs[ord(char)] += 1
        for c in range(ord('a'), ord('z') + 1):
            graph.add_flow_weighted_edge(0, 1 + (c - ord('a')), 0, occurs[c])

        for i in range(n // 2):
            graph.add_flow_weighted_edge(1 + 26 + i, 1 + 26 + n // 2, 0, 2)

        flow = MinCostFlow(graph, 0, 1 + 26 + n // 2, True).min_cost_max_flow(n)
        out_writer.write(f"{-flow[0]}\n")

def main():
    input_stream = sys.stdin.buffer
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = sys.stdout
    solver = TaskF()
    solver.solve(1, in_reader, out_writer)

if __name__ == "__main__":
    main()
