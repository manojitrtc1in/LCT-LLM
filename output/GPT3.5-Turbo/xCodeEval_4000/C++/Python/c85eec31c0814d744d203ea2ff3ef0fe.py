import sys

class TreeSegment:
    def __init__(self, n, default_val, magic, apply_mod, merge_mods, mod):
        self.n = n
        self.S = [self.Node() for _ in range(2 * n + 1)]
        self.init(0, 0, len(default_val), default_val)
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods

    class Node:
        def __init__(self):
            self.have_mod = False
            self.value = None
            self.mod = None

    def __intersects(self, tl, tr, ql, qr):
        return not (tr <= ql or qr <= tl)

    def __get_value(self, i, tl, tr):
        if not S[i].have_mod:
            return S[i].value
        return apply_mod(S[i].value, S[i].mod, tl, tr)

    def __recalc_value(self, i, tl, tr):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            S[i].value = magic(
                __get_value(i + 1, tl, mid),
                __get_value(i + (mid - tl) * 2, mid, tr)
            )

    def __add_mod(self, i, tl, tr, sub):
        if S[i].have_mod:
            S[i].mod = merge_mods(S[i].mod, sub, tl, tr)
        else:
            S[i].mod = sub
            S[i].have_mod = True

    def __push(self, i, tl, tr):
        if S[i].have_mod:
            S[i].value = apply_mod(S[i].value, S[i].mod, tl, tr)
            if tl + 1 != tr:
                mid = (tl + tr) // 2
                __add_mod(i + 1, tl, mid, S[i].mod)
                __add_mod(i + (mid - tl) * 2, mid, tr, S[i].mod)
            S[i].have_mod = False

    def init(self, i, tl, tr, src):
        if tl + 1 == tr:
            S[i].value = src[tl]
        else:
            mid = (tl + tr) // 2
            init(i + 1, tl, mid, src)
            init(i + (mid - tl) * 2, mid, tr, src)
            __recalc_value(i, tl, tr)

    def __query(self, i, tl, tr, ql, qr):
        __push(i, tl, tr)
        if ql <= tl and tr <= qr:
            return S[i].value
        else:
            mid = (tl + tr) // 2
            if __intersects(tl, mid, ql, qr) and __intersects(mid, tr, ql, qr):
                return magic(
                    __query(i + 1, tl, mid, ql, qr),
                    __query(i + (mid - tl) * 2, mid, tr, ql, qr)
                )
            elif __intersects(tl, mid, ql, qr):
                return __query(i + 1, tl, mid, ql, qr)
            else:
                return __query(i + (mid - tl) * 2, mid, tr, ql, qr)

    def __change(self, i, tl, tr, j, _new):
        __push(i, tl, tr)
        if tl + 1 == tr:
            S[i].value = _new
        else:
            m = (tl + tr) // 2
            if j < m:
                __change(S[i].l, tl, m, j, _new)
            else:
                __change(S[i].r, m, tr, j, _new)
            __recalc_value(i, tl, tr)

    def __update(self, i, tl, tr, ql, qr, mod):
        __push(i, tl, tr)
        if ql <= tl and tr <= qr:
            __add_mod(i, tl, tr, mod)
        else:
            mid = (tl + tr) // 2
            if __intersects(tl, mid, ql, qr):
                __update(i + 1, tl, mid, ql, qr, mod)
            if __intersects(mid, tr, ql, qr):
                __update(i + (mid - tl) * 2, mid, tr, ql, qr, mod)
            __recalc_value(i, tl, tr)

    def query(self, ql, qr):
        assert ql < qr
        return __query(0, 0, n, ql, qr)

    def change(self, i, value):
        assert 0 <= i and i < n
        __change(0, 0, n, i, value)

    def update(self, ql, qr, mod):
        __update(0, 0, n, ql, qr, mod)

    def __find_right(self, i, tl, tr, L, checker, pref):
        __push(i, tl, tr)
        if tr <= L:
            return (-1, pref)
        if tl + 1 == tr:
            _this = magic(pref, __get_value(i, tl, tr))
            if checker(_this):
                return (tl, _this)
            else:
                return (-1, _this)
        else:
            mid = (tl + tr) // 2
            if L <= tl:
                _left = magic(pref, __get_value(i + 1, tl, mid))
                if checker(_left):
                    return __find_right(i + 1, tl, mid, L, checker, pref)
                else:
                    return __find_right(i + (mid - tl) * 2, mid, tr, L, checker, _left)
            else:
                t = __find_right(i + 1, tl, mid, L, checker, pref)
                if t[0] != -1:
                    return t
                return __find_right(i + (mid - tl) * 2, mid, tr, L, checker, t[1])

    def __find_left(self, i, tl, tr, R, checker, pref):
        __push(i, tl, tr)
        if R < tl:
            return (-1, pref)
        if tl + 1 == tr:
            _this = magic(pref, __get_value(i, tl, tr))
            if checker(_this):
                return (tl, _this)
            else:
                return (-1, _this)
        else:
            mid = (tl + tr) // 2
            if tr <= R + 1:
                _right = magic(pref, __get_value(S[i].r, mid, tr))
                if checker(_right):
                    return __find_left(S[i].r, mid, tr, R, checker, pref)
                else:
                    return __find_left(S[i].l, tl, mid, R, checker, _right)
            else:
                t = __find_left(S[i].r, mid, tr, R, checker, pref)
                if t[0] != -1:
                    return t
                return __find_left(S[i].l, tl, mid, R, checker, t[1])

    def init(self, src):
        n = len(src)
        self.S = [self.Node() for _ in range(2 * n + 1)]
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

class FastScanner:
    def __init__(self):
        self.input = sys.stdin.buffer
        self.buffer = bytearray()
        self.pos = 0

    def read(self, size):
        if self.pos >= len(self.buffer):
            self.buffer = self.input.read(size)
            self.pos = 0
        self.pos += size
        return self.buffer[self.pos - size:self.pos]

    def readline(self):
        res = bytearray()
        while True:
            b = self.read(1)
            if not b or b == b"\n":
                break
            res += b
        return res.decode()

    def read_int(self):
        s = self.readline().strip()
        return int(s)

    def read_ints(self):
        s = self.readline().strip()
        return list(map(int, s.split()))

    def read_string(self):
        return self.readline().strip()

def main():
    fs = FastScanner()
    n, q = fs.read_ints()
    pos = fs.read_ints()
    w = fs.read_ints()

    ts = TreeSegment(n, 0, magic, apply_mod, merge_mods, 1337)
    ts.init(w)

    subw = [0] * n
    for i in range(n):
        subw[i] = (w[i] * (i - pos[i])) % MOD

    resp = TreeSegment(n, 0, magic, apply_mod, merge_mods, 1337)
    resp.init(subw)

    for _ in range(q):
        x, y = fs.read_ints()
        if x < 0:
            ind = -x
            _new = y
            ind -= 1
            ts.update(ind, ind + 1, _new)
            resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD)
        else:
            l, r = x, y
            l -= 1

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
