import sys
from collections import deque

class Main:
    @staticmethod
    def main():
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_reader = InputReader(input_stream)
        out_writer = OutputWriter(output_stream)
        solver = TaskD()
        solver.solve(1, in_reader, out_writer)
        out_writer.close()

class TaskD:
    def __init__(self):
        self.graph = None
        self.weight = None
        self.path = None

    def solve(self, test_number, in_reader, out_writer):
        n = in_reader.read_int()
        k = in_reader.read_int()
        a = IOUtils.read_int_array(in_reader, n)
        u = [0] * (n - 1)
        v = [0] * (n - 1)
        IOUtils.read_int_arrays(in_reader, u, v)
        MiscUtils.decrease_by_one(u, v)
        self.graph = BidirectionalGraph.create_graph(n, u, v)
        order = ArrayUtils.order(a)
        order.reverse()
        left = k
        right = n
        self.weight = [0] * n
        degree = [0] * n
        for i in range(n - 1):
            degree[u[i]] += 1
            degree[v[i]] += 1
        remaining = [0] * n
        queue = [0] * n
        self.path = [0] * n
        while left < right:
            middle = (left + right) // 2
            threshold = a[order[middle - 1]]
            self.weight = [1 if a[i] >= threshold else 0 for i in range(n)]
            remaining[:] = degree[:]
            size = 0
            for i in range(n):
                if degree[i] == 1 and self.weight[i] > 0:
                    queue[size] = i
                    size += 1
            for i in range(size):
                current = queue[i]
                for j in self.graph.first_outbound(current):
                    next_vertex = self.graph.destination(j)
                    if self.weight[next_vertex] != 0:
                        self.weight[next_vertex] += self.weight[current]
                        self.weight[current] = 0
                        remaining[next_vertex] -= 1
                        if remaining[next_vertex] == 1:
                            queue[size] = next_vertex
                            size += 1
            result = self.dfs(0, -1)
            if result >= k:
                right = middle
            else:
                left = middle + 1
        out_writer.print_line(a[order[left - 1]])

    def dfs(self, current, last):
        result = 0
        max_weight = 0
        second_max = 0
        for i in self.graph.first_outbound(current):
            next_vertex = self.graph.destination(i)
            if next_vertex == last:
                continue
            result = max(result, self.dfs(next_vertex, current))
            if self.path[next_vertex] > max_weight:
                second_max = max_weight
                max_weight = self.path[next_vertex]
            else:
                second_max = max(second_max, self.path[next_vertex])
        if self.weight[current] != 0:
            self.path[current] = self.weight[current] + max_weight
            result = max(result, max_weight + second_max + self.weight[current])
        else:
            self.path[current] = 0
        return result

class OutputWriter:
    def __init__(self, output_stream):
        self.writer = output_stream

    def close(self):
        pass

    def print_line(self, i):
        self.writer.write(f"{i}\n")

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buf = bytearray(1024)
        self.cur_char = 0
        self.num_chars = 0

    def read(self):
        if self.num_chars == -1:
            raise ValueError("InputMismatchException")
        if self.cur_char >= self.num_chars:
            self.cur_char = 0
            self.num_chars = self.stream.readinto(self.buf)
            if self.num_chars <= 0:
                return -1
        return self.buf[self.cur_char]

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

class IOUtils:
    @staticmethod
    def read_int_array(in_reader, size):
        return [in_reader.read_int() for _ in range(size)]

    @staticmethod
    def read_int_arrays(in_reader, *arrays):
        for i in range(len(arrays[0])):
            for j in range(len(arrays)):
                arrays[j][i] = in_reader.read_int()

class MiscUtils:
    @staticmethod
    def decrease_by_one(*arrays):
        for array in arrays:
            for i in range(len(array)):
                array[i] -= 1

class ArrayUtils:
    @staticmethod
    def order(array):
        return sorted(range(len(array)), key=lambda i: array[i])

class Graph:
    REMOVED_BIT = 0

    def __init__(self, vertex_count):
        self.vertex_count = vertex_count
        self.first_outbound = [-1] * vertex_count
        self.from_edges = []
        self.to_edges = []
        self.next_outbound = []
        self.flags = []

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        self.ensure_edge_capacity(len(self.from_edges) + 1)
        if self.first_outbound[from_id] != -1:
            self.next_outbound.append(self.first_outbound[from_id])
        else:
            self.next_outbound.append(-1)
        self.first_outbound[from_id] = len(self.from_edges)
        self.from_edges.append(from_id)
        self.to_edges.append(to_id)
        self.flags.append(0)
        return len(self.from_edges) - 1

    def ensure_edge_capacity(self, size):
        if len(self.from_edges) < size:
            new_size = max(size, 2 * len(self.from_edges))
            self.from_edges.extend([0] * (new_size - len(self.from_edges)))
            self.to_edges.extend([0] * (new_size - len(self.to_edges)))
            self.next_outbound.extend([-1] * (new_size - len(self.next_outbound)))
            self.flags.extend([0] * (new_size - len(self.flags)))

    def first_outbound(self, vertex):
        id = self.first_outbound[vertex]
        while id != -1 and self.is_removed(id):
            id = self.next_outbound[id]
        return id

    def next_outbound(self, id):
        id = self.next_outbound[id]
        while id != -1 and self.is_removed(id):
            id = self.next_outbound[id]
        return id

    def destination(self, id):
        return self.to_edges[id]

    def is_removed(self, id):
        return (self.flags[id] >> self.REMOVED_BIT & 1) != 0

class BidirectionalGraph(Graph):
    def __init__(self, vertex_count):
        super().__init__(vertex_count)
        self.transposed_edge = []

    @staticmethod
    def create_graph(vertex_count, from_edges, to_edges):
        graph = BidirectionalGraph(vertex_count)
        for i in range(len(from_edges)):
            graph.add_edge(from_edges[i], to_edges[i], 0, 0, -1)
        return graph

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        last_edge_count = len(self.from_edges)
        super().add_edge(from_id, to_id, weight, capacity, reverse_edge)
        super().add_edge(to_id, from_id, weight, capacity, reverse_edge if reverse_edge == -1 else reverse_edge + 1)
        self.transposed_edge.append(last_edge_count + 1)
        self.transposed_edge.append(last_edge_count)

if __name__ == "__main__":
    Main.main()
