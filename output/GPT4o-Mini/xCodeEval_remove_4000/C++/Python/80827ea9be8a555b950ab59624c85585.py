from collections import deque
import sys

input = sys.stdin.read
MOD = int(1e9 + 7)

class TreeSegment:
    class Node:
        def __init__(self):
            self.have_mod = False
            self.value = 0
            self.mod = 0

    def __init__(self, src, magic, apply_mod, merge_mods):
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods
        self.n = len(src)
        self.S = [self.Node() for _ in range(2 * self.n + 1)]
        self.init(0, 0, self.n, src)

    def init(self, i, tl, tr, src):
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self.init(i + 1, tl, mid, src)
            self.init(i + (mid - tl) * 2, mid, tr, src)
            self.recalc_value(i, tl, tr)

    def recalc_value(self, i, tl, tr):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            self.S[i].value = self.magic(
                self.get_value(i + 1, tl, mid),
                self.get_value(i + (mid - tl) * 2, mid, tr)
            )

    def get_value(self, i, tl, tr):
        if not self.S[i].have_mod:
            return self.S[i].value
        return self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)

    def push(self, i, tl, tr):
        if self.S[i].have_mod:
            self.S[i].value = self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)
            if tl + 1 != tr:
                mid = (tl + tr) // 2
                self.add_mod(i + 1, tl, mid, self.S[i].mod)
                self.add_mod(i + (mid - tl) * 2, mid, tr, self.S[i].mod)
            self.S[i].have_mod = False

    def add_mod(self, i, tl, tr, sub):
        if self.S[i].have_mod:
            self.S[i].mod = self.merge_mods(self.S[i].mod, sub, tl, tr)
        else:
            self.S[i].mod = sub
            self.S[i].have_mod = True

    def update(self, ql, qr, mod):
        self.push(0, 0, self.n)
        if ql <= 0 and qr >= self.n:
            self.add_mod(0, 0, self.n, mod)
        else:
            mid = (0 + self.n) // 2
            if self.intersects(0, mid, ql, qr):
                self.update(ql, qr, mod)
            if self.intersects(mid, self.n, ql, qr):
                self.update(ql, qr, mod)

    def intersects(self, tl, tr, ql, qr):
        return not (tr <= ql or qr <= tl)

    def query(self, ql, qr):
        assert ql < qr
        return self.__query(0, 0, self.n, ql, qr)

    def __query(self, i, tl, tr, ql, qr):
        self.push(i, tl, tr)
        if ql <= tl and tr <= qr:
            return self.S[i].value
        mid = (tl + tr) // 2
        if self.intersects(tl, mid, ql, qr) and self.intersects(mid, tr, ql, qr):
            return self.magic(
                self.__query(i + 1, tl, mid, ql, qr),
                self.__query(i + (mid - tl) * 2, mid, tr, ql, qr)
            )
        elif self.intersects(tl, mid, ql, qr):
            return self.__query(i + 1, tl, mid, ql, qr)
        else:
            return self.__query(i + (mid - tl) * 2, mid, tr, ql, qr)

def floor_mod(a, b):
    if a % b == 0:
        return 0
    if a >= 0 and b >= 0:
        return a % b
    if a <= 0 and b <= 0:
        return a % b
    return abs(b) - (abs(a) % abs(b))

def main():
    n, q = map(int, input().split())
    pos = list(map(int, input().split()))
    w = list(map(int, input().split()))

    ts = TreeSegment(w, lambda a, b: a + b, lambda value, mod, _, _: mod)

    subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]
    resp = TreeSegment(subw, lambda a, b: (a + b) % MOD, lambda value, mod, _, _: mod)

    for _ in range(q):
        x, y = map(int, input().split())
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

            left = 0
            if l < bestL:
                left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l)
            right = 0
            if bestL < r:
                right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l)

            print(floor_mod(left - right, MOD))

if __name__ == "__main__":
    main()
