import sys
from collections import deque

class Main:
    @staticmethod
    def main():
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_reader = InputReader(input_stream)
        out_writer = OutputWriter(output_stream)
        solver = TaskC1()
        solver.solve(1, in_reader, out_writer)
        out_writer.close()

class TaskC1:
    def solve(self, test_number, in_reader, out_writer):
        row_count = in_reader.read_int()
        column_count = in_reader.read_int()
        type_matrix = IOUtils.read_int_table(in_reader, row_count, column_count)
        graph = Graph(row_count * column_count + 2)
        source = graph.vertex_count() - 2
        sink = graph.vertex_count() - 1
        
        for i in range(row_count):
            for j in range(column_count):
                index = i * column_count + j
                if (i + j) % 2 == 0:
                    graph.add_flow_edge(source, index, 1)
                    for k in range(4):
                        row = i + MiscUtils.DX4[k]
                        column = j + MiscUtils.DY4[k]
                        if MiscUtils.is_valid_cell(row, column, row_count, column_count):
                            graph.add_flow_weighted_edge(index, row * column_count + column, 
                                                          0 if type_matrix[i][j] == type_matrix[row][column] else 1, 1)
                else:
                    graph.add_flow_edge(index, sink, 1)
        
        out_writer.print_line(MinCostFlow(graph, source, sink, False).min_cost_max_flow()[0])

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

    def is_space_char(self, c):
        return c in (ord(' '), ord('\n'), ord('\r'), ord('\t'), -1)

class OutputWriter:
    def __init__(self, output_stream):
        self.writer = output_stream

    def print(self, *objects):
        self.writer.write(' '.join(map(str, objects)))

    def print_line(self, *objects):
        self.print(*objects)
        self.writer.write('\n')

    def close(self):
        self.writer.close()

class IOUtils:
    @staticmethod
    def read_int_array(in_reader, size):
        return [in_reader.read_int() for _ in range(size)]

    @staticmethod
    def read_int_table(in_reader, row_count, column_count):
        return [IOUtils.read_int_array(in_reader, column_count) for _ in range(row_count)]

class Graph:
    REMOVED_BIT = 0

    def __init__(self, vertex_count):
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

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        self.ensure_edge_capacity(self.edge_count + 1)
        if self.first_outbound[from_id] != -1:
            self.next_outbound[self.edge_count] = self.first_outbound[from_id]
        else:
            self.next_outbound[self.edge_count] = -1
        self.first_outbound[from_id] = self.edge_count
        self.from_edges.append(from_id)
        self.to_edges.append(to_id)
        if capacity != 0:
            if self.capacity is None:
                self.capacity = [0] * len(self.from_edges)
            self.capacity[self.edge_count] = capacity
        if weight != 0:
            if self.weight is None:
                self.weight = [0] * len(self.from_edges)
            self.weight[self.edge_count] = weight
        if reverse_edge != -1:
            if self.reverse_edge is None:
                self.reverse_edge = [-1] * len(self.from_edges)
            self.reverse_edge[self.edge_count] = reverse_edge
        self.edge_count += 1
        return self.edge_count - 1

    def add_flow_weighted_edge(self, from_id, to_id, weight, capacity):
        if capacity == 0:
            return self.add_edge(from_id, to_id, weight, 0, -1)
        else:
            last_edge_count = self.edge_count
            self.add_edge(to_id, from_id, -weight, 0, last_edge_count + 1)
            return self.add_edge(from_id, to_id, weight, capacity, last_edge_count)

    def add_flow_edge(self, from_id, to_id, capacity):
        return self.add_flow_weighted_edge(from_id, to_id, 0, capacity)

    def vertex_count(self):
        return self.vertex_count

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
        return (self.flags[id] >> self.REMOVED_BIT & 1) != 0

    def ensure_edge_capacity(self, size):
        if len(self.from_edges) < size:
            new_size = max(size, 2 * len(self.from_edges))
            self.from_edges.extend([0] * (new_size - len(self.from_edges)))
            self.to_edges.extend([0] * (new_size - len(self.to_edges)))
            self.next_outbound.extend([-1] * (new_size - len(self.next_outbound)))
            if self.weight is not None:
                self.weight.extend([0] * (new_size - len(self.weight)))
            if self.capacity is not None:
                self.capacity.extend([0] * (new_size - len(self.capacity)))
            if self.reverse_edge is not None:
                self.reverse_edge.extend([-1] * (new_size - len(self.reverse_edge)))
            self.flags.extend([0] * (new_size - len(self.flags)))

class MiscUtils:
    DX4 = [1, 0, -1, 0]
    DY4 = [0, -1, 0, 1]

    @staticmethod
    def is_valid_cell(row, column, row_count, column_count):
        return 0 <= row < row_count and 0 <= column < column_count

class MinCostFlow:
    def __init__(self, graph, source, destination, has_negative_edges):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.phi = [0] * graph.vertex_count()
        if has_negative_edges:
            self.ford_bellman()
        self.dijkstra_result = [0] * graph.vertex_count()
        self.last_edge = [-1] * graph.vertex_count()
        self.vertex_count = graph.vertex_count()

    def ford_bellman(self):
        self.phi = [float('inf')] * self.vertex_count
        self.phi[self.source] = 0
        in_queue = [False] * self.vertex_count
        queue = deque([self.source])
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
            current_cost, current = heap.pop(0)
            edge_id = self.graph.first_outbound_edge(current)
            while edge_id != -1:
                if self.graph.capacity[edge_id] != 0:
                    next_vertex = self.graph.to_edges[edge_id]
                    total = self.graph.weight[edge_id] - self.phi[next_vertex] + self.phi[current] + self.dijkstra_result[current]
                    if self.dijkstra_result[next_vertex] > total:
                        self.dijkstra_result[next_vertex] = total
                        heap.append((total, next_vertex))
                        self.last_edge[next_vertex] = edge_id
                edge_id = self.graph.next_outbound_edge(edge_id)

class Pair:
    @staticmethod
    def make_pair(first, second):
        return first, second
