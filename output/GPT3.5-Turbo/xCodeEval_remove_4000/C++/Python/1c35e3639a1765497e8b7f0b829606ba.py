import math

class ModInt:
    def __init__(self, v):
        self.mod = 998244353
        self.v = v % self.mod

    def __add__(self, other):
        return ModInt(self.v + other.v)

    def __sub__(self, other):
        return ModInt(self.v - other.v)

    def __mul__(self, other):
        return ModInt(self.v * other.v)

    def __pow__(self, p):
        if p == 0:
            return ModInt(1)
        elif p % 2 == 0:
            half = self.__pow__(p // 2)
            return half * half
        else:
            return self * self.__pow__(p - 1)

    def __str__(self):
        return str(self.v)

class Poly:
    def __init__(self, v):
        self.v = v

    def __add__(self, other):
        n = max(len(self.v), len(other.v))
        ret = [0] * n
        for i in range(n):
            ret[i] = self.v[i] + other.v[i]
        return Poly(ret)

    def __sub__(self, other):
        n = max(len(self.v), len(other.v))
        ret = [0] * n
        for i in range(n):
            ret[i] = self.v[i] - other.v[i]
        return Poly(ret)

    def __mul__(self, other):
        if len(self.v) == 0 or len(other.v) == 0:
            return Poly([])
        return self.mul_fft(other)

    def __str__(self):
        ret = ""
        for i in range(len(self.v)):
            if self.v[i] != 0:
                ret += str(self.v[i]) + "x^" + str(i)
                if i != len(self.v) - 1:
                    ret += " + "
        return ret

    def mul_fft(self, other):
        ret = multiply_fft(self.v, other.v)
        return Poly(ret)

def multiply_fft(x, y):
    s = max(len(x), len(y))
    N = 1 << (s - 1).bit_length()
    a = [0] * N
    b = [0] * N
    for i in range(len(x)):
        a[i] = complex(x[i], 0)
    for i in range(len(y)):
        b[i] = complex(y[i], 0)
    fft(False, a)
    fft(False, b)
    c = [0] * N
    for xt in range(2):
        for y in range(0, N, 2):
            now = complex(1, 0) if xt == 0 else complex(1, 0).conjugate()
            for x in range(N // 2):
                l = a[y << 1 | x]
                r = now * a[y << 1 | x | N]
                c[y | x] = l + r
                c[y | x | N >> 1] = l - r
    fft(True, c)
    ret = []
    for i in range(len(c)):
        ret.append(ModInt(round(c[i].real())))
    return ret

def fft(type, c):
    buf = [[] for _ in range(30)]
    N = len(c)
    s = (N - 1).bit_length()
    assert 1 << s == N
    if len(buf[s]) == 0:
        buf[s] = [0] * N
        for i in range(N):
            buf[s][i] = complex(1, i * 2 * math.pi / N)
    a = [0] * N
    b = [0] * N
    a = c.copy()
    for i in range(1, s + 1):
        W = 1 << (s - i)
        for y in range(0, N, 2 * W):
            now = buf[s][y]
            if type:
                now = now.conjugate()
            for x in range(W):
                l = a[y << 1 | x]
                r = now * a[y << 1 | x | W]
                b[y | x] = l + r
                b[y | x | N >> 1] = l - r
        a, b = b, a.copy()
    c = a.copy()

def id4(x, y):
    B = 15
    S = len(x) + len(y) - 1
    N = 2 << (len(bin(S - 1)) - 2)
    a = [[0] * N for _ in range(2)]
    b = [[0] * N for _ in range(2)]
    for t in range(2):
        for i in range(len(x)):
            a[t][i] = complex((x[i].v >> (t * B)) & ((1 << B) - 1), 0)
        for i in range(len(y)):
            b[t][i] = complex((y[i].v >> (t * B)) & ((1 << B) - 1), 0)
        fft(False, a[t])
        fft(False, b[t])
    z = [0] * S
    c = [0] * N
    base = ModInt(1)
    for t in range(3):
        c = [0] * N
        for xt in range(max(t - 1, 0), min(1, t) + 1):
            yt = t - xt
            for i in range(N):
                c[i] += a[xt][i] * b[yt][i]
        fft(True, c)
        for i in range(S):
            c[i] *= 1.0 / N
            z[i] += ModInt(round(c[i].real())) * base
        base *= 1 << B
    return z

def id3(terms, deg, ord = -1, verify = True):
    if ord != -1:
        n = (deg + 1) * (ord + 1) + ord - 1
        while len(terms) > n:
            terms.pop()
    n = len(terms)
    B = (n + 2) // (deg + 2)
    C = B * (deg + 1)
    R = n - (B - 1)
    assert B >= 2
    assert R >= C - 1
    mat = [[0] * C for _ in range(R)]
    for y in range(R):
        for b in range(B):
            v = terms[y + b]
            for d in range(deg + 1):
                mat[y][b * (deg + 1) + d] = v
                v *= y + b
    rank = 0
    for x in range(C):
        pivot = -1
        for y in range(rank, R):
            if mat[y][x] != 0:
                pivot = y
                break
        if pivot < 0:
            break
        if pivot != rank:
            mat[rank], mat[pivot] = mat[pivot], mat[rank]
        inv = ModInt(1) / mat[rank][x]
        for x2 in range(x, C):
            mat[rank][x2] *= inv
        for y in range(rank + 1, R):
            if mat[y][x] != 0:
                c = -mat[y][x]
                for x2 in range(x, C):
                    mat[y][x2] += c * mat[rank][x2]
        rank += 1
    if rank == C:
        error(B - 1, deg)
    for y in range(rank - 1, -1, -1):
        if mat[y][rank] != 0:
            assert mat[y][y] == 1
            c = -mat[y][rank]
            for y2 in range(y):
                mat[y2][rank] += c * mat[y2][y]
    order = rank // (deg + 1)
    ret = [[0] * (deg + 1) for _ in range(order + 1)]
    ret[0][rank % (deg + 1)] = 1
    for y in range(rank - 1, -1, -1):
        k = order - y // (deg + 1)
        d = y % (deg + 1)
        ret[k][d] = -mat[y][rank]
    if verify:
        extended_terms = extended(n - 1, ret, terms[:order])
        for i in range(len(terms)):
            if terms[i] != extended_terms[i]:
                error(B - 1, deg)
    verbose = lambda: None
    def verbose():
        last = n - 1 if verify else order + R - 1
        print("[ Found a recurrence relation ]")
        print("- order", order)
        print("- degree", deg)
        print("- verified up to a(", last, ") (number of non-trivial terms:", (last + 1) - ((deg + 2) * (order + 1) - 2), ")")
        print("{")
        for k in range(order + 1):
            print("  {", end="")
            for d in range(deg + 1):
                if d:
                    print(", ", end="")
                print(ret[k][d].v, end="")
            print("}", end="")
            if k == order:
                print()
            else:
                print(",")
        print("}\n")
    verbose()
    return ret

def extended(n, coeffs, terms):
    ret = [0] * max(n + 1, len(terms))
    ret[:len(terms)] = terms
    order = len(coeffs) - 1
    deg = len(coeffs[0]) - 1
    assert len(terms) >= order
    for m in range(len(terms), n + 1):
        s = 0
        for i in range(1, order + 1):
            k = m - i
            t = ret[k]
            for d in range(deg + 1):
                s += t * coeffs[i][d]
                t *= k
        denom = 0
        mpow = 1
        for d in range(deg + 1):
            denom += mpow * coeffs[0][d]
            mpow *= m
        ret[m] = -s / denom
    return ret

def id1(n, terms, degree, order = -1):
    coeffs = id3(terms, degree, order)
    extended_terms = extended(n - 1, coeffs, terms[:order])
    for i in range(len(extended_terms)):
        print(i, extended_terms[i].v)
    print()

def id2(n, terms, degree, order = -1):
    coeffs = id3(terms, degree, order)
    return extended(n, coeffs, terms)

def solve(N):
    res = ModInt(0)
    for i in range(N + 1):
        if i == 0:
            for j in range(1, N + 1):
                res += (-1) ** (i + j) * Choose(N, j) * ModInt(3) ** (j + N * (N - j))
        else:
            res += (-1) ** i * Choose(N, i) * ((ModInt(3) ** (N - i) - 1) ** N - ModInt(3) ** ((N - i) * N)) * ModInt(3)
            res += (-1) ** i * Choose(N, i) * ModInt(3) ** (i + N * (N - i))
    return -res

N = int(input())
print(solve(N))
