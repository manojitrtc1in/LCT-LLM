import sys
from typing import List, Tuple, Set

def xo(i: int) -> int:
    if (i & 3) == 0:
        return i
    if (i & 3) == 1:
        return 1
    if (i & 3) == 2:
        return i + 1
    return 0

def main() -> None:
    n = int(input())
    tot = 0
    data = []
    for _ in range(n):
        k, a, x, y, m = map(int, input().split())
        tot += k
        tmp = [a]
        for j in range(2, k + 1):
            tmp.append((tmp[-1] * x + y) % m)
        data.append(tmp)
    
    q = set()
    for i in range(n):
        q.add((data[i][0], (i, 0)))
    
    ans = []
    sol = []
    p = 0
    while len(ans) < tot:
        it = next((x for x in q if x[0] >= p), iter(q))
        v = it[0]
        p = v
        o = it[1]
        ans.append(v)
        sol.append((v, o[0] + 1))
        q.remove(it)
        if o[1] + 1 < len(data[o[0]]):
            q.add((data[o[0]][o[1] + 1], (o[0], o[1] + 1)))
    
    bad = 0
    for i in range(1, len(ans)):
        if ans[i - 1] > ans[i]:
            bad += 1
    
    print(bad)
    if tot <= 200000:
        for i in range(len(sol)):
            print(sol[i][0], sol[i][1])

if __name__ == "__main__":
    main()
