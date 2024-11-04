import sys
from collections import defaultdict

class Graph:
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count
        self.first_outbound = [-1] * vertex_count
        self.edges = []
        self.next_outbound = []
        self.from_ = []
        self.to = []

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        edge_id = len(self.edges)
        self.edges.append((from_id, to_id, weight, capacity))
        self.from_.append(from_id)
        self.to.append(to_id)
        self.next_outbound.append(self.first_outbound[from_id])
        self.first_outbound[from_id] = edge_id
        return edge_id

    def first_outbound_edge(self, vertex):
        return self.first_outbound[vertex]

    def next_outbound_edge(self, edge_id):
        return self.next_outbound[edge_id]

    def destination(self, edge_id):
        return self.to[edge_id]

class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read_int(self):
        return int(self.stream.readline().strip())

class OutputWriter:
    def __init__(self, stream):
        self.stream = stream

    def print_line(self, value):
        self.stream.write(f"{value}\n")

class TaskD:
    def __init__(self):
        self.graph = None
        self.weight = []
        self.path = []

    def solve(self, test_number, in_reader, out_writer):
        n = in_reader.read_int()
        k = in_reader.read_int()
        a = list(map(int, in_reader.stream.readline().strip().split()))
        u = []
        v = []
        for _ in range(n - 1):
            u.append(in_reader.read_int())
            v.append(in_reader.read_int())
        self.graph = Graph(n)
        for i in range(n - 1):
            self.graph.add_edge(u[i] - 1, v[i] - 1, 0, 0, -1)
        order = sorted(range(n), key=lambda x: a[x], reverse=True)
        left, right = k, n
        self.weight = [0] * n
        degree = [0] * n
        for i in range(n - 1):
            degree[u[i] - 1] += 1
            degree[v[i] - 1] += 1
        remaining = [0] * n
        queue = []
        self.path = [0] * n

        while left < right:
            middle = (left + right) // 2
            threshold = a[order[middle - 1]]
            self.weight = [1 if a[i] >= threshold else 0 for i in range(n)]
            remaining[:] = degree[:]
            size = 0
            for i in range(n):
                if degree[i] == 1 and self.weight[i] > 0:
                    queue.append(i)
                    size += 1
            for i in range(size):
                current = queue[i]
                for j in range(self.graph.first_outbound_edge(current), -1, self.graph.next_outbound_edge):
                    next_vertex = self.graph.destination(j)
                    if self.weight[next_vertex] != 0:
                        self.weight[next_vertex] += self.weight[current]
                        self.weight[current] = 0
                        remaining[next_vertex] -= 1
                        if remaining[next_vertex] == 1:
                            queue.append(next_vertex)
            result = self.dfs(0, -1)
            if result >= k:
                right = middle
            else:
                left = middle + 1
        out_writer.print_line(a[order[left - 1]])

    def dfs(self, current, last):
        result = 0
        max_path = 0
        second_max = 0
        for i in range(self.graph.first_outbound_edge(current), -1, self.graph.next_outbound_edge):
            next_vertex = self.graph.destination(i)
            if next_vertex == last:
                continue
            result = max(result, self.dfs(next_vertex, current))
            if self.path[next_vertex] > max_path:
                second_max = max_path
                max_path = self.path[next_vertex]
            else:
                second_max = max(second_max, self.path[next_vertex])
        if self.weight[current] != 0:
            self.path[current] = self.weight[current] + max_path
            result = max(result, max_path + second_max + self.weight[current])
        else:
            self.path[current] = 0
        return result

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = OutputWriter(output_stream)
    solver = TaskD()
    solver.solve(1, in_reader, out_writer)

if __name__ == "__main__":
    main()
