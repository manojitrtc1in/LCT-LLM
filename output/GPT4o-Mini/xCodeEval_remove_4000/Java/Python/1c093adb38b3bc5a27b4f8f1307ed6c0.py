import sys
from collections import deque

class Main:
    @staticmethod
    def main():
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_reader = InputReader(input_stream)
        out_writer = OutputWriter(output_stream)
        solver = Id2()
        solver.solve(1, in_reader, out_writer)
        out_writer.close()

class Id2:
    def solve(self, test_number, in_reader, out_writer):
        row_count = in_reader.read_int()
        column_count = in_reader.read_int()
        type_matrix = IOUtils.read_matrix(in_reader, row_count, column_count)
        graph = Graph(row_count * column_count + 2)
        source = graph.vertex_count() - 2
        sink = graph.vertex_count() - 1
        
        for i in range(row_count):
            for j in range(column_count):
                index = i * column_count + j
                if (i + j) % 2 == 0:
                    graph.add_edge(source, index, 1, 1, -1)
                    for k in range(4):
                        row = i + MiscUtils.DX4[k]
                        column = j + MiscUtils.DY4[k]
                        if MiscUtils.is_valid(row, column, row_count, column_count):
                            graph.add_edge(index, row * column_count + column, 0 if type_matrix[i][j] == type_matrix[row][column] else 1, 1, -1)
                else:
                    graph.add_edge(index, sink, 1, 1, -1)
        
        out_writer.print_line(Id10(graph, source, sink, False).calculate_flow().first)

class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read(self):
        return self.stream.read(1)

    def read_int(self):
        return int(self.read_line().strip())

    def read_line(self):
        return self.stream.readline()

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
    def read_matrix(in_reader, row_count, column_count):
        return [list(map(int, in_reader.read_line().split())) for _ in range(row_count)]

class Graph:
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count
        self.edges = []
        self.first_outbound = [-1] * vertex_count
        self.edge_count = 0

    def add_edge(self, from_id, to_id, weight, capacity, reverse_edge):
        self.edges.append((from_id, to_id, weight, capacity, reverse_edge))
        self.first_outbound[from_id] = self.edge_count
        self.edge_count += 1

    def vertex_count(self):
        return self.vertex_count

class MiscUtils:
    DX4 = [1, 0, -1, 0]
    DY4 = [0, -1, 0, 1]

    @staticmethod
    def is_valid(row, column, row_count, column_count):
        return 0 <= row < row_count and 0 <= column < column_count

class Id10:
    def __init__(self, graph, source, destination, id16):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.phi = [float('inf')] * graph.vertex_count()
        self.id8 = [0] * graph.vertex_count()
        self.last_edge = [-1] * graph.vertex_count()
        self.vertex_count = graph.vertex_count()

    def calculate_flow(self):
        # Placeholder for flow calculation logic
        return Pair(0, 0)

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

if __name__ == "__main__":
    Main.main()
