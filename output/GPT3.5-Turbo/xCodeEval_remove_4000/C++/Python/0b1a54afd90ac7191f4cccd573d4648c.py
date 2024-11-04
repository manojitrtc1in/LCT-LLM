import sys
from typing import List, Tuple
from collections import defaultdict

def solve(N: int, a: List[int], b: List[int]) -> int:
    mp = defaultdict(int)
    for i in range(N):
        mp[a[i]] += 1
    
    vs = []
    for elem in mp:
        if mp[elem] > 1:
            vs.append(elem)
    
    ans = 0
    for i in range(N):
        isok = False
        for elem in vs:
            if (elem & a[i]) == a[i]:
                isok = True
                break
        
        if isok:
            ans += b[i]
    
    return ans

def from_input_string(input_string: str) -> Tuple[int, List[int], List[int]]:
    lines = input_string.strip().split("\n")
    N = int(lines[0])
    a = list(map(int, lines[1].strip().split()))
    b = list(map(int, lines[2].strip().split()))
    return N, a, b

def to_input_string(inputs: Tuple[int, List[int], List[int]]) -> str:
    N, a, b = inputs
    res = []
    res.append(str(N))
    res.append(" ".join(str(x) for x in a))
    res.append(" ".join(str(x) for x in b))
    return "\n".join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)
