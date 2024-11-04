class TreeSegment:
    def __init__(self, n, default, magic, apply_mod, merge_mods, mod):
        self.n = n
        self.S = [self.Node() for _ in range(2 * n + 1)]
        self.magic = magic
        self.apply_mod = apply_mod
        self.merge_mods = merge_mods
        self.init([default] * n)
    
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
    
    def query(self, ql, qr):
        assert ql < qr
        return __query(0, 0, n, ql, qr)
    
    def change(self, i, value):
        assert 0 <= i < n
        __change(0, 0, n, i, value)
    
    def update(self, ql, qr, mod):
        __update(0, 0, n, ql, qr, mod)
    
    def find_right(self, L, checker, start):
        if checker(start):
            return L - 1
        rez = __find_right(0, 0, n, L, checker, start)[0]
        return n if rez == -1 else rez
    
    def find_left(self, R, checker, start):
        if checker(start):
            return R + 1
        rez = __find_left(0, 0, n, R, checker, start)[0]
        return -1 if rez == -1 else rez
    
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
        self.init(0, 0, len(src), src)

def floor_mod(a, b):
    if a % b == 0:
        return 0
    if a >= 0 and b >= 0:
        return a % b
    if a <= 0 and b <= 0:
        return a % b
    return abs(b) - (abs(a) % abs(b))

class SmartIO:
    def __init__(self):
        self.print_start = ""
        self.sep = " "
        self.first_print = False
    
    def precall_print(self):
        print(self.print_start, end="")
        self.print_start = "\n"
        self.first_print = True
    
    def _print(self, names, *args):
        if not self.first_print:
            print("\n", end="")
        else:
            self.first_print = False
        print(names[0], end=" = ")
        print(args[0], end="")
        names.pop(0)
        self._print(names, *args[1:])
    
    def __call__(self, *args):
        self._print(list(args), *args)

def fast_scan(x):
    x[0] = int(input())

def fast_print(x):
    print(x[0], end="")

def fast_print_string(x):
    print(x[0], end="")

def fast_print_char(x):
    print(x[0], end="")

def fast_print_list(x):
    print(*x, end="")

def fast_print_list_list(x):
    for i in range(len(x)):
        print(*x[i], sep=" ")
        if i != len(x) - 1:
            print()

def fast_print_tuple(x):
    print(*x, sep=" ", end="")

def fast_print_dict(x):
    for key, value in x.items():
        print(key, value, sep=" ", end="")

def fast_print_set(x):
    print(*x, sep=" ", end="")

def fast_print_bool(x):
    print(x[0], end="")

def fast_print_float(x):
    print(x[0], end="")

def fast_print_complex(x):
    print(x[0], end="")

def fast_print_none(x):
    print(x[0], end="")

def fast_print_bytes(x):
    print(x[0], end="")

def fast_print_bytearray(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_range(x):
    print(*x, end="")

def fast_print_frozenset(x):
    print(*x, sep=" ", end="")

def fast_print_type(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
    print(x[0], end="")

def fast_print_module(x):
    print(x[0], end="")

def fast_print_function(x):
    print(x[0], end="")

def fast_print_method(x):
    print(x[0], end="")

def fast_print_class(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_exception(x):
    print(x[0], end="")

def fast_print_file(x):
    print(x[0], end="")

def fast_print_code(x):
    print(x[0], end="")

def fast_print_frame(x):
    print(x[0], end="")

def fast_print_traceback(x):
    print(x[0], end="")

def fast_print_slice(x):
    print(x[0], end="")

def fast_print_staticmethod(x):
    print(x[0], end="")

def fast_print_classmethod(x):
    print(x[0], end="")

def fast_print_property(x):
    print(x[0], end="")

def fast_print_memoryview(x):
