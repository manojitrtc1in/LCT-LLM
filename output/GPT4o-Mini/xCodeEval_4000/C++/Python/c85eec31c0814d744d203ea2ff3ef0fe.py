import sys
from collections import deque

MOD = 10**9 + 7

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
        self.n = n
        self.S = [self.Node() for _ in range(2 * n + 1)]
        self.init([def_value] * n)

    def init(self, src):
        self._init(0, 0, len(src), src)

    def _init(self, i, tl, tr, src):
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self._init(i + 1, tl, mid, src)
            self._init(i + (mid - tl) * 2, mid, tr, src)
            self._recalc_value(i, tl, tr)

    def _recalc_value(self, i, tl, tr):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            self.S[i].value = self.magic(
                self._get_value(i + 1, tl, mid),
                self._get_value(i + (mid - tl) * 2, mid, tr)
            )

    def _get_value(self, i, tl, tr):
        if not self.S[i].have_mod:
            return self.S[i].value
        return self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)

    def _push(self, i, tl, tr):
        if self.S[i].have_mod:
            self.S[i].value = self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)
            if tl + 1 != tr:
                mid = (tl + tr) // 2
                self._add_mod(i + 1, tl, mid, self.S[i].mod)
                self._add_mod(i + (mid - tl) * 2, mid, tr, self.S[i].mod)
            self.S[i].have_mod = False

    def _add_mod(self, i, tl, tr, sub):
        if self.S[i].have_mod:
            self.S[i].mod = self.merge_mods(self.S[i].mod, sub, tl, tr)
        else:
            self.S[i].mod = sub
            self.S[i].have_mod = True

    def query(self, ql, qr):
        assert ql < qr
        return self._query(0, 0, self.n, ql, qr)

    def _query(self, i, tl, tr, ql, qr):
        self._push(i, tl, tr)
        if ql <= tl and tr <= qr:
            return self.S[i].value
        else:
            mid = (tl + tr) // 2
            if self._intersects(tl, mid, ql, qr) and self._intersects(mid, tr, ql, qr):
                return self.magic(
                    self._query(i + 1, tl, mid, ql, qr),
                    self._query(i + (mid - tl) * 2, mid, tr, ql, qr)
                )
            elif self._intersects(tl, mid, ql, qr):
                return self._query(i + 1, tl, mid, ql, qr)
            else:
                return self._query(i + (mid - tl) * 2, mid, tr, ql, qr)

    def _intersects(self, tl, tr, ql, qr):
        return not (tr <= ql or qr <= tl)

    def update(self, ql, qr, mod):
        self._update(0, 0, self.n, ql, qr, mod)

    def _update(self, i, tl, tr, ql, qr, mod):
        self._push(i, tl, tr)
        if ql <= tl and tr <= qr:
            self._add_mod(i, tl, tr, mod)
        else:
            mid = (tl + tr) // 2
            if self._intersects(tl, mid, ql, qr):
                self._update(i + 1, tl, mid, ql, qr, mod)
            if self._intersects(mid, tr, ql, qr):
                self._update(i + (mid - tl) * 2, mid, tr, ql, qr, mod)
            self._recalc_value(i, tl, tr)

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    q = int(data[1])
    pos = list(map(int, data[2:n + 2]))
    w = list(map(int, data[n + 2:2 * n + 2]))

    ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, _, __: mod, lambda old, new, _, __: new)

    subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]
    resp = TreeSegment(n, 0, lambda a, b: (a + b) % MOD, lambda value, mod, _, __: mod, lambda old, new, _, __: new)

    index = 2 * n + 2
    for _ in range(q):
        x = int(data[index])
        y = int(data[index + 1])
        index += 2
        
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
