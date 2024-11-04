from collections import defaultdict
import sys
import itertools

class Vector(list):
    def __init__(self, n=0, value=None):
        super().__init__([value] * n if value is not None else [])
    
    def __getitem__(self, ind):
        if ind >= len(self):
            raise IndexError("Out of bounds")
        return super().__getitem__(ind)

    def __setitem__(self, ind, value):
        if ind >= len(self):
            raise IndexError("Out of bounds")
        super().__setitem__(ind, value)

class arr:
    def __init__(self, n=0, init=None):
        self.b = [init] * n if init is not None else []
        self.n = n

    def size(self):
        return self.n

    def __getitem__(self, at):
        if at < 0 or at >= self.n:
            raise IndexError("Out of bounds")
        return self.b[at]

    def __setitem__(self, at, value):
        if at < 0 or at >= self.n:
            raise IndexError("Out of bounds")
        self.b[at] = value

class arr2d:
    def __init__(self, d1, d2, init=None):
        self.d1 = d1
        self.d2 = d2
        self.b = [[init] * d2 for _ in range(d1)] if init is not None else [[0] * d2 for _ in range(d1)]

    def __call__(self, i1, i2):
        if i1 < 0 or i1 >= self.d1 or i2 < 0 or i2 >= self.d2:
            raise IndexError("Out of bounds")
        return self.b[i1][i2]

    def __getitem__(self, at):
        if at < 0 or at >= self.d1:
            raise IndexError("Out of bounds")
        return self.b[at]

class Input:
    def __init__(self, stream):
        self.in_stream = stream

    def read_int(self):
        return int(self.in_stream.readline().strip())

    def read_int_array(self, size):
        return list(map(int, self.in_stream.readline().strip().split()))

    def read_arrays(self, n, *arrays):
        for array in arrays:
            array.extend(self.read_int_array(n))

class Output:
    def __init__(self, stream):
        self.out_stream = stream

    def print_line(self, *args):
        self.out_stream.write(' '.join(map(str, args)) + '\n')

class Graph:
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count
        self.edges = defaultdict(list)

    def add_edge(self, edge):
        self.edges[edge.from_].append(edge)

class BiEdge:
    def __init__(self, from_, to):
        self.from_ = from_
        self.to = to

class TaskD:
    def solve(self, inp, outp):
        in_stream = Input(inp)
        out_stream = Output(outp)

        n = in_stream.read_int()
        m = in_stream.read_int()
        b = in_stream.read_int_array(n)
        w = in_stream.read_int_array(n)
        x, y = [], []
        in_stream.read_arrays(n - 1, x, y)

        for i in range(n - 1):
            x[i] -= 1
            y[i] -= 1

        graph = Graph(n)
        for i in range(n - 1):
            graph.add_edge(BiEdge(x[i], y[i]))

        q = [0] * n

        def calc_q(vert, last):
            res = 1
            for e in graph.edges[vert]:
                next_ = e.to
                if next_ == last:
                    continue
                res += calc_q(next_, vert)
            q[vert] = res
            return res

        calc_q(0, -1)

        answer = arr2d(3000, 3002)
        temp = arr(n + 2)

        def go(vert, last):
            id_ = -1
            for e in graph.edges[vert]:
                next_ = e.to
                if next_ == last:
                    continue
                go(next_, vert)
                if id_ == -1 or q[next_] > q[id_]:
                    id_ = next_

            cur = answer[vert]
            delta = w[vert] - b[vert]
            if id_ == -1:
                cur[0] = (0, delta)
                cur[1] = (1 if delta > 0 else 0, 0)
                return

            aid = answer[id_]
            for i in range(q[id_] + 1):
                cur[i] = aid[i]
                cur[i] = (cur[i][0], cur[i][1] + delta)

            sz = q[id_]
            for e in graph.edges[vert]:
                next_ = e.to
                if next_ == last or next_ == id_:
                    continue
                anext = answer[next_]
                for i in range(sz + 1):
                    temp[i] = cur[i]
                    cur[i] = (-1, 0)

                nsz = sz + q[next_]
                for i in range(sz + 1):
                    for j in range(q[next_] + 1):
                        maxim(cur[i + j], (temp[i][0] + anext[j][0], temp[i][1] + anext[j][1]))

                sz = nsz

            if vert == 0:
                for i in range(n - 1, -1, -1):
                    cur[i + 1] = (cur[i][0] + (1 if cur[i][1] > 0 else 0), 0)
                return

            for i in range(sz + 1):
                maxim(cur[i + 1], (cur[i][0] + (1 if cur[i][1] > 0 else 0), 0))

        go(0, -1)
        out_stream.print_line(answer[0][m][0])

def maxim(a, b):
    return (max(a[0], b[0]), a[1] + b[1])

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    n = int(input_stream.readline().strip())
    solver = TaskD()
    for _ in range(n):
        solver.solve(input_stream, output_stream)

if __name__ == "__main__":
    main()
