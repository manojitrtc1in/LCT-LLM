import sys
from typing import List, Tuple

def solve(n: int, a: List[int]) -> int:
    a.sort()
    d = [0] * n
    for i in range(n):
        c = a[i]
        for j in range(2, int(c ** 0.5) + 1):
            while c % j == 0:
                d[i] += 1
                c //= j
        if c != 1:
            d[i] += 1
    
    infty = sys.maxsize // 2
    reachable = [infty] * (1 << n)
    reachable[0] = 0
    for i in range(n):
        for j in range(1 << i):
            rem = a[i]
            good = True
            for k in range(i):
                if (j >> k) & 1:
                    if rem % a[k] != 0:
                        good = False
                        break
                    rem //= a[k]
            qty = 0
            for c in range(2, int(rem ** 0.5) + 1):
                while rem % c == 0:
                    qty += 1
                    rem //= c
            if rem != 1:
                qty += 1
            lim = 0 if i == 0 else 1 << (i - 1)
            if good:
                for k in range(1 << i):
                    if (j & k) == 0 and reachable[j + k] != infty and j + k >= lim:
                        reachable[(1 << i) + k] = min(reachable[(1 << i) + k], reachable[j + k] + qty + (d[i] == 1))
    
    answer = infty
    for i in range(1 << (n - 1), 1 << n):
        if reachable[i] != 0:
            answer = min(answer, reachable[i] + (bin(i).count('1') == 1))
    
    return answer

def from_input_string(input_string: str) -> Tuple[int, List[int]]:
    lines = input_string.strip().split('\n')
    n = int(lines[0])
    a = list(map(int, lines[1].strip().split()))
    return n, a

def to_input_string(inputs: Tuple[int, List[int]]) -> str:
    n, a = inputs
    res = []
    res.append(str(n))
    res.append(' '.join(str(x) for x in a))
    return '\n'.join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)
