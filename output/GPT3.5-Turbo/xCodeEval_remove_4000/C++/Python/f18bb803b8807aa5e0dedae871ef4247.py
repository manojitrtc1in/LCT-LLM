import sys
from typing import List, Tuple
from collections import defaultdict

def read() -> int:
    num = 0
    c = sys.stdin.read(1)
    if c == '-':
        return -read()
    while c >= '0' and c <= '9':
        num = (num << 3) + (num << 1) + int(c) - int('0')
        c = sys.stdin.read(1)
    return num

def main() -> None:
    n, w = map(int, input().split())
    x = [0.0] * n
    y = [0.0] * n
    cnt = defaultdict(int)
    for i in range(n):
        a, b = map(int, input().split())
        x[i] = 1.00 * a / (b + w)
        y[i] = 1.00 * a / (b - w)
        cnt[y[i]] += 1
    ans = 0
    for i in range(n):
        ans += cnt[y[i]] - 1
    ans //= 2
    as_ = sorted(x)
    cnta = len(set(as_))
    bs = sorted([(y[i], i) for i in range(n)])
    bit = BIT()
    now = 0
    for i in range(n):
        while bs[now][0] < bs[i][0]:
            id_ = as_.index(x[bs[now][1]])
            bit.add(100006 - id_, 1)
            now += 1
        id_ = as_.index(x[bs[i][1]])
        ans += bit.sum(100006 - id_)
    print(ans)

class BIT:
    def __init__(self) -> None:
        self.bit = [0] * 100007
        self.n = 100007

    def add(self, djg: int, x: int) -> None:
        while djg <= self.n:
            self.bit[djg] += x
            djg += (djg & -djg)

    def sum(self, djg: int) -> int:
        id0 = 0
        while djg:
            id0 += self.bit[djg]
            djg -= (djg & -djg)
        return id0

if __name__ == "__main__":
    main()
