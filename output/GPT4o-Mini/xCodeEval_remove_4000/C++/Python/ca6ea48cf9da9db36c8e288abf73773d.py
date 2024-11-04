from collections import deque
import sys

MAXMEM = 200 * 1000 * 1024
_memory = bytearray(MAXMEM)
_ptr = 0

def fast_scan_int():
    return int(sys.stdin.readline().strip())

def fast_scan_long():
    return int(sys.stdin.readline().strip())

def fast_scan_unsigned_long():
    return int(sys.stdin.readline().strip())

def fast_scan_double():
    return float(sys.stdin.readline().strip())

def fast_scan_string():
    return sys.stdin.readline().strip()

def fast_print(value):
    print(value, end='')

def fast_print_string(value):
    print(value, end='')

def fast_print_vector(v):
    if not v:
        return
    fast_print(v[0])
    for i in range(1, len(v)):
        fast_print(' ')
        fast_print(v[i])

def fast_print_vector_of_vectors(v):
    if not v:
        return
    fast_print_vector(v[0])
    for i in range(1, len(v)):
        fast_print('\n')
        fast_print_vector(v[i])

class TreeSegment:
    class Node:
        def __init__(self):
            self.have_mod = False
            self.l = -1
            self.r = -1
            self.value = 0
            self.mod = 0

    def __init__(self, n, def_value, magic, apply_mod, merge_mods):
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods
        self.S = []
        self.n = n
        self.init([def_value] * n)

    def __intersects(self, tl, tr, ql, qr):
        return not (tr <= ql or qr <= tl)

    def __create_node(self):
        node = self.Node()
        self.S.append(node)
        return len(self.S) - 1

    def __get_value(self, i, tl, tr):
        if not self.S[i].have_mod:
            return self.S[i].value
        return self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)

    def __recalc_value(self, i, tl, tr):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            self.S[i].value = self.magic(
                self.__get_value(self.S[i].l, tl, mid),
                self.__get_value(self.S[i].r, mid, tr)
            )

    def __add_mod(self, i, tl, tr, sub):
        if self.S[i].have_mod:
            self.S[i].mod = self.merge_mods(self.S[i].mod, sub, tl, tr)
        else:
            self.S[i].mod = sub
            self.S[i].have_mod = True

    def __push(self, i, tl, tr):
        if self.S[i].have_mod:
            self.S[i].value = self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)
            if tl + 1 != tr:
                mid = (tl + tr) // 2
                self.__add_mod(self.S[i].l, tl, mid, self.S[i].mod)
                self.__add_mod(self.S[i].r, mid, tr, self.S[i].mod)
            self.S[i].have_mod = False

    def init(self, src):
        self.n = len(src)
        self.__init_nodes(0, self.n, src)

    def __init_nodes(self, tl, tr, src):
        i = self.__create_node()
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self.S[i].l = self.__init_nodes(tl, mid, src)
            self.S[i].r = self.__init_nodes(mid, tr, src)
            self.__recalc_value(i, tl, tr)
        return i

    def query(self, ql, qr):
        return self.__query(0, 0, self.n, ql, qr)

    def __query(self, i, tl, tr, ql, qr):
        self.__push(i, tl, tr)
        if ql <= tl and tr <= qr:
            return self.S[i].value
        mid = (tl + tr) // 2
        if self.__intersects(tl, mid, ql, qr) and self.__intersects(mid, tr, ql, qr):
            return self.magic(
                self.__query(self.S[i].l, tl, mid, ql, qr),
                self.__query(self.S[i].r, mid, tr, ql, qr)
            )
        elif self.__intersects(tl, mid, ql, qr):
            return self.__query(self.S[i].l, tl, mid, ql, qr)
        elif self.__intersects(mid, tr, ql, qr):
            return self.__query(self.S[i].r, mid, tr, ql, qr)
        else:
            raise AssertionError("Query out of bounds")

    def update(self, ql, qr, mod):
        self.__update(0, 0, self.n, ql, qr, mod)

    def __update(self, i, tl, tr, ql, qr, mod):
        self.__push(i, tl, tr)
        if ql <= tl and tr <= qr:
            self.__add_mod(i, tl, tr, mod)
        else:
            mid = (tl + tr) // 2
            if self.__intersects(tl, mid, ql, qr):
                self.__update(self.S[i].l, tl, mid, ql, qr, mod)
            if self.__intersects(mid, tr, ql, qr):
                self.__update(self.S[i].r, mid, tr, ql, qr, mod)
            self.__recalc_value(i, tl, tr)

def floor_mod(a, b):
    if a % b == 0:
        return 0
    if a >= 0 and b >= 0:
        return a % b
    if a <= 0 and b <= 0:
        return a % b
    return abs(b) - (abs(a) % abs(b))

n = fast_scan_int()
q = fast_scan_int()
pos = [0] * n
w = [0] * n
for i in range(n):
    pos[i] = fast_scan_int()
for i in range(n):
    w[i] = fast_scan_int()

ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, _, _: mod)

subw = [(w[i] * (i - pos[i])) % (10**9 + 7) for i in range(n)]
resp = TreeSegment(subw, 0, lambda a, b: (a + b) % (10**9 + 7), lambda value, mod, _, _: mod)

for _ in range(q):
    x = fast_scan_int()
    y = fast_scan_int()
    if x < 0:
        ind = -x - 1
        _new = y
        ts.update(ind, ind + 1, _new)
        resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % (10**9 + 7))
    else:
        l = x - 1
        r = y
        sm = ts.query(l, r)

        bestL = ts.find_right(l, lambda x: x * 2 >= sm, 0)

        x = pos[bestL] - bestL + l

        left = 0
        if l < bestL:
            left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l)
        right = 0
        if bestL < r:
            right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l)

        fast_print(floor_mod(left - right, 10**9 + 7))
