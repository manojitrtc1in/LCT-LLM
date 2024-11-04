class modint:
    def __init__(self, val):
        self.val = val % self.get_mod()
    
    def __lt__(self, other):
        return self.val < other.val
    
    def __iadd__(self, other):
        self.val = (self.val + other.val) % self.get_mod()
        return self
    
    def __isub__(self, other):
        self.val = (self.val - other.val + self.get_mod()) % self.get_mod()
        return self
    
    def __imul__(self, other):
        self.val = (self.val * other.val) % self.get_mod()
        return self
    
    def __idiv__(self, other):
        self.val = (self.val * other.inverse().val) % self.get_mod()
        return self
    
    def __neg__(self):
        return modint(self.get_mod() - self.val)
    
    def __add__(self, other):
        return modint(self.val + other.val)
    
    def __sub__(self, other):
        return modint(self.val - other.val)
    
    def __mul__(self, other):
        return modint(self.val * other.val)
    
    def __div__(self, other):
        return modint(self.val * other.inverse().val)
    
    def __eq__(self, other):
        return self.val == other.val
    
    def __ne__(self, other):
        return self.val != other.val
    
    def inverse(self):
        a = self.val
        b = self.get_mod()
        u = 1
        v = 0
        while b > 0:
            t = a // b
            a, b = b, a - t * b
            u, v = v, u - t * v
        return modint(u)
    
    def pow(self, n):
        ret = modint(1)
        mul = modint(self.val)
        while n > 0:
            if n & 1:
                ret *= mul
            mul *= mul
            n >>= 1
        return ret
    
    @staticmethod
    def get_mod():
        return 1000000007


class id4:
    def __init__(self, val):
        self.val = val % self.get_mod()
    
    def __lt__(self, other):
        return self.val < other.val
    
    @staticmethod
    def get_mod():
        return id4.mod
    
    @staticmethod
    def set_mod(md):
        id4.mod = md
    
    def __iadd__(self, other):
        self.val = (self.val + other.val) % self.get_mod()
        return self
    
    def __isub__(self, other):
        self.val = (self.val - other.val + self.get_mod()) % self.get_mod()
        return self
    
    def __imul__(self, other):
        a = self.val
        b = other.val
        xh = a >> 32
        xl = a & 0xffffffff
        d, m = divmod(xh * b, self.get_mod())
        d, m = divmod(d << 32, self.get_mod())
        d, m = divmod(d << 32, self.get_mod())
        self.val = m
        return self
    
    def __idiv__(self, other):
        self *= other.inverse()
        return self
    
    def __neg__(self):
        return id4(self.get_mod() - self.val)
    
    def __add__(self, other):
        return id4(self.val + other.val)
    
    def __sub__(self, other):
        return id4(self.val - other.val)
    
    def __mul__(self, other):
        return id4(self.val * other.val)
    
    def __div__(self, other):
        return id4(self.val * other.inverse().val)
    
    def __eq__(self, other):
        return self.val == other.val
    
    def __ne__(self, other):
        return self.val != other.val
    
    def inverse(self):
        a = self.val
        b = self.get_mod()
        u = 1
        v = 0
        while b > 0:
            t = a // b
            a, b = b, a - t * b
            u, v = v, u - t * v
        return id4(u)
    
    def pow(self, n):
        ret = id4(1)
        mul = id4(self.val)
        while n > 0:
            if n & 1:
                ret *= mul
            mul *= mul
            n >>= 1
        return ret


class Scanner:
    def __init__(self, fp):
        self.fp = fp
        self.line = bytearray((1 << 15) + 1)
        self.st = 0
        self.ed = 0
    
    def reread(self):
        self.line[:self.ed - self.st] = self.line[self.st:self.ed]
        self.ed -= self.st
        self.st = 0
        self.ed += self.fp.readinto(self.line[self.ed:])
        self.line[self.ed] = 0
    
    def succ(self):
        while True:
            if self.st == self.ed:
                self.reread()
                if self.st == self.ed:
                    return False
            while self.st != self.ed and self.line[self.st].isspace():
                self.st += 1
            if self.st != self.ed:
                break
        if self.ed - self.st <= 50:
            sep = False
            for i in range(self.st, self.ed):
                if self.line[i].isspace():
                    sep = True
                    break
            if not sep:
                self.reread()
        return True
    
    def read_single(self, ref):
        if not self.succ():
            return False
        while True:
            sz = 0
            while self.st + sz < self.ed and not self.line[self.st + sz].isspace():
                sz += 1
            ref.extend(self.line[self.st:self.st + sz])
            self.st += sz
            if not sz or self.st != self.ed:
                break
            self.reread()
        return True
    
    def read(self, *args):
        for ref in args:
            if not self.read_single(ref):
                return


class Printer:
    def __init__(self, fp):
        self.fp = fp
        self.line = bytearray(Printer.SIZE)
        self.pos = 0
    
    def flush(self):
        self.fp.write(self.line[:self.pos])
        self.pos = 0
    
    def write(self, val):
        if self.pos == Printer.SIZE:
            self.flush()
        self.line[self.pos] = val
        self.pos += 1
    
    def __del__(self):
        self.flush()
    
    def write_str(self, s):
        for c in s:
            self.write(ord(c))
    
    def write_int(self, val):
        if val == 0:
            self.write(ord('0'))
            return
        if val < 0:
            self.write(ord('-'))
            val = -val
        s = []
        while val:
            s.append(chr(ord('0') + val % 10))
            val //= 10
        for c in reversed(s):
            self.write(ord(c))
    
    def write_float(self, val):
        s = format(val, '.15f')
        self.write_str(s)
    
    def write(self, val):
        if isinstance(val, str):
            self.write_str(val)
        elif isinstance(val, int):
            self.write_int(val)
        elif isinstance(val, float):
            self.write_float(val)
        elif isinstance(val, modint):
            self.write_int(val.val)
        elif isinstance(val, id4):
            self.write_int(val.val)
        elif isinstance(val, list):
            for i, v in enumerate(val):
                if i > 0:
                    self.write(ord(' '))
                self.write(v)
        elif isinstance(val, tuple):
            for i, v in enumerate(val):
                if i > 0:
                    self.write(ord(' '))
                self.write(v)
        elif isinstance(val, dict):
            for i, (k, v) in enumerate(val.items()):
                if i > 0:
                    self.write(ord(' '))
                self.write(k)
                self.write(ord(' '))
                self.write(v)
        else:
            raise ValueError(f"Unsupported type: {type(val)}")
    
    def writeln(self, *args):
        self.write(*args)
        self.write(ord('\n'))


def YES(t=True):
    if t:
        print("YES")
    else:
        print("NO")


def NO(t=True):
    YES(not t)


def Yes(t=True):
    if t:
        print("Yes")
    else:
        print("No")


def No(t=True):
    Yes(not t)


def yes(t=True):
    if t:
        print("yes")
    else:
        print("no")


def no(t=True):
    yes(not t)


class Group_Add:
    @staticmethod
    def op(x, y):
        return x + y
    
    @staticmethod
    def inverse(x):
        return -x
    
    @staticmethod
    def power(x, n):
        return n * x
    
    @staticmethod
    def unit():
        return 0
    
    commute = True


class id2:
    def __init__(self, n):
        self.n = n
        self.log = 1
        while (1 << self.log) < n:
            self.log += 1
        self.size = 1 << self.log
        self.laz = [Group_Add.unit()] * (self.size << 1)
    
    def reset(self):
        for i in range(len(self.laz)):
            self.laz[i] = Group_Add.unit()
    
    def all_apply(self, k, a):
        self.laz[k] = Group_Add.op(self.laz[k], a)
    
    def get(self, p):
        assert 0 <= p < self.n
        p += self.size
        for i in range(self.log, 0, -1):
            self.push(p >> i)
        return self.laz[p]
    
    def get_all(self):
        for i in range(self.size):
            self.push(i)
        return self.laz[self.size:self.size + self.n]
    
    def apply(self, l, r, a):
        assert 0 <= l <= r <= self.n
        if l == r:
            return
        l += self.size
        r += self.size
        if not Group_Add.commute:
            for i in range(self.log, 0, -1):
                if (l >> i) << i != l:
                    self.push(l >> i)
                if (r >> i) << i != r:
                    self.push((r - 1) >> i)
        l2 = l
        r2 = r
        while l < r:
            if l & 1:
                self.all_apply(l, a)
                l += 1
            if r & 1:
                r -= 1
                self.all_apply(r, a)
            l >>= 1
            r >>= 1
        l = l2
        r = r2
    
    def debug(self):
        print("dualsegtree getall:", self.get_all())
    
    def push(self, k):
        self.all_apply(2 * k, self.laz[k])
        self.all_apply(2 * k + 1, self.laz[k])
        self.laz[k] = Group_Add.unit()


def solve():
    N, mod = map(int, input().split())
    id4.set_mod(mod)
    seg = id2(Group_Add)
    dp = [0] * (N + 1)
    dp[1] = 1
    for n in range(1, N + 1):
        dp[n] += seg.get(n)
        seg.apply(n + 1, N + 1, dp[n])
        z = 2
        while True:
            l = n * z
            r = (n + 1) * z
            if l > N:
                break
            z += 1
            r = min(r, N + 1)
            seg.apply(l, r, dp[n])
    print(dp[-1])


T = 1
for _ in range(T):
    solve()
