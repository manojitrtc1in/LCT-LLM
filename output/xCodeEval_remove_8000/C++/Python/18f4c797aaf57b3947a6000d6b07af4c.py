from typing import List, Tuple
from collections import defaultdict

def solve(n: int, A: str, m: int, queries: List[str]) -> List[int]:
    ans = defaultdict(int)
    stk = []
    nn = 0
    vis = [False] * 26

    def push(x: int) -> None:
        nonlocal nn
        if not vis[x]:
            vis[x] = True
            stk.append(x)
            nn += 1
        else:
            j = stk.index(x)
            for i in range(j, nn-1):
                stk[i] = stk[i+1]
            stk[nn-1] = x

    for i in range(n):
        push(ord(A[i]) - ord('a'))
        s = 0
        for j in range(nn, -1, -1):
            s |= (1 << stk[j])
            if s & (1 << ord(A[i+1]) - ord('a')):
                break
            if s in queries:
                ans[s] += 1

    result = []
    for query in queries:
        result.append(ans[query])
    return result

n = int(input())
A = input()
m = int(input())
queries = [input() for _ in range(m)]

output = solve(n, A, m, queries)
for ans in output:
    print(ans)
