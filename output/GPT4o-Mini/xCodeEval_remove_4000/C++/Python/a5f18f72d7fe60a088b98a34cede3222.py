from collections import defaultdict
from itertools import islice
import sys
import math

class Vector(list):
    def __init__(self, n=None, value=None):
        if n is None:
            super().__init__()
        elif value is None:
            super().__init__([0] * n)
        else:
            super().__init__([value] * n)

    def __getitem__(self, ind):
        if ind >= len(self):
            raise IndexError("Out of bounds")
        return super().__getitem__(ind)

    def __setitem__(self, ind, value):
        if ind >= len(self):
            raise IndexError("Out of bounds")
        super().__setitem__(ind, value)

class Input:
    def __init__(self, inp):
        self.inp = inp

    def read_int(self):
        return int(self.inp.readline().strip())

    def read_int_array(self, size):
        return list(map(int, self.inp.readline().strip().split()))

class Output:
    def __init__(self, out):
        self.out = out

    def print_line(self, *args):
        self.out.write(' '.join(map(str, args)) + '\n')

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def next_prime(n):
    if n <= 2:
        return 2
    n += 1 - (n & 1)
    while not is_prime(n):
        n += 2
    return n

def primes(n):
    return [i for i in range(n) if is_prime(i)]

def id7(n):
    res = [0] * n
    if n > 1:
        res[1] = 1
    for i in range(2, n):
        if res[i] == 0:
            res[i] = i
            for j in range(i * i, n, i):
                res[j] = i
    return res

class DKhaotichnayaV:
    def solve(self, inp, outp):
        in_ = Input(inp)
        out = Output(outp)

        n = in_.read_int()
        k = in_.read_int_array(n)

        p = primes(5000)
        d = id7(5001)
        id0 = [Vector() for _ in range(5001)]
        id0[0] = Vector()
        id0[1] = Vector()
        for i in range(2, 5001):
            id0[i] = id0[i - 1][:]
            if d[i] == i:
                id0[i].append(1)
            else:
                for q in iter(lambda: d[q], 1):
                    id0[i][p.index(d[q])] += 1

        answer = 0
        q = defaultdict(int)
        for num in k:
            q[num] += 1

        lost = 0
        still = [True] * 5001
        cur = [0] * len(p)

        while True:
            cur = [0] * len(p)
            for i in range(5001):
                if still[i] and id0[i]:
                    cur[len(id0[i]) - 1] += q[i]

            pos = cur.index(max(cur))
            if cur[pos] <= n // 2:
                pos = -2

            step = float('inf')
            for i in range(5001):
                if still[i] and len(id0[i]) - 1 != pos:
                    answer += q[i] * sum(id0[i])
                    lost += q[i]
                    still[i] = False
                elif still[i]:
                    step = min(step, id0[i][-1])

            if pos == -2:
                break

            answer += step * lost
            for i in range(5001):
                if still[i]:
                    id0[i][-1] -= step
                    if id0[i][-1] == 0:
                        id0[i].pop()

        out.print_line(answer)

def main():
    DKhaotichnayaV().solve(sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()
