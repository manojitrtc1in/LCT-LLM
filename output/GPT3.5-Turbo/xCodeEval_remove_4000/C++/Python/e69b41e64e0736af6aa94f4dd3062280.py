class TreeSegment:
    def __init__(self, n, default, magic, apply_mod, merge_mods, mod):
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods
        self.S = []
        self.n = n
        self.init([default] * n)
    
    def __intersects(self, tl, tr, ql, qr):
        return not (tr <= ql or qr <= tl)
    
    def __create_node(self):
        self.S.append({'have_mod': False, 'l': -1, 'r': -1, 'value': None, 'mod': None})
        return len(self.S) - 1
    
    def __get_value(self, i, tl, tr):
        if not self.S[i]['have_mod']:
            return self.S[i]['value']
        return self.apply_mod(self.S[i]['value'], self.S[i]['mod'], tl, tr)
    
    def __recalc_value(self, i, tl, tr):
        if tl + 1 != tr:
            mid = (tl + tr) // 2
            self.S[i]['value'] = self.magic(
                self.__get_value(self.S[i]['l'], tl, mid),
                self.__get_value(self.S[i]['r'], mid, tr)
            )
    
    def __add_mod(self, i, tl, tr, sub):
        if self.S[i]['have_mod']:
            self.S[i]['mod'] = self.merge_mods(self.S[i]['mod'], sub, tl, tr)
        else:
            self.S[i]['mod'] = sub
            self.S[i]['have_mod'] = True
    
    def __push(self, i, tl, tr):
        if self.S[i]['have_mod']:
            self.S[i]['value'] = self.apply_mod(self.S[i]['value'], self.S[i]['mod'], tl, tr)
            if tl + 1 != tr:
                mid = (tl + tr) // 2
                self.__add_mod(self.S[i]['l'], tl, mid, self.S[i]['mod'])
                self.__add_mod(self.S[i]['r'], mid, tr, self.S[i]['mod'])
            self.S[i]['have_mod'] = False
    
    def init(self, tl, tr, src):
        i = self.__create_node()
        if tl + 1 == tr:
            self.S[i]['value'] = src[tl]
        else:
            mid = (tl + tr) // 2
            self.S[i]['l'] = self.init(tl, mid, src)
            self.S[i]['r'] = self.init(mid, tr, src)
            self.__recalc_value(i, tl, tr)
        return i
    
    def query(self, ql, qr):
        return self.__query(0, 0, self.n, ql, qr)
    
    def update(self, ql, qr, mod):
        self.__update(0, 0, self.n, ql, qr, mod)
    
    def find_right(self, L, checker, start):
        if checker(start):
            return L - 1
        rez = self.id0(0, 0, self.n, L, checker, start)[0]
        return self.n if rez == -1 else rez
    
    def find_left(self, R, checker, start):
        if checker(start):
            return R + 1
        rez = self.id3(0, 0, self.n, R, checker, start)[0]
        return -1 if rez == -1 else rez
    
    def __query(self, i, tl, tr, ql, qr):
        self.__push(i, tl, tr)
        if ql <= tl and tr <= qr:
            return self.S[i]['value']
        else:
            mid = (tl + tr) // 2
            if self.__intersects(tl, mid, ql, qr) and self.__intersects(mid, tr, ql, qr):
                return self.magic(
                    self.__query(self.S[i]['l'], tl, mid, ql, qr),
                    self.__query(self.S[i]['r'], mid, tr, ql, qr)
                )
            elif self.__intersects(tl, mid, ql, qr):
                return self.__query(self.S[i]['l'], tl, mid, ql, qr)
            elif self.__intersects(mid, tr, ql, qr):
                return self.__query(self.S[i]['r'], mid, tr, ql, qr)
            else:
                assert False
    
    def __update(self, i, tl, tr, ql, qr, mod):
        self.__push(i, tl, tr)
        if ql <= tl and tr <= qr:
            self.__add_mod(i, tl, tr, mod)
        else:
            mid = (tl + tr) // 2
            if self.__intersects(tl, mid, ql, qr):
                self.__update(self.S[i]['l'], tl, mid, ql, qr, mod)
            if self.__intersects(mid, tr, ql, qr):
                self.__update(self.S[i]['r'], mid, tr, ql, qr, mod)
            self.__recalc_value(i, tl, tr)
    
    def id0(self, i, tl, tr, L, checker, pref):
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
                _left = self.magic(pref, self.__get_value(self.S[i]['l'], tl, mid))
                if checker(_left):
                    return self.id0(self.S[i]['l'], tl, mid, L, checker, pref)
                else:
                    return self.id0(self.S[i]['r'], mid, tr, L, checker, _left)
            else:
                t = self.id0(self.S[i]['l'], tl, mid, L, checker, pref)
                if t[0] != -1:
                    return t
                return self.id0(self.S[i]['r'], mid, tr, L, checker, t[1])
    
    def id3(self, i, tl, tr, R, checker, pref):
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
                _right = self.magic(pref, self.__get_value(self.S[i]['r'], mid, tr))
                if checker(_right):
                    return self.id3(self.S[i]['r'], mid, tr, R, checker, pref)
                else:
                    return self.id3(self.S[i]['l'], tl, mid, R, checker, _right)
            else:
                t = self.id3(self.S[i]['r'], mid, tr, R, checker, pref)
                if t[0] != -1:
                    return t
                return self.id3(self.S[i]['l'], tl, mid, R, checker, t[1])
    
    def init(self, src):
        self.n = len(src)
        self.init(0, len(src), src)


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

    ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, tl, tr: mod, lambda old, _new, tl, tr: _new, 1337)
    resp = TreeSegment(n, 0, lambda a, b: (a + b) % MOD, lambda value, mod, tl, tr: mod, lambda old, _new, tl, tr: _new, 1337)

    subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]

    ts.init(subw)

    for _ in range(q):
        x, y = map(int, input().split())
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
