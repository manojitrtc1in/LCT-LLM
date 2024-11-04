from typing import List, Tuple

def merge(l: Tuple[int, int], r: Tuple[int, int]) -> Tuple[int, int]:
    return min(l[0], r[0]), max(l[1], r[1])

def apply_val(l: Tuple[int, int], r: Tuple[int, int]) -> Tuple[int, int]:
    return r

def init(st: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    n = len(st)
    T = [None] * (2 * n)
    for i in range(n):
        T[n + i] = st[i]
    for i in range(n - 1, 0, -1):
        T[i] = merge(T[i << 1], T[i << 1 | 1])
    return T

def update(T: List[Tuple[int, int]], i: int, v: Tuple[int, int]) -> None:
    n = len(T) // 2
    i += n
    T[i] = apply_val(T[i], v)
    while i > 1:
        T[i >> 1] = merge(T[i], T[i ^ 1])
        i >>= 1

def query(T: List[Tuple[int, int]], l: int, r: int) -> Tuple[int, int]:
    n = len(T) // 2
    ql, qr = (float('inf'), -float('inf')), (float('inf'), -float('inf'))
    l += n
    r += n
    while l <= r:
        if l & 1:
            ql = merge(ql, T[l])
            l += 1
        if not (r & 1):
            qr = merge(T[r], qr)
            r -= 1
        l >>= 1
        r >>= 1
    return merge(ql, qr)

def solve(N: int, R: List[int]) -> List[int]:
    id0 = 20
    T = [None] * id0
    RANGE = [[None] * (3 * N) for _ in range(id0)]
    ans = [0] * N

    for i in range(id0):
        T[i] = init([max(0, j - R[j % N]), min(3 * N - 1, j + R[j % N])] for j in range(3 * N))
        for j in range(3 * N):
            RANGE[i][j] = query(T[i - 1], RANGE[i - 1][j][0], RANGE[i - 1][j][1])

    for i in range(N):
        ans[i] = 1
        cur = (N + i, N + i)
        for j in range(id0 - 1, -1, -1):
            nxt = query(T[j], cur[0], cur[1])
            if nxt[1] - nxt[0] + 1 < N:
                ans[i] += 1 << j
                cur = nxt

    return ans

N = int(input())
R = list(map(int, input().split()))

if N == 1:
    print(0)
else:
    ans = solve(N, R)
    print(*ans)
