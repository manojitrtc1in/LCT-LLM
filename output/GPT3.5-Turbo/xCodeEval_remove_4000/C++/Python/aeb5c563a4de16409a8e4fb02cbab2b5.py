import sys
from typing import List, Tuple

MOD = 998244353

def solve(a: List[List[int]], w: List[int], dp: List[int], l: int, r: int) -> None:
    if r - l == 1:
        for i in range(a[l].size() + 1):
            ans = max(ans, dp[k - i] + sum(a[l][:i]))
        return
    m = (r + l) // 2
    dp2 = dp.copy()
    for i in range(m, r):
        for j in range(k - 1, -1, -1):
            if len(a[i]) + j <= k:
                dp2[j + len(a[i])] = max(dp2[j + len(a[i])], dp2[j] + w[i])
    solve(a, w, dp2, l, m)
    for i in range(l, m):
        for j in range(k - 1, -1, -1):
            if len(a[i]) + j <= k:
                dp[j + len(a[i])] = max(dp[j + len(a[i])], dp[j] + w[i])
    solve(a, w, dp, m, r)

def maximum_beauty(n: int, k: int, a: List[List[int]]) -> int:
    w = [sum(x) for x in a]
    ans = 0
    dp = [0] * (k + 1)
    solve(a, w, dp, 0, n)
    return ans

def from_input_string(input_string: str) -> Tuple[int, int, List[List[int]]]:
    lines = input_string.strip().split("\n")
    n, k = map(int, lines[0].strip().split())
    a = [list(map(int, x.strip().split())) for x in lines[1:]]
    return n, k, a

def to_input_string(inputs: Tuple[int, int, List[List[int]]]) -> str:
    n, k, a = inputs
    res = []
    res.append(f"{n} {k}")
    for x in a:
        res.append(" ".join(str(i) for i in x))
    return "\n".join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)
