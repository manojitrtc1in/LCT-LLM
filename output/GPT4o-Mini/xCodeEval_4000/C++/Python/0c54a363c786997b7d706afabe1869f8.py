import sys
from collections import deque
from typing import List, Tuple, Callable

MOD = int(1e9 + 7)

def floor_mod(a: int, b: int) -> int:
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

    def __init__(self, n: int, def_value: int, magic: Callable, apply_mod: Callable, merge_mods: Callable):
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods
        self.S = [self.Node() for _ in range(2 * n + 1)]
        self.n = n

    def __intersects(self, tl: int, tr: int, ql: int, qr: int) -> bool:
        return not (tr <= ql or qr <= tl)

    def __get_value(self, i: int, tl: int, tr: int):
        if not self.S[i].have_mod:
            return self.S[i].value
        return self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)

    def __recalc_value(self, i: int, tl: int, tr: int):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            self.S[i].value = self.magic(
                self.__get_value(i + 1, tl, mid),
                self.__get_value(i + (mid - tl) * 2, mid, tr)
            )

    def __add_mod(self, i: int, tl: int, tr: int, sub):
        if self.S[i].have_mod:
            self.S[i].mod = self.merge_mods(self.S[i].mod, sub, tl, tr)
        else:
            self.S[i].mod = sub
            self.S[i].have_mod = True

    def __push(self, i: int, tl: int, tr: int):
        if self.S[i].have_mod:
            self.S[i].value = self.apply_mod(self.S[i].value, self.S[i].mod, tl, tr)
            if tl + 1 != tr:
                mid = (tl + tr) // 2
                self.__add_mod(i + 1, tl, mid, self.S[i].mod)
                self.__add_mod(i + (mid - tl) * 2, mid, tr, self.S[i].mod)
            self.S[i].have_mod = False

    def init(self, src: List[int]):
        self.n = len(src)
        self.S = [self.Node() for _ in range(2 * self.n + 1)]
        self.__init(0, 0, self.n, src)

    def __init(self, i: int, tl: int, tr: int, src: List[int]):
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self.__init(i + 1, tl, mid, src)
            self.__init(i + (mid - tl) * 2, mid, tr, src)
            self.__recalc_value(i, tl, tr)

    def __query(self, i: int, tl: int, tr: int, ql: int, qr: int):
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

    def query(self, ql: int, qr: int) -> int:
        assert ql < qr
        return self.__query(0, 0, self.n, ql, qr)

    def change(self, i: int, value: int):
        assert 0 <= i < self.n
        self.__change(0, 0, self.n, i, value)

    def __change(self, i: int, tl: int, tr: int, j: int, new_value: int):
        self.__push(i, tl, tr)
        if tl + 1 == tr:
            self.S[i].value = new_value
        else:
            mid = (tl + tr) // 2
            if j < mid:
                self.__change(self.S[i].l, tl, mid, j, new_value)
            else:
                self.__change(self.S[i].r, mid, tr, j, new_value)
            self.__recalc_value(i, tl, tr)

    def update(self, ql: int, qr: int, mod):
        self.__update(0, 0, self.n, ql, qr, mod)

    def __update(self, i: int, tl: int, tr: int, ql: int, qr: int, mod):
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

    def find_right(self, L: int, checker: Callable, start: int) -> int:
        if checker(start):
            return L - 1
        rez = self.__find_right(0, 0, self.n, L, checker, start).first
        return rez if rez != -1 else self.n

    def __find_right(self, i: int, tl: int, tr: int, L: int, checker: Callable, pref: int):
        self.__push(i, tl, tr)
        if tr <= L:
            return -1, pref
        if tl + 1 == tr:
            _this = self.magic(pref, self.__get_value(i, tl, tr))
            return (tl, _this) if checker(_this) else (-1, _this)
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

    def find_left(self, R: int, checker: Callable, start: int) -> int:
        if checker(start):
            return R + 1
        rez = self.__find_left(0, 0, self.n, R, checker, start).first
        return rez if rez != -1 else -1

    def __find_left(self, i: int, tl: int, tr: int, R: int, checker: Callable, pref: int):
        self.__push(i, tl, tr)
        if R < tl:
            return -1, pref
        if tl + 1 == tr:
            _this = self.magic(pref, self.__get_value(i, tl, tr))
            return (tl, _this) if checker(_this) else (-1, _this)
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

def main():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    n = int(data[index])
    index += 1
    q = int(data[index])
    index += 1
    
    pos = [0] * n
    w = [0] * n
    
    for i in range(n):
        pos[i] = int(data[index])
        index += 1
    for i in range(n):
        w[i] = int(data[index])
        index += 1

    ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, _, _: mod, lambda old, new, _, _: new)

    subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]
    resp = TreeSegment(n, 0, lambda a, b: (a + b) % MOD, lambda value, mod, _, _: mod, lambda old, new, _, _: new)

    for _ in range(q):
        x = int(data[index])
        index += 1
        y = int(data[index])
        index += 1
        
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
