import sys
import math
from collections import deque

MAX_64 = 0x7fffffffffffffff
MAX_32 = 0x7fffffff
PRICE_MAX = MAX_64

class MCMF_CS2:
    def __init__(self, num_nodes, num_arcs):
        self.n = num_nodes
        self.m = num_arcs
        self.cap = [0] * (2 * self.m)
        self.nodes = [self.NODE() for _ in range(self.n + 2)]
        self.arcs = [self.ARC() for _ in range(2 * self.m + 1)]
        self.arc_tail = [0] * (2 * self.m)
        self.arc_first = [0] * (self.n + 2)

        self.node_min = self.n
        self.node_max = 0
        self.max_cost = 0
        self.total_p = 0
        self.total_n = 0
        self.pos_current = 0
        self.arc_current = self.arcs
        self.d_node = self.NODE()
        self.d_arc = self.ARC()
        self.excq_first = None
        self.excq_last = None

    class NODE:
        def __init__(self):
            self.excess = 0
            self.price = 0
            self.first = None
            self.current = None
            self.suspended = None
            self.q_next = None
            self.b_next = None
            self.b_prev = None
            self.rank = 0
            self.inp = 0

    class ARC:
        def __init__(self):
            self.rez_capacity = 0
            self.cost = 0
            self.head = None
            self.sister = None

    def f(self, r, c):
        return r * self.m + c + 1

    def set_arc(self, tail_node_id, head_node_id, low_bound, up_bound, cost):
        if tail_node_id < 0 or tail_node_id > self.n or head_node_id < 0 or head_node_id > self.n:
            sys.exit(1)
        if up_bound < 0:
            up_bound = MAX_32
        if low_bound < 0 or low_bound > up_bound:
            sys.exit(1)

        self.arc_first[tail_node_id + 1] += 1
        self.arc_first[head_node_id + 1] += 1
        i_node = self.nodes[tail_node_id]
        j_node = self.nodes[head_node_id]

        self.arc_tail[self.pos_current] = tail_node_id
        self.arc_tail[self.pos_current + 1] = head_node_id
        self.arc_current.head = j_node
        self.arc_current.rez_capacity = up_bound - low_bound
        self.cap[self.pos_current] = up_bound
        self.arc_current.cost = cost
        self.arc_current.sister = self.arc_current + 1
        (self.arc_current + 1).head = self.nodes[tail_node_id]
        (self.arc_current + 1).rez_capacity = 0
        self.cap[self.pos_current + 1] = 0
        (self.arc_current + 1).cost = -cost
        (self.arc_current + 1).sister = self.arc_current

        i_node.excess -= low_bound
        j_node.excess += low_bound

        if head_node_id < self.node_min:
            self.node_min = head_node_id
        if tail_node_id < self.node_min:
            self.node_min = tail_node_id
        if head_node_id > self.node_max:
            self.node_max = head_node_id
        if tail_node_id > self.node_max:
            self.node_max = tail_node_id

        if cost < 0:
            cost = -cost
        if cost > self.max_cost and up_bound > 0:
            self.max_cost = cost

        self.arc_current += 2
        self.pos_current += 2

    def set_supply_demand_of_node(self, id, excess):
        if id < 0 or id > self.n:
            sys.exit(1)
        self.nodes[id].excess = excess
        if excess > 0:
            self.total_p += excess
        if excess < 0:
            self.total_n -= excess

def main():
    n, m = map(int, sys.stdin.readline().split())
    grid = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    a, b, c = [], [], []

    for i in range(n):
        for j in range(m):
            if (i + j) % 2:
                if i > 0:
                    a.append(f(i, j))
                    b.append(f(i - 1, j))
                    c.append(grid[i][j] != grid[i - 1][j])
                if j > 0:
                    a.append(f(i, j))
                    b.append(f(i, j - 1))
                    c.append(grid[i][j] != grid[i][j - 1])
                if i + 1 < n:
                    a.append(f(i, j))
                    b.append(f(i + 1, j))
                    c.append(grid[i][j] != grid[i + 1][j])
                if j + 1 < m:
                    a.append(f(i, j))
                    b.append(f(i, j + 1))
                    c.append(grid[i][j] != grid[i][j + 1])

    num_nodes = n * m * 4
    num_arcs = len(a)

    my_mcmf_problem = MCMF_CS2(num_nodes, num_arcs)
    for i in range(num_arcs):
        my_mcmf_problem.set_arc(a[i], b[i], 0, 1, c[i])
    for i in range(n):
        for j in range(m):
            if (i + j) % 2:
                my_mcmf_problem.set_supply_demand_of_node(f(i, j), 1)
            else:
                my_mcmf_problem.set_supply_demand_of_node(f(i, j), -1)
    my_mcmf_problem.run_cs2()

if __name__ == "__main__":
    main()
