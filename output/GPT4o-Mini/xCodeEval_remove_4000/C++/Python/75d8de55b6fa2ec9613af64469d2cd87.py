from collections import defaultdict
from typing import List, Tuple, Any

class Vector:
    def __init__(self, n: int = 0, value: Any = None):
        self.data = [value] * n if n > 0 else []

    def __getitem__(self, ind: int) -> Any:
        if ind >= len(self.data):
            raise IndexError("Out of bounds")
        return self.data[ind]

    def __setitem__(self, ind: int, value: Any):
        if ind >= len(self.data):
            raise IndexError("Out of bounds")
        self.data[ind] = value

    def size(self) -> int:
        return len(self.data)

    def __len__(self):
        return len(self.data)

class arr:
    def __init__(self, n: int, init: Any = None):
        if n < 0:
            raise MemoryError("bad alloc")
        self.data = [init] * n if n > 0 else []
    
    def __getitem__(self, at: int) -> Any:
        if at < 0 or at >= len(self.data):
            raise IndexError("Out of bounds")
        return self.data[at]

    def __setitem__(self, at: int, value: Any):
        if at < 0 or at >= len(self.data):
            raise IndexError("Out of bounds")
        self.data[at] = value

    def size(self) -> int:
        return len(self.data)

class id4:
    def __init__(self, d1: int, d2: int, init: Any = None):
        self.d1 = d1
        self.d2 = d2
        self.data = arr(d1 * d2, init)

    def __getitem__(self, indices: Tuple[int, int]) -> Any:
        i1, i2 = indices
        if i1 < 0 or i1 >= self.d1 or i2 < 0 or i2 >= self.d2:
            raise IndexError("Out of bounds")
        return self.data[i1 * self.d2 + i2]

    def __setitem__(self, indices: Tuple[int, int], value: Any):
        i1, i2 = indices
        if i1 < 0 or i1 >= self.d1 or i2 < 0 or i2 >= self.d2:
            raise IndexError("Out of bounds")
        self.data[i1 * self.d2 + i2] = value

class Graph:
    def __init__(self, vertex_count: int):
        self.vertex_count = vertex_count
        self.edges = defaultdict(list)

    def add_edge(self, edge):
        self.edges[edge.from_].append(edge)
        reverse_edge = edge.reverse()
        if reverse_edge:
            self.edges[reverse_edge.from_].append(reverse_edge)

class BiEdge:
    def __init__(self, from_: int, to: int):
        self.from_ = from_
        self.to = to
        self.reverse_edge = BiEdge(to, from_)

    def reverse(self):
        return self.reverse_edge

class Input:
    def __init__(self, inp):
        self.inp = inp

    def read_int(self) -> int:
        return int(self.inp.readline().strip())

    def read_int_array(self, size: int) -> List[int]:
        return list(map(int, self.inp.readline().strip().split()))

class Output:
    def __init__(self, out):
        self.out = out

    def print_line(self, *args):
        self.out.write(' '.join(map(str, args)) + '\n')

class TaskD:
    def solve(self, inp: Input, out: Output):
        n = inp.read_int()
        m = inp.read_int()
        b = inp.read_int_array(n)
        w = inp.read_int_array(n)
        x, y = [], []
        for _ in range(n - 1):
            x.append(inp.read_int())
            y.append(inp.read_int())

        graph = Graph(n)
        for i in range(n - 1):
            graph.add_edge(BiEdge(x[i], y[i]))

        q = arr(n)

        def calc_q(vert: int, last: int) -> int:
            res = 1
            for e in graph.edges[vert]:
                next_ = e.to
                if next_ == last:
                    continue
                res += calc_q(next_, vert)
            q[vert] = res
            return res

        calc_q(0, -1)

        answer = id4(3000, 3002)
        temp = arr(n + 2)

        def go(vert: int, last: int):
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
                cur[0, 0] = (0, delta)
                cur[1, 0] = (1 if delta > 0 else 0, 0)
                return

            aid = answer[id_]
            for i in range(q[id_] + 1):
                cur[i, 0] = aid[i, 0]
                cur[i, 1] += delta

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
                        cur[i + j] = max(cur[i + j], (temp[i][0] + anext[j][0], temp[i][1] + anext[j][1]))

                sz = nsz

            if vert == 0:
                for i in range(n - 1, -1, -1):
                    cur[i + 1] = (cur[i][0] + (1 if cur[i][1] > 0 else 0), 0)
                return

            for i in range(sz + 1):
                cur[i + 1] = max(cur[i + 1], (cur[i][0] + (1 if cur[i][1] > 0 else 0), 0))

        go(0, -1)
        out.print_line(answer[0][m][0])

def main():
    import sys
    input = sys.stdin
    output = sys.stdout
    solver = TaskD()
    n = int(input.readline().strip())
    for _ in range(n):
        solver.solve(Input(input), Output(output))

if __name__ == "__main__":
    main()
