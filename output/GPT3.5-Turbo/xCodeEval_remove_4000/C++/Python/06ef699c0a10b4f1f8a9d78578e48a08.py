import sys
from typing import List, Tuple

MOD = 1000000007

def solve(n: int, k: int, a: List[List[int]]) -> int:
    def dfs(l: int, r: int, dp: List[int]) -> None:
        if r - l == 1:
            sum_val = 0
            for i in range(len(a[l]) + 1):
                ans[0] = max(ans[0], dp[k - i] + sum_val)
                if i != len(a[l]):
                    sum_val += a[l][i]
            return
        m = (l + r) // 2
        dp2 = dp.copy()
        for i in range(m, r):
            for j in range(k - 1, -1, -1):
                if len(a[i]) + j <= k:
                    dp2[j + len(a[i])] = max(dp2[j + len(a[i])], dp2[j] + sum(a[i]))
        dfs(l, m, dp2)
        for i in range(l, m):
            for j in range(k - 1, -1, -1):
                if len(a[i]) + j <= k:
                    dp[j + len(a[i])] = max(dp[j + len(a[i])], dp[j] + sum(a[i]))
        dfs(m, r, dp)
    
    ans = [0]
    dp = [0] * (k + 1)
    dfs(0, n, dp)
    return ans[0]

def from_input_string(input_string: str) -> Tuple[int, int, List[List[int]]]:
    lines = input_string.strip().split('\n')
    n, k = map(int, lines[0].strip().split())
    a = [list(map(int, x.strip().split())) for x in lines[1:]]
    return n, k, a

def to_input_string(inputs: Tuple[int, int, List[List[int]]]) -> str:
    n, k, a = inputs
    res = []
    res.append(f"{n} {k}")
    for row in a:
        res.append(' '.join(str(x) for x in row))
    return '\n'.join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)
