import sys

class TreeSegment:
    def __init__(self, n, def_val, magic, apply_mod, merge_mods, mod):
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods
        self.n = n
        self.S = [self.Node() for _ in range(2 * n + 1)]
        self.init(0, 0, len(def_val), def_val)

    class Node:
        def __init__(self):
            self.have_mod = False
            self.value = None
            self.mod = None

    def __intersects(self, tl, tr, ql, qr):
        return not (tr <= ql or qr <= tl)

    def __get_value(self, i, tl, tr):
        if not self.S[i].have_mod:
            return self.S[i].value
        return self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)

    def __recalc_value(self, i, tl, tr):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            self.S[i].value = self.magic(
                self.__get_value(i + 1, tl, mid),
                self.__get_value(i + (mid - tl) * 2, mid, tr)
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
                self.__add_mod(i + 1, tl, mid, self.S[i].mod)
                self.__add_mod(i + (mid - tl) * 2, mid, tr, self.S[i].mod)
            self.S[i].have_mod = False

    def init(self, i, tl, tr, src):
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self.init(i + 1, tl, mid, src)
            self.init(i + (mid - tl) * 2, mid, tr, src)
            self.__recalc_value(i, tl, tr)

    def query(self, ql, qr):
        assert ql < qr
        return self.__query(0, 0, self.n, ql, qr)

    def change(self, i, value):
        assert 0 <= i < self.n
        self.__change(0, 0, self.n, i, value)

    def update(self, ql, qr, mod):
        self.__update(0, 0, self.n, ql, qr, mod)

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

    def __change(self, i, tl, tr, j, _new):
        self.__push(i, tl, tr)
        if tl + 1 == tr:
            self.S[i].value = _new
        else:
            m = (tl + tr) // 2
            if j < m:
                self.__change(self.S[i].l, tl, m, j, _new)
            else:
                self.__change(self.S[i].r, m, tr, j, _new)
            self.__recalc_value(i, tl, tr)

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

    def find_right(self, L, checker, start):
        if checker(start):
            return L - 1
        rez = self.__find_right(0, 0, self.n, L, checker, start)[0]
        return self.n if rez == -1 else rez

    def find_left(self, R, checker, start):
        if checker(start):
            return R + 1
        rez = self.__find_left(0, 0, self.n, R, checker, start)[0]
        return -1 if rez == -1 else rez

    def __find_right(self, i, tl, tr, L, checker, pref):
        self.__push(i, tl, tr)
        if tr <= L:
            return -1, pref
        if tl + 1 == tr:
            _this = self.magic(pref, self.__get_value(i, tl, tr))
            if checker(_this):
                return tl, _this
            else:
                return -1, _this
        else:
            mid = (tl + tr) // 2
            if L <= tl:
                _left = self.magic(pref, self.__get_value(i + 1, tl, mid))
                if checker(_left):
                    return self.__find_right(i + 1, tl, mid, L, checker, pref)
                else:
                    return self.__find_right(i + (mid - tl) * 2, mid, tr, L, checker, _left)
            else:
                t = self.__find_right(i + 1, tl, mid, L, checker, pref)
                if t[0] != -1:
                    return t
                return self.__find_right(i + (mid - tl) * 2, mid, tr, L, checker, t[1])

    def __find_left(self, i, tl, tr, R, checker, pref):
        self.__push(i, tl, tr)
        if R < tl:
            return -1, pref
        if tl + 1 == tr:
            _this = self.magic(pref, self.__get_value(i, tl, tr))
            if checker(_this):
                return tl, _this
            else:
                return -1, _this
        else:
            mid = (tl + tr) // 2
            if tr <= R + 1:
                _right = self.magic(pref, self.__get_value(self.S[i].r, mid, tr))
                if checker(_right):
                    return self.__find_left(self.S[i].r, mid, tr, R, checker, pref)
                else:
                    return self.__find_left(self.S[i].l, tl, mid, R, checker, _right)
            else:
                t = self.__find_left(self.S[i].r, mid, tr, R, checker, pref)
                if t[0] != -1:
                    return t
                return self.__find_left(self.S[i].l, tl, mid, R, checker, t[1])

    def __get_value(self, i, tl, tr):
        if not self.S[i].have_mod:
            return self.S[i].value
        return self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)

    def __recalc_value(self, i, tl, tr):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            self.S[i].value = self.magic(
                self.__get_value(i + 1, tl, mid),
                self.__get_value(i + (mid - tl) * 2, mid, tr)
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
                self.__add_mod(i + 1, tl, mid, self.S[i].mod)
                self.__add_mod(i + (mid - tl) * 2, mid, tr, self.S[i].mod)
            self.S[i].have_mod = False

    def init(self, src):
        self.n = len(src)
        self.S = [self.Node() for _ in range(2 * self.n + 1)]
        self.init(0, 0, len(src), src)

def floor_mod(a, b):
    if a % b == 0:
        return 0
    if a >= 0 and b >= 0:
        return a % b
    if a <= 0 and b <= 0:
        return a % b
    return abs(b) - (abs(a) % abs(b))

def magic(a, b):
    return a + b

def apply_mod(value, mod, tl, tr):
    return mod

def merge_mods(old, _new, tl, tr):
    return _new

def solve():
    n, q = map(int, input().split())
    pos = list(map(int, input().split()))
    w = list(map(int, input().split()))

    ts = TreeSegment(n, 0, magic, apply_mod, merge_mods, 1337)
    resp = TreeSegment(w, lambda a, b: (a + b) % MOD, apply_mod, merge_mods, merge_mods, 1337)

    subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]

    resp = TreeSegment(subw, lambda a, b: (a + b) % MOD, apply_mod, merge_mods, merge_mods, 1337)

    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] < 0:
            ind = -query[0] - 1
            _new = query[1]
            ts.update(ind, ind + 1, _new)
            resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD)
        else:
            l, r = query[0] - 1, query[1]
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

solve()
