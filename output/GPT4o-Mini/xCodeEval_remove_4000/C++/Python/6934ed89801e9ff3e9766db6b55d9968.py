class Id32:
    def __init__(self, num_nodes, id13):
        self._n = num_nodes
        self._m = id13
        self._flag_price = 0
        self.id29 = 0
        self._n_push = 0
        self.id24 = 0
        self.id17 = 0
        self.id22 = 0
        self._n_update = 0
        self._n_scan = 0
        self.id6 = 0
        self.id34 = 0
        self.id27 = 0
        self.id15 = 0
        self.id7 = 0
        self.id3 = 0
        self.id2 = False
        self._check_solution = False
        self.id1 = False
        self._cost_restart = False
        self._print_ans = True
        self.allocate_arrays()

    def allocate_arrays(self):
        self._nodes = [Node() for _ in range(self._n + 2)]
        self._arcs = [Arc() for _ in range(2 * self._m + 1)]
        self._cap = [0] * (2 * self._m)
        self._arc_tail = [0] * (2 * self._m)
        self._arc_first = [0] * (self._n + 2)

        for node in self._nodes:
            node.set_excess(0)

        if not self._nodes or not self._arcs or not self._arc_first or not self._arc_tail:
            exit(1)

        self._pos_current = 0
        self._arc_current = self._arcs
        self._node_max = 0
        self._node_min = self._n
        self._max_cost = 0
        self._total_p = 0
        self._total_n = 0

    def set_arc(self, id10, id28, low_bound, up_bound, cost):
        if id10 < 0 or id10 > self._n or id28 < 0 or id28 > self._n:
            exit(1)
        if up_bound < 0:
            up_bound = 0
        if low_bound < 0 or low_bound > up_bound:
            exit(1)

        self._arc_first[id10 + 1] += 1
        self._arc_first[id28 + 1] += 1
        self._i_node = self._nodes[id10]
        self._j_node = self._nodes[id28]

        self._arc_tail[self._pos_current] = id10
        self._arc_tail[self._pos_current + 1] = id28
        self._arc_current.set_head(self._j_node)
        self._arc_current.set_rez_capacity(up_bound - low_bound)
        self._cap[self._pos_current] = up_bound
        self._arc_current.set_cost(cost)
        self._arc_current.set_sister(self._arc_current + 1)
        (self._arc_current + 1).set_head(self._nodes[id10])
        (self._arc_current + 1).set_rez_capacity(0)
        self._cap[self._pos_current + 1] = 0
        (self._arc_current + 1).set_cost(-cost)
        (self._arc_current + 1).set_sister(self._arc_current)

        self._i_node.dec_excess(low_bound)
        self._j_node.inc_excess(low_bound)

        if id28 < self._node_min:
            self._node_min = id28
        if id10 < self._node_min:
            self._node_min = id10
        if id28 > self._node_max:
            self._node_max = id28
        if id10 > self._node_max:
            self._node_max = id10

        if cost < 0:
            cost = -cost
        if cost > self._max_cost and up_bound > 0:
            self._max_cost = cost

        self._arc_current += 2
        self._pos_current += 2

    def set_supply_demand_of_node(self, id, excess):
        if id < 0 or id > self._n:
            exit(1)
        self._nodes[id].set_excess(excess)
        if excess > 0:
            self._total_p += excess
        if excess < 0:
            self._total_n -= excess

    def run_cs2(self):
        # Implementation of the cs2 algorithm
        pass

class Node:
    def __init__(self):
        self._excess = 0
        self._price = 0
        self._first = None
        self._current = None
        self._suspended = None
        self._q_next = None
        self._b_next = None
        self._b_prev = None
        self._rank = 0
        self._inp = 0

    def set_excess(self, excess):
        self._excess = excess

    def dec_excess(self, delta):
        self._excess -= delta

    def inc_excess(self, delta):
        self._excess += delta

    def set_price(self, price):
        self._price = price

    def dec_price(self, delta):
        self._price -= delta

    def set_first(self, first):
        self._first = first

    def set_current(self, current):
        self._current = current

    def set_suspended(self, suspended):
        self._suspended = suspended

    def set_q_next(self, q_next):
        self._q_next = q_next

    def set_b_next(self, b_next):
        self._b_next = b_next

    def set_b_prev(self, b_prev):
        self._b_prev = b_prev

    def set_rank(self, rank):
        self._rank = rank

    def set_inp(self, inp):
        self._inp = inp

    def excess(self):
        return self._excess

    def price(self):
        return self._price

    def first(self):
        return self._first

    def current(self):
        return self._current

    def suspended(self):
        return self._suspended

    def q_next(self):
        return self._q_next

    def b_next(self):
        return self._b_next

    def b_prev(self):
        return self._b_prev

    def rank(self):
        return self._rank

    def inp(self):
        return self._inp

class Arc:
    def __init__(self):
        self.id5 = 0
        self._cost = 0
        self._head = None
        self._sister = None

    def set_rez_capacity(self, rez_capacity):
        self.id5 = rez_capacity

    def dec_rez_capacity(self, delta):
        self.id5 -= delta

    def inc_rez_capacity(self, delta):
        self.id5 += delta

    def set_cost(self, cost):
        self._cost = cost

    def multiply_cost(self, mult):
        self._cost *= mult

    def set_head(self, head):
        self._head = head

    def set_sister(self, sister):
        self._sister = sister

    def rez_capacity(self):
        return self.id5

    def cost(self):
        return self._cost

    def head(self):
        return self._head

    def sister(self):
        return self._sister

def f(r, c, m):
    return r * m + c + 1

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
a, b, c = [], [], []

for i in range(n):
    for j in range(m):
        if (i + j) % 2:
            if i > 0:
                a.append(f(i, j, m))
                b.append(f(i - 1, j, m))
                c.append(grid[i][j] != grid[i - 1][j])
            if j > 0:
                a.append(f(i, j, m))
                b.append(f(i, j - 1, m))
                c.append(grid[i][j] != grid[i][j - 1])
            if i + 1 < n:
                a.append(f(i, j, m))
                b.append(f(i + 1, j, m))
                c.append(grid[i][j] != grid[i + 1][j])
            if j + 1 < m:
                a.append(f(i, j, m))
                b.append(f(i, j + 1, m))
                c.append(grid[i][j] != grid[i][j + 1])

num_nodes = n * m * 4
id13 = len(a)

id8 = Id32(num_nodes, id13)
for i in range(id13):
    id8.set_arc(a[i], b[i], 0, 1, c[i])

for i in range(n):
    for j in range(m):
        if (i + j) % 2:
            id8.set_supply_demand_of_node(f(i, j, m), 1)
        else:
            id8.set_supply_demand_of_node(f(i, j, m), -1)

id8.run_cs2()
