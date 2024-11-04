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

    def __repr__(self):
        return str(self.v)

def choose(a, b):
    if b < 0 or a < b:
        return ModInt(0)
    return fact[a] * ifact[b] * ifact[a-b]

def init_fact(N):
    global fact, ifact
    fact = [ModInt(0)] * N
    ifact = [ModInt(0)] * N
    fact[0] = ModInt(1)
    for i in range(1, N):
        fact[i] = fact[i-1] * ModInt(i)
    ifact[N-1] = fact[N-1].__pow__(-1)
    for i in range(N-2, -1, -1):
        ifact[i] = ifact[i+1] * ModInt(i+1)

def berlekamp_massey(u):
    N = len(u)
    b = [-1]
    c = [-1]
    y = ModInt(1)
    for n in range(1, N+1):
        L = len(c)
        M = len(b)
        x = ModInt(0)
        for i in range(L):
            x += c[i] * u[n-L+i]
        b.append(0)
        M += 1
        if x == 0:
            continue
        coef = x / y
        if L < M:
            tmp = c
            c = [0] * (M-L) + c
            for i in range(M):
                c[M-1-i] -= coef * b[M-1-i]
            b = tmp
            y = x
        else:
            for i in range(M):
                c[L-1-i] -= coef * b[M-1-i]
    return c

def multiply_fft(x, y):
    N = len(x) + len(y) - 1
    s = math.ceil(math.log2(N))
    assert 2**s == N
    buf = [0] * s
    a = [0] * N
    b = [0] * N
    for t in range(2):
        a[t] = [0] * N
        b[t] = [0] * N
        for i in range(len(x)):
            a[t][i] = complex(x[i].v >> (t*15) & ((1<<15)-1), 0)
        for i in range(len(y)):
            b[t][i] = complex(y[i].v >> (t*15) & ((1<<15)-1), 0)
        fft(False, a[t])
        fft(False, b[t])
    z = [0] * N
    c = [0] * N
    base = ModInt(1)
    for t in range(3):
        c = [0] * N
        for xt in range(max(t-1, 0), min(1, t)+1):
            yt = t - xt
            for i in range(N):
                c[i] += a[xt][i] * b[yt][i]
        fft(True, c)
        for i in range(N):
            c[i] *= 1/N
            z[i] += ModInt(round(c[i].real())) * base
        base *= 1<<15
    return z

def multiply_fft2(x, y):
    return multiply_fft(x, y)

class Poly:
    def __init__(self, v):
        self.v = v

    def size(self):
        return len(self.v)

    def at(self, i):
        if i < self.size():
            return self.v[i]
        else:
            return 0

    def set(self, i, x):
        if i >= self.size() and x == 0:
            return
        while i >= self.size():
            self.v.append(0)
        self.v[i] = x
        self.shrink()

    def shrink(self):
        while self.v and self.v[-1] == 0:
            self.v.pop()

    def __add__(self, other):
        N = max(self.size(), other.size())
        ret = [0] * N
        for i in range(N):
            ret[i] = self.at(i) + other.at(i)
        return Poly(ret)

    def __sub__(self, other):
        N = max(self.size(), other.size())
        ret = [0] * N
        for i in range(N):
            ret[i] = self.at(i) - other.at(i)
        return Poly(ret)

    def __neg__(self):
        N = self.size()
        ret = [0] * N
        for i in range(N):
            ret[i] = -self.at(i)
        return Poly(ret)

    def __mul__(self, other):
        if self.size() == 0 or other.size() == 0:
            return Poly([])
        return self.mul_fft(other)

    def __rmul__(self, other):
        N = self.size()
        ret = [0] * N
        for i in range(N):
            ret[i] = self.v[i] * other
        return Poly(ret)

    def __truediv__(self, other):
        return self.div_fast(other)

    def __mod__(self, other):
        return self.rem_fast(other)

    def __lshift__(self, n):
        N = self.size()
        ret = [0] * (N + n)
        for i in range(N):
            ret[i+n] = self.v[i]
        return Poly(ret)

    def __rshift__(self, n):
        N = self.size()
        if N <= n:
            return Poly([])
        ret = [0] * (N - n)
        for i in range(N-n):
            ret[i] = self.v[i+n]
        return Poly(ret)

    def __eq__(self, other):
        return self.v == other.v

    def __ne__(self, other):
        return self.v != other.v

    def __iadd__(self, other):
        return self.__add__(other)

    def __isub__(self, other):
        return self.__sub__(other)

    def __imul__(self, other):
        return self.__mul__(other)

    def __itruediv__(self, other):
        return self.__truediv__(other)

    def __ilshift__(self, n):
        return self.__lshift__(n)

    def __irshift__(self, n):
        return self.__rshift__(n)

    def mul_naive(self, other):
        N = self.size()
        M = other.size()
        ret = [0] * (N + M - 1)
        for i in range(N):
            for j in range(M):
                ret[i+j] += self.at(i) * other.at(j)
        return Poly(ret)

    def mul_ntt(self, other):
        return Poly(multiply_ntt(self.v, other.v))

    def mul_fft(self, other):
        ret = multiply_fft(self.v, other.v)
        return Poly(ret)

    def div_fast_with_inv(self, inv, B):
        return (self * inv) >> (B-1)

    def div_fast(self, y):
        if self.size() < y.size():
            return Poly([])
        n = self.size()
        return self.div_fast_with_inv(y.inv(n), n)

    def rem_naive(self, y):
        x = Poly(self.v)
        while y.size() <= x.size():
            N = x.size()
            M = y.size()
            coef = x.v[N-1] / y.v[M-1]
            x -= (y << (N-M)) * coef
        return x

    def rem_fast(self, y):
        return self - y * self.div_fast(y)

    def strip(self, n):
        res = self.v
        res = res[:min(n, len(res))]
        return Poly(res)

    def rev(self, n=-1):
        res = self.v
        if n != -1:
            res = res[:n]
        res = res[::-1]
        return Poly(res)

    def inv(self, n):
        N = self.size()
        assert N >= 1
        assert n >= N-1
        coef = ModInt(1) / self.at(N-1)
        a = self.rev()
        g = Poly([coef])
        for i in range(1, 2*N-2, 2):
            g *= (Poly([2]) - a*g).strip(2**i)
        return g.rev(n+1-N)

    def __str__(self):
        if self.size() == 0:
            return "0"
        ret = ""
        for i in range(self.size()):
            if self.v[i] != 0:
                ret += str(self.v[i]) + "x^" + str(i)
                if i != self.size()-1:
                    ret += " + "
        return ret

def fft(type, c):
    buf = [0] * 30
    N = len(c)
    s = N.bit_length() - 1
    assert 1 << s == N
    if len(buf[s]) == 0:
        buf[s] = [0] * N
        for i in range(N):
            buf[s][i] = complex(1, i*2*math.pi/N)
    a = [0] * N
    b = [0] * N
    a[::] = c
    for i in range(1, s+1):
        W = 1 << (s-i)
        for y in range(0, N, 2*W):
            now = buf[s][y]
            if type:
                now = now.conjugate()
            for x in range(W):
                l = a[y << 1 | x]
                r = now * a[y << 1 | x | W]
                b[y | x] = l + r
                b[y | x | N >> 1] = l - r
        a, b = b, a
    c[::] = a

def multiply_fft(x, y):
    return multiply_fft2(x, y)

def find_recurrence_relation(terms, deg, ord=-1, verify=True):
    if ord != -1:
        n = (deg+1)*(ord+1)+ord-1
        while len(terms) > n:
            terms.pop()
    n = len(terms)
    B = (n + 2) // (deg + 2)
    C = B * (deg + 1)
    R = n - (B - 1)
    assert B >= 2
    assert R >= C - 1
    error = lambda order, deg: print(f"Error: Could not find a recurrence relation of order <= {order} and degree <= {deg}.\n\n")
    mat = [[0] * C for _ in range(R)]
    for y in range(R):
        for b in range(B):
            v = terms[y+b]
            for d in range(deg+1):
                mat[y][b*(deg+1)+d] = v
                v *= y+b
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
        inv = mat[rank][x].__pow__(-1)
        for x2 in range(x, C):
            mat[rank][x2] *= inv
        for y in range(rank+1, R):
            if mat[y][x] != 0:
                c = -mat[y][x]
                for x2 in range(x, C):
                    mat[y][x2] += c * mat[rank][x2]
        rank += 1
    if rank == C:
        error(B-1, deg)
    for y in range(rank-1, -1, -1):
        if mat[y][rank] != 0:
            assert mat[y][y] == 1
            c = -mat[y][rank]
            for y2 in range(y):
                mat[y2][rank] += c * mat[y2][y]
    order = rank // (deg + 1)
    ret = [[0] * (deg + 1) for _ in range(order + 1)]
    ret[0][rank % (deg + 1)] = 1
    for y in range(rank-1, -1, -1):
        k = order - y // (deg + 1)
        d = y % (deg + 1)
        ret[k][d] = -mat[y][rank]
    if verify:
        extended_terms = extended(n - 1, ret, terms[:order])
        for i in range(len(terms)):
            if terms[i] != extended_terms[i]:
                error(B-1, deg)
    verbose = lambda: print(f"[ Found a recurrence relation ]\n- order {order}\n- degree {deg}\n- verified up to a({n-1}) (number of non-trivial terms: {n - ((deg + 2) * (order + 1) - 2)})\n")
    verbose()
    return ret

def extended(n, coeffs, terms):
    ret = [0] * max(n + 1, len(terms))
    ret[:len(terms)] = terms
    order = len(coeffs) - 1
    deg = len(coeffs[0]) - 1
    assert len(terms) >= order
    for m in range(len(terms), n+1):
        s = 0
        for i in range(1, order+1):
            k = m - i
            t = ret[k]
            for d in range(deg+1):
                s += t * coeffs[i][d]
                t *= k
        denom = 0
        mpow = 1
        for d in range(deg+1):
            denom += mpow * coeffs[0][d]
            mpow *= m
        ret[m] = -s / denom
    return ret

def show_extended_sequence(n, terms, degree, order=-1):
    coeffs = find_recurrence_relation(terms, degree, order)
    extended_terms = extended(n, coeffs, terms)
    for i in range(len(extended_terms)):
        print(i, extended_terms[i])
    print()

def get_extended_sequence(n, terms, degree, order=-1):
    coeffs = find_recurrence_relation(terms, degree, order)
    return extended(n, coeffs, terms)

def solve(N):
    res = ModInt(0)
    for i in range(N+1):
        if i == 0:
            for j in range(1, N+1):
                res += (-1)**(i+j) * choose(N, j) * ModInt(3)**(j + N*(N-j))
        else:
            res += (-1)**i * choose(N, i) * ((ModInt(3)**(N-i) - 1)**N - ModInt(3)**((N-i)*N)) * ModInt(3)
            res += (-1)**i * choose(N, i) * ModInt(3)**(i + N*(N-i))
    return -res

N = int(input())
init_fact(2000010)
print(solve(N))
