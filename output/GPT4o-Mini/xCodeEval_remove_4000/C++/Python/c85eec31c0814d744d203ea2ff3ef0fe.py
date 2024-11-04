from collections import deque
import sys

MAXMEM = 200 * 1000 * 1024
_memory = bytearray(MAXMEM)
_ptr = 0

def new(size):
    global _ptr
    _ptr += size
    assert _ptr < MAXMEM
    return _memory[_ptr - size:_ptr]

def delete(obj):
    pass

string_in_buffer = bytearray(260)

def fast_scan_int():
    return int(sys.stdin.readline().strip())

def fast_scan_long():
    return int(sys.stdin.readline().strip())

def fast_scan_unsigned_long():
    return int(sys.stdin.readline().strip())

def fast_scan_double():
    return float(sys.stdin.readline().strip())

def fast_scan_long_double():
    return float(sys.stdin.readline().strip())

def fast_scan_char():
    return sys.stdin.read(1)

def fast_scan_string():
    return sys.stdin.readline().strip()

def fast_scan_pair():
    return (fast_scan_int(), fast_scan_int())

def fast_scan_vector(n):
    return [fast_scan_int() for _ in range(n)]

def fast_print(value):
    print(value, end='')

def fast_print_vector(v):
    if not v:
        return
    fast_print(v[0])
    for i in range(1, len(v)):
        fast_print(' ')
        fast_print(v[i])

class SmartIO:
    print_start = ""
    sep = " "
    first_print = False

    @staticmethod
    def id1():
        fast_print(SmartIO.print_start)
        SmartIO.print_start = "\n"
        SmartIO.first_print = True

    @staticmethod
    def _print(names, *args):
        if not SmartIO.first_print:
            fast_print("\n")
        else:
            SmartIO.first_print = False
        fast_print(names.popleft())
        fast_print(" = ")
        fast_print(args[0])
        if len(args) > 1:
            SmartIO._print(names, *args[1:])

def floor_mod(a, b):
    if a % b == 0:
        return 0
    if a >= 0 and b >= 0:
        return a % b
    if a <= 0 and b <= 0:
        return a % b
    return abs(b) - (abs(a) % abs(b))

MOD = int(1e9 + 7)

class TreeSegment:
    class Node:
        def __init__(self):
            self.have_mod = False
            self.value = 0
            self.mod = 0

    def __init__(self, n, def_value, magic, apply_mod, merge_mods):
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods
        self.S = [self.Node() for _ in range(2 * n + 1)]
        self.n = n
        self.init([def_value] * n)

    def init(self, src):
        self._init(0, 0, self.n, src)

    def _init(self, i, tl, tr, src):
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self._init(i + 1, tl, mid, src)
            self._init(i + (mid - tl) * 2, mid, tr, src)
            self.__recalc_value(i, tl, tr)

    def __recalc_value(self, i, tl, tr):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            self.S[i].value = self.magic(
                self.__get_value(i + 1, tl, mid),
                self.__get_value(i + (mid - tl) * 2, mid, tr)
            )

    def __get_value(self, i, tl, tr):
        if not self.S[i].have_mod:
            return self.S[i].value
        return self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)

    def query(self, ql, qr):
        assert ql < qr
        return self.__query(0, 0, self.n, ql, qr)

    def __query(self, i, tl, tr, ql, qr):
        self.__push(i, tl, tr)
        if ql <= tl and tr <= qr:
            return self.S[i].value
        mid = (tl + tr) // 2
        if self.__intersects(tl, mid, ql, qr) and self.__intersects(mid, tr, ql, qr):
            return self.magic(
                self.__query(i + 1, tl, mid, ql, qr),
                self.__query(i + (mid - tl) * 2, mid, tr, ql, qr)
            )
        elif self.__intersects(tl, mid, ql, qr):
            return self.__query(i + 1, tl, mid, ql, qr)
        else:
            return self.__query(i + (mid - tl) * 2, mid, tr, ql, qr)

    def __intersects(self, tl, tr, ql, qr):
        return not (tr <= ql or qr <= tl)

    def update(self, ql, qr, mod):
        self.__update(0, 0, self.n, ql, qr, mod)

    def __update(self, i, tl, tr, ql, qr, mod):
        self.__push(i, tl, tr)
        if ql <= tl and tr <= qr:
            self.__add_mod(i, tl, tr, mod)
        else:
            mid = (tl + tr) // 2
            if self.__intersects(tl, mid, ql, qr):
                self.__update(i + 1, tl, mid, ql, qr, mod)
            if self.__intersects(mid, tr, ql, qr):
                self.__update(i + (mid - tl) * 2, mid, tr, ql, qr, mod)
            self.__recalc_value(i, tl, tr)

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
                self.__add_mod(i + 1, tl, mid, self.S[i].mod)
                self.__add_mod(i + (mid - tl) * 2, mid, tr, self.S[i].mod)
            self.S[i].have_mod = False

n, q = fast_scan_int(), fast_scan_int()
pos = fast_scan_vector(n)
w = fast_scan_vector(n)

ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, _, _: mod, 1337)

subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]
resp = TreeSegment(subw, 0, lambda a, b: (a + b) % MOD, lambda value, mod, _, _: mod, 1337)

for _ in range(q):
    x, y = fast_scan_int(), fast_scan_int()
    if x < 0:
        ind = -x - 1
        _new = y
        ts.update(ind, ind + 1, _new)
        resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD)
    else:
        l, r = x - 1, y
        sm = ts.query(l, r)

        bestL = ts.find_right(l, lambda x: x * 2 >= sm, 0)
        x = pos[bestL] - bestL + l

        left = 0
        if l < bestL:
            left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l)
        right = 0
        if bestL < r:
            right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l)

        fast_print(floor_mod(left - right, MOD))
