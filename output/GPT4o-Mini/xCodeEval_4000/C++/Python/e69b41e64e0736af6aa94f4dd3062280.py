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
        self.__init(0, len(src), src)

    def __init(self, tl, tr, src):
        i = self.__create_node()
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self.S[i].l = self.__init(tl, mid, src)
            self.S[i].r = self.__init(mid, tr, src)
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
            assert False

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

    def find_right(self, L, checker, start):
        if checker(start):
            return L - 1
        rez = self.__find_right(0, 0, self.n, L, checker, start)[0]
        return self.n if rez == -1 else rez

    def __find_right(self, i, tl, tr, L, checker, pref):
        self.__push(i, tl, tr)
        if tr <= L:
            return -1, pref
        if tl + 1 == tr:
            _this = self.magic(pref, self.__get_value(i, tl, tr))
            return (tl, _this) if checker(_this) else (-1, _this)
        mid = (tl + tr) // 2
        if L <= tl:
            _left = self.magic(pref, self.__get_value(self.S[i].l, tl, mid))
            if checker(_left):
                return self.__find_right(self.S[i].l, tl, mid, L, checker, pref)
            else:
                return self.__find_right(self.S[i].r, mid, tr, L, checker, _left)
        else:
            t = self.__find_right(self.S[i].l, tl, mid, L, checker, pref)
            if t[0] != -1:
                return t
            return self.__find_right(self.S[i].r, mid, tr, L, checker, t[1])

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    q = int(data[1])
    pos = list(map(int, data[2:n + 2]))
    w = list(map(int, data[n + 2:2 * n + 2]))

    ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, _, _: mod, lambda old, new, _, _: new)

    subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]
    resp = TreeSegment(subw, 0, lambda a, b: (a + b) % MOD, lambda value, mod, _, _: mod, lambda old, new, _, _: new)

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
                left = (resp.query(l, bestL) + ts.query(l, bestL) * (x - l)) % MOD
            right = 0
            if bestL < r:
                right = (resp.query(bestL, r) + ts.query(bestL, r) * (x - l)) % MOD

            print(floor_mod(left - right, MOD))

if __name__ == "__main__":
    main()
