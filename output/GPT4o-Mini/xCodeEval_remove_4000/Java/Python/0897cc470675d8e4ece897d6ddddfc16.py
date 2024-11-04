import sys
from collections import deque

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

    def next_int(self):
        c = self.read()
        while self.is_whitespace(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.is_whitespace(c):
            if c < ord('0') or c > ord('9'):
                raise ValueError("InputMismatchException")
            res = res * 10 + (c - ord('0'))
            c = self.read()
        return res * sgn

    def next_string(self):
        c = self.read()
        while self.is_whitespace(c):
            c = self.read()
        res = []
        while not self.is_whitespace(c):
            res.append(chr(c))
            c = self.read()
        return ''.join(res)

    @staticmethod
    def is_whitespace(c):
        return c in (ord(' '), ord('\n'), ord('\r'), ord('\t'), -1)

class OutputWriter:
    def __init__(self, output_stream):
        self.writer = output_stream

    def close(self):
        self.writer.close()

    def println(self, i):
        self.writer.write(f"{i}\n")

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
        self.id8(self.edge_count + 1)
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
        return self.edge_count - 1

    def id8(self, size):
        if len(self.from_edges) < size:
            new_size = max(size, 2 * len(self.from_edges))
            self.from_edges.extend([0] * (new_size - len(self.from_edges)))
            self.to_edges.extend([0] * (new_size - len(self.to_edges)))
            self.next_outbound.extend([-1] * (new_size - len(self.next_outbound)))
            self.weight.extend([0] * (new_size - len(self.weight)))
            self.capacity.extend([0] * (new_size - len(self.capacity)))
            self.reverse_edge.extend([-1] * (new_size - len(self.reverse_edge)))

    def id2(self, from_id, to_id, weight, capacity):
        if capacity == 0:
            return self.add_edge(from_id, to_id, weight, 0, -1)
        else:
            id5 = self.edge_count
            self.add_edge(to_id, from_id, -weight, 0, id5 + 1)
            return self.add_edge(from_id, to_id, weight, capacity, id5)

class TaskF:
    def solve(self, test_number, in_reader, out_writer):
        n = in_reader.next_int()
        s = in_reader.next_string()
        a = [in_reader.next_int() for _ in range(n)]
        cnt = [0] * 26
        for char in s:
            cnt[ord(char) - ord('a')] += 1
        g = Graph(n + 100)
        source = n + 100 - 2
        target = source + 1
        for i in range(n // 2):
            g.id2(i, target, 0, 2)
        for i in range(26):
            g.id2(source, i + n, 0, cnt[i])
            for j in range(n // 2):
                if s[j] == s[n - j - 1]:
                    w = 0
                    if s[j] == chr(i + ord('a')):
                        w = -max(a[j], a[n - j - 1])
                    g.id2(i + n, j, w, 1)
                else:
                    w = 0
                    if s[j] == chr(i + ord('a')):
                        w -= a[j]
                    if s[n - j - 1] == chr(i + ord('a')):
                        w -= a[n - j - 1]
                    g.id2(i + n, j, w, 1)
        id3 = id6(g, source, target, True)
        out_writer.println(-id3.id1()[0])

class id6:
    def __init__(self, graph, source, destination, id11):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.phi = [float('inf')] * graph.vertex_count
        if id11:
            self.id7()
        self.id4 = [float('inf')] * graph.vertex_count
        self.last_edge = [-1] * graph.vertex_count
        self.vertex_count = graph.vertex_count
        self.visited = [0] * graph.vertex_count
        self.visit_index = 0

    def id7(self):
        self.phi[self.source] = 0
        in_queue = [False] * self.vertex_count
        queue = deque([self.source])
        in_queue[self.source] = True
        step_count = 0
        max_steps = 2 * self.vertex_count * self.vertex_count
        while queue:
            vertex = queue.popleft()
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
                edge_id = self.graph.next_outbound[edge_id]
            if step_count > max_steps:
                raise ValueError("Graph contains negative cycle")
            step_count += 1

    def id1(self, max_flow=float('inf')):
        cost = 0
        flow = 0
        while max_flow != 0:
            self.id13()
            if self.last_edge[self.destination] == -1:
                return cost, flow
            for i in range(len(self.id4)):
                if self.id4[i] != float('inf'):
                    self.phi[i] += self.id4[i]
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
        return cost, flow

    def id13(self):
        self.id4 = [float('inf')] * self.vertex_count
        self.last_edge = [-1] * self.vertex_count
        self.id4[self.source] = 0
        heap = []
        heap.append(self.source)
        while heap:
            current = heap.pop(0)
            edge_id = self.graph.first_outbound[current]
            while edge_id != -1:
                if self.graph.capacity[edge_id] != 0:
                    next_vertex = self.graph.to_edges[edge_id]
                    total = self.graph.weight[edge_id] - self.phi[next_vertex] + self.phi[current] + self.id4[current]
                    if self.id4[next_vertex] > total:
                        self.id4[next_vertex] = total
                        heap.append(next_vertex)
                        self.last_edge[next_vertex] = edge_id
                edge_id = self.graph.next_outbound[edge_id]

def main():
    input_stream = sys.stdin.buffer
    output_stream = sys.stdout.buffer
    in_reader = InputReader(input_stream)
    out_writer = OutputWriter(output_stream)
    solver = TaskF()
    solver.solve(1, in_reader, out_writer)
    out_writer.close()

if __name__ == "__main__":
    main()
