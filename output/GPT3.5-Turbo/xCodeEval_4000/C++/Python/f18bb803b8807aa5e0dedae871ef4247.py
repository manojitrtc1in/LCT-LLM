import sys
from typing import List, Tuple
from collections import defaultdict

def read_int() -> int:
    return int(sys.stdin.readline())

def read_ints() -> Tuple[int, int]:
    return tuple(map(int, sys.stdin.readline().split()))

def solve(n: int, w: int, data: List[Tuple[int, int]]) -> int:
    x = [0.0] * n
    y = [0.0] * n
    cnt = defaultdict(int)
    
    for i in range(n):
        a, b = data[i]
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
    
    bit = [0] * 100007
    
    now = 0
    for i in range(n):
        while bs[now][0] < bs[i][0]:
            id_ = as_.index(x[bs[now][1]])
            bit[100006 - id_] += 1
            now += 1
        id_ = as_.index(x[bs[i][1]])
        ans += sum(bit[100006 - id_:])
    
    return ans

def main() -> None:
    n, w = read_ints()
    data = [read_ints() for _ in range(n)]
    ans = solve(n, w, data)
    print(ans)

if __name__ == "__main__":
    main()
