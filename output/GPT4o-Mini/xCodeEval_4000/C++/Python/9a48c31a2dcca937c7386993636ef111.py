import sys
from collections import deque

MOD = int(1e9 + 7)

def floor_mod(a, b):
    if a % b == 0:
        return 0
    if a >= 0 and b >= 0:
        return a % b
    if a <= 0 and b <= 0:
        return a % b
    return abs(b) - (abs(a) % abs(b))

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
        self.__init(0, 0, self.n, src)

    def __init(self, i, tl, tr, src):
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self.__init(i + 1, tl, mid, src)
            self.__init(i + (mid - tl) * 2, mid, tr, src)
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

    def __push(self, i, tl, tr):
        if self.S[i].have_mod:
            self.S[i].value = self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)
            if tl + 1 != tr:
                mid = (tl + tr) // 2
                self.__add_mod(i + 1, tl, mid, self.S[i].mod)
                self.__add_mod(i + (mid - tl) * 2, mid, tr, self.S[i].mod)
            self.S[i].have_mod = False

    def __add_mod(self, i, tl, tr, sub):
        if self.S[i].have_mod:
            self.S[i].mod = self.merge_mods(self.S[i].mod, sub, tl, tr)
        else:
            self.S[i].mod = sub
            self.S[i].have_mod = True

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

    def __intersects(self, tl, tr, ql, qr):
        return not (tr <= ql or qr <= tl)

    def query(self, ql, qr):
        assert ql < qr
        return self.__query(0, 0, self.n, ql, qr)

    def __query(self, i, tl, tr, ql, qr):
        self.__push(i, tl, tr)
        if ql <= tl and tr <= qr:
            return self.S[i].value
        else:
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

n, q = map(int, sys.stdin.readline().split())
pos = list(map(int, sys.stdin.readline().split()))
w = list(map(int, sys.stdin.readline().split()))

ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, _, _: mod, lambda old, new, _, _: new)

subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]
resp = TreeSegment(n, 0, lambda a, b: (a + b) % MOD, lambda value, mod, _, _: mod, lambda old, new, _, _: new)

for _ in range(q):
    x, y = map(int, sys.stdin.readline().split())
    if x < 0:
        ind = -x - 1
        _new = y
        ts.update(ind, ind + 1, _new)
        resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD)
    else:
        l = x - 1
        r = y
        sm = ts.query(l, r)

        bestL = ts.find_right(l, lambda x: x * 2 >= sm, 0)
        x = pos[bestL] - bestL + l

        left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l) if l < bestL else 0
        right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l) if bestL < r else 0

        print(floor_mod(left - right, MOD))
