import sys
from collections import deque
from typing import List, Tuple, Callable

MOD = 10**9 + 7

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

    def __create_node(self):
        self.S.append(self.Node())
        return len(self.S) - 1

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

    def init(self, i: int, tl: int, tr: int, src: List[int]):
        if tl + 1 == tr:
            self.S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            self.init(i + 1, tl, mid, src)
            self.init(i + (mid - tl) * 2, mid, tr, src)
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

    def init_tree(self, src: List[int]):
        self.init(0, 0, len(src), src)

    def query(self, ql: int, qr: int):
        assert ql < qr
        return self.__query(0, 0, self.n, ql, qr)

    def change(self, i: int, value: int):
        assert 0 <= i < self.n
        self.__change(0, 0, self.n, i, value)

    def update(self, ql: int, qr: int, mod):
        self.__update(0, 0, self.n, ql, qr, mod)

def main():
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    n = int(data[idx])
    q = int(data[idx + 1])
    idx += 2
    
    pos = list(map(int, data[idx:idx + n]))
    idx += n
    w = list(map(int, data[idx:idx + n]))
    idx += n

    ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, _, _: mod, lambda old, new, _, _: new)
    subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]
    resp = TreeSegment(n, 0, lambda a, b: (a + b) % MOD, lambda value, mod, _, _: mod, lambda old, new, _, _: new)

    ts.init_tree(w)
    resp.init_tree(subw)

    results = []
    
    for _ in range(q):
        x = int(data[idx])
        y = int(data[idx + 1])
        idx += 2
        
        if x < 0:
            ind = -x - 1
            new_value = y
            ts.update(ind, ind + 1, new_value)
            resp.update(ind, ind + 1, (new_value * (ind - pos[ind])) % MOD)
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

            results.append(floor_mod(left - right, MOD))

    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
