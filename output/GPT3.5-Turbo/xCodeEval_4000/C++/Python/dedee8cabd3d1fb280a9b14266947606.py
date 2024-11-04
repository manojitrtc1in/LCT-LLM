import sys
from typing import List, Tuple

def dfs(k: int, n: int, A: List[int]) -> None:
    A.append(n)
    if k == 9:
        return
    else:
        dfs(k+1, n * 10 + 4, A)
        dfs(k+1, n * 10 + 7, A)

def I(l: int, r: int, l_: int, r_: int) -> int:
    l = max(l, l_)
    r = min(r, r_)
    return max(0, r - l + 1)

def solve(pl: int, pr: int, vl: int, vr: int, k: int) -> float:
    A = []
    dfs(0, 0, A)
    A.sort()
    A.append(sys.maxsize)
    cnt = 0
    for i in range(len(A) - k):
        l1 = A[i-1] + 1 if i > 0 else 0
        r1 = A[i]
        l2 = A[i + k - 1]
        r2 = A[i + k] - 1
        d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr)
        d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr)
        cnt += d1 + d2
        if d1 and d2 and k == 1:
            cnt -= 1
    return cnt / ((pr - pl + 1) * (vr - vl + 1))

def from_input_string(input_string: str) -> Tuple[int, int, int, int, int]:
    lines = input_string.strip().split('\n')
    pl, pr, vl, vr, k = map(int, lines[0].strip().split())
    return pl, pr, vl, vr, k

def to_input_string(inputs: Tuple[int, int, int, int, int]) -> str:
    pl, pr, vl, vr, k = inputs
    res = []
    res.append(f"{pl} {pr} {vl} {vr} {k}")
    return '\n'.join(res)

def from_output_string(output_string: str) -> float:
    return float(output_string.strip())

def to_output_string(output: float) -> str:
    return str(output)
