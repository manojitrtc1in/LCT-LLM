class Permutation(list):
    def __init__(self, size):
        super().__init__(range(size))

    def multiply(self, rhs):
        res = Permutation(len(self))
        for i in range(len(self)):
            res[i] = self[rhs[i]]
        return res

    def __mul__(self, rhs):
        return self.multiply(rhs)

    def __imul__(self, rhs):
        res = self.multiply(rhs)
        self[:] = res
        return self

    def pow(self, deg):
        result = Permutation(len(self))
        a = self
        b = deg
        while b > 0:
            if b & 1:
                result *= a
            a *= a
            b >>= 1
        return result

    def next(self):
        return next_permutation(self)

def check(a):
    n = len(a)
    b = [0] * n
    log = ""

    def merge(l, r):
        nonlocal a, b, log
        if r - l <= 1:
            return
        m = (l + r) // 2
        merge(l, m)
        merge(m, r)
        i = l
        j = m
        k = l
        while i < m and j < r:
            if a[i] < a[j]:
                log += '0'
                b[k] = a[i]
                i += 1
            else:
                log += '1'
                b[k] = a[j]
                j += 1
            k += 1
        while i < m:
            b[k] = a[i]
            i += 1
            k += 1
        while j < r:
            b[k] = a[j]
            j += 1
            k += 1
        for p in range(l, r):
            a[p] = b[p]

    merge(0, n)
    return log

def try_recover(l, r, s, p):
    if r - l <= 1:
        return True
    mid = (l + r) // 2
    if not try_recover(l, mid, s, p) or not try_recover(mid, r, s, p):
        return False
    left = [p[i] for i in range(mid, l, -1)]
    right = [p[i] for i in range(r - 1, mid - 1, -1)]
    pos = l
    while left and right:
        if not s:
            return False
        ch = s[-1]
        s = s[:-1]
        if ch == '1':
            p[pos] = right.pop()
        else:
            p[pos] = left.pop()
        pos += 1
    while left:
        p[pos] = left.pop()
        pos += 1
    while right:
        p[pos] = right.pop()
        pos += 1
    return True

def solve():
    s = input().strip()[::-1]

    L = 1
    R = 1111
    while R - L > 1:
        len = (L + R) // 2
        p = Permutation(len)
        tmp = s
        recovered = try_recover(0, len, tmp, p)
        if recovered:
            if not tmp:
                ans = [0] * len
                for i in range(len):
                    ans[p[i]] = i
                print(len)
                print(" ".join(str(x + 1) for x in ans))
                return
            L = len
        else:
            R = len

solve()
