class TreeSegment:
    def __init__(self, n, default, magic, apply_mod, merge_mods, mod):
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods
        self.S = []
        self.n = n
        
        def create_node():
            self.S.append({
                'have_mod': False,
                'l': -1,
                'r': -1,
                'value': default,
                'mod': mod
            })
            return len(self.S) - 1
        
        def get_value(i, tl, tr):
            if not self.S[i]['have_mod']:
                return self.S[i]['value']
            return apply_mod(self.S[i]['value'], self.S[i]['mod'], tl, tr)
        
        def recalc_value(i, tl, tr):
            if tl + 1 != tr:
                mid = (tl + tr) // 2
                self.S[i]['value'] = magic(
                    get_value(self.S[i]['l'], tl, mid),
                    get_value(self.S[i]['r'], mid, tr)
                )
        
        def add_mod(i, tl, tr, sub):
            if self.S[i]['have_mod']:
                self.S[i]['mod'] = merge_mods(self.S[i]['mod'], sub, tl, tr)
            else:
                self.S[i]['mod'] = sub
                self.S[i]['have_mod'] = True
        
        def push(i, tl, tr):
            if self.S[i]['have_mod']:
                self.S[i]['value'] = apply_mod(self.S[i]['value'], self.S[i]['mod'], tl, tr)
                if tl + 1 != tr:
                    mid = (tl + tr) // 2
                    add_mod(self.S[i]['l'], tl, mid, self.S[i]['mod'])
                    add_mod(self.S[i]['r'], mid, tr, self.S[i]['mod'])
                self.S[i]['have_mod'] = False
        
        def init(tl, tr, src):
            i = create_node()
            if tl + 1 == tr:
                self.S[i]['value'] = src[tl]
            else:
                mid = (tl + tr) // 2
                self.S[i]['l'] = init(tl, mid, src)
                self.S[i]['r'] = init(mid, tr, src)
                recalc_value(i, tl, tr)
            return i
        
        self.init(0, n, [default] * n)
    
    def query(self, ql, qr):
        def __query(i, tl, tr, ql, qr):
            push(i, tl, tr)
            if ql <= tl and tr <= qr:
                return self.S[i]['value']
            else:
                mid = (tl + tr) // 2
                if tl <= mid < tr:
                    return magic(
                        __query(self.S[i]['l'], tl, mid, ql, qr),
                        __query(self.S[i]['r'], mid, tr, ql, qr)
                    )
                elif tl <= mid:
                    return __query(self.S[i]['l'], tl, mid, ql, qr)
                elif mid < tr:
                    return __query(self.S[i]['r'], mid, tr, ql, qr)
                else:
                    assert False
        
        return __query(0, 0, self.n, ql, qr)
    
    def update(self, ql, qr, mod):
        def __update(i, tl, tr, ql, qr, mod):
            push(i, tl, tr)
            if ql <= tl and tr <= qr:
                add_mod(i, tl, tr, mod)
            else:
                mid = (tl + tr) // 2
                if tl <= mid < tr:
                    __update(self.S[i]['l'], tl, mid, ql, qr, mod)
                if tl <= mid:
                    __update(self.S[i]['r'], mid, tr, ql, qr, mod)
                recalc_value(i, tl, tr)
        
        __update(0, 0, self.n, ql, qr, mod)
    
    def find_right(self, L, checker, start):
        def __find_right(i, tl, tr, L, checker, pref):
            push(i, tl, tr)
            if tr <= L:
                return -1, pref
            if tl + 1 == tr:
                _this = magic(pref, get_value(i, tl, tr))
                if checker(_this):
                    return tl, _this
                else:
                    return -1, _this
            else:
                mid = (tl + tr) // 2
                if L <= tl:
                    _left = magic(pref, get_value(self.S[i]['l'], tl, mid))
                    if checker(_left):
                        return __find_right(self.S[i]['l'], tl, mid, L, checker, pref)
                    else:
                        return __find_right(self.S[i]['r'], mid, tr, L, checker, _left)
                else:
                    t = __find_right(self.S[i]['l'], tl, mid, L, checker, pref)
                    if t[0] != -1:
                        return t
                    return __find_right(self.S[i]['r'], mid, tr, L, checker, t[1])
        
        if checker(start):
            return L - 1
        rez = __find_right(0, 0, self.n, L, checker, start)[0]
        return self.n if rez == -1 else rez
    
    def find_left(self, R, checker, start):
        def __find_left(i, tl, tr, R, checker, pref):
            push(i, tl, tr)
            if R < tl:
                return -1, pref
            if tl + 1 == tr:
                _this = magic(pref, get_value(i, tl, tr))
                if checker(_this):
                    return tl, _this
                else:
                    return -1, _this
            else:
                mid = (tl + tr) // 2
                if tr <= R + 1:
                    _right = magic(pref, get_value(self.S[i]['r'], mid, tr))
                    if checker(_right):
                        return __find_left(self.S[i]['r'], mid, tr, R, checker, pref)
                    else:
                        return __find_left(self.S[i]['l'], tl, mid, R, checker, _right)
                else:
                    t = __find_left(self.S[i]['r'], mid, tr, R, checker, pref)
                    if t[0] != -1:
                        return t
                    return __find_left(self.S[i]['l'], tl, mid, R, checker, t[1])
        
        if checker(start):
            return R + 1
        rez = __find_left(0, 0, self.n, R, checker, start)[0]
        return -1 if rez == -1 else rez


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
    
    ts = TreeSegment(n, 0, lambda a, b: a + b, lambda value, mod, _, __: mod, lambda old, _new, _, __: _new, 1337)
    
    subw = [(w[i] * (i - pos[i])) % MOD for i in range(n)]
    
    resp = TreeSegment(n, 0, lambda a, b: (a + b) % MOD, lambda value, mod, _, __: mod, lambda old, _new, _, __: _new, 1337)
    
    for i in range(q):
        query = list(map(int, input().split()))
        if query[0] < 0:
            ind = -query[0] - 1
            _new = query[1]
            ts.update(ind, ind + 1, _new)
            resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD)
        else:
            l, r = query
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


if __name__ == '__main__':
    main()
