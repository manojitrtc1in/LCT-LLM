from collections import defaultdict
from typing import List, Tuple, Any

MOD7 = 1000000007
MOD9 = 1000000009
MODF = 998244353
mod = MOD7

def gcd(a: int, b: int) -> Tuple[int, int, int]:
    if a == 0:
        return b, 0, 1
    d, x, y = gcd(b % a, a)
    x -= (b // a) * y
    return d, x, y

class ModInt:
    def __init__(self, n: int):
        if n >= 0 and n < mod:
            self.n = n
            return
        n %= mod
        if n < 0:
            n += mod
        self.n = n

    def __add__(self, other):
        return ModInt(self.n + other.n)

    def __sub__(self, other):
        return ModInt(self.n - other.n)

    def __mul__(self, other):
        return ModInt(self.n * other.n % mod)

    def __truediv__(self, other):
        if other.n == 0:
            raise ValueError("Division by zero")
        return self * other.inverse()

    def inverse(self):
        x, y, g = gcd(self.n, mod)
        if g != 1:
            raise ValueError("not inversable")
        return ModInt(x)

    def __repr__(self):
        return str(self.n)

class TaskD:
    def solve(self, inp: Any, outp: Any):
        n = int(inp.readline().strip())
        x = list(map(int, inp.readline().strip().split()))
        v = list(map(int, inp.readline().strip().split()))
        p = list(map(int, inp.readline().strip().split()))
        
        global mod
        mod = MODF
        
        pp = [None] * (4 * n)
        tmp = [None] * (4 * n)
        allowed = [[True] * 4 for _ in range(n)]

        def join(left, right):
            result = [ModInt(0)] * 4
            for i in range(2):
                for j in range(2):
                    for k in range(2):
                        for l in range(2):
                            if allowed[at][2 * j + k]:
                                result[i * 2 + l] += left[i * 2 + j] * right[k * 2 + l]
            return result

        def init(root, left, right):
            pp[root] = [ModInt(0)] * 4
            tmp[root] = [ModInt(0)] * 4
            if left + 1 == right:
                pp[root][0] = ModInt(100 - p[left]) / 100
                pp[root][3] = ModInt(1) - pp[root][0]
            else:
                mid = (left + right) // 2
                init(2 * root + 1, left, mid)
                init(2 * root + 2, mid, right)
                pp[root] = join(pp[2 * root + 1], pp[2 * root + 2])

        init(0, 0, n)

        class Event:
            def __init__(self, type, at, dx, v):
                self.type = type
                self.at = at
                self.dx = dx
                self.v = v

            def __lt__(self, other):
                return self.dx * other.v < other.dx * self.v

        events = []
        for i in range(1, n):
            events.append(Event(2, i, x[i] - x[i - 1], v[i] + v[i - 1]))
            if v[i] > v[i - 1]:
                events.append(Event(0, i, x[i] - x[i - 1], v[i] - v[i - 1]))
            elif v[i] < v[i - 1]:
                events.append(Event(3, i, x[i] - x[i - 1], v[i - 1] - v[i]))

        events.sort()

        def query(root, left, right, from_, to):
            if left >= to or right <= from_:
                return False
            if left >= from_ and right <= to:
                tmp[root] = pp[root][:]
                return True
            mid = (left + right) // 2
            l_res = query(2 * root + 1, left, mid, from_, to)
            r_res = query(2 * root + 2, mid, right, from_, to)
            if not l_res:
                tmp[root] = tmp[2 * root + 2][:]
                return True
            if not r_res:
                tmp[root] = tmp[2 * root + 1][:]
                return True
            tmp[root] = join(tmp[2 * root + 1], tmp[2 * root + 2])
            return True

        def recalc(root, left, right, at):
            if left >= at or right <= at:
                return
            mid = (left + right) // 2
            recalc(2 * root + 1, left, mid, at)
            recalc(2 * root + 2, mid, right, at)
            pp[root] = join(pp[2 * root + 1], pp[2 * root + 2])

        answer = ModInt(0)
        for e in events:
            query(0, 0, n, 0, e.at)
            left = tmp[0][e.type // 2] + tmp[0][2 + e.type // 2]
            query(0, 0, n, e.at, n)
            right = tmp[0][e.type % 2 * 2] + tmp[0][e.type % 2 * 2 + 1]
            answer += ModInt(e.dx) / e.v * left * right
            allowed[e.at][e.type] = False
            recalc(0, 0, n, e.at)

        outp.write(f"{answer}\n")

if __name__ == "__main__":
    import sys
    task = TaskD()
    task.solve(sys.stdin, sys.stdout)