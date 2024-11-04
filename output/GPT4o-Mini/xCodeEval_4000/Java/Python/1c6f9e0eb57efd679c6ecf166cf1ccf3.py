import sys
from collections import deque

class F2:
    mod = 998244353
    m2 = mod * mod
    BIG = 8 * m2

    def solve(self):
        n, m = self.ni(), self.ni()
        ss = [self.ns().strip() for _ in range(n)]
        oss = [s for s in ss]
        offset = [0] * (n + 1)
        offset[0] = 1
        for i in range(n):
            offset[i + 1] = offset[i] + len(ss[i]) - 1
        U = offset[n] - 1

        D = 5
        M = [[0] * ((U + 1) * D) for _ in range((U + 1) * D)]

        for i in range(U + 1):
            lb, of = (0, 0) if i == 0 else (self.lower_bound(offset, i + 1) - 1, i - offset[lb] + 1)

            if i == 0:
                for j in range(n):
                    for k in range(n):
                        if k != j and oss[k].startswith(oss[j]):
                            M[offset[k] + len(ss[j]) - 1][0 + (U + 1) * (len(ss[j]) - 1)] = 1
                    M[0][0 + (U + 1) * (len(ss[j]) - 1)] += 1
            else:
                for j in range(n):
                    if oss[lb][of:] == oss[j]:
                        M[0][i + (U + 1) * (len(oss[j]) - 1)] += 2
                    elif oss[lb][of:].startswith(oss[j]):
                        M[i + len(oss[j])][i + (U + 1) * (len(oss[j]) - 1)] += 1

                suf = oss[lb][of:]
                for j in range(n):
                    if oss[j].startswith(suf) and oss[j] != suf:
                        M[offset[j] + len(suf) - 1][i + (U + 1) * (len(suf) - 1)] += 1

        for i in range(U + 1):
            for j in range(D - 1):
                M[i + (U + 1) * (j + 1)][i + (U + 1) * j] = 1

        v = [0] * ((U + 1) * D)
        v[0] = 1
        v = self.pow(M, v, m)

        print(v[0])

    def pow(self, A, v, e):
        for i in range(len(v)):
            if v[i] >= self.mod:
                v[i] %= self.mod
        MUL = A
        while e > 0:
            if e & 1:
                v = self.mul(MUL, v)
            MUL = self.p2(MUL)
            e >>= 1
        return v

    def mul(self, A, v):
        m = len(A)
        n = len(v)
        w = [0] * m
        for i in range(m):
            sum_ = 0
            for k in range(n):
                sum_ += A[i][k] * v[k]
                if sum_ >= self.BIG:
                    sum_ -= self.BIG
            w[i] = sum_ % self.mod
        return w

    def p2(self, A):
        n = len(A)
        C = [[0] * n for _ in range(n)]
        for i in range(n):
            sum_ = [0] * n
            for k in range(n):
                for j in range(n):
                    sum_[j] += A[i][k] * A[k][j]
                    if sum_[j] >= self.BIG:
                        sum_[j] -= self.BIG
            for j in range(n):
                C[i][j] = sum_[j] % self.mod
        return C

    def lower_bound(self, a, v):
        return self.lower_bound_helper(a, 0, len(a), v)

    def lower_bound_helper(self, a, l, r, v):
        if l > r or l < 0 or r > len(a):
            raise ValueError("Invalid bounds")
        low, high = l - 1, r
        while high - low > 1:
            h = (high + low) // 2
            if a[h] >= v:
                high = h
            else:
                low = h
        return high

    def run(self):
        self.is_oj = 'ONLINE_JUDGE' in sys.argv
        input_data = sys.stdin.read().splitlines() if not self.is_oj else []
        self.input_iter = iter(input_data)
        self.solve()

    def ni(self):
        return int(next(self.input_iter))

    def ns(self):
        return next(self.input_iter)

if __name__ == "__main__":
    F2().run()
